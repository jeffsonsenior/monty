#include "monty.h"

/**
 *
 * -queue -sets the format of data to queue (FIFO/LILO)
 *  @doubly: head of the linked list (unused par)
 *  @cline: line number (unused par)
 */
void _queue(stack_t  **doubly, unsigned int cline)
{
	(void)doubly; /* suppress the unused par */
	(void)cline;

	vglo.lifo = 0;
}
/**
 * _stack - sets the format of data to stack (LIFO/FILO)
 * @doubly: linked list head had (unused par)
 * @cline: line number (unused par)
 */
void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 1; /*stack format*/
}
