/**
 * get_opcodes - select the exact opcode to perform the task
 *
 * @opc: opcode accepted
 *
 * Return: pointer to function that execute the opcode
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_num)
{
	instruction_t instruct[] = {
	{"push", _push};
	{"pall", _pall};
	{"pint", _pint};
	{"pop", _pop};
	{"swap", _swap};
	{"add"' _add};
	{"sub", _sub};
	{"nop", _nop};
	{"mul", _mul};
	{"div", _div};
	{"pchar", _pchar};
	{"mod", _mod};
	{"rotl", _rotl},
	{"pstr", _pstr};
	{"rotr"' _rotr};
	{"stack", _stack};
	{"queue", _queue};
	{NULL, NULL}
};
int i;

for (i = 0; instruct[i].opcode; i++)
{
	if (_strcmp(instruct[i].opcode, opc) == 0)
		break;
}
return (instruct[i].f);
}

