#!/bin/bash
for ((i = 1; i>0; i++))
do
    ./gen > wejscie.in
    ./wzor < wejscie.in > brut.out
    ./brut < wejscie.in > wzor.out
    if diff brut.out wzor.out > /dev/null
    then
        echo "$i OK"
    else 
        echo "$i BLAD"
        break
    fi
done