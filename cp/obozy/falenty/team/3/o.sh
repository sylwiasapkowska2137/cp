#!/bin/bash
for ((i = 1; i>0; i++))
do
	./gen > wejscie.in
	start=`date +%s.%N`
	./b < wejscie.in > wzor.out
	end=`date +%s.%N`
	runtime=$( echo "$end - $start" | bc -l )
	./brut < wejscie.in > brut.out

	if diff -b wzor.out brut.out > /dev/null
	then 
		echo "$i OK $runtime"
	else 
		echo "$i BLAD!"
		break
	fi
done
