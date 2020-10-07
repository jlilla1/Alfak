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

for i in inputs.txt
do 
  echo "$i" \| test \>\> out_res.txt
done

if diff out_res.txt units/out_ok.txt
then : no difference
else : there is a difference
fi

