#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRING_LENGTH 100 // macro for the default length of a string
#define MEMORY_SIZE 20 // macro for the size of the operation memory

// STRUCTS

typedef struct { // a single memory unit
    char String[STRING_LENGTH];
    double Result;
} OPERATION;

// FUNCTION PROTOTYPES

double calc(char *string); // function for calculating the result of an operation from a string
void mem_add(OPERATION *mem_start, int *mem_used, OPERATION operation); // function for adding an instance to the operation memory
void mem_clear(OPERATION *mem_start, int *mem_used); // function for clearing the operation memory
void mem_print(OPERATION *mem_start, int mem_used); // function for printing the operation memory to output stream (printf)

// MAIN

int main() {

    // declare initial variables
    OPERATION operation_memory[MEMORY_SIZE];
    int mem_used = 0;
    char action[STRING_LENGTH], operation_string[STRING_LENGTH];

    // print introductory message
    printf("C calculator\n");

    // begin looping until exit action
    while (strcmp(action, "exit")) {

        // print action selection and get user input
        printf("\n\nAction (calc, clear, print, exit): ");
        scanf("%s", action);
        if (!strcmp(action, "calc")) {
            
            // get user input operation string
            printf("\nCalculation: ");
            scanf("%s", operation_string);

            // get result from user input string
            double result = calc(operation_string);

            // print result
            printf("\nThe result is %lg", result);
            
            // create OPERATION struct and add it to memory
            OPERATION current_operation;
            strcpy(current_operation.String, operation_string);
            current_operation.Result = result;
            mem_add(operation_memory, &mem_used, current_operation);

            // print success message
            printf("\nOperation added to memory!\n");

        }
        else if (!strcmp(action, "clear")) {
            
            // call mem_clear
            mem_clear(operation_memory, &mem_used);

            // print success message
            printf("\nMemory cleared!\n");

        }
        else if (!strcmp(action, "print")) {
            
            // call mem_print
            mem_print(operation_memory, mem_used);

        }
        else if (!strcmp(action, "exit")) {
            
            // break from loop
            break;

        }
        else {

            // print error message
            printf("\nUnrecognized action, please try again!\n");

        }
    }

    return 0;
}

// FUNCTIONS


double calc(char *string){

}

void mem_add(OPERATION *mem_start, int *mem_used, OPERATION operation) {

}

void mem_clear(OPERATION *mem_start, int *mem_used) {

}

void mem_print(OPERATION *mem_start, int mem_used) {
    
}