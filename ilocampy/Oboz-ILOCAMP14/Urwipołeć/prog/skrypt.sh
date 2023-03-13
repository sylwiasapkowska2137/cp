#!/bin/bash
for i in `seq 1 100000`
do
    echo $i
    ./gen $i > test.in
    ./wzor < test.in > wzor.out
    ./brut < test.in > brut.out
    if !(diff -bq wzor.out brut.out)
    then
        echo "WA"
        break
    fi
    echo "OK"
done