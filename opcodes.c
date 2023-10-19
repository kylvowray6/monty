/**
 * pall - Prints all values in the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty byte code file.
 *
 * Description: This function prints all the values in the stack,
 * starting from the top of the stack.
 */
#include "monty.h"
#include <stdio.h>
#include <string.h>

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current; 

    (void)line_number; /* Silence unused parameter warning */

    current = *stack; 

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * execute_opcode - Executes the appropriate opcode.
 * @stack: Double pointer to the stack.
 * @line: Line containing the opcode from the Monty byte code file.
 * @line_number: Line number in the Monty byte code file.
 *
 * Description: This function parses the opcode from the input line and executes
 * the corresponding operation on the stack or modifies program control as needed.
 */
void execute_opcode(stack_t **stack, char *line, unsigned int line_number)
{
    char *opcode = strtok(line, " \t\n");

    if (opcode == NULL || *opcode == '#')
        return;

    if (strcmp(opcode, "push") == 0)
        push(stack, line_number);
    else if (strcmp(opcode, "pall") == 0)
        pall(stack, line_number);
    else if (strcmp(opcode, "pint") == 0)
        pint(stack, line_number);
    else if (strcmp(opcode, "pop") == 0)
        pop(stack, line_number);
    else if (strcmp(opcode, "swap") == 0)
        swap(stack, line_number);
    else if (strcmp(opcode, "add") == 0)
        add(stack, line_number);
    else if (strcmp(opcode, "nop") == 0)
    {
        /* nop doesn't do anything, so it can be left empty. */
    }
    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}
