#!/bin/bash
PS3="Select an option (1-3): "
options=("Option 1" "Option 2" "Quit")
select opt in "${options[@]}"; do
 case $opt in
 "Option 1") echo "You chose Option 1";;
 "Option 2") echo "You chose Option 2";;
 "Quit") break;;
 *) echo "Invalid option";;
 esac
done