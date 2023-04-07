#!/bin/bash
for((i = 0;;i++))
do
    ./gen > wejscie.in
    ./brut < wejscie.in > brut.out
    ./e < wejscie.in > wzo.out

    if diff -b wzo.out brut.out >/dev/null
    then 
        echo "$i OK"
    else 
        echo "fatalnie sylwia"
        break
    fi
done