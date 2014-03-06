#!/bin/bash
mkdir data
mkdir Bin

echo UUUUUUUUU|minimodem --tx --ascii --alsa -f ./data/nnapped.bin 100

gcc ./src/Map.c -o ./Bin/mAp

xxd ./data/nnapped.bin |head

./Bin/mAp

xxd ./data/nnapped.bin |head

