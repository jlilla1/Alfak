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



while IFS= read -r line; do
   echo "$i" >> out_res.txt
done < inputs.txt

if diff out_res.txt units/out_ok.txt
then : no difference
else : there is a difference
fi

