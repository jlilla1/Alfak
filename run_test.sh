#!/bin/bash

IFS=$'\n'


if [ -f out_res.txt ]
then
  rm out_res.txt 
  
fi
cat > out_res.txt

echo `./main units/unit1.json units/unit2.json` | tee -a out_res.txt
echo `./main units/unit1.json units/unit3.json` 
echo `./main units/unit2.json units/unit1.json`
echo `./main units/unit2.json units/unit3.json`
echo `./main units/unit3.json units/unit1.json`
echo `./main units/unit3.json units/unit2.json`
