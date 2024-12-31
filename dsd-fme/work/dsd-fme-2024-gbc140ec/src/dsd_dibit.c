/*
 * Copyright (C) 2010 DSD Author
 * GPG Key ID: 0x3F1D7FD0 (74EF 430D F7F2 0A48 FCE6  F630 FAA2 635D 3F1D 7FD0)
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#include <assert.h>

#include "dsd.h"

#include "p25p1_heuristics.h"

static void
print_datascope(dsd_opts* opts, dsd_state* state, int* sbuf2)
{
  int i, j, o;
  char modulation[8];
  int spectrum[64];

  if (state->rf_mod == 0)
    {
      sprintf (modulation, "C4FM");
    }
  else if (state->rf_mod == 1)
    {
      sprintf (modulation, "QPSK");
    }
  else if (state->rf_mod == 2)
    {
      sprintf (modulation, "GFSK");
    }

  for (i = 0; i < 64; i++)
    {
      spectrum[i] = 0;
    }
  for (i = 0; i < opts->ssize; i++)
    {
      o = (sbuf2[i] + 32768) / 1024;
      spectrum[o]++;
    }
  if (state->symbolcnt > (4800 / opts->scoperate))
    {
      state->symbolcnt = 0;
      fprintf (stderr, "\n");
      fprintf (stderr, "Demod mode:     %s                Nac:                     %4X\n", modulation, state->nac);
      fprintf (stderr, "Frame Type:    %s        Talkgroup:            %7i\n", state->ftype, state->lasttg);
      fprintf (stderr, "Frame Subtype: %s       Source:          %12i\n", state->fsubtype, state->lastsrc);
      fprintf (stderr, "TDMA activity:  %s %s     Voice errors: %s\n", state->slot0light, state->slot1light, state->err_str);
      fprintf (stderr, "+----------------------------------------------------------------+\n");
      for (i = 0; i < 10; i++)
        {
          printf ("|");
          for (j = 0; j < 64; j++)
            {
              if (i == 0)
                {
                  if ((j == ((state->min) + 32768) / 1024) || (j == ((state->max) + 32768) / 1024))
                    {
                      fprintf (stderr, "#");
                    }
                  else if ((j == ((state->lmid) + 32768) / 1024) || (j == ((state->umid) + 32768) / 1024))
                    {
                      fprintf (stderr, "^");
                    }
                  else if (j == (state->center + 32768) / 1024)
                    {
                      fprintf (stderr, "!");
                    }
                  else
                    {
                      if (j == 32)
                        {
                          fprintf (stderr, "|");
                        }
                      else
                        {
                          fprintf (stderr, " ");
                        }
                    }
                }
              else
                {
                  if (spectrum[j] > 9 - i)
                    {
                      fprintf (stderr, "*");
                    }
                  else
                    {
                      if (j == 32)
                        {
                          fprintf (stderr, "|");
                        }
                      else
                        {
                          fprintf (stderr, " ");
                        }
                    }
                }
            }
          fprintf (stderr, "|\n");
        }
      fprintf (stderr, "+----------------------------------------------------------------+\n");
    }
}

static void
use_symbol (dsd_opts* opts, dsd_state* state, int symbol)
{
  UNUSED(symbol);

  int i;
  int sbuf2[128];
  int lmin, lmax, lsum;

  for (i = 0; i < opts->ssize; i++)
    {
      sbuf2[i] = state->sbuf[i];
    }

  qsort (sbuf2, opts->ssize, sizeof (int), comp);

  // continuous update of min/max in rf_mod=1 (QPSK) mode
  // in c4fm min/max must only be updated during sync
  if (state->rf_mod == 1)
    {
      lmin = (sbuf2[0] + sbuf2[1]) / 2;
      lmax = (sbuf2[(opts->ssize - 1)] + sbuf2[(opts->ssize - 2)]) / 2;
      state->minbuf[state->midx] = lmin;
      state->maxbuf[state->midx] = lmax;
      if (state->midx == (opts->msize - 1))
        {
          state->midx = 0;
        }
      else
        {
          state->midx++;
        }
      lsum = 0;
      for (i = 0; i < opts->msize; i++)
        {
          lsum += state->minbuf[i];
        }
      state->min = lsum / opts->msize;
      lsum = 0;
      for (i = 0; i < opts->msize; i++)
        {
          lsum += state->maxbuf[i];
        }
      state->max = lsum / opts->msize;
      state->center = ((state->max) + (state->min)) / 2;
      state->umid = (((state->max) - state->center) * 5 / 8) + state->center;
      state->lmid = (((state->min) - state->center) * 5 / 8) + state->center;
      state->maxref = (int)((state->max) * 0.80F);
      state->minref = (int)((state->min) * 0.80F);
    }
  else
    {
      state->maxref = state->max;
      state->minref = state->min;
    }

  // Increase sidx
  if (state->sidx >= (opts->ssize - 1))
    {
      state->sidx = 0;

      if (opts->datascope == 1)
        {
          print_datascope(opts, state, sbuf2);
        }
    }
  else
    {
      state->sidx++;
    }

  if (state->dibit_buf_p > state->dibit_buf + 900000)
  {
    state->dibit_buf_p = state->dibit_buf + 200;
  }

  //dmr buffer
  if (state->dmr_payload_p > state->dmr_payload_buf + 900000)
  {
   state->dmr_payload_p = state->dmr_payload_buf + 200;
  }
  //dmr buffer end
}

static int
invert_dibit(int dibit)
{
    switch (dibit)
    {
    case 0:
        return 2;
    case 1:
        return 3;
    case 2:
        return 0;
    case 3:
        return 1;
    }

    // Error, shouldn't be here
    assert(0);
    return -1;
}

int digitize (dsd_opts* opts, dsd_state* state, int symbol)
{
  // determine dibit state
  if ((state->synctype == 6) || (state->synctype == 14)|| (state->synctype == 18) || (state->synctype == 37))

    {
      //  6 +D-STAR
      // 14 +ProVoice
      // 18 +D-STAR_HD
      // 37 +EDACS

      if (symbol > state->center)
        {
          *state->dibit_buf_p = 1;
          state->dibit_buf_p++;
          return (0);               // +1
        }
      else
        {
          *state->dibit_buf_p = 3;
          state->dibit_buf_p++;
          return (1);               // +3
        }
    }
  else if ((state->synctype == 7) || (state->synctype == 15)|| (state->synctype == 19) || (state->synctype == 38))
    {
      //  7 -D-STAR
      // 15 -ProVoice
      // 19 -D-STAR_HD
      // 38 -EDACS

      if (symbol > state->center)
        {
          *state->dibit_buf_p = 1;
          state->dibit_buf_p++;
          return (1);               // +3
        }
      else
        {
          *state->dibit_buf_p = 3;
          state->dibit_buf_p++;
          return (0);               // +1
        }
    }

  else if ((state->synctype == 1) || (state->synctype == 3)  || (state->synctype == 5)  ||
          (state->synctype == 9)  || (state->synctype == 11) || (state->synctype == 13) ||
          (state->synctype == 17) || (state->synctype == 29) || (state->synctype == 31) ||
          (state->synctype == 77) || (state->synctype == 87) ||(state->synctype == 36) || 
          (state->synctype == 99)                              )

    {
      //  1 -P25p1
      //  3 -X2-TDMA (inverted signal voice frame)
      //  5 -X2-TDMA (inverted signal data frame)
      //  9 -M17 LSR
      // 11 -DMR (inverted signal voice frame)
      // 13 -DMR (inverted signal data frame)
      // 17 -M17 STR
      // 29 -NXDN (inverted FSW)
      // 31 -YSF 
      // 36 -P25p2 
      // 77 -M17 BRT
      // 87 -M17 PKT
      // 99 -M17 Preamble

      int valid;
      int dibit;

      valid = 0;

      UNUSED(opts);

      //testing again, either on Voice channels only (when tuned) or with trunk disabled
      // if (state->synctype == 1 && (opts->p25_is_tuned == 1 || opts->p25_trunk == 0) && opts->use_heuristics == 1)
      if (state->synctype == 1 && opts->use_heuristics == 1)
      {
        // Use the P25p1 heuristics if available
        valid = estimate_symbol(state->rf_mod, &(state->inv_p25_heuristics), state->last_dibit, symbol, &dibit);
      }

      if (valid == 0)
        {
          // Revert to the original approach: choose the symbol according to the regions delimited
          // by center, umid and lmid
          if (symbol > state->center)
            {
              if (symbol > state->umid)
                {
                  dibit = 3;               // -3
                }
              else
                {
                  dibit = 2;               // -1
                }
            }
          else
            {
              if (symbol < state->lmid)
                {
                  dibit = 1;               // +3
                }
              else
                {
                  dibit = 0;               // +1
                }
            }
        }

      state->last_dibit = dibit;

      *state->dibit_buf_p = invert_dibit(dibit);
      state->dibit_buf_p++;

      //dmr buffer
      *state->dmr_payload_p = invert_dibit(dibit); 
      state->dmr_payload_p++;
      //dmr buffer end

      return dibit;
    }
  else
    {
      //  0 +P25p1
      //  2 +X2-TDMA (non inverted signal data frame)
      //  4 +X2-TDMA (non inverted signal voice frame)
      //  8 +M17 LSF
      // 10 +DMR (non inverted signal data frame)
      // 12 +DMR (non inverted signal voice frame)
      // 16 +M17 STR
      // 28 +NXND (FSW)
      // 30 +YSF
      // 35 +p25p2
      // 76 +M17 BRT
      // 86 +M17 PKT
      // 98 +M17 Preamble

      int valid;
      int dibit;

      valid = 0;

      //testing again, either on Voice channels only (when tuned) or with trunk disabled
      // if (state->synctype == 0 && (opts->p25_is_tuned == 1 || opts->p25_trunk == 0) && opts->use_heuristics == 1)
      if (state->synctype == 0 && opts->use_heuristics == 1)
      {
        // Use the P25p1 heuristics if available
        valid = estimate_symbol(state->rf_mod, &(state->p25_heuristics), state->last_dibit, symbol, &dibit);
      }

      if (valid == 0)
        {
          // Revert to the original approach: choose the symbol according to the regions delimited
          // by center, umid and lmid
          if (symbol > state->center)
            {
              if (symbol > state->umid)
                {
                  dibit = 1;               // +3
                }
              else
                {
                  dibit = 0;               // +1
                }
            }
          else
            {
              if (symbol < state->lmid)
                {
                  dibit = 3;               // -3
                }
              else
                {
                  dibit = 2;               // -1
                }
            }
        }

      state->last_dibit = dibit;

      *state->dibit_buf_p = dibit;
      state->dibit_buf_p++;

      //dmr buffer
      //note to self, perceived bug with initial dibit buffer appears to be caused by
      //media player, when playing back from audacity, the initial few dmr frames are
      //decoded properly, need to investigate the root cause of what audacity is doing
      //vs other audio sources...perhaps just the audio level itself?
      *state->dmr_payload_p = dibit;
      state->dmr_payload_p++;
      //dmr buffer end

      return dibit;
    }
}

int
get_dibit_and_analog_signal (dsd_opts* opts, dsd_state* state, int* out_analog_signal)
{
  int symbol;
  int dibit;

#ifdef TRACE_DSD
  unsigned int l, r;
#endif

  state->numflips = 0;

#ifdef TRACE_DSD
  l = state->debug_sample_index;
#endif

  symbol = getSymbol (opts, state, 1);

#ifdef TRACE_DSD
  r = state->debug_sample_index;
#endif


  state->sbuf[state->sidx] = symbol;

  if (out_analog_signal != NULL)
    {
      *out_analog_signal = symbol;
    }

  use_symbol (opts, state, symbol);

  dibit = digitize (opts, state, symbol);

  if (opts->audio_in_type == 4) 
  {
    //assign dibit from last symbol/dibit read from capture bin
    dibit = state->symbolc;
    if (state->use_throttle == 1)
		{
			usleep(0); 
		}
  }

  //symbol/dibit file capture/writing
  if (opts->symbol_out_f)
  {
    //fprintf (stderr, "%d", dibit);
    fputc (dibit, opts->symbol_out_f);
  }

#ifdef TRACE_DSD
  {
      float left, right;
      if (state->debug_label_dibit_file == NULL) {
          state->debug_label_dibit_file = fopen ("pp_label_dibit.txt", "w");
      }
      left = l / 48000.0;
      right = r / 48000.0;
      fprintf(state->debug_label_dibit_file, "%f\t%f\t%i\n", left, right, dibit);
  }
#endif

  return dibit;
}

/**
 * \brief This important method reads the last analog signal value (getSymbol call) and digitizes it.
 * Depending of the ongoing transmission it in converted into a bit (0/1) or a di-bit (00/01/10/11).
 */
int
getDibit (dsd_opts* opts, dsd_state* state)
{
  return get_dibit_and_analog_signal (opts, state, NULL);
}

void
skipDibit (dsd_opts * opts, dsd_state * state, int count)
{

  short sample;
  int i;
  UNUSED(sample);

  for (i = 0; i < (count); i++)
    {
      sample = getDibit (opts, state);
    }
}
