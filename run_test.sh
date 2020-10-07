#!/bin/bash

IFS=$'\n'


if test -f out_res.txt do rm out_res.txt done fi

for i in 'cat inputs.txt' do main \<\< $i \> out_res.txt done
