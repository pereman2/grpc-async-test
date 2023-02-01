#!/bin/bash


for q in 1 2 4 8 16 32
do
  for t in 1 2 4 8 16 32
  do 
  kill -9 $(pgrep test | xargs)
    TEST_G_THREADS=$t TEST_G_QUEUE=$q TEST_G_CD=1000 ./test &
    pid=$(pgrep test)
    python test.py
  done
done

# for q in 1 2 4 8 16 32 64 128 256 512 1024 2048 4196
# do
#   kill -9 $(pgrep test | xargs)
#   TEST_G_THREADS=12 TEST_G_QUEUE=12 TEST_G_CD=$q ./test &
#   pid=$(pgrep test)
#   python test.py
# 
# done
