#!/bin/bash
read -p "Enter word to search for: " word
grep -o "$word" demo.txt | wc -l 