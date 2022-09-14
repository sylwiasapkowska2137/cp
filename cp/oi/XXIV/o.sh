#!/bin/bash
for ((i = 1; i>0; i++))
do
	./gen > wejscie.in
	./strajk < wejscie.in > wzor.out
	./strajk3 < wejscie.in > brut.out
	
	if diff -b wzor.out brut.out > /dev/null
	then
		echo "$i OK"
	else 
		echo "$i BLAD"
		break
	fi
done
