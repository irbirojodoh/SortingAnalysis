#!/bin/bash

# Compile QuickSort.c
gcc QuickSort.c -o QuickSort
gcc BubbleSort.c -o BubbleSort
gcc randomNumber.c -o randomNumber

# Define input values
input_values=("10" "100" "1000" "10000" "25000" "50000" "100000")

# Print table header
printf "%-10s %-20s %-20s\n" "Run" "Input Value" "Time (in seconds)"
echo "------------------------------------------------------------"

# Run the script five times
for ((run=1; run<=5; run++))
do
    # Loop over input values
    for value in "${input_values[@]}"
    do
        # Run randomNumber with input and capture the output
        random_output=$(echo "$value" | ./randomNumber)

        # Run BubbleSort and capture the time output
        bubble_time=$(./BubbleSort)

        # Run QuickSort and capture the time output
        quick_time=$(./QuickSort)

        # Print table row
        printf "%-10s %-20s %-20s\n" "$run" "$value" "$bubble_time / $quick_time"
    done
    
    echo "------------------------------------------------------------"
done

# Cleanup compiled files
