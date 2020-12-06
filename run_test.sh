#!/bin/bash

cat > out_res.txt
echo `./b scenario1.json` | tee -main out_res.txt
echo `./b scenario2.json` | tee -main out_res.txt