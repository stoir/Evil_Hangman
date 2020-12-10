#ifndef GENERIC_VECTOR_H
#define GENERIC_VECTOR_H

#include <stdio.h>
#include <stdlib.h>


#include "generic.h"

typedef void* GENERIC_VECTOR;

GENERIC_VECTOR generic_vector_init_default(void(*assignment)(Item* pLeft, Item Right), void(*destroy)(Item* pItem));

void generic_vector_destroy( GENERIC_VECTOR *phVector) ;

int generic_vector_get_capacity( GENERIC_VECTOR hVector ) ;

int generic_vector_get_size( GENERIC_VECTOR hVector ) ;

Status generic_vector_push_back( GENERIC_VECTOR hVector, Item item ) ;

Status generic_vector_pop_back( GENERIC_VECTOR hVector ) ;

Item generic_vector_at( GENERIC_VECTOR hVector, int index ) ;

Boolean generic_vector_empty( GENERIC_VECTOR hVector ) ;

#endif
