#!/bin/bash
mkdir data
mkdir bin

echo UUUUUUUUU|minimodem --tx --ascii --alsa -f ./data/nnapped.bin 100

gcc ./src/Map.c -o ./bin/mAp

xxd ./data/nnapped.bin |head

./bin/mAp

xxd ./data/nnapped.bin |head

