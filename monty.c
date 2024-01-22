#include "monty.h"

/*declaration of function pointer*/
void (*f)(stack_t **stack, unsigned int line_number);
global_t vglo;

/**
 * free_vlo - free the global variables
 *
 * releasing the memoy in connecction with global variables
 * the function free doubly linked list,buffer
 * then close the file descriptor.
 */
void free_vglo(void)
{
	free_dlistint(vglo.head);
	free(vglo.buffer);
	fclose(vglo.fd);
}
/**
 * start_vglo - initializing global variables.
 * the func set the initial values for global var in
 * the vglo structure,set default val, including the fd
 *
 *
 * @fd: file descriptorthat will be assigned to vglo.fd.
 */
void start_vglo(FILE *fd)
{
	vglo.lifo = 1; /*SET LIFO TO 1*/
	vglo.cont = 1; /* SET CONT TO 1*/
	vglo.arg = NULL; /*SET ARG TO NULL*/
	vglo.head = NULL; /*SET HEAD TO NULL*/
	vglo.fd = fd;  /* SET FD*/
	vglo.buffer = NULL; /*SET BUFFER TO NULL*/
}
/**
 * check_inpt - check if file exist and if can be opened.
 *
 * this func varifies cmd-line args ant try to open specific file
 * if succss it returns the pointer to file if not
 * return pointer to error messege
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct if file is sccssful opened
 */
FILE *check_inpt(int argc, char *argv[])
{
	FILE *fd
		;
	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/**
 * main - entry point of monty program
 * this is the main entry of monty interpretor.
 * it process cmd_l args,openr specific file,
 * initialize global var,read and execute cmd from files
 * and frees allocated memry then exit
 *
 * @argc: arguments count
 * @argv: arguments vectors
 * Return: 0 on successful.
 */
int main(int argc, char *argv[])
{
	FILE *fd;

	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_inpt(argc, argv); /* validate and open input file */
	start_vglo(fd);
	nlines = getline(&vglo.buffer, &size, fd);

	while (nlines != -1)
	{
		lines[0] = _strtoky(vglo.buffer, "\t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", vglo.cont);
				dprintf(2, "unknown intruction %s\n", lines[0]);
				free_vglo();
				exit(EXIT_FAILURE);
			}
			vglo.arg = _strtoky(NULL, "\t\n");
			f(&vglo.head, vglo.cont);
		}
		nlines = getline(&vglo.buffer, &size, fd);
		vglo.cont++;
	}
	free_vglo();
	return (0);
}




