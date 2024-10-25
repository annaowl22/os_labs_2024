#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#ifdef _WIN32
#include <windows.h>
#endif

//push bite to array
void push(unsigned char *arr, unsigned char value, int *size, int *capacity){
     int* ptr;
     if(*size > *capacity){
          ptr = realloc(arr, sizeof(arr) + sizeof(unsigned char));
          if(ptr == NULL)
               exit(0);
          else
               *capacity = sizeof(arr) + sizeof(unsigned char);
     }
 
     arr[*size] = value;
     *size = *size + 1;
}


int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    int capacity = 10;
    unsigned char* data = malloc(capacity * sizeof(unsigned char));
    int size = 0;

    FILE *file = fopen(argv[1], "rb");

    if (!file) {
        printf("Failed to open file %s\n", argv[1]);
        return 1;
    }

    unsigned char buffer;
    while (fread(&buffer, 1, 1, file)) {
        push(data, buffer, &size, &capacity);
    }
    fclose(file);
    
    for(int i = 0; i < size; i++){
          printf("0x%02X", data[i]);
    }

    return 0;
}
