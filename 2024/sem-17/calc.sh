#!/bin/bash

expression="$*"

echo "$expression"

result=$(echo "$expression" | bc)

echo "Результат: $result"
