#!/bin/bash
for((i=1;i <= 1000000000;i++))
do
    echo $i
    ./gen > test.in
    ./kkszad < test.in > test.out
    (head -n 1 test.in;cat test.out) > test2.in
    ./kkrzad < test2.in > test2.out
    ./compare_kkr test2.in test2.out test.in wynik.xml
    if ! grep "Accepted" wynik.xml > /dev/null
    then
        echo "BLAD1"
        break
    fi
    (head -n 1 test.in;cat test2.out) > test3.in
    ./kkszad < test3.in > test3.out
    if ! diff -bq test.out test3.out;
    then
        echo "BLAD2";
        break
    fi
done
