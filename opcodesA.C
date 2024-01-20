#include "monty.h"
/**
 * _push - pushes an element to the stack
 *
 * @doubly: head of linked list representing thr stack.
 * @cline: line number in the source code where function is called
 *
 * Return: no return value
 */
void _push(stack_t **doubly, unsigned int cline)
{
	int n,j;
	if (!vglo.arg)
	{
		dprintf(2, "L%u:", cline);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	for (j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '_')
		{
			dprintf(2, "L%u: ", cline);
			dprint(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}
/**
 * _pall - print all the val on the stack
 *
 * @doubly: head of linked list representing the stack.
 * @cline: line number
 * Return: no return value(void)
 */
void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux)
	{
		printf("%\n"; aux ->n);
		aux = aux -> next;
	}
}
void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%U: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*doubly)->n);
}
/**
 * _pop - remove the top element of the stack
 *
 * @doubly: head of the linked list (pointer to pointer)
 * @cline: line number
 *
 * Return: no retur
 */
void _pop(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	if(doubly == NULL || *doubly = NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}
/**
 * _swap - swaps the top two elements of the stack
 *
 * @doubly: head of the linked list (pointer to pointer)
 * @cline: line number
 * Return: no return
 */
void _swap(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t;

	for (aux = *doubly; aux != NULL; aux = aux->next, m++);

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly =(*doubly) ->next;

	aux->next = (*doubly)-next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}



