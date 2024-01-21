#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <string.h>


extern global_t vglo;

/*opcodes */
void _push(stack_t **stack, unsigned int line_numb);
void _pall(stack_t **stack, unsigned int line_numb);
void _pop(stack_t **doubly, unsigned int cline);
void _pint(stack_t **doubly, unsigned int cline);
void _rotr(stack_t **doubly, unsigned int cline);
void _swap(stack_t **doubly, unsigned int cline);
void _rot1(stack_t **doubly, unsigned int cline);
void _queue(stack_t **doubly, unsigned int cline);
void _pstr(stack_t **doubly, unsigned int cline);
void _stack(stack_t **doubly, unsigned int cline);
void _pchar(stack_t **doubly, unsigned int cline);
void _add(stack_t **doubly, unsigned int cline);
void _mod(stack_t **doubly, unsigned int cline);
void _nop(stack_t **doubly, unsigned int cline);
void _mul(stack_t **doubly, unsigned int cline);
void _sub(stack_t **doubly, unsigned int cline);
void _div(stack_t **doubly, unsigned int cline);

/* get_function */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_num);

/*list fuction */
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stock_t *head);

/* main */
void free_vglo(void);

/* other functions-imp */
int _sch(char *s, char c);
char *_strtoky(char *s, char *d);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/**
 * struct stack_s - doubly linked representation of a stack(or queue)
 * @n: integer value stored in the node
 * @prev: pointer to previous elements in a  stack(or queue)
 * @next: pointer to the next element in stack(or queue)
 * description: doubly linked list node structure
 * for stack, queue,LIFO,FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;

	sruct stack_s *next;
} stack_t;

/**
 * struct globals - global structure to use in funcctions
 * @lifo: flag indicating if its stack or queue
 * @cont: current line number
 * @arg: 2nd parameter inside the current line
 * @head: pointer to doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 * description: structure holding global variables
 * for stack, queue, LIFO,FIFO
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char *arg;
	strack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct bus_s - varriable to carry value through the program
 * @arg: value
 * @file:pointer to monty file
 * @content: line content
 * @lifi: flag indicating changes btwn stack and queue
 * description: struct carrying values through the prog
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;

extern bus_t bus;

/**
 * struct instruction_s - opcode and its corresponding func
 * @opcode: operation code
 * @f: function to hundle opcode
 * description: opcode (operation code)
 * for stack,queue,LIFO,FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


#endif


