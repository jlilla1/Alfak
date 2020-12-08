#!/bin/bash

cat > out_res.txt
cat > out_res2.txt
echo `./main scenario1.json` | tee -a out_res.txt
echo `./main scenario2.json` | tee -a out_res2.txt