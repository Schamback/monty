#include "monty.h"

/**
 * custom_push - adds a new node to the top of stack
 * @custom_stack: pointer to the head node pointer of stack
 * @line_num: the line number
 *
 * Return: Nothing.
 */
void custom_push(custom_stack_t **custom_stack, unsigned int line_num)
{
	custom_stack_t *new_node;

	if (custom_stack == NULL)
	{
		fprintf(stderr, "Line %d: custom_stack not found\n", line_num);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(custom_stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_custom_stack(custom_stack);
		exit(EXIT_FAILURE);
	}

	new_node->next = *custom_stack;
	new_node->prev = NULL;
	new_node->data = custom_arg.custom_data;
	if (*custom_stack)
		(*custom_stack)->prev = new_node;
	*custom_stack = new_node;
}

/**
 * custom_print_all - prints the data of all nodes in custom_stack
 * @custom_stack: pointer to the head node pointer of custom_stack
 * @line_num: the line number
 *
 * Return: Nothing.
 */
void custom_print_all(custom_stack_t **custom_stack, unsigned int line_num)
{
	custom_stack_t *temp;
	(void)line_num;

	temp = *custom_stack;
	while (temp)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

/**
 * free_custom_stack - frees all nodes in a custom_stack
 * @custom_stack: pointer to the head node pointer of custom_stack
 *
 * Return: Nothing.
 */
void free_custom_stack(custom_stack_t **custom_stack)
{
	custom_stack_t *temp = NULL;

	if (custom_stack == NULL || *custom_stack == NULL)
		return;

	while (*custom_stack != NULL)
	{
		temp = (*custom_stack)->next;
		free(*custom_stack);
		*custom_stack = temp;
	}
}

/**
 * custom_nop - does literally nothing
 * @custom_stack: pointer to the head node pointer of custom_stack
 * @line_num: the line number
 * Return: Nothing.
 */
void custom_nop(custom_stack_t **custom_stack, unsigned int line_num)
{
	(void)custom_stack;
	(void)line_num;
}

/**
 * custom_is_alpha - checks if int is in alphabet
 * @ch: int
 * Return: 1 if yes, 0 if no
 */
int custom_is_alpha(int ch)
{
	if (((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')))
		return (1);
	else
		return (0);
}
