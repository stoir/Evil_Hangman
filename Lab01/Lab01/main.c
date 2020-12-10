//
//  main.c
//  Lab01
//
//  Created by Sanjana Cheerla on 1/23/19.
//  Copyright © 2019 Sanjana Cheerla. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
   
    int *p;

    p = (int*)malloc(sizeof(int)*600);
    
    if (p == NULL){
        printf("error allocating memory");
               exit(1);
    }
               
    printf("Hello World! I have created a dynamic 2D array of 20x30 integers!\n");
               
    int i;
    int j = 0;
    int k = 30;
    
    for(j = 0; j < 20; j++, k++){
        for(i = j; i < k; i++){
            p[i] = i;
            printf("%4d", i);
        }
        printf("\n");
    }
    
    printf("\n");
    
    free(p); p = NULL;
               
    return 0;
}
