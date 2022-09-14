#!/bin/bash
for ((i = 1; i>0; i++))
do
    ./gen > wejscie.in
    ./moc < wejscie.in > wzor.out
    ./brut < wejscie.in > brut.out

    if diff brut.out wzor.out > /dev/null
    then
        echo "$i OK"
    else 
        echo "$i BLAD!"
        break
    fi
done