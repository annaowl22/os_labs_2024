#!/bin/bash

if [ $# -eq 0]; then
    echo "No arguments"
    exit 1
fi

count=$#

sum=0

for arg in "$@"; do
    sum=$((sum+arg))
done

average=$(echo "scale=3; $sum/$count" | bc)

echo "Number of args: $count"
echo "Sum of args: $sum"
echo "Average of args: $average"