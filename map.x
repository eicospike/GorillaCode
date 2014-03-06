#!/bin/bash
echo UUUUUUUUU|minimodem --tx --ascii --alsa -f nnapped.bin 100

gcc Map.c

xxd nnapped.bin |head

./a.out

xxd nnapped.bin |head

