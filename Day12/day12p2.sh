#!/bin/bash

# Advent of Code 2019
# Day 12 : The N-Body Problem
# 
# Author : Charlie Rose
# Language : Bash
# Date : 12/X/2019


cp day12modinput1.txt day12stepinput.txt
cp day12modinput1.txt day12tracking.txt

echo "\n" > temp
i=1


while true 
do
	./day12p2.py

	currcode=`cat day12stepinput.txt`

	if [[ -n "$(cat day12tracking.txt | grep '$currcode')"  ]] 
	then
		echo "Completed \n"
		echo $i
		break
	fi

	newD12T=`cat day12tracking.txt temp day12stepinput.txt temp`
	echo $newD12T > day12tracking.txt

	echo $i

	i=$(( i+1 ))
done

rm temp
