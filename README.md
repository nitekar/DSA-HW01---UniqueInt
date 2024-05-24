# Unique Integer Processor

This project contains a C++ implementation of a data structure and algorithm designed to process and sort unique integers from multiple text files. The main functionality is provided by the `UniqueInt` class, which reads integers from input files, ensures their uniqueness within a specified range, sorts them, and writes the sorted unique integers to output files.

## Features

- **Read and Process Files:** Read integers from multiple input text files.
- **Filter Unique Integers:** Ensure each integer is unique within the range -1023 to 1023.
- **Sort Integers:** Sort the unique integers using a sorting algorithm.
- **Output Results:** Write the sorted unique integers to corresponding output files.
- **Performance Measurement:** Measure the time taken to process each file.

## Implementation Details

### Data Structure

- **Boolean Array:** A fixed-size boolean array is used to track the presence of integers within the range -1023 to 1023. This allows efficient checking and insertion of unique integers.

### Algorithm

1. **Read Input File:** Read lines from an input file.
2. **Strip Whitespace:** Remove leading and trailing whitespace from each line.
3. **Validate Integer:** Check if the line represents a valid integer.
4. **Check Range:** Ensure the integer is within the range -1023 to 1023.
5. **Check Uniqueness:** Use the boolean array to check if the integer has already been seen.
6. **Store Unique Integer:** If the integer is unique, store it in a vector.
7. **Sort Integers:** Sort the vector of unique integers.
8. **Write Output File:** Write the sorted integers to the output file.


