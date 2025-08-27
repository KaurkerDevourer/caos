#!/bin/bash

process_data() {
    local id=$1
    local sleep_time=$2
    echo "Task $id starting, will take $sleep_time seconds"
    sleep $sleep_time
    echo "Task $id completed"
}

process_data 1 5 &
process_data 2 3 &
process_data 3 4 &

wait
echo "All tasks completed"
