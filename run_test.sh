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

chmod -x units/unit1.json
chmod -x units/unit2.json
chmod -x units/unit3.json

while IFS= read -r line; do
    res=test "units/unit1.json" "units/unit2.json" 
    $res >> out_res.txt
done < inputs.txt

if diff out_res.txt units/out_ok.txt
then : no difference
else : there is a difference
fi

