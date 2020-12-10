

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_string.h"
#include "generic_vector.h"
#include "associative_array.h"

int play_game(int word_length, int guesses, Boolean total_words);
int get_word_length(void);
int get_num_guesses(void);
Boolean running_total(void);
char play_again(void);
void clear_keyboard_buffer(void);
char get_guess(void);

int main(int argc, char* argv[]){
    
    do{
        int word_length, guesses;
        Boolean total_words;
        printf("\n\nEVIL HANGMAN!\n\n");
        word_length = get_word_length();
        guesses = get_num_guesses();
        total_words = running_total();
        play_game(word_length, guesses, total_words);
    }
    while (play_again() == 'y');
    
    return 0;
}

int play_game(int word_length, int guesses, Boolean total_words){
    GENERIC_VECTOR word_list = generic_vector_init_default(my_string_assignment, my_string_destroy);
    MY_STRING hString = my_string_init_default();
    MY_STRING current_word_family = my_string_init_default();
    MY_STRING new_key = my_string_init_default();
    MY_STRING guessed_letters = my_string_init_default();
    GENERIC_VECTOR largest = NULL;
    tNode *word_families  = NULL;
    char guess;
    int i,j, k;
    
    FILE* fp;
    fp = fopen("dictionary.txt", "r");
    
    while(my_string_extraction(hString, fp)){
        if (my_string_get_size(hString) == word_length){
            generic_vector_push_back(word_list, hString);
        }
    }
    
    fclose(fp);
    my_string_destroy(&hString);
    
    for(i = 0; i < word_length; i++){
        my_string_push_back(current_word_family, '-');
    }
    
    while(guesses > 0){
        if (total_words){
            printf("\nThe Computer has %d possibilities remaining.\n", generic_vector_get_size(word_list));
        }
        
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\nYou have %d guesses left.\n", guesses);
        printf("Guessed letters: ");
        
        for (j=0; j<my_string_get_size(guessed_letters); j++){
            printf(" %c", *my_string_at(guessed_letters, j));
        }
        
        printf("\n");
        printf("Word: %s\n", my_string_c_str(current_word_family));
        
        if(!(my_string_compare(generic_vector_at(word_list, 0), current_word_family) == 0)){//added
            guess = get_guess(); //was there before
            if(my_string_compare(generic_vector_at(word_list, 0), current_word_family) == 0){
                printf("You won!\n");
                printf("The word was '%s'.\n\n", my_string_c_str(generic_vector_at(word_list, 0)));
                guesses = 0;
            }
        } //added
        
        my_string_push_back(guessed_letters, guess);
        
        for(k = 0; k < generic_vector_get_size(word_list); k++){
            get_word_key_value(current_word_family, new_key, generic_vector_at(word_list, k), guess);
            word_families = insertNodes(word_families, new_key, generic_vector_at(word_list, k));
            
            if (total_words){
                my_string_insertion(generic_vector_at(word_list, k), stdout);
                printf(": ");
                my_string_insertion(new_key, stdout);
                printf("\n");
            }
        }
        printf("\n");
        largest = largest_family(word_families, total_words);
        
        generic_vector_destroy(&word_list);
        
        word_list = generic_vector_init_default(my_string_assignment, my_string_destroy);
        
        for(i = 0; i < generic_vector_get_size(largest); i++){
            generic_vector_push_back(word_list, generic_vector_at(largest, i));
        }
        
        
        
        get_word_key_value(current_word_family, new_key, generic_vector_at(word_list, 0), guess);
        
        if (my_string_compare(current_word_family, new_key) == 0){
            printf("\nI'm sorry, there are no %c's in the word.\n\n", guess);
            guesses--;
        }
        else{
            printf("Correct guess!\n\n");
        }
        
        my_string_assignment(&current_word_family, new_key);
        
        if(guesses <= 0){
            printf("You lost!\n");
            printf("The word was '%s'.\n\n", my_string_c_str(generic_vector_at(word_list, 0)));
        }
        
        if(my_string_compare(generic_vector_at(word_list, 0), current_word_family) == 0){
            printf("You won!\n");
            printf("The word was '%s'.\n\n", my_string_c_str(generic_vector_at(word_list, 0)));
            guesses = 0;
        }
        
        generic_vector_destroy(&largest);
        destroy_tree(word_families);
        my_string_destroy(&new_key);
        new_key = my_string_init_default();
        word_families = NULL;
    }
    my_string_destroy(&new_key);
    my_string_destroy(&guessed_letters);
    my_string_destroy(&current_word_family);
    generic_vector_destroy(&word_list);
    free(word_families);
    
    return 0;
    
}

char play_again(void){
    char choice = 'y';
    int noc;
    
    printf("Would yoy like to play again?(y/n):");
    noc = scanf(" %c", &choice);
    clear_keyboard_buffer();
    
    while((choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') || noc != 1){
        printf("I'm sorry you must either enter 'y' or 'n'): ");
        noc = scanf(" %c", &choice);
        clear_keyboard_buffer();
    }
    
    if (choice == 'y' || choice == 'Y'){
        return 'y';
    }
    
    return 'n';
}


int get_word_length()
{
    int word_length;
    int noc;
    
    do
    {
        printf("Enter the number of letters you want the word to be: ");
        noc = scanf(" %d", &word_length);
        clear_keyboard_buffer();
    
    }while(noc != 1 || word_length < 2 || word_length > 29 || word_length == 23 || word_length == 25 || word_length == 26 || word_length == 27);

    return word_length;
}

int get_num_guesses()
{
    int guesses;
    int noc;
 
    do
    {
        printf("Enter the number of guesses would you like to have:  ");
        noc = scanf(" %d", &guesses);
        clear_keyboard_buffer();
    
    }while(noc != 1 || guesses <= 0);
    
    return guesses;
}

Boolean running_total(){
    char choice = 'y';
    int noc;
    
    printf("Would you like to see the number of words remaining? (y/n):");
    noc = scanf(" %c", &choice);
    clear_keyboard_buffer();
    
    while((choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') || noc != 1){
        printf("I'm sorry you must either enter 'y' or 'n'): ");
        noc = scanf(" %c", &choice);
        clear_keyboard_buffer();
    }
    
    if (choice == 'y' || choice == 'Y'){
        return 1;
    }
    
    return 0;
}

void clear_keyboard_buffer(void){
    char c;
    scanf("%c", &c);
    while (c != '\n'){
        scanf("%c", &c);
    }
}

char get_guess(void){
    char c;
    int noc;
    
    do{
        printf("Enter your guess: ");
        noc = scanf(" %c", &c);
    }while(noc == 0 || !isalpha(c));
    
    
    
    if( isupper(c)){
        c = tolower(c);
    }
    
    return c;
}
