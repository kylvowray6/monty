#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - Doubly linked list representation of a stack
 * @n: Integer
 * @prev: Points to the previous element of the stack
 * @next: Points to the next element of the stack
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty byte code file.
 */
void push(stack_t **stack, unsigned int line_number);

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty byte code file.
 */
void pop(stack_t **stack, unsigned int line_number);

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty byte code file.
 */
void swap(stack_t **stack, unsigned int line_number);

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty byte code file.
 */
void add(stack_t **stack, unsigned int line_number);

/**
 * is_numeric - Check if a string is a numeric value.
 * @str: String to check.
 * Return: 1 if numeric, 0 otherwise.
 */
int is_numeric(const char *str);

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty byte code file.
 */
void pall(stack_t **stack, unsigned int line_number);

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty byte code file.
 */
void pint(stack_t **stack, unsigned int line_number);

/**
 * execute_opcode - Executes the appropriate opcode.
 * @stack: Double pointer to the stack.
 * @line: Line containing the opcode from the Monty byte code file.
 * @line_number: Line number in the Monty byte code file.
 */
void execute_opcode(stack_t **stack, char *line, unsigned int line_number);

/**
 * free_stack - Frees the stack.
 * @stack: Double pointer to the stack.
 */
void free_stack(stack_t **stack);

#endif
