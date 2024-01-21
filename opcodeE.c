#include "monty.h"

/**
 * _rot1 - rote first element to bottom and
 * second to top
 * @doubly: the head of linked list
 * @cline: the line number
 *
 * Return:
 */

void _rot1(stack_t **doubly, unsigned int cline)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;
	if ((*doubly)->next == NULL)
		return;

	aux1 = (*doubly)->next;
	aux2 = *doubly;

	for (; aux2->next != NULL; aux2 = aux2->next)
	       ;
	aux1->prev = NULL;
	aux2->next = *doubly;
	(*doubly)->next = NULL;
	(*doubly)->prev = aux2;
	*doublt = aux1;
}

/**
 * _rotr - reverse stack
 * @doubly: linked list head
 * @cline: line number
 * Return:
 */

void _rotr(stack_t **doubly, unsigned int cline)
{
	stack_t *aux = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next != NULL; aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *doubly;
	aux->prev = NULL;
	*doubly = aux;
}







