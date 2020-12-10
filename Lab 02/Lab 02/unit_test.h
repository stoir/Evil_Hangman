
#ifndef unit_test_h
#define unit_test_h

#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);

Status test_get_size_on_init_default_returns_0(char* buffer, int length);


Status scheerla_test_03_get_size_on_init_c_strreturns_non0(char* buffer, int length);
Status scheerla_test_04_destroy(char* buffer, int length);
Status scheerla_test_05_push_back(char* buffer, int length);
Status scheerla_test_06_pop_back(char* buffer, int length);

Status scheerla_test_07_check_size(char* buffer, int length);
Status scheerla_test_08_check_capacity(char* buffer, int length);
Status scheerla_test_09_concat(char* buffer, int length);

Status scheerla_test_10_at_neg(char* buffer, int length);
Status scheerla_test_11_at_greater_than_size(char* buffer, int length);

Status scheerla_test_12_compare_lex_equal(char* buffer, int length);
Status scheerla_test_13_concat_equal_length(char* buffer, int length);

Status scheerla_test_14_compare_equal_length_a_z(char* buffer, int length);
Status scheerla_test_15_compare_equal_length_z_a(char* buffer, int length);
Status scheerla_test_16_compare_equal_length_A_Z(char* buffer, int length);
Status scheerla_test_17_compare_equal_length_Z_A(char* buffer, int length);
Status scheerla_test_18_compare_unequal_length(char* buffer, int length);

Status scheerla_test_19_compare_unequal_length_left_1_short(char* buffer, int length);
Status scheerla_test_20_compare_unequal_length_right_1_short(char* buffer, int length);

Status scheerla_test_21_extraction_createFile(char* buffer, int length);
Status scheerla_test_22_extraction_readFile(char* buffer, int length);
Status scheerla_test_23_extraction_deleteFile(char* buffer, int length);

Status scheerla_test_24_compare_unequal_length_aardvark_Zoo(char* buffer, int length);
Status scheerla_test_25_compare_unequal_length_zoo_Aardvark(char* buffer, int length);

Status lab_6_copy_me(char* buffer, int length);
Status lab_7_same_length(char* buffer, int length);

//do not delete this
#endif /* unit_test_h */
