#include "monty.h"

/**
 * open_up - open a monty and validate input
 * @argc: args count
 * @filename: path to monty
 */
void open_up(int argc, char *filename)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty.file = fopen(filename, "r");
	if (!monty.file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * read_line - reads and executes each line of input from monty file
 */
void read_line(void)
{
	size_t len = 0;
	ssize_t read;
	char *opcode, *data;

	while ((read = getline(&monty.line, &len, monty.file)) != -1)
	{
		opcode = strtok(monty.line, " \t\n$");
		if (*opcode == '#' || *opcode == '\n')
		{
			monty.line_number++;
			continue;
		}
		else if (strcmp(opcode, "push") == 0)
		{
			data = strtok(NULL, " \n\t");
			if (monty.is_queue)
			{
				push_queue(data);
			}
			else
				push(data);
		}
		else
			op_choose(&monty.stack, opcode);
		monty.line_number++;
	}
}

/**
 * op_choose - find & call the function that corresponds with the opcode
 * @stack: **pointer to stack
 * @opcode: opcode from this line of our monty file
 */
void op_choose(stack_t **stack, char *opcode)
{
	int i;
	char *op;
	instruction_t fncs[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	op = strtok(opcode, "\n");
	for (i = 0; fncs[i].opcode; i++)
	{
		if (strcmp(op, fncs[i].opcode) == 0)
		{
			fncs[i].f(stack, monty.line_number);
			return;
		}
	}
	if (strcmp(opcode, "push"))
	{
		dprintf(STDERR_FILENO, "L%u: ", monty.line_number);
		dprintf(STDERR_FILENO, "unknown instruction %s\n", opcode);
	}
	else
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n"
				, monty.line_number);
	exit(EXIT_FAILURE);
}

/**
 * main- entry point
 * @argc: args count
 * @argv: args vector
 *
 * Return: EXIT_SUCCESS
 */
int main(int argc, char **argv)
{

	init_montyStruct();
	open_up(argc, argv[1]);
	read_line();
	free_it_all();
	return (EXIT_SUCCESS);
}

/**
 *  init_montyStruct - initialise the struct
 *
 *
 *
 */
void init_montyStruct(void)
{

	monty.file = NULL;
	monty.line = NULL;
	monty.stack = NULL;
	monty.line_number = 1;
	monty.is_queue = false;
}
