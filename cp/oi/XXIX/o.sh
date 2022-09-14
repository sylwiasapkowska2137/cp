#!/bin/bash
make gen brut imp
for((i = 1; ; i++))
do
	./gen > wejscie.in
	./brut < wejscie.in > brut.out
	./imp < wejscie.in > wzor.out
	
	if diff -b wzor.out brut.out > /dev/null
	then
		echo "$i OK"
	else 
		echo "$i BLAD"
		break
	fi
done
