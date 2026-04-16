# Cache Simulator (CS3339 Homework 3)

## Description
This program simulates a set-associative cache. It reads memory addresses from an input file and determines whether each access is a HIT or MISS.

## How to Compile
Using g++:
g++ cache_sim.cpp -o cache_sim

## How to Run
./cache_sim num_entries associativity input_file

Example:
./cache_sim 4 2 input0

## Output
The program creates a file called:
cache_sim_output

Each line is formatted as:
[address] : HIT or MISS

## Notes
- Cache starts empty
- Each block contains one word
- Uses LRU replacement policy
