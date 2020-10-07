#!/bin/bash

IFS=$'\n'


if [ -f out_res.txt ]
then
  rm out_res.txt 
  
fi

for i in 'cat inputs.txt' 
do 
main \<\< $i \> out_res.txt
done
