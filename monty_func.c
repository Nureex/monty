#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * read_file - Read a bytecode file and execute commands
 * @filename: Pathname to the file
 * @stack: Pointer to the top of the stack
 */
void read_file(char *filename, stack_t **stack)
{
    char *line;
    size_t i = 0;
    int line_count = 1;
    instruct_func s;
    int check;
    int read;

    /* Open the file for reading */
    var_global.file = fopen(filename, "r");

    /* Check if file opening was successful */
    if (var_global.file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    /* Read each line of the file */
    while ((read = getline(&var_global.buffer, &i, var_global.file)) != -1)
    {
        line = parse_line(var_global.buffer, stack, line_count);

        /* Skip blank lines and comments */
        if (line == NULL || line[0] == '#')
        {
            line_count++;
            continue;
        }

        /* Get the function corresponding to the opcode */
        s = get_op_func(line);

        /* Check if the opcode is valid */
        if (s == NULL)
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
            exit(EXIT_FAILURE);
        }

        /* Execute the function corresponding to the opcode */
        s(stack, line_count);
        line_count++;
    }

    /* Free dynamically allocated memory and close the file */
    free(var_global.buffer);
    check = fclose(var_global.file);
    if (check == -1)
        exit(-1);
}

/**
 * get_op_func - Check the opcode and return the corresponding function
 * @str: The opcode
 * Return: Returns a function pointer, or NULL on failure
 */
instruct_func get_op_func(char *str)
{
    int i;

    instruction_t instruct[] = {
        {"push", _push},
        {"pall", _pall},
        {"pint", _pint},
        {"pop", _pop},
        {"swap", _swap},
        {"add", _add},
        {"nop", _nop},
        {"sub", _sub},
        {"mul", _mul},
        {"div", _div},
        {"mod", _mod},
        {"pchar", _pchar},
        {"pstr", _pstr},
        {"rotl", _rotl},
        {"rotr", _rotr},
        {NULL, NULL},
    };

    /* Search for the opcode in the instruction array */
    i = 0;
    while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
    {
        i++;
    }

    return (instruct[i].f);
}

/**
 * isnumber - Check if a string represents a number
 * @str: String to be checked
 * Return: Returns 1 if the string is a number, 0 otherwise
 */
int isnumber(char *str)
{
    unsigned int i;

    if (str == NULL)
        return (0);
    i = 0;
    while (str[i])
    {
        if (str[0] == '-')
        {
            i++;
            continue;
        }
        if (!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

/**
 * parse_line - Parse a line for an opcode and arguments
 * @line: The line to be parsed
 * @stack: Pointer to the head of the stack
 * @line_number: The current line number
 * Return: Returns the opcode or NULL on failure
 */
char *parse_line(char *line, stack_t **stack, unsigned int line_number)
{
    char *op_code, *push, *arg;
    (void)stack;

    push = "push";
    /* Tokenize the line to extract the opcode */
    op_code = strtok(line, "\n ");
    if (op_code == NULL)
        return (NULL);

    /* If the opcode is "push", extract the argument and convert it to an integer */
    if (strcmp(op_code, push) == 0)
    {
        arg = strtok(NULL, "\n ");
        if (isnumber(arg) == 1 && arg != NULL)
        {
            var_global.push_arg = atoi(arg);
        }
        else
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
    }
    return (op_code);
}
