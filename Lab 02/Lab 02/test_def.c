#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_string.h"
#include "unit_test.h"
#include "generic_vector.h"



Status test_init_default_returns_nonNULL(char* buffer, int length)
{
    MY_STRING hString = NULL;
    hString = my_string_init_default();
    if(hString == NULL)
    {
        strncpy(buffer, "test_init_default_returns_nonNULL\n"
                "my_string_init_default returns NULL", length);
        return FAILURE;
    }
    else
    {
        my_string_destroy((Item*)&hString);
        strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
        return SUCCESS;
    }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();
    if(my_string_get_size(hString) != 0)
    {
        status = FAILURE;
        printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
                "\tDid not receive 0 from get_size after init_default\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
                , length);
    }
    my_string_destroy((Item*)&hString);
    return status;
}


Status scheerla_test_03_get_size_on_init_c_strreturns_non0(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("Creating a test String: The quick brown fox jumps over a lazy dog");
    
    if(my_string_get_size(hString) != 0){
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_03_get_size_on_init_c_strreturns_non0\n"
                , length);
    }
    else{
        status = FAILURE;
        printf("Expected a size of non 0 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "scheerla_test_03_get_size_on_init_c_strreturns_non0\n"
                "\tDid not receive a non 0 from scheerla_test_03_get_size_on_init_c_strreturns_non0\n", length);
    }
    my_string_destroy((Item*)&hString);
    return status;
}

Status scheerla_test_04_destroy(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();
    
    my_string_destroy((Item*)&hString);
    
    if (hString!=NULL){
        status = FAILURE;
        printf("Expected to destroy string but got %sn", my_string_c_str(hString));
        strncpy(buffer, "scheerla_test_04_destroy\n"
                "\tDid not receive a destroy from scheerla_test_04_destroy\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_04_destroy\n"
                , length);
    }
    return status;
}

Status scheerla_test_05_push_back(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();
    
    int i;
    for(i = 0; i < 10; i++){
        my_string_push_back(hString, 'a');
    }
    
    if (my_string_get_size(hString) >= 11 || my_string_get_size(hString) <= 0) {
        status = FAILURE;
        printf("Expected to push to string, size of 10 string but got %sn", my_string_c_str(hString));
        strncpy(buffer, "scheerla_test_05_push_back\n"
                "\tDid not revice a pushed letter from scheerla_test_05_push_back\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_05_push_back\n"
                , length);
    }
    
    my_string_destroy((Item*)&hString);
    
    return status;
}

Status scheerla_test_06_pop_back(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("The quick brown fox jumps over a lazy dog");
    
    int i;
    int size = my_string_get_size(hString);
    
    for(i = 0; i < size; i++){
        my_string_pop_back(hString);
    }
    
    
    if ((my_string_get_size(hString) < 0) || (my_string_get_size(hString) > 0 )) {
        status = FAILURE;
        printf("Expected to pop to string, size of 0 string but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "scheerla_test_06_pop_back\n"
                "\tDid not pop using the function scheerla_test_06_pop_back\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_06_pop_back\n"
                , length);
    }
    
    my_string_destroy((Item*)&hString);
    
    return status;
}


Status scheerla_test_07_check_size(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("The quick brown fox jumps over a lazy dog");
    
    int size = my_string_get_size(hString);
    
    if ((my_string_get_size(hString) < 0) || (my_string_get_size(hString) > size)) {
        status = FAILURE;
        printf("Expected to get %d, but got %d\n", size, my_string_get_size(hString));
        strncpy(buffer, "scheerla_test_07_check_size\n"
                "\tDid not get correct size using the function scheerla_test_07_check_size\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_07_check_size\n"
                , length);
    }
    
    my_string_destroy((Item*)&hString);
    
    return status;
}

Status scheerla_test_08_check_capacity(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("The quick brown fox jumps over a lazy dog");
    
    int cap = my_string_get_capacity(hString);
    
    if ((my_string_get_capacity(hString) < 0) || (my_string_get_capacity(hString) > cap)) {
        status = FAILURE;
        printf("Expected to get %d, but got %d\n", cap, my_string_get_capacity(hString));
        strncpy(buffer, "scheerla_test_08_check_capacity\n"
                "\tDid not get correct capacity using the function scheerla_test_08_check_capacity\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_08_check_capacity\n"
                , length);
    }
    
    my_string_destroy((Item*)&hString);
    
    return status;
}

Status scheerla_test_09_concat(char* buffer, int length){
    MY_STRING hStringR = NULL;
    MY_STRING hStringA = NULL;
    Status status;

    hStringR = my_string_init_c_string("The quick brown fox ");
    hStringA = my_string_init_c_string("jumps over a lazy dog");

    int sizeR = my_string_get_size(hStringR);
    int sizeA = my_string_get_size(hStringA);
    int size = sizeR+sizeA;
    
    my_string_concat(hStringR, hStringA);

    if (my_string_get_size(hStringR) >= size+2) {
        status = FAILURE;
        printf("Expected to get %d, but got %d\n", size, my_string_get_size(hStringR));
        strncpy(buffer, "scheerla_test_09_concat\n"
                "\tDid not get correct size using the function scheerla_test_09_concat\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_09_concat\n"
                , length);
    }

    my_string_destroy((Item*)&hStringR);
    my_string_destroy((Item*)&hStringA);
    
    return status;
}


Status scheerla_test_10_at_neg(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("hello world");
    
    char* at = my_string_at(hString, -1);
    
    if (at != NULL) {
        status = FAILURE;
        printf("Expected to get nothing, but got %s\n", at);
        strncpy(buffer, "scheerla_test_10_at_neg\n"
                "\tDid not get correct result using the function scheerla_test_10_at_neg\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_10_at_neg\n"
                , length);
    }
    
    my_string_destroy((Item*)&hString);
    
    return status;
}

Status scheerla_test_11_at_greater_than_size(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("hello world");
    
    char* at = my_string_at(hString, 15);
    
    if (at != NULL) {
        status = FAILURE;
        printf("Expected to get nothing, but got %s\n", at);
        strncpy(buffer, "scheerla_test_11_at_greater_than_size\n"
                "\tDid not get correct result using the function scheerla_test_11_at_greater_than_size\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_11_at_greater_than_size\n"
                , length);
    }
    
    my_string_destroy((Item*)&hString);
    
    return status;
}


Status scheerla_test_12_compare_lex_equal(char* buffer, int length){
    MY_STRING hStringR = NULL;
    MY_STRING hStringL = NULL;
    Status status;
    hStringR = my_string_init_c_string("Hello");
    hStringL = my_string_init_c_string("Hello");
    
    int lex = my_string_compare(hStringL, hStringR);
   
    if (lex < 0 || lex > 0) {
        status = FAILURE;
        printf("Expected to get 0, but got %d\n",lex);
        strncpy(buffer, "scheerla_test_12_compare_lex_equal\n"
                "\tDid not get correct result using the function scheerla_test_12_compare_lex_equal \n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_12_compare_lex_equal\n"
                , length);
    }
    
    my_string_destroy((Item*)&hStringR);
    my_string_destroy((Item*)&hStringL);
    
    return status;
}

Status scheerla_test_13_concat_equal_length(char* buffer, int length){
    MY_STRING hStringR = NULL;
    MY_STRING hStringA = NULL;
    Status status;
    
    hStringR = my_string_init_c_string("Equal Length ");
    hStringA = my_string_init_c_string("Equal Length");
    
    int sizeR = my_string_get_size(hStringR);
    int sizeA = my_string_get_size(hStringA);
    int size = sizeR+sizeA;
    
    my_string_concat(hStringR, hStringA);
    
    if (my_string_get_size(hStringR) >= size+2) {
        status = FAILURE;
        printf("Expected to get %d, but got %d\n", size, my_string_get_size(hStringR));
        strncpy(buffer, "sscheerla_test_13_concat_equal_length\n"
                "\tDid not get correct size using the function scheerla_test_13_concat_equal_length\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_13_concat_equal_length\n"
                , length);
    }
    
    my_string_destroy((Item*)&hStringR);
    my_string_destroy((Item*)&hStringA);
    
    return status;
}

Status scheerla_test_14_compare_equal_length_a_z(char* buffer, int length){
    MY_STRING hStringR = NULL;
    MY_STRING hStringL = NULL;
    Status status;
    hStringR = my_string_init_c_string("a b c d e f g h i j k l m n o p q r s t u v w x y z");
    hStringL = my_string_init_c_string("a b c d e f g h i j k l m n o p q r s t u v w x y z");
    
    int lex = my_string_compare(hStringL, hStringR);
    
    if (lex < 0 || lex > 0) {
        status = FAILURE;
        printf("Expected to get 0, but got %d\n",lex);
        strncpy(buffer, "scheerla_test_14_compare_equal_length_a_z\n"
                "\tDid not get correct result using the function scheerla_test_14_compare_equal_length_a_z\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_14_compare_equal_length_a_z\n"
                , length);
    }
    
    my_string_destroy((Item*)&hStringR);
    my_string_destroy((Item*)&hStringL);
    
    return status;
}

Status scheerla_test_15_compare_equal_length_z_a(char* buffer, int length){
    MY_STRING hStringR = NULL;
    MY_STRING hStringL = NULL;
    Status status;
    hStringR = my_string_init_c_string("z y x w v u t s r q p o n m l k j i h g f e d c b a");
    hStringL = my_string_init_c_string("z y x w v u t s r q p o n m l k j i h g f e d c b a");
    
    int lex = my_string_compare(hStringL, hStringR);
    
    if (lex < 0 || lex > 0) {
        status = FAILURE;
        printf("Expected to get 0, but got %d\n",lex);
        strncpy(buffer, "scheerla_test_15_compare_equal_length_z_a\n"
                "\tDid not get correct result using the function scheerla_test_15_compare_equal_length_z_a\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_15_compare_equal_length_z_a\n"
                , length);
    }
    
    my_string_destroy((Item*)&hStringR);
    my_string_destroy((Item*)&hStringL);
    
    return status;
}

Status scheerla_test_16_compare_equal_length_A_Z(char* buffer, int length){
    MY_STRING hStringR = NULL;
    MY_STRING hStringL = NULL;
    Status status;
    hStringR = my_string_init_c_string("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
    hStringL = my_string_init_c_string("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
    
    int lex = my_string_compare(hStringL, hStringR);
    
    if (lex < 0 || lex > 0) {
        status = FAILURE;
        printf("Expected to get 0, but got %d\n",lex);
        strncpy(buffer, "scheerla_test_16_compare_equal_length_A_Z\n"
                "\tDid not get correct result using the function scheerla_test_16_compare_equal_length_A_Z\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_16_compare_equal_length_A_Z\n"
                , length);
    }
    
    my_string_destroy((Item*)&hStringR);
    my_string_destroy((Item*)&hStringL);
    
    return status;
}

Status scheerla_test_17_compare_equal_length_Z_A(char* buffer, int length){
    MY_STRING hStringR = NULL;
    MY_STRING hStringL = NULL;
    Status status;
    hStringR = my_string_init_c_string("Z Y X W V U T S R Q P O N M L K J I H G F E D C B A");
    hStringL = my_string_init_c_string("Z Y X W V U T S R Q P O N M L K J I H G F E D C B A");
    
    int lex = my_string_compare(hStringL, hStringR);
    
    if (lex < 0 || lex > 0) {
        status = FAILURE;
        printf("Expected to get 0, but got %d\n",lex);
        strncpy(buffer, "scheerla_test_17_compare_equal_length_Z_A\n"
                "\tDid not get correct result using the function scheerla_test_17_compare_equal_length_Z_A\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_17_compare_equal_length_Z_A\n"
                , length);
    }
    
    my_string_destroy((Item*)&hStringR);
    my_string_destroy((Item*)&hStringL);
    
    return status;
}

Status scheerla_test_18_compare_unequal_length(char* buffer, int length){
    MY_STRING hStringR = NULL;
    MY_STRING hStringL = NULL;
    Status status;
    hStringR = my_string_init_c_string("unequal");
    hStringL = my_string_init_c_string("unequall");
    
    int lex = my_string_compare(hStringL, hStringR);
    
    if (lex  == 0) {
        status = FAILURE;
        printf("Expected to get %d, but got 0\n",lex);
        strncpy(buffer, "scheerla_test_18_compare_unequal_length\n"
                "\tDid not get correct result using the function scheerla_test_18_compare_unequal_length\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_18_compare_unequal_length\n"
                , length);
    }
    
    my_string_destroy((Item*)&hStringR);
    my_string_destroy((Item*)&hStringL);
    
    return status;
}


Status scheerla_test_19_compare_unequal_length_left_1_short(char* buffer, int length){
    MY_STRING hStringR = NULL;
    MY_STRING hStringL = NULL;
    Status status;
    hStringR = my_string_init_c_string("unequal with right being longer");
    hStringL = my_string_init_c_string("unequal with left short");
    
    int lex = my_string_compare(hStringL, hStringR);
    
    if (lex  >= 0) {
        status = FAILURE;
        printf("Expected to get a negative number, but got %d\n",lex);
        strncpy(buffer, "scheerla_test_19_compare_unequal_length_left_1_short\n"
                "\tDid not get correct result using the function scheerla_test_19_compare_unequal_length_left_1_short\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_19_compare_unequal_length_left_1_short\n"
                , length);
    }
    
    my_string_destroy((Item*)&hStringR);
    my_string_destroy((Item*)&hStringL);

    return status;
}

Status scheerla_test_20_compare_unequal_length_right_1_short(char* buffer, int length){
    MY_STRING hStringR = NULL;
    MY_STRING hStringL = NULL;
    Status status;
    hStringR = my_string_init_c_string("unequal with right being longer");
    hStringL = my_string_init_c_string("unequal with left short");
    
    int lex = my_string_compare(hStringL, hStringR);
    
    if (lex  >= 0) {
        status = FAILURE;
        printf("Expected to get a negative number, but got %d\n",lex);
        strncpy(buffer, "scheerla_test_20_compare_unequal_length_right_1_short\n"
                "\tDid not get correct result using the function scheerla_test_20_compare_unequal_length_right_1_short\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_20_compare_unequal_length_right_1_short\n"
                , length);
    }
    
    my_string_destroy((Item*)&hStringR);
    my_string_destroy((Item*)&hStringL);
    
    return status;
}


Status scheerla_test_21_extraction_createFile(char* buffer, int length){
    FILE *file;
    Status status;
    
    file = fopen("extraction_test.txt", "w+");
    
    if (file != NULL)
    {
        fprintf(file, "This is an auto-generated test file for the extraction function.\n");
        fclose(file);
        
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_21_extraction_createFile\n", length);
    }
    else
    {
        printf("Unable to write file to filesystem\n");
        strncpy(buffer, "scheerla_test_21_extraction_createFile", length);
        status = FAILURE;
    }
    
    return status;
}

Status scheerla_test_22_extraction_readFile(char* buffer, int length){
    FILE *file;
    Status status;
    MY_STRING hString1 = my_string_init_default();
    MY_STRING hString2 = my_string_init_c_string("auto-generated");;
    
    file = fopen("extraction_test.txt", "r");
    
    if (file != NULL)
    {
        my_string_extraction(hString1, file);  // This
        my_string_extraction(hString1, file);  // is
        my_string_extraction(hString1, file);  // an
        my_string_extraction(hString1, file);  // auto-generated
        
        
        if (my_string_compare(hString1, hString2) == 0)
        {
            status = SUCCESS;
            strncpy(buffer, "scheerla_test_22_extraction_readFile\n", length);
        }
        else
        {
            printf("\nUnexpected character(s) returned from extraction\nExpected: \"%s\"\n     Got: \"%s\"\n"
                   "Quotes were added to help see any leading or trailing spaces.  They are not part of the test string.\n", my_string_c_str(hString2), my_string_c_str(hString1));
            strncpy(buffer, "scheerla_test_22_extraction_readFile", length);
            status = FAILURE;
        }
        
        fclose(file);
    }
    else
    {
        printf("Unable to read auto-generated file: extraction_test.txt\n");
        strncpy(buffer, "test_17__extraction_readFile", length);
        status = FAILURE;
    }
    
    my_string_destroy((Item*)&hString1);
    my_string_destroy((Item*)&hString2);

    return status;
}

Status scheerla_test_23_extraction_deleteFile(char* buffer, int length){
    int result;
    Status status;
    
    result = remove("extraction_test.txt");
    
    if (result == 0)
    {
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_23_extraction_deleteFile\n", length);
    }
    else
    {
        printf("\nUnable to delete file: extraction_test.txt\n");
        strncpy(buffer, "scheerla_test_23_extraction_deleteFile", length);
        status = FAILURE;
    }
    
    return status;
}

Status scheerla_test_24_compare_unequal_length_aardvark_Zoo(char* buffer, int length)
{
    int expectation = 1;
    MY_STRING hString1 = NULL;
    MY_STRING hString2 = NULL;
    Status status;
    
    hString1 = my_string_init_c_string("aardvark");
    hString2 = my_string_init_c_string("Zoo");
    
    if (my_string_compare(hString1, hString2) != expectation)
    {
        status = FAILURE;
        printf("Expected %d but got %d\n", expectation, my_string_compare(hString1, hString2));
        strncpy(buffer, "scheerla_test_24_compare_unequal_length_aardvark_Zoo", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_24_compare_unequal_length_aardvark_Zoo\n", length);
    }
    my_string_destroy((Item*)&hString1);
    my_string_destroy((Item*)&hString2);
    return status;
}

Status scheerla_test_25_compare_unequal_length_zoo_Aardvark(char* buffer, int length)
{
    int expectation = 1;
    MY_STRING hString1 = NULL;
    MY_STRING hString2 = NULL;
    Status status;
    
    hString1 = my_string_init_c_string("zoo");
    hString2 = my_string_init_c_string("Aardvark");
    
    if (my_string_compare(hString1, hString2) != expectation)
    {
        status = FAILURE;
        printf("Expected %d but got %d\n", expectation, my_string_compare(hString1, hString2));
        strncpy(buffer, "scheerla_test_25_compare_unequal_length_zoo_Aardvark", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "scheerla_test_25_compare_unequal_length_zoo_Aardvark\n", length);
    }
    my_string_destroy((Item*)&hString1);
    my_string_destroy((Item*)&hString2);
    return status;
}

Status lab_6_copy_me(char* buffer, int length){
    Status status = FAILURE;
    //printf("Expected to create 100 copies.\n");
    strncpy(buffer, "lab_6_copy_me", length);
    MY_STRING hString[100];
    int i;
    
    for(i = 0; i < 100; i++){
        hString[i] =  NULL;
    }
    
    hString[0] = my_string_init_c_string("COPY ME!");
    
    for(i = 1; i < 100; i++){
        //hString[i] = my_string_init_default(); //dont need this because the func takes care of it
        my_string_assignment(&hString[i], hString[0]);
    }
    
    for (i = 0; i < 100; i++){
        my_string_insertion(hString[i], stdout);
        printf("\n");
        my_string_destroy((Item*)&hString[i]);
    }
    
    status = SUCCESS;
    strncpy(buffer, "lab_6_copy_me\n", length);
    
    return status;
}

Status lab_7_same_length(char* buffer, int length){
    Status status = FAILURE;
    int i;
    FILE* fp;
    
    GENERIC_VECTOR array[30];
    
    for ( i = 0; i < 30; i++){
        array[i] = generic_vector_init_default(my_string_assignment, my_string_destroy);
        
        if (array[i] == NULL){
            printf("No space avaliable for vector");
            status = FAILURE;
            return status;
        }
    }
    
    MY_STRING hstring = my_string_init_default();
    fp = fopen("dictionary.txt", "r");
    if(fp == NULL){
        printf("unable to open dictionary.txt file");
        status = FAILURE;
        return status;
    }
    while ((my_string_extraction(hstring, fp) == SUCCESS)){
        if(my_string_get_size(hstring) < 30){
            generic_vector_push_back(array[my_string_get_size(hstring)], hstring);
        }
    }
    
    for(i = 0; i < 30; i++){
        printf("The number of words in the dictionary with %d characters are %d\n", i, generic_vector_get_size(array[i]));
    }
    
    for(i = 0; i < 30; i++){
        printf("trying to destroy generic vector \n");
        generic_vector_destroy(&(array[i]));
        printf("destroification complete of generic vector \n");
    }
    fclose(fp);
    
    printf("trying to destroy string\n");
    my_string_destroy(&hstring);
    printf("destroification complete of string\n");
    
    status = SUCCESS;
    return status;
}
