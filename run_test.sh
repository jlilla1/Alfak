#!/bin/bash


cat > out_res.txt

echo `./main units/unit1.json units/unit2.json` | tee -a out_res.txt
echo `./main units/unit1.json units/unit3.json` | tee -a out_res.txt
echo `./main units/unit2.json units/unit1.json` | tee -a out_res.txt
echo `./main units/unit2.json units/unit3.json` | tee -a out_res.txt
echo `./main units/unit3.json units/unit1.json` | tee -a out_res.txt
echo `./main units/unit3.json units/unit2.json` | tee -a out_res.txt