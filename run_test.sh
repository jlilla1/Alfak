#!/bin/bash

IFS=$'\n'


if [ -f out_res.txt ]
then
  rm out_res.txt 
  
fi

echo `./main unit1.json unit2.json` >> out_res.txt
echo `./main unit1.json unit3.json` >> out_res.txt
echo `./main unit2.json unit1.json` >> out_res.txt
echo `./main unit2.json unit3.json` >> out_res.txt
echo `./main unit3.json unit1.json` >> out_res.txt
echo `./main unit3.json unit2.json` >> out_res.txt
