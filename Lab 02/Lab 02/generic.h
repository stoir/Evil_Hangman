
#ifndef GENERIC_H
#define GENERIC_H

#include "status.h"

typedef void *Item ;

typedef struct generic_vector {
    
    void(*assignment)(Item *pLeft, Item Right) ;
    void(*destroy)(Item *pItem) ;
    int size ;
    int capacity ;
    Item *data ;
    
} Generic_vector ;


#endif
