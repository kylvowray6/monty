/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty byte code file.
 *
 * Description: This function pushes an element with the specified value onto the stack.
 * It performs error checking to ensure that the value is a valid integer.
 */
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void push(stack_t **stack, unsigned int line_number)
{
    char *value = strtok(NULL, " \t\n");
    int n;
    stack_t *new_node;

    if (value == NULL || !is_numeric(value))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(value);

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty byte code file.
 *
 * Description: This function removes the top element of the stack.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = temp->next;
    if (temp->next)
        temp->next->prev = NULL;
    free(temp);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty byte code file.
 *
 * Description: This function swaps the top two elements of the stack.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *first, *second;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    first = *stack;
    second = first->next;

    first->next = second->next;
    second->next = first;
    first->prev = second;
    if (first->next)
        first->next->prev = first;
    second->prev = NULL;
    *stack = second;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty byte code file.
 *
 * Description: This function adds the top two elements of the stack and stores
 * the result in the second top element while removing the top element.
 */
void add(stack_t **stack, unsigned int line_number)
{
    stack_t *first, *second;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    first = *stack;
    second = first->next;

    second->n += first->n;
    pop(stack, line_number);
}

