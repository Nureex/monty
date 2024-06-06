#include "monty.h"

/**
 * _pstr - Print the string starting from the top of the stack
 * @stack: Pointer to the stack (linked list)
 * @line_number: Line number where the opcode occurs (unused)
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;
    int c = 0;

    (void)line_number;

    // Traverse the stack and print each character until a null byte or non-printable character is encountered
    while (tmp)
    {
        c = tmp->n;
        if (c == 0 || _isalpha(c) == 0)
            break;
        putchar(c);
        tmp = tmp->next;
    }
    putchar('\n');
}

/**
 * _rotl - Rotate the stack to the top
 * @stack: Pointer to the stack (linked list)
 * @line_number: Line number where the opcode occurs (unused)
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *runner = *stack;
    int aux1 = 0;

    // Check if the stack is empty or has only one element
    if (!line_number || !stack || !*stack || !(*stack)->next)
        return;

    aux1 = runner->n;

    // Move each element to the previous node until the last node
    while (runner->next)
    {
        runner = runner->next;
        runner->prev->n = runner->n;
    }

    // Move the first element to the last position
    runner->n = aux1;
}

/**
 * _rotr - Rotate the stack to the bottom
 * @stack: Pointer to the stack (linked list)
 * @line_number: Line number where the opcode occurs (unused)
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *runner = *stack;
    int aux1 = 0;

    // Check if the stack is empty or has only one element
    if (!line_number || !stack || !*stack || !(*stack)->next)
        return;

    // Move to the last node
    while (runner->next)
        runner = runner->next;

    aux1 = runner->n;

    // Move each element to the next node until the first node
    while (runner->prev)
    {
        runner = runner->prev;
        runner->next->n = runner->n;
    }

    // Move the last element to the first position
    runner->n = aux1;
}
