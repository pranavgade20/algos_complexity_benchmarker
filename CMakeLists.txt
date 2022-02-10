cmake_minimum_required(VERSION 3.21)
project(sem4_algos C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_FLAGS "-O0")

add_executable(sem4_algos main.c)
add_executable(insertionsort insertionsort.c)
add_executable(selectionsort selectionsort.c)
add_executable(bubblesort bubblesort.c)
add_executable(radixsort radixsort.c)
add_executable(bucketsort bucketsort.c)
add_executable(countingsort countingsort.c)
