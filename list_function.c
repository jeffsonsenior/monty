#include "monty.h"

/**
 * add_dnodeint_end - Adds a node at the end of the doubly linked list.
 * @head: pointer to the first node of the linked list.
 * @n: data to store i the new  node.
 *
 * Return: A pointer to the updated doubly linked list.
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *temp, *aux;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	if (*head == NULL)
	{
	temp->next = *head;
	temp->prev = NULL;
	*head = temp;
	return (*head);
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	temp->next = aux->next;
	temp->prev = aux;
	aux->next = temp;
	return (aux->next);
}

/**
 * add_dnodeint - Adds a node at the beggining of the doubly linked list.
 * @head: pointer to the first node of the linked list
 * @n: data to store in the new node.
 *
 * Return: a pointer to the updated doubly linked list.
 *
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;

		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}
/**
 * free_dlistint - Frees the memory allocated for doubly linked list.
 * @head: pointer to the first node of the linked list
 *
 * Return: no return value
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}
