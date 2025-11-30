#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "../inc/data.h"

void	fill_data(int argc, char **argv, t_data *data)
{
	size_t	i;

	data->hostname = argv[1];
	i = 2;
	while (i < (size_t)argc)
	{
		if (argv[i] && (strcmp(argv[i], "-?") == 0 ||  strcmp(argv[i], "-v")  == 0))
		{
			data->flags.has_packets_errors = true;
			break;
		}
		i ++;
	}
}

void	display_executable();

void	manage_inputs(int argc, char **argv, t_data *data)
{
	if (argc == 1) {
		display_executable();
		exit(EXIT_FAILURE);
	}
	fill_data(argc, argv, data);
}
