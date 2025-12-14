#!/bin/sh
doas make makesum
doas make reinstall
doas make clean
../../git.sh