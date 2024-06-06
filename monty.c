#include "monty.h"

/* Declaration of the global variable */
global_var var_global;

/**
 * main - Entry point for the Monty program
 * @ac: Number of arguments passed to the program
 * @av: Array of strings containing the arguments
 * Return: Always 0 (Success)
 */
int main(int ac, char **av)
{
    stack_t *stack;

    stack = NULL;

    /* Check if the number of arguments is correct */
    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Read and execute commands from the bytecode file */
    read_file(av[1], &stack);

    /* Free dynamically allocated memory */
    free_dlistint(stack);

    return (0);
}
