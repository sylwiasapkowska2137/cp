#!/bin/bash
for i in `seq 1 100000`
do
    echo $i
    ./gen $i > test.in
    ./ktos4 < test.in > wzor.out
    ./osibrut < test.in > brut.out
    ./compare_osi test.in brut.out wzor.out diff.out > lol
    if !(diff -bq lol acc)
    then
        echo "WA"
        break
    fi
    echo "OK"

#     if !(diff -bq wzor.out brut.out)
#     then
done
