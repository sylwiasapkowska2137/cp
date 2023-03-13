#!/bin/bash

for i in {1..1000000}
do
    ./ubij $i > testU.in;
    ./lokzad < testU.in > testU.out;
    val=$(< testU.out)
    minLimit=50000
    echo $val
    if [[ "$val" -gt "$minLimit" ]]
        then break
    fi
done