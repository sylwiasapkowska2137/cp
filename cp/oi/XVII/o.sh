#!/bin/bash
for ((i=1;;i++))
do
    ./gen > wejscie.in
    ./piloci < wejscie.in > wzor.out
    ./brut2 < wejscie.in > brut.out
    if diff wzor.out brut.out >/dev/null 
    then
        echo "$i OK"
    else 
        break;
    fi
done