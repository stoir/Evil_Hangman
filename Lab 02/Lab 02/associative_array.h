#ifndef ASSOCIATIVE_ARRAY
#define ASSOCIATIVE_ARRAY

#include<stdio.h>
#include<stdlib.h>
#include"my_string.h"
#include"generic_vector.h"

typedef struct Node tNode;

tNode* insertNodes(tNode* node, MY_STRING new_key, MY_STRING word);
tNode* createNode(MY_STRING new_key, MY_STRING word);
int getHeight(tNode *node);
int getBalancefactor(tNode* node);
int findmax(int x, int y);
tNode *rightRotation(tNode* nodey);
tNode* leftRotation(tNode* nodex);
void inorderTraversal(tNode* root);
void preorderTraversal(tNode* root);
GENERIC_VECTOR largest_family(tNode* node, Boolean total_words);
GENERIC_VECTOR get_largest_family(tNode* node, Boolean total_words);
void print_tree(tNode* node);
void destroy_tree(tNode* node);
#endif
