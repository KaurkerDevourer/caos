#!/bin/bash

FILE_PATH="./test_file.txt"

if [ -f "$FILE_PATH" ]; then
    echo "File already exists at $FILE_PATH"
    exit 1
else
    echo "File does not exist, safe to create"
    exit 0
fi
