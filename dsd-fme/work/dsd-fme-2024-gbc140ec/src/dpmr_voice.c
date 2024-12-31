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

#include "dsd.h"
#include "dpmr_const.h"

void processdPMRvoice (dsd_opts * opts, dsd_state * state)
{
  uint32_t i, j, k, dibit;
  uint8_t CCH[NB_OF_DPMR_VOICE_FRAME_TO_DECODE][72] = {0};
  uint8_t CCHDescrambled[NB_OF_DPMR_VOICE_FRAME_TO_DECODE][72] = {0};
  uint8_t CCHDeInterleaved[NB_OF_DPMR_VOICE_FRAME_TO_DECODE][72] = {0};
  uint8_t CCHDataHammingCorrected[NB_OF_DPMR_VOICE_FRAME_TO_DECODE][48];
  uint8_t CCHDataCRC[NB_OF_DPMR_VOICE_FRAME_TO_DECODE];

  memset (CCHDataHammingCorrected, 1, sizeof(CCHDataHammingCorrected));
  memset (CCHDataCRC, 1, sizeof(CCHDataCRC));

  uint8_t CCHDataCRCComputed[NB_OF_DPMR_VOICE_FRAME_TO_DECODE];
  memset (CCHDataCRCComputed, 0, sizeof(CCHDataCRCComputed));

  uint8_t CC[NB_OF_DPMR_VOICE_FRAME_TO_DECODE / 2][24] = {0};
  char ambe_fr[NB_OF_DPMR_VOICE_FRAME_TO_DECODE * 4][4][24];
  memset (ambe_fr, 0, sizeof (ambe_fr));
  const int *w, *x, *y, *z;
  uint32_t  ScramblerLFSR = 0;
  bool correctable = true;
  bool HammingCorrectable[NB_OF_DPMR_VOICE_FRAME_TO_DECODE][6] = {0};
  uint32_t  CrcOk[NB_OF_DPMR_VOICE_FRAME_TO_DECODE] = {0};
  uint32_t  HammingOk[NB_OF_DPMR_VOICE_FRAME_TO_DECODE] = {0};
  uint32_t Temp = 0;
  /* CCH (Control CHannel) data */
  uint32_t CCH_FrameNumber[NB_OF_DPMR_VOICE_FRAME_TO_DECODE] = {0};
  uint32_t CCH_CalledID = 0;
  uint32_t CCH_CallingID = 0;
  uint32_t CCH_CommunicationMode[NB_OF_DPMR_VOICE_FRAME_TO_DECODE] = {0};
  uint32_t CCH_Version[NB_OF_DPMR_VOICE_FRAME_TO_DECODE];
  uint32_t CCH_CommsFormat[NB_OF_DPMR_VOICE_FRAME_TO_DECODE];
  uint32_t CCH_EmergencyPriority[NB_OF_DPMR_VOICE_FRAME_TO_DECODE];
  uint32_t CCH_Reserved[NB_OF_DPMR_VOICE_FRAME_TO_DECODE];
  uint32_t CCH_SlowData[NB_OF_DPMR_VOICE_FRAME_TO_DECODE];
  uint32_t PartOfSuperFrame = 0;
  uint8_t CalledID[8] = {0};
  uint8_t CallingID[8] = {0};
  UNUSED(PartOfSuperFrame);

  /* First CCH (Control CHannel) - 72 bit */
  k = 0;

  for (i = 0; i < 36; i++)
  {
    dibit = getDibit (opts, state);

    if (opts->inverted_dpmr == 1)
    {
      dibit = (dibit ^ 2);
    }

    CCH[0][(i * 2)]     =  (1 & (dibit >> 1));   // bit 1
    CCH[0][(i * 2) + 1] =  (1 & dibit);          // bit 0

  }

  /* 4 TCH (Traffic CHannel) = 4 x 72 bit voice playload */
  k = 0;
  for (j = 0; j < 4; j++)
  {
    w = dPmrW;
    x = dPmrX;
    y = dPmrY;
    z = dPmrZ;
    k = 0;
    for (i = 0; i < 36; i++)
    {
      dibit = getDibit (opts, state);

      if (opts->inverted_dpmr == 1)
      {
        dibit = (dibit ^ 2);
      }

      ambe_fr[j][*w][*x] = (1 & (dibit >> 1));   // bit 1
      ambe_fr[j][*y][*z] = (1 & dibit);          // bit 0
      state->dPMRVoiceFS2Frame.RawVoiceBit[j][k]     = (1 & (dibit >> 1)); // bit 1
      state->dPMRVoiceFS2Frame.RawVoiceBit[j][k + 1] = (1 & dibit);        // bit 0
      k = k + 2;
      w++;
      x++;
      y++;
      z++;
    }
  }

  /* First CC (Channel Code) - 24 bit */
  k = 0;
  for (i = 0; i < 12; i++)
  {
    dibit = getDibit (opts, state);

    if (opts->inverted_dpmr == 1)
    {
      dibit = (dibit ^ 2);
    }

    CC[0][k++] =  (1 & (dibit >> 1));   // bit 1
    CC[0][k++] =  (1 & dibit);          // bit 0


  }

  /* Get the color code */
  state->dPMRVoiceFS2Frame.ColorCode[0] = (unsigned int)GetdPmrColorCode(CC[0]);

  /* Second CCH (Control CHannel) - 72 bit */
  k = 0;
  for (i = 0; i < 36; i++)
  {
    dibit = getDibit (opts, state);

    if (opts->inverted_dpmr == 1)
    {
      dibit = (dibit ^ 2);
    }

    CCH[1][k++] =  (1 & (dibit >> 1));   // bit 1
    CCH[1][k++] =  (1 & dibit);          // bit 0


  }

  /* 4 TCH (Traffic CHannel) = 4 x 72 bit voice playload */

  k = 0;
  for (j = 0; j < 4; j++)
  {
    w = dPmrW;
    x = dPmrX;
    y = dPmrY;
    z = dPmrZ;
    k = 0;
    for (i = 0; i < 36; i++)
    {
      dibit = getDibit (opts, state);

    if (opts->inverted_dpmr == 1)
    {
      dibit = (dibit ^ 2);
    }

      ambe_fr[j + 4][*w][*x] = (1 & (dibit >> 1));   // bit 1
      ambe_fr[j + 4][*y][*z] = (1 & dibit);          // bit 0
      state->dPMRVoiceFS2Frame.RawVoiceBit[j + 4][k]     = (1 & (dibit >> 1)); // bit 1
      state->dPMRVoiceFS2Frame.RawVoiceBit[j + 4][k + 1] = (1 & dibit);        // bit 0
      k = k + 2;
      w++;
      x++;
      y++;
      z++;

    }
  }

  /* Decoding all CCH (Control CHannel) */
  for(i = 0; i < NB_OF_DPMR_VOICE_FRAME_TO_DECODE; i++)
  {
    /* Init LFSR value - All bit to '1' */
    ScramblerLFSR = 0x1FF;

    /* Descramble data - Input 72 bit => Output 72 bit */
    ScrambledPMRBit(&ScramblerLFSR, CCH[i], CCHDescrambled[i], 72);

    /* Deinterleave data - Input 72 bit => Output 72 bit */
    DeInterleave6x12DPmrBit(CCHDescrambled[i], CCHDeInterleaved[i]);

    correctable = true;
    for(j = 0; j < 6; j++)
    {
      /* Apply the Hamming(12,8) correction - Input 72 bit => Output 48 bit */
      HammingCorrectable[i][j] = Hamming_12_8_decode(&CCHDeInterleaved[i][j*12], &CCHDataHammingCorrected[i][j*8], 1);
      if(HammingCorrectable[i][j] == false) correctable = false;
    }

    if(correctable) HammingOk[i] = 1;
    else HammingOk[i] = 0;

    /* Reconstitute the 7 bit CRC */
    CCHDataCRC[i] = 0;
    CCHDataCRC[i] |= (CCHDataHammingCorrected[i][41]) << 6;
    CCHDataCRC[i] |= (CCHDataHammingCorrected[i][42]) << 5;
    CCHDataCRC[i] |= (CCHDataHammingCorrected[i][43]) << 4;
    CCHDataCRC[i] |= (CCHDataHammingCorrected[i][44]) << 3;
    CCHDataCRC[i] |= (CCHDataHammingCorrected[i][45]) << 2;
    CCHDataCRC[i] |= (CCHDataHammingCorrected[i][46]) << 1;
    CCHDataCRC[i] |= (CCHDataHammingCorrected[i][47]) << 0;

    /* Compute the 7 bit CRC */
    CCHDataCRCComputed[i] = CRC7BitdPMR(CCHDataHammingCorrected[i], 41);

    if(CCHDataCRC[i] == CCHDataCRCComputed[i]) CrcOk[i] = 1;
    else CrcOk[i] = 0;

    /* Fill the frame number */
    CCH_FrameNumber[i] = ConvertBitIntoBytes(&CCHDataHammingCorrected[i][0], 2);

    /* Fill the communication mode */
    CCH_CommunicationMode[i] = ConvertBitIntoBytes(&CCHDataHammingCorrected[i][14], 3);

    /* Fill the version */
    CCH_Version[i] = ConvertBitIntoBytes(&CCHDataHammingCorrected[i][17], 2);

    /* Fill the comm format */
    CCH_CommsFormat[i] = ConvertBitIntoBytes(&CCHDataHammingCorrected[i][19], 2);

    /* Fill the emergency priority bit */
    CCH_EmergencyPriority[i] = (uint32_t)CCHDataHammingCorrected[i][21];

    /* Fill the reserved bit */
    CCH_Reserved[i] = (uint32_t)CCHDataHammingCorrected[i][22];

    /* Fill the slow data */
    CCH_SlowData[i] = ConvertBitIntoBytes(&CCHDataHammingCorrected[i][23], 18);

    /* Copy the CCH data into the structure */
    memcpy(state->dPMRVoiceFS2Frame.CCHData[i], CCHDataHammingCorrected[i], 48);
           state->dPMRVoiceFS2Frame.CCHDataHammingOk[i]  = HammingOk[i];
           state->dPMRVoiceFS2Frame.CCHDataCRC[i]        = CCHDataCRC[i];
           state->dPMRVoiceFS2Frame.CCHDataCrcOk[i]      = CrcOk[i];
           state->dPMRVoiceFS2Frame.FrameNumbering[i]    = CCH_FrameNumber[i];
           state->dPMRVoiceFS2Frame.CommunicationMode[i] = CCH_CommunicationMode[i];
           state->dPMRVoiceFS2Frame.Version[i]           = CCH_Version[i];
           state->dPMRVoiceFS2Frame.CommsFormat[i]       = CCH_CommsFormat[i];
           state->dPMRVoiceFS2Frame.EmergencyPriority[i] = CCH_EmergencyPriority[i];
           state->dPMRVoiceFS2Frame.Reserved[i]          = CCH_Reserved[i];
           state->dPMRVoiceFS2Frame.SlowData[i]          = CCH_SlowData[i];
  } /* End for(i = 0; i < NB_OF_DPMR_VOICE_FRAME_TO_DECODE; i++) */

  /* Get the last TG */
  strcpy((char *)CalledID, (char *)state->dPMRVoiceFS2Frame.CalledID);
  CalledID[7] = '\0';

  /* Get the last source ID */
  strcpy((char *)CallingID, (char *)state->dPMRVoiceFS2Frame.CallingID);
  CallingID[7] = '\0';


  /* To determine the part of the payload frame, we need to check the
   * Hamming code result, the CRC and the frame number */

//  if( (HammingOk[0] && CrcOk[0] && (CCH_FrameNumber[0] == 0)) ||
//      (HammingOk[1] && CrcOk[1] && (CCH_FrameNumber[1] == 1)))

  if(((CrcOk[0] || HammingCorrectable[0][0]) && (CCH_FrameNumber[0] == 0)) ||
     ((CrcOk[1] || HammingCorrectable[1][0]) && (CCH_FrameNumber[1] == 1)))
  {
    /* First part of the super frame */
    PartOfSuperFrame = 1;

    /* The next part will normally be the second part */
    opts->dPMR_next_part_of_superframe = 2;

    /* Fill the called ID (talk group - TG) */
    Temp = ConvertBitIntoBytes(&CCHDataHammingCorrected[0][2], 12);
    CCH_CalledID = ((Temp << 12) & 0x00FFF000); /* 12 MSBit */
    Temp = ConvertBitIntoBytes(&CCHDataHammingCorrected[1][2], 12);
    CCH_CalledID |= (Temp & 0x00000FFF); /* 12 LSBit */
    ConvertAirInterfaceID(CCH_CalledID, CalledID);
    CalledID[7] = '\0';

    /* Determine if the called TG ID only is correct */
    //if(HammingOk[0] && CrcOk[0] && HammingOk[1] && CrcOk[1])
    if((CrcOk[0] || (HammingCorrectable[0][0] && HammingCorrectable[0][1])) &&
       (CrcOk[1] || (HammingCorrectable[1][0] && HammingCorrectable[1][1])))
    {
      /* Save CCH data parameters */
      state->dPMRVoiceFS2Frame.CalledIDOk = 1;
    }
    else
    {
      state->dPMRVoiceFS2Frame.CalledIDOk = 0;
    }

    /* BUGFIX : Copy in all case the TG ID */
    strcpy((char *)state->dPMRVoiceFS2Frame.CalledID, (char *)CalledID);
  }

  /* To determine the part of the payload frame, we need to check the
   * Hamming code result, the CRC and the frame number */

//  else if( (HammingOk[0] && CrcOk[0] && (CCH_FrameNumber[0] == 2)) ||
//           (HammingOk[1] && CrcOk[1] && (CCH_FrameNumber[1] == 3)))

  else if(((CrcOk[0] || HammingCorrectable[0][0]) && (CCH_FrameNumber[0] == 2)) ||
          ((CrcOk[1] || HammingCorrectable[1][0]) && (CCH_FrameNumber[1] == 3)))
  {
    /* Second part of the super frame */
    PartOfSuperFrame = 2;

    /* The next part will normally be the first part */
    opts->dPMR_next_part_of_superframe = 1;

    /* Fill the calling ID (source) */
    Temp = ConvertBitIntoBytes(&CCHDataHammingCorrected[0][2], 12);
    CCH_CallingID = ((Temp << 12) & 0x00FFF000); /* 12 MSBit */
    Temp = ConvertBitIntoBytes(&CCHDataHammingCorrected[1][2], 12);
    CCH_CallingID |= (Temp & 0x00000FFF); /* 12 LSBit */
    ConvertAirInterfaceID(CCH_CallingID, CallingID);
    CallingID[7] = '\0';

    /* Determine if the calling SRC ID is correct */

    //if(HammingOk[0] && CrcOk[0] && HammingOk[1] && CrcOk[1])

    if((CrcOk[0] || (HammingCorrectable[0][0] && HammingCorrectable[0][1])) &&
       (CrcOk[1] || (HammingCorrectable[1][0] && HammingCorrectable[1][1])))
    {
      /* Save CCH data parameters */
      state->dPMRVoiceFS2Frame.CallingIDOk = 1;
    }
    else
    {
      state->dPMRVoiceFS2Frame.CallingIDOk = 0;
    }

    /* BUGFIX : Copy in all case the SRC ID */
    strcpy((char *)state->dPMRVoiceFS2Frame.CallingID, (char *)CallingID);
  }
  else
  {
    /* The dPMR source and destination ID are now invalid */
    state->dPMRVoiceFS2Frame.CalledIDOk  = 0;
    state->dPMRVoiceFS2Frame.CallingIDOk = 0;

    /* Unknown part of superframe => We suppose
     * it is the next part of the previous frame received */
    PartOfSuperFrame = opts->dPMR_next_part_of_superframe;

    /* Set the next part of the superframe to receive */
    if(opts->dPMR_next_part_of_superframe == 1)
    {
      /* Set the next part as the second part */
      opts->dPMR_next_part_of_superframe = 2;
    }
    else if(opts->dPMR_next_part_of_superframe == 2)
    {
      /* Set the next part as the first part */
      opts->dPMR_next_part_of_superframe = 1;
    }
    else
    {
      /* Unknown current part, set to 0 */
      opts->dPMR_next_part_of_superframe = 0;
    }
  }

  /* Display the destination ID (talk group - TG) */
  fprintf (stderr, "\n");

  if(state->dPMRVoiceFS2Frame.CalledIDOk)
  {
    fprintf (stderr, "%s", KGRN);
    fprintf(stderr, " TG=%s", CalledID);
    fprintf (stderr, "%s", KNRM);

    //check other as well before assigning
    if(state->dPMRVoiceFS2Frame.CallingIDOk) sprintf (state->dpmr_target_id, "%s", CalledID);

  }
  else
  {
    fprintf (stderr, "%s", KRED);
    fprintf(stderr, " TG=(CRC ERR)");
    fprintf (stderr, "%s", KNRM);
  }

  /* Display the source ID */
  if(state->dPMRVoiceFS2Frame.CallingIDOk)
  {
    fprintf (stderr, "%s", KGRN);
    fprintf(stderr, " Src=%s", CallingID);
    fprintf (stderr, "%s", KNRM);

    //check other as well before assigning
    if(state->dPMRVoiceFS2Frame.CalledIDOk) sprintf (state->dpmr_caller_id, "%s", CallingID);

    //stashed channel code in here, more likely to be correct, but no guarantee
    if(state->dPMRVoiceFS2Frame.ColorCode[0] != (unsigned int)(-1))
    {
      fprintf (stderr, "%s", KGRN);
      fprintf(stderr, " Channel Code=%02d", (int)state->dPMRVoiceFS2Frame.ColorCode[0]);
      fprintf (stderr, "%s", KNRM);

      //check other as well before assigning
      if(state->dPMRVoiceFS2Frame.CalledIDOk) state->dpmr_color_code = (int)state->dPMRVoiceFS2Frame.ColorCode[0];
    }

  }
  else
  {
  fprintf (stderr, "%s", KRED);
  fprintf(stderr, " Src=(CRC ERR) Channel Code =(CRC ERR)");
  fprintf (stderr, "%s", KNRM); 
  }

  if (state->dPMRVoiceFS2Frame.Version[0] == 3)
  {
    fprintf (stderr, "%s", KRED);
    fprintf (stderr, " Scrambler");
    fprintf (stderr, "%s", KNRM);
    if (state->R != 0)
    {
      fprintf (stderr, "%s", KYEL);
      fprintf (stderr, " Key %05lld ", state->R );
      fprintf (stderr, "%s", KNRM);
    }
  }

  //Play only voice frames by first looking to see if there is a TCH voice in CommunicationMode,
  short start = 0;
  short end = 4;

  //not really even sure why I made this loop
  //I probably should actually read the manual again
  for (short o = 0; o < 2; o++)
  {

    //reset scrambler key seed on frame 0
    if (state->dPMRVoiceFS2Frame.FrameNumbering[o] == 0) state->payload_miN = 0;
    
    //depending on first or second TCH, set start and end variables appropriately
    if (o == 1)
    {
      start = 4;
      end = 8;

    }

    //this is used so we can simply pass the voice here to the 
    //nxdn scrambler by telling mbe these are nxdn frames and to
    //apply the same descramble method to them if necessary
    int realsynctype = state->synctype; 

    // fprintf (stderr, "\nCommunication Mode: %d\n", state->dPMRVoiceFS2Frame.CommunicationMode[o]);
    // fprintf (stderr, "Encryption Mode: %d\n", state->dPMRVoiceFS2Frame.Version[o]); //shows as 3 (manufacturer specific, 5.16) on the dPMR scrambler values received
    // fprintf (stderr, "Superframe Number: %d", state->dPMRVoiceFS2Frame.FrameNumbering[o]); 

    if((state->dPMRVoiceFS2Frame.CommunicationMode[o] == 0) ||
       (state->dPMRVoiceFS2Frame.CommunicationMode[o] == 1) ||
       (state->dPMRVoiceFS2Frame.CommunicationMode[o] == 5))
    {

      //check to see if we are using scrambler
      if (state->dPMRVoiceFS2Frame.Version[o] == 3) //!= 0
      {
        state->synctype = 28; //fake it as nxdn
        state->nxdn_cipher_type = 0x01; //turn on nxdn scrambler cipher
        state->dmr_encL = 1; //flag on enc bit here so we can mute if no key provided
      }
      
      //flag back off if key is provided
      if (state->R != 0) state->dmr_encL = 0;

      //print Current Frame Number if payload verbosity enabled
      if (opts->payload == 1)
        fprintf (stderr, "\n FN %d/4", state->dPMRVoiceFS2Frame.FrameNumbering[o]+1);
      
      //There are 4 AMBE voice frames per TCH
      for(i = start; i < end; i++)
      {
        processMbeFrame (opts, state, NULL, ambe_fr[i], NULL);
        if (opts->floating_point == 0)
          playSynthesizedVoiceMS(opts, state);
        if (opts->floating_point == 1)
          playSynthesizedVoiceFM(opts, state);
      } 

      //set the correct sync type again and flag off the cipher
      state->synctype = realsynctype;
      state->nxdn_cipher_type = 0;

    } 
  } 

  fprintf(stderr, "\n");


//keep code below, could be handy cheat sheet for other info
#ifdef dPMR_PRINT_DEBUG_INFO
  //Display the CCH content
  for(i = 0; i < NB_OF_DPMR_VOICE_FRAME_TO_DECODE; i++)
  {
    fprintf(stderr, "i = %u - ", i);
    fprintf(stderr, "Comm Mode = %01u - ", state->dPMRVoiceFS2Frame.CommunicationMode[i]);
    fprintf(stderr, "Version = %01u - ", state->dPMRVoiceFS2Frame.Version[i]);
    fprintf(stderr, "Comms Format = %01u - ", state->dPMRVoiceFS2Frame.CommsFormat[i]);
    fprintf(stderr, "Emergency = %01u - ", state->dPMRVoiceFS2Frame.EmergencyPriority[i]);
    fprintf(stderr, "Reserved = %01u - ", state->dPMRVoiceFS2Frame.Reserved[i]);
    fprintf(stderr, "Slow Data = 0x%05X - ", state->dPMRVoiceFS2Frame.SlowData[i]);
    if(HammingOk[i] && CrcOk[i]) fprintf(stderr, "Valid");
    else fprintf(stderr, "CRC ERROR");
    fprintf(stderr, "\n");
  }
#endif //dPMR_PRINT_DEBUG_INFO

} //End processdPMRvoice()


/* Scrambler used for dPMR transmission (different of the
 * voice encryption scrambler), see ETSI TS 102 658 chapter
 * 7.3 for the polynomial description.
 * It is a X^9 + X^5 + 1 polynomial. */

void ScrambledPMRBit(uint32_t * LfsrValue, uint8_t * BufferIn, uint8_t * BufferOut, uint32_t NbOfBitToScramble)
{
  uint8_t  S[9] = {0};
  uint32_t i;
  uint8_t  Temp;
  uint32_t LFSRValue;

  LFSRValue = *LfsrValue;

  /* Load the initial LFSR value */
  for(i = 0; i < 9; i++)
  {
    S[i] = LFSRValue & 1;
    LFSRValue >>= 1;
  }

  /* There are 72 bit to descramble for voice and 288 bit for data */
  for(i = 0; i < NbOfBitToScramble; i++)
  {
    BufferOut[i] = (BufferIn[i] ^ S[0]) & 0x01;

    /* Shift registers */
    Temp = S[4] ^ S[0];
    S[0] = S[1];
    S[1] = S[2];
    S[2] = S[3];
    S[3] = S[4];
    S[4] = S[5];
    S[5] = S[6];
    S[6] = S[7];
    S[7] = S[8];
    S[8] = Temp;
  }

  /* Save the final LFSR value */
  LFSRValue = 0;
  for(i = 9; i > 0; i--)
  {
    LFSRValue <<= 1;
    LFSRValue |= S[i - 1] & 1;
  }

  *LfsrValue = LFSRValue;
} /* End ScrambleDPmrBit() */


/* Scrambler used for dPMR scrambling / descrambling,
 * see ETSI TS 102 658 chapter 7.4 for the
 * polynomial description.
 * It is a X^9 + X^5 + 1 polynomial. */
void DeInterleave6x12DPmrBit(uint8_t * BufferIn, uint8_t * BufferOut)
{
  uint8_t Matrix[12][6] = {0};
  uint32_t i, j, k;

  /* Step 1 : Filling the 12 x 6 bit matrix */
  k = 0;
  for(i = 0; i < 12; i++)
  {
    for(j = 0; j < 6; j++)
    {
      Matrix[i][j] = BufferIn[k++];
    }
  }

  /* Step 2 : Filling the output buffer with deinterleaved data */
  k = 0;
  for(j = 0; j < 6; j++)
  {
    for(i = 0; i < 12; i++)
    {
      BufferOut[k++] = Matrix[i][j];
    }
  }
} /* End DeInterleave6x12DPmrBit() */


/* CRC 7 bit computation with the following
 * polynomial : X^7 + X^3 + 1 */
uint8_t CRC7BitdPMR(uint8_t * BufferIn, uint32_t BitLength)
{
  uint8_t  ShiftRegister = 0x00; /* All bit to '0' (7 LSBit only used) */
  uint8_t  Polynome = 0x09;      /* X^7 + X^3 + 1 */
  uint32_t i;

  for(i = 0; i < BitLength; i++)
  {
    if(((ShiftRegister >> 6) & 1) ^ BufferIn[i])
    {
      ShiftRegister = ((ShiftRegister << 1) ^ Polynome) & 0x7F;
    }
    else
    {
      ShiftRegister = (ShiftRegister << 1) & 0x7F;
    }
  }

  return ShiftRegister;
} /* End CRC7BitdPMR() */


/* CRC 8 bit computation with the following
 * polynomial : X^8 + X^2 + X + 1 */
uint8_t CRC8BitdPMR(uint8_t * BufferIn, uint32_t BitLength)
{
  uint8_t  ShiftRegister = 0xFF; /* All bit to '1' */
  uint8_t  Polynome = 0x07;      /* X^7 + X^3 + 1 */
  uint32_t i;

  for(i = 0; i < BitLength; i++)
  {
    if(((ShiftRegister >> 7) & 1) ^ BufferIn[i])
    {
      ShiftRegister = ((ShiftRegister << 1) ^ Polynome) & 0xFF;
    }
    else
    {
      ShiftRegister = (ShiftRegister << 1) & 0xFF;
    }
  }

  return ShiftRegister;
} /* End CRC8BitdPMR() */


/* Convert an air interface identifier (AI ID) into
 * a 7 ASCII digit string.
 *
 * See dPMR standard chapter A.1.2.1.1.6
 * "Mapping of dialled strings to the AI address space" */
void ConvertAirInterfaceID(uint32_t AI_ID, uint8_t ID[8])
{
  uint32_t AI_ID_Temp = AI_ID;
  uint32_t Digit;

  /* 1st digit */
  Digit = AI_ID_Temp / 1464100;
  AI_ID_Temp = AI_ID_Temp % 1464100;
  if(Digit == 10) ID[0] = '*';
  else ID[0] = Digit + '0';

  /* 2nd digit */
  Digit = AI_ID_Temp / 146410;
  AI_ID_Temp = AI_ID_Temp % 146410;
  if(Digit == 10) ID[1] = '*';
  else ID[1] = Digit + '0';

  /* 3rd digit */
  Digit = AI_ID_Temp / 14641;
  AI_ID_Temp = AI_ID_Temp % 14641;
  if(Digit == 10) ID[2] = '*';
  else ID[2] = Digit + '0';

  /* 4th digit */
  Digit = AI_ID_Temp / 1331;
  AI_ID_Temp = AI_ID_Temp % 1331;
  if(Digit == 10) ID[3] = '*';
  else ID[3] = Digit + '0';

  /* 5th digit */
  Digit = AI_ID_Temp / 121;
  AI_ID_Temp = AI_ID_Temp % 121;
  if(Digit == 10) ID[4] = '*';
  else ID[4] = Digit + '0';

  /* 6th digit */
  Digit = AI_ID_Temp / 11;
  AI_ID_Temp = AI_ID_Temp % 11;
  if(Digit == 10) ID[5] = '*';
  else ID[5] = Digit + '0';

  /* 7th digit */
  Digit = AI_ID_Temp;
  if(Digit == 10) ID[6] = '*';
  else ID[6] = Digit + '0';

  /* Add the "end of string" */
  ID[7] = '\0';

} /* End convertAirInterfaceID() */

/* End of file */
