#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*--- Struct Definitions ---*/
extern int push_arg; /* External variable to hold the argument for the push operation */

/**
 * struct stack_s - Doubly linked list node structure for a stack (or queue)
 * @n: Integer value stored in the node
 * @prev: Pointer to the previous element in the stack (or queue)
 * @next: Pointer to the next element in the stack (or queue)
 * Description: Node structure used for implementing a stack (or queue)
 * for the Holberton project following LIFO and FIFO principles
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Structure for an opcode and its corresponding function
 * @opcode: The operation code (command)
 * @f: Function pointer to execute the command
 * Description: Structure that pairs an opcode with its corresponding function
 * for stack (or queue) operations in the Holberton project
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variable - Structure to hold global variables used throughout the project
 * @file: File pointer to the script being executed
 * @push_arg: Argument to be used with the push command
 * @buffer: Buffer to store the current line being processed
 * Description: Structure to manage global variables for file handling,
 * argument storage, and buffer management
 */
typedef struct global_variable
{
    FILE *file;   /* File pointer for the input script */
    int push_arg; /* Argument for the push operation */
    char *buffer; /* Buffer to store the input line */
} global_var;

extern global_var var_global; /* Extern declaration of the global variable structure */

/* Function to read and process the script file */
void read_file(char *filename, stack_t **stack);

/* Function to parse a line and execute the corresponding operation */
char *parse_line(char *line, stack_t **stack, unsigned int line_number);

/* Function to get the appropriate function for a given opcode */
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
instruct_func get_op_func(char *str);

/* Monty opcode functions */
void _pall(stack_t **stack, unsigned int line_number); /* Print all elements in the stack */
void _push(stack_t **stack, unsigned int line_number); /* Push an element onto the stack */
void _pint(stack_t **stack, unsigned int line_number); /* Print the top element of the stack */
void _pop(stack_t **stack, unsigned int line_number);  /* Remove the top element from the stack */
void _swap(stack_t **stack, unsigned int line_number); /* Swap the top two elements of the stack */
void _nop(stack_t **stack, unsigned int line_number);  /* No operation */
void _rotl(stack_t **stack, unsigned int line_number); /* Rotate the stack to the top */
void _rotr(stack_t **stack, unsigned int line_number); /* Rotate the stack to the bottom */

/* ASCII-related functions */
void _pchar(stack_t **stack, unsigned int line_number); /* Print the character at the top of the stack */
void _pstr(stack_t **stack, unsigned int line_number);  /* Print the string starting from the top of the stack */

/* Mathematical operation functions */
void _sub(stack_t **stack, unsigned int line_number); /* Subtract the second top element from the top element */
void _add(stack_t **stack, unsigned int line_number); /* Add the top two elements */
void _mul(stack_t **stack, unsigned int line_number); /* Multiply the top two elements */
void _div(stack_t **stack, unsigned int line_number); /* Divide the second top element by the top element */
void _mod(stack_t **stack, unsigned int line_number); /* Compute the remainder of the division */

/* Utility functions */
void free_dlistint(stack_t *head); /* Free a doubly linked list */
void dobfree(stack_t **stack);     /* Free the stack */
void dobfree2(stack_t **stack);    /* Free the stack and other resources */
int _isalpha(int c);               /* Check if a character is alphabetic */

#endif
