#!/bin/bash

cat > out_res.txt
echo `./k scenario1.json` | tee -a out_res.txt
echo `./k scenario2.json` | tee -a out_res.txt