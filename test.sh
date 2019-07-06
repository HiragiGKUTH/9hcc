#!/bin/bash

try() {
    expected="$1"
    input="$2"

    ./9hcc "$input" > tmp.s
    gcc -o tmp tmp.s
    ./tmp
    actual="$?"

    if [ "$actual" = "$expected" ]; then
	echo "$input => $actual"
    else
	echo "$input => $expected expected, but got $actual"
	exit 1
    fi
}


try 0 0
try 42 42
try 23 '20+4-1'
try 128 '10 + 114 - 23 + 27'

echo OK

