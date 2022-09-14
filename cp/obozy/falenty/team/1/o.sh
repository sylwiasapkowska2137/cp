#!/bin/bash
for ((i = 1; i>0; i++))
do
	./gen > wejscie.in
	./k < wejscie.in > wzor.out
	./brut < wejscie.in > brut.out

	if diff -b wzor.out brut.out > /dev/null
	then 
		echo "$i OK $runtime"
	else 
		echo "$i BLAD!"
		break
	fi
done
