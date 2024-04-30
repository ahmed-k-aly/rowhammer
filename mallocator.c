// This file allocates enough memory
// fill out the entire pagetable
// @author: Ahmed Aly  (aaly24@amherst.edu)
// @author: Brandon Ngacho (bngacho24@amherst.edu)
#include <stdlib.h>

void main(int argc, char *argv[]){
    
    // Memory size == 7997476 kb == 7997476000 bytes
    // divided by 8 (bytes in int) = 999684500
    int limit = 999684500;
    for (int i = 0; i < limit; i++){
        int* x = (int*)malloc(sizeof(int));
    }
}