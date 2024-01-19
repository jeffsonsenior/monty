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

