#!/bin/bash

for i in `seq 1 100000`
do
    echo $i
    ./pjkgen $i > test.in
    ./pjkzad < test.in > wzor.out
    ./pjkbrut < test.in > brut.out
    if !(diff -bq wzor.out brut.out)
    then
        echo "WA"
        break
    fi
    echo "OK"
done