/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Description: The main function reads Monty script from a file, processes
 * Monty opcodes, and executes them. It maintains a stack and performs
 * various stack manipulation operations based on the opcodes in the script.
 *
 * Return: EXIT_SUCCESS on successful execution, EXIT_FAILURE on errors.
 */
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file;
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    while (fgets(line, len, file) != NULL)
    {
        line_number++;
        execute_opcode(&stack, line, line_number);
    }

    free_stack(&stack);
    free(line);
    fclose(file);

    return (EXIT_SUCCESS);
}
