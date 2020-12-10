//#include <stdio.h>
//#include "unit_test.h"
//int main(int argc, char* argv[]){
//    Status (*tests[])(char*, int) =
//    {
//        test_init_default_returns_nonNULL,
//        test_get_size_on_init_default_returns_0,
//        scheerla_test_03_get_size_on_init_c_strreturns_non0,
//        scheerla_test_04_destroy,
//        scheerla_test_05_push_back,
//        scheerla_test_06_pop_back,
//        scheerla_test_07_check_size,
//        scheerla_test_08_check_capacity,
//        scheerla_test_09_concat,
//        scheerla_test_10_at_neg,
//        scheerla_test_11_at_greater_than_size,
//        scheerla_test_12_compare_lex_equal,
//        scheerla_test_13_concat_equal_length,
//        scheerla_test_14_compare_equal_length_a_z,
//        scheerla_test_15_compare_equal_length_z_a,
//        scheerla_test_16_compare_equal_length_A_Z,
//        scheerla_test_17_compare_equal_length_Z_A,
//        scheerla_test_18_compare_unequal_length,
//        scheerla_test_19_compare_unequal_length_left_1_short,
//        scheerla_test_20_compare_unequal_length_right_1_short,
//        scheerla_test_21_extraction_createFile,
//        scheerla_test_22_extraction_readFile,
//        scheerla_test_23_extraction_deleteFile,
//        scheerla_test_24_compare_unequal_length_aardvark_Zoo,
//        scheerla_test_25_compare_unequal_length_zoo_Aardvark,
//        lab_6_copy_me,
//        lab_7_same_length,
//    };
//
//
////    int number_of_functions = sizeof(tests) / sizeof(tests[0]);
//    int i;
//    char buffer[1500];
//    int success_count = 0;
//    int failure_count = 0;
//    for(i=0; i<number_of_functions; i++)
//    {
//        if(tests[i](buffer, 500) == FAILURE || tests[i] == FAILURE)
//        {
//            printf("FAILED: Test %d failed miserably\n", i);
//            printf("\t%s\n", buffer);
//            failure_count++;
//        }
//        else
//        {
//            printf("PASS: Test %d passed\n", i);
//            printf("\t%s\n", buffer);
//            success_count++;
//        }
//    }
//    printf("Total number of tests: %d\n", number_of_functions);
//    printf("%d/%d Pass, %d/%d Failure\n", success_count,
//           number_of_functions, failure_count, number_of_functions);
//
//    return 0;
//}
