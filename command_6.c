#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    if (argc < 2){
        return 1;
    }

    FILE *fptr;
    fptr = fopen(argv[1], "r");

    int line_inc = 0;
    char buffer[128];
    char *buff = buffer;
    size_t bufsize = 128;
    char *lines[128];

    while (getline(&buff, &bufsize, fptr) >= 0){
        lines[line_inc] = strdup(buff);
        line_inc++;
    }

    printf("%s", lines[line_inc - 2]);
    printf("%s", lines[line_inc - 1]);

    for (int i=0; i < line_inc; i++){
        free(lines[i]);
    }

    return 0; 
}
