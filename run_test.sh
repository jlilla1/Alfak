#!/bin/bash

IFS=$'\n'


if [ -f out_res.txt ]
then
  rm out_res.txt 
  
fi

if [ -f test.exe ]
then
  rm test.exe
  
fi

g++  *.cpp -o test

for i in 'cat inputs.txt' 
do 
  test \<\< $i \> out_res.txt
done
