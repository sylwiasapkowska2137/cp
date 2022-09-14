#!/bin/bash
for ((i = 1600000; i>0; i++))
do
	./gen $i > wejscie.in
	start=`date +%s.%N`
	./a < wejscie.in > wzor.out
	end=`date +%s.%N`
	runtime=$( echo "$end - $start" | bc -l )
	./ab < wejscie.in > brut.out

	if diff -b wzor.out brut.out > /dev/null
	then 
		echo "$i OK $runtime"
	else 
		echo "$i BLAD!"
		break
	fi
done
