#include "monty.h"

/**
 * _sub - Subtract the top element from the second top element of the stack
 * @stack: Pointer to the stack (linked list)
 * @line_number: Line number where the opcode occurs
 */
void _sub(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;
    int sub = 0, i = 0;

    /* Check if the stack is empty */
    if (tmp == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Count the number of elements in the stack */
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }

    /* Check if there are fewer than two elements in the stack */
    if (stack == NULL || (*stack)->next == NULL || i <= 1)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    /* Subtract the top element from the second top element and update the stack */
    sub = (*stack)->next->n - (*stack)->n;
    _pop(stack, line_number);

    (*stack)->n = sub;
}

/**
 * _mul - Multiply the top two elements of the stack
 * @stack: Pointer to the stack (linked list)
 * @line_number: Line number where the opcode occurs
 */
void _mul(stack_t **stack, unsigned int line_number)
{
    int aux;

    /* Check if the stack has fewer than two elements */
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        free(var_global.buffer);
        fclose(var_global.file);
        free_dlistint(*stack);
        exit(EXIT_FAILURE);
    }
    else
    {
        aux = (*stack)->n;
        _pop(stack, line_number);
        (*stack)->n *= aux;
    }
}

/**
 * _div - Divide the second top element by the top element of the stack
 * @stack: Pointer to the stack (linked list)
 * @line_number: Line number where the opcode occurs
 */
void _div(stack_t **stack, unsigned int line_number)
{
    int div = 0;

    /* Check if the stack has fewer than two elements or if division by zero is attempted */
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        free(var_global.buffer);
        fclose(var_global.file);
        free_dlistint(*stack);
        exit(EXIT_FAILURE);
    }
    else if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        free(var_global.buffer);
        fclose(var_global.file);
        free_dlistint(*stack);
        exit(EXIT_FAILURE);
    }
    else
    {
        div = (*stack)->n;
        _pop(stack, line_number);
        (*stack)->n /= div;
    }
}

/**
 * _mod - Compute the remainder of the division of the second top element by the top element of the stack
 * @stack: Pointer to the stack (linked list)
 * @line_number: Line number where the opcode occurs
 */
void _mod(stack_t **stack, unsigned int line_number)
{
    int mod = 0;

    /* Check if the stack has fewer than two elements or if division by zero is attempted */
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        free(var_global.buffer);
        fclose(var_global.file);
        free_dlistint(*stack);
        exit(EXIT_FAILURE);
    }
    else if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        free(var_global.buffer);
        fclose(var_global.file);
        free_dlistint(*stack);
        exit(EXIT_FAILURE);
    }
    else
    {
        mod = (*stack)->n;
        _pop(stack, line_number);
        (*stack)->n %= mod;
    }
}