#include "monty.h"
/**
 * _add - adding the top 2 val of a stack_t linked list.
 * @doubly: head of the linked list.
 * @cline: line number.
 *
 * info: result is stored in to be stored in the 2nd val node.
 * the top and the top value is removed.
 *
 */
void _add(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;
	if (m <2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next;
	aux->n += (*doubly) ->n;
	_pop(doubly,cline);
}

/**
 * _nop - dnt do anything
 * @doubly:link head on the list
 * @cline: line nmbr
 *
 */
void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}

/**
 * _sub - sub secound val from top of staack_t linked list by top val
 * @head: head node
 * @cline: line number
 * info: result is stored in the 2nd val node
 * from the top and top val is remvd
 *
 */
void _sub(stack_t **head, unsigned int cline)
{
	int m = 0;
	stack_t *current;
	current = *head;

	for (; current != NULL; current = current->next, m++)
		;
	if (m < 2)
	{
		dprintf(2, "L%u: can't substract,stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	current = (*head)->next;
	current->n -= (*head)->n;
	_pop(head, cline);
}

/**
 * _div - divide second val from the top of stack_t linkedlist by the top val
 * @doubly: head of the linked list
 * @cline: line number
 *
 * Return: no val
 */
void _div(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;
	if (m < 2)
	{
		dprintf(2, "L%u: can't divide, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next;
	aux->n /= (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _mul - multiply second val from top of stack_t linked list by top val.
 * @head: head node
 * @cline : line number
 * description: result will be stored on the second val node
 * from the top,the top val wil be removed
 *
 */
void _mul(stack_t **head, unsigned int cline)
{
	int m = 0;
	stack_t *current;

	current = *head;

	for (; current != NULL; current = current->next, m++)
		;
	if (m < 2)
	{
		dprintf(2, "L%u: can't multiply, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	current = (*head)-> next;
	current->n *= (*head)->n;
	_pop(head,cline);
}

