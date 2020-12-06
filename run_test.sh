#!/bin/bash

cat > out_res.txt
echo `./k units/scenario1.json` | tee -a out_res.txt
echo `./k units/scenario2.json` | tee -a out_res.txt