#!/bin/bash
for((i = 1; ; i++))
do
	./gen > wejscie.in
	./brut < wejscie.in > brut.out
	./wzo < wejscie.in > wzor.out
 
	if diff -b wzor.out brut.out > /dev/null
	then
		echo "$i OK"
	else 
		echo "fatalnie sylwia"
		break
	fi
done