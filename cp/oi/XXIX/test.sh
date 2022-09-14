#!/bin/bash

PROGRAM = "$1"
LOCATION = "./wyb_tests"
pts={0, 17, 18, 20, 17, 19}
SECRET = 1

function error(){
    echo "ERROR: $1"
    exit 1
}

if [ ! -x "$PROGRAM"]
then 
    eror "'$PROGRAM' doesn't exist"
fi

OUTFILE = ${mktemp}
TMFILE = ${mktemp}

function runtest(){
    TEST = "$1"
    fin = "$LOCATION$TEST.in"
    fout = "$LOCATION$TEST.out"
    if [! -f "$fin" -o ! -f "$fout"]
    then 
        error "brak plikow $fin $fout"
    fi 
    (ulimit -t 6 -v 261000; /usr/bin/time -f "%U" -o "$TMFILE" ./$PROGRAM < "$fin" > "$fout")
}