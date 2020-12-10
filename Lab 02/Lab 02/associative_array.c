#include <stdlib.h>
#include <stdio.h>
#include "generic_vector.h"
#include "generic.h"
#include "associative_array.h"

typedef struct Node tNode;

struct Node{
    MY_STRING key;
    GENERIC_VECTOR word_list;
    tNode *lChild;
    tNode *rChild;
    int nodeHeight;
};


tNode* createNode(MY_STRING new_key, MY_STRING word){
    tNode* pNode = (tNode*)malloc(sizeof(tNode));
    pNode->key = my_string_init_c_string(my_string_c_str(new_key));
    pNode->word_list = generic_vector_init_default(my_string_assignment, my_string_destroy);
    pNode->lChild = NULL;
    pNode->rChild = NULL;
    pNode->nodeHeight = 1;
    
    generic_vector_push_back(pNode->word_list, word);
    return(pNode);
}

tNode* insertNodes(tNode* node, MY_STRING new_key, MY_STRING word)
{
    if (node == NULL){
        return(createNode(new_key, word));
    }
    
    if ((my_string_compare(node->key, new_key)) < 0){
        node->lChild = insertNodes(node->lChild, new_key, word);
    }
    else if ((my_string_compare(node->key, new_key)) > 0){
        node->rChild = insertNodes(node->rChild, new_key, word);
    }
    
    else{
        generic_vector_push_back(node->word_list, word);
    }

    node->nodeHeight = 1 + findmax(getHeight(node->lChild),getHeight(node->rChild));

    int balance = getBalancefactor(node);
    
    if (balance > 1 && my_string_compare(node->lChild->key, new_key) < 0)
        return rightRotation(node);

    if (balance < -1 && my_string_compare(node->rChild->key, new_key) > 0)
        return leftRotation(node);

    if (balance > 1 && my_string_compare(node->lChild->key, new_key) > 0)    {
        node->lChild =  leftRotation(node->lChild);
        return rightRotation(node);
    }

    if (balance < -1 && my_string_compare(node->rChild->key, new_key) < 0)    {
        node->rChild = rightRotation(node->rChild);
        return leftRotation(node);
    }
    
    return node;
    
}

int getHeight(tNode *node){
    if (node == NULL)
        return 0;
    return node->nodeHeight;
}

int getBalancefactor(tNode* node){
    if (node == NULL)
        return 0;
    return getHeight(node->lChild) - getHeight(node->rChild);
}

tNode *rightRotation(tNode* nodey){
    tNode* nodex = nodey->lChild;
    tNode* T2 = nodex->rChild;

    nodex->rChild = nodey;
    nodey->lChild = T2;

    nodey->nodeHeight = findmax(getHeight(nodey->lChild), getHeight(nodey->rChild))+1;
    nodex->nodeHeight = findmax(getHeight(nodex->lChild), getHeight(nodex->rChild))+1;

    return nodex;
}

tNode* leftRotation(tNode* nodex)
{
    tNode* nodey = nodex->rChild;
    tNode* T2 = nodey->lChild;
    
    nodey->lChild = nodex;
    nodex->rChild = T2;

    nodex->nodeHeight = findmax(getHeight(nodex->lChild), getHeight(nodex->rChild))+1;
    nodey->nodeHeight = findmax(getHeight(nodey->lChild), getHeight(nodey->rChild))+1;

    return nodey;
}

int findmax(int x, int y){
    return (x > y)? x : y;
}

GENERIC_VECTOR largest_family(tNode* node, Boolean total_words){
    GENERIC_VECTOR largest;
    GENERIC_VECTOR new_word_list = NULL;
    
    int i;
    
    largest = get_largest_family(node, total_words);
    new_word_list = generic_vector_init_default(my_string_assignment, my_string_destroy);
    for (i=0; i < generic_vector_get_size(largest); i++){
        generic_vector_push_back(new_word_list, generic_vector_at(largest, i));
    }
    return new_word_list;
}

GENERIC_VECTOR get_largest_family(tNode* node, Boolean total_words){
    
    Generic_vector* temp = NULL;
    int current_node_size;
    
    current_node_size = generic_vector_get_size(node->word_list);{
        if (node->lChild != NULL){
            temp = get_largest_family(node->lChild, total_words);
            if (temp == NULL || generic_vector_get_size(temp) < generic_vector_get_size(node->word_list))  {
                temp = node->word_list;
            }
        }
        if (node->rChild != NULL) {
            temp = get_largest_family(node->rChild, total_words);
            if (temp == NULL || generic_vector_get_size(temp) < generic_vector_get_size(node->word_list)) {
                temp = node->word_list;
            }
        }
        if (temp == NULL || generic_vector_get_size(temp) < generic_vector_get_size(node->word_list)) {
            temp = node->word_list;
        }
    }
    if (total_words){
        my_string_insertion(node->key, stdout);
        printf(" %d\n", current_node_size);
    }
    return temp;
}

void print_tree(tNode* node){
    if (node == NULL)
        return;
    
    printf("%s, %d \n", my_string_c_str(node->key), generic_vector_get_size(node->word_list));
    
    print_tree(node->lChild);
    
    print_tree(node->rChild);
}

void destroy_tree(tNode* pNode){
    if (pNode == NULL){
        return;
    }
    
    destroy_tree(pNode->lChild);
    destroy_tree(pNode->rChild);
    my_string_destroy(&pNode->key);
    generic_vector_destroy(&pNode->word_list);
    free(pNode);
}
