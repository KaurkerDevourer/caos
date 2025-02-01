#!/bin/bash

FILE_PATH="./test_file.txt"

echo "Creating file at $FILE_PATH"
echo "This file was created at $(date)" > "$FILE_PATH"

if [ $? -eq 0 ]; then
    echo "File successfully created"
    exit 0
else
    echo "Error creating file"
    exit 1
fi
