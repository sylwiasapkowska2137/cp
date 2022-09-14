#!/bin/bash
for ((i=1;;i++))
do
    ./gen > wejscie.in
    ./e < wejscie.in > wzor.out
    ./brut < wejscie.in > brut.out
    if diff wzor.out brut.out > /dev/null
    then
        echo "$i OK"
    else 
        echo "$i BLAD"
        break
    fi
done
