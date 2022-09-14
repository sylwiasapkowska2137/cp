#!/bin/bash
for ((i = 1; i>0; i++))
do
    ./gen > wejscie.in
    ./nck < wejscie.in > wzor.out
    ./brut < wejscie.in > brut.out
    if diff -b wzor.out brut.out > /dev/null
    then
        echo "$i OK"
    else 
        echo "$i BLAD!"
        echo "Test:"
        cat wejscie.in
        echo "Your output:"
        cat wzor.out
        echo "Correct output:"
        cat brut.out
        break
    fi
done
