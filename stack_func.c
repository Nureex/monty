#include "monty.h"

/**
 * _push - Push an integer onto the stack
 * @stack: Pointer to the stack (linked list)
 * @line_number: Line number where the opcode occurs (unused)
 */
void _push(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
    stack_t *top;

    (void)line_number;

    /* Allocate memory for a new stack node */
    top = malloc(sizeof(stack_t));
    if (top == NULL)
    {
        /* Print error message if malloc fails */
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize the new node */
    top->n = var_global.push_arg;
    top->next = *stack;
    top->prev = NULL;
    if (*stack != NULL)
        (*stack)->prev = top;
    *stack = top;
}

/**
 * _pall - Print all elements in the stack
 * @stack: Pointer to the stack (linked list)
 * @line_number: Line number where the opcode occurs (unused)
 */
void _pall(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
    stack_t *runner;

    runner = *stack;
    /* Traverse the stack and print each element */
    while (runner != NULL)
    {
        printf("%d\n", runner->n);
        runner = runner->next;
    }
}

/**
 * _pint - Print the integer at the top of the stack
 * @stack: Pointer to the stack (linked list)
 * @line_number: Line number where the opcode occurs
 */
void _pint(stack_t **stack, unsigned int line_number)
{
    stack_t *runner;

    runner = *stack;
    /* Check if the stack is empty */
    if (runner == NULL)
    {
        /* Print error message if the stack is empty */
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    /* Print the top element */
    printf("%d\n", runner->n);
}

/**
 * _pop - Remove the top element from the stack
 * @stack: Pointer to the first node in the stack
 * @line_number: Line number where the opcode occurs
 */
void _pop(stack_t **stack, unsigned int line_number)
{
    stack_t *nodo = *stack;

    /* Check if the stack is empty */
    if (stack == NULL || *stack == NULL)
    {
        /* Print error message if the stack is empty */
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    /* Remove the top element and update the stack */
    *stack = nodo->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(nodo);
}

/**
 * free_dlistint - Free a doubly linked list
 * @head: Pointer to the first node in the list
 */
void free_dlistint(stack_t *head)
{
    stack_t *tmp;

    /* Traverse the list and free each node */
    while (head != NULL)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}