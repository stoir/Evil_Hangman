
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_string.h"

struct my_string
{
    int size;
    int capacity;
    char* data;
};

typedef struct my_string My_String;

MY_STRING my_string_init_default(void){
    My_String * pMy_string;
    pMy_string = (My_String*)malloc(sizeof(My_String));
    if(pMy_string != NULL){
        pMy_string->size=0;
        pMy_string->capacity=7;
        pMy_string->data=malloc(sizeof(char)*pMy_string->capacity);
        return (MY_STRING)pMy_string;
    }
    else{
        return NULL;
    }/Volumes/Sanjana/Iphone photos/2020_09_08(sep 8)/sanjana.photoslibrary/resources/derivatives/5/560D28D0-5511-4825-8FD7-250E445A427F_1_105_c.jpeg
}

MY_STRING my_string_init_c_string(const char* c_string){
    My_String * pMy_string;
    pMy_string = (My_String*)malloc(sizeof(My_String));
    
    int size=0;
    int i=0;
    
    while(c_string[size] != '\0'){
        size++;
    }
    
    if(pMy_string != NULL){
        pMy_string->size=(size);
        pMy_string->capacity=size+1;
        pMy_string->data=malloc(sizeof(char)*pMy_string->capacity);
        while(c_string[i] != '\0'){
            pMy_string->data[i] = c_string[i];
            i++;
        }
        return (MY_STRING)pMy_string;
    }
    
    else{
        return NULL;
    }
}

int my_string_get_capacity(MY_STRING hMy_string){
    My_String * pMy_string = (My_String*)hMy_string;
    int capacity = pMy_string->capacity;
    return capacity;
}

int my_string_get_size(MY_STRING hMy_string){
    My_String * pMy_string = (My_String*)hMy_string;
    int size= pMy_string->size;
    return size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
    My_String* pLeft_string = (My_String*) hLeft_string;
    My_String* pRight_string = (My_String*) hRight_string;
    int i;
    
    if(hLeft_string == NULL || hRight_string == NULL)
    {
        if(hLeft_string == NULL)
        {
            return -1;
        }
        else if (hRight_string == NULL)
        {
            return 1;
        }
    }
    
    for  (i = 0; pLeft_string->data[i] == pRight_string->data[i]; i++)
    {
        if (pLeft_string->data[i] == '\0')
        {
            return 0;
        }
    }
    
    return (pLeft_string->data[i] - pRight_string->data[i]);
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp){
    My_String *pMy_string = (My_String*) hMy_string;
    char *temp;
    char ch;
    int noc;
    int i;
    
    pMy_string->size = 0;
    
    noc = fscanf(fp, " %c", &ch);
    if (noc <= 0){
        return FAILURE;
    }
    
    while(noc >= 0  && !isspace(ch)){
        pMy_string->data[pMy_string->size] = ch;
        pMy_string->size++;
        noc = fscanf(fp, "%c", &ch);
        
        if(pMy_string->size >= pMy_string->capacity){
            temp = (char*) malloc(sizeof(char) * pMy_string->capacity * 2);
            pMy_string->capacity *= 2;
            
            if (temp == NULL)
            {
                printf("could not allocate memory for resize");
                exit(1);
            }
            
            for (i = 0; i < pMy_string->size; i++){
                temp[i] = pMy_string->data[i];
            }
            
            free(pMy_string->data);
            pMy_string->data = temp;
        }
    }
    
    if (noc != EOF){
        ungetc(ch ,fp);
    }
    
    return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp){
    My_String* pMy_string = (My_String*)hMy_string;
    if(pMy_string->size == 0){
        return FAILURE;
    }
    
    for(int i = 0; i < pMy_string->size; i++){
        fputc(pMy_string->data[i],fp);
    }
    return SUCCESS;
}

Status my_string_push_back(MY_STRING hMy_string, char Item){
    My_String* pMy_string = (My_String*)hMy_string;
    char* pTemp;
    int i;
    
    if (pMy_string->size >= pMy_string->capacity){
        pTemp = (char*) malloc(sizeof(char)*2*pMy_string->capacity);
        if(pTemp == NULL){
            return FAILURE;
        }
        for(i=0; i<pMy_string->size; i++){
            pTemp[i] = pMy_string->data[i];
        }
        free(pMy_string->data);
        pMy_string->data = pTemp;
        pMy_string-> capacity *=2;
    }
    
    pMy_string->data[pMy_string->size] = Item;
    pMy_string->size++;
    return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string){
    My_String* pMy_string = (My_String*)hMy_string;
    if(pMy_string->size <= 0){
        return FAILURE;
    }
    pMy_string->size--;
    return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index){
    My_String* pMy_string = (My_String*)hMy_string;
    
    if(index < 0 || index >= pMy_string->size){
        return NULL;
    }
    return &(pMy_string->data[index]);
}

char* my_string_c_str(MY_STRING hMy_string){
    My_String* pMy_string = (My_String*) hMy_string;
    pMy_string->data[pMy_string->size] = '\0';
    return pMy_string->data;
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend){
    My_String* pResult = (My_String*) hResult;
    My_String* pAppend = (My_String*) hAppend;
    char* tData = NULL;
    int i = 0;

    if ((pResult->size || pAppend->size) == 0){
        return FAILURE;
    }
    
    if ((pResult->size + pAppend->size) >= pResult->capacity){
        tData = (char*)malloc(sizeof(char) * (pResult->size + pAppend->size) + 2);
        
        if (tData == NULL){
            return FAILURE;
        }
        
        for (i=0; i <= pResult->size; i++){
            tData[i] = pResult->data[i];
        }
        free(pResult->data);
        pResult->data = tData;
        
        pResult->capacity = (pResult->size + pAppend->size);
    }
    
    for (i=0; i <= pAppend->size; i++){
        pResult->data[pResult->size + i] = pAppend->data[i];
    }
    
    pResult->size = (pResult->size + pAppend->size) + 1;
    pResult->data[pResult->size] = '\0';
    
    return SUCCESS;
    
}

Boolean my_string_empty(MY_STRING hMy_string){
    My_String* pMy_string = (My_String*)hMy_string;
    if (pMy_string->size == 0) {
        return TRUE;
    }
    return FALSE;
}

void my_string_destroy(Item* pItem){
    My_String* pMy_string = (My_String*)*pItem;
    free(pMy_string->data);
    free(pMy_string);
    *pItem = NULL;
    
}

void my_string_assignment( Item *pLeft, Item Right ) {
    
    My_String *pMy_string_left = ( My_String *) *pLeft ;
    My_String *pMy_string_right = ( My_String *) Right ;
    int i ;
    const char *temp ;
    
    temp = my_string_c_str(( MY_STRING ) Right ) ;
    
    if ( pMy_string_left == NULL ) {
        
        pMy_string_left = my_string_init_c_string( temp ) ;
        
    } else {
        
        pMy_string_left -> size = 0 ;
        
        for (i = 0; i < pMy_string_right->size + 1; i++) {
            
            my_string_push_back( pMy_string_left, pMy_string_right -> data[i] ) ;
            
        }
        
    }
    
    *pLeft = pMy_string_left ;
    
}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
    My_String* pNew_key = (My_String*)new_key;
    My_String* pWord = (My_String*)word;
    int i;
    
    guess = tolower(guess);
    
    my_string_assignment(&new_key, current_word_family);
    
    for(i = 0; i < pWord->size; i++)
    {
        if(pWord->data[i] == guess)
        {
            pNew_key->data[i] = guess;
        }
    }
    
    return SUCCESS;
}
