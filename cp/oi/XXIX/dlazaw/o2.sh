#!/bin/bash
for((i = 1; ; i++))
do
	./gen > wejscie.in
	./glo < wejscie.in > wzor.out
	
	if diff -b wzor.out brut.out > /dev/null
	then
		echo "$i OK"
	else 
		echo "$i BLAD"
		break
	fi
done
