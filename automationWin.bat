@echo off

rem Compile QuickSort.c
gcc QuickSort.c -o QuickSort
gcc BubbleSort.c -o BubbleSort
gcc randomNumber.c -o randomNumber

rem Define input values
set input_values=("10" "100" "1000" "10000" "25000" "50000" "100000")

rem Print table header
echo Run        Input Value          Time (in seconds)
echo ------------------------------------------------------------

rem Run the script five times
for /L %%run in (1,1,5) do (
    rem Loop over input values
    for %%value in %input_values% do (
        rem Run randomNumber with input and capture the output
        for /F %%o in ('echo %%value ^| randomNumber') do set random_output=%%o

        rem Run BubbleSort and capture the time output
        for /F %%b in ('BubbleSort') do set bubble_time=%%b

        rem Run QuickSort and capture the time output
        for /F %%q in ('QuickSort') do set quick_time=%%q

        rem Print table row
        echo %%run        %%value                  !bubble_time! / !quick_time!
    )

    echo ------------------------------------------------------------
)

rem Cleanup compiled files
