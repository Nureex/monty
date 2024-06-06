#include "monty.h"

/**
 * _swap - Swap the top two elements of the stack
 * @stack: Pointer to the stack (linked list)
 * @line_number: Line number where the opcode occurs
 */
void _swap(stack_t **stack, unsigned int line_number)
{
    stack_t *runner;
    int tmp;

    runner = *stack;
    /* Check if there are fewer than two elements in the stack */
    if (runner == NULL || runner->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    /* Swap the values of the top two elements */
    tmp = runner->n;
    runner->n = runner->next->n;
    runner->next->n = tmp;
}

/**
 * _add - Add the top two elements of the stack
 * @stack: Pointer to the stack (linked list)
 * @line_number: Line number where the opcode occurs
 */
void _add(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;
    int sum = 0, i = 0;

    /* Check if the stack is empty or has fewer than two elements */
    if (tmp == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Count the number of elements in the stack */
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }

    if (stack == NULL || (*stack)->next == NULL || i <= 1)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    /* Add the top two elements and update the stack */
    sum = (*stack)->next->n + (*stack)->n;
    _pop(stack, line_number);

    (*stack)->n = sum;
}

/**
 * _nop - No operation function
 * @stack: Pointer to the stack (linked list)
 * @line_number: Line number where the opcode occurs (unused)
 */
void _nop(__attribute__ ((unused)) stack_t **stack,
          __attribute__ ((unused)) unsigned int line_number)
{
    /* This function does nothing */
    ;
}

/**
 * _pchar - Print the character at the top of the stack
 * @stack: Pointer to the top of the stack (linked list)
 * @line_number: Line number where the opcode occurs
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
    int val;

    /* Check if the stack is empty */
    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        free(var_global.buffer);
        fclose(var_global.file);
        free_dlistint(*stack);
        exit(EXIT_FAILURE);
    }

    val = (*stack)->n;
    /* Check if the value is a valid ASCII character */
    if (val > 127 || val < 0)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        free(var_global.buffer);
        fclose(var_global.file);
        free_dlistint(*stack);
        exit(EXIT_FAILURE);
    }

    /* Print the character */
    putchar(val);
    putchar('\n');
}

/**
 * _isalpha - Check if an integer corresponds to an alphabetic character
 * @c: The integer to check
 * Return: 1 if the integer is an alphabetic character, 0 otherwise
 */
int _isalpha(int c)
{
    if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
        return (1);
    else
        return (0);
}