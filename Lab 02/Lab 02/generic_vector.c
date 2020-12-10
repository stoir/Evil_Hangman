#include <stdio.h>
#include <stdlib.h>

#include "generic.h"
#include "generic_vector.h"

GENERIC_VECTOR generic_vector_init_default( void( *assignment )( Item* pLeft, Item Right ), void( *destroy )( Item *pItem ) ) {
    Generic_vector *pVector ;
    int i;
    pVector = ( Generic_vector * ) malloc( sizeof( Generic_vector ) ) ;
    if ( pVector != NULL) {
        pVector -> size = 0 ;
        pVector -> capacity = 1 ;
        pVector -> data = ( Item *) malloc( pVector -> capacity * sizeof( Item ) ) ;
        if ( pVector -> data == NULL ) {
            free( pVector ) ;
            pVector = NULL ;
        } else {
            for ( i = 0; i < pVector -> capacity; i++ ) pVector -> data[i] = NULL ;
            pVector -> assignment = assignment ;
            pVector -> destroy = destroy ;
        }
    }
    return pVector ;
}

void generic_vector_destroy( GENERIC_VECTOR *phVector) {
    Generic_vector *pVector = ( Generic_vector * ) *phVector ;
    int i ;
    for ( i = 0; i < pVector -> size; i++ ) {
        pVector -> destroy( &(pVector -> data[i] ));
    }
    free(pVector -> data);
    free(pVector) ;
    *phVector = NULL ;
}

int generic_vector_get_capacity( GENERIC_VECTOR hVector ) {
    return ((Generic_vector *)hVector) -> capacity ;
}

int generic_vector_get_size( GENERIC_VECTOR hVector ) {
    return ((Generic_vector * ) hVector) -> size ;
}

Status generic_vector_push_back( GENERIC_VECTOR hVector, Item item ) {
    Generic_vector *pVector = ( Generic_vector * ) hVector ;
    Item *new_data ;
    int i ;
    
    if ( pVector -> size >= pVector -> capacity ) {
        new_data = ( Item * ) realloc( pVector -> data, 2 * pVector -> capacity * sizeof( Item ) ) ;
        if ( new_data == NULL ) return FAILURE ;
        pVector -> capacity *= 2 ;
        for ( i = pVector -> size; i < pVector -> capacity; i++ ) new_data[i] = NULL ;
        pVector -> data = new_data ;
    }
    
    pVector -> assignment( &pVector -> data[pVector -> size], item ) ;
    if ( pVector -> data[pVector -> size] == NULL ) return FAILURE ;
    pVector -> size++ ;
    return SUCCESS ;
}

Status generic_vector_pop_back( GENERIC_VECTOR hVector ){
    Generic_vector *pVector = ( Generic_vector * ) hVector ;
    if ( pVector -> size <= 0 ) return FAILURE ;
    pVector -> size-- ;
    if ( pVector -> data[pVector -> size] != NULL ) {
        pVector -> destroy( &( pVector -> data[pVector -> size] ) ) ;
    }
    return SUCCESS ;
}

Item generic_vector_at( GENERIC_VECTOR hVector, int index ) {
    Generic_vector *pVector = ( Generic_vector * ) hVector ;
    if ( index < 0 || index >= pVector -> size ) return NULL ;
    return ( pVector -> data[index] ) ;
    
}

Boolean generic_vector_empty( GENERIC_VECTOR hVector ) {
    return ( ( ( Generic_vector * ) hVector ) -> size ) == 0 ;
    
}

