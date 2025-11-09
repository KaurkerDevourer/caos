#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 2, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int pid  = fork();
    if (pid == 0){
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size - 1; j++){
                if (arr[j] > arr[j + 1]){
                    int tmp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
        print_array(arr, size);
    }
    else{
        wait(NULL);
        printf("good\n");
    }
    return 0;
}
