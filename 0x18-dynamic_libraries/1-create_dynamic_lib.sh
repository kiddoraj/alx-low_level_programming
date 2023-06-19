#!/bin/bash

# Collect all .c files in the current directory
c_files=$(find . -maxdepth 1 -type f -name '*.c')

# Compile the .c files into object files
for file in $c_files; do
    gcc -c -fPIC "$file"
done

# Create the dynamic library
gcc -shared -o liball.so *.o

# Clean up the object files
rm -f *.o

echo "Dynamic library 'liball.so' created successfully."
