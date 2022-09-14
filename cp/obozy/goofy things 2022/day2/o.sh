#!/bin/bash
g++ trs.cpp -Wall -static -Wshadow -O3 -g -o trs
for ((i = 1; i>0; i++))
do
	./gen > wejscie.in
	./trs < wejscie.in > wzor.out
	./bts < wejscie.in > brut.out

	if diff -b wzor.out brut.out > /dev/null
	then 
		echo "$i OK"
	else 
		echo "$i BLAD!"
		break
	fi
done
