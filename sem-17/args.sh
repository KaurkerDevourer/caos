#!/bin/bash

echo "Имя скрипта: $0"
echo "Первый аргумент: $1"
echo "Второй аргумент: $2"
echo "Количество аргументов: $#"
echo "Все аргументы одной строкой: $*"
echo "Все аргументы: $@"

for arg in "$@"
do
    echo "Аргумент: $arg"
done
exit 1
