#ifndef CODEXION_H
#define CODEXION_H

#include <stdio.h>
#include <string.h>

typedef struct data {
	long	number_of_coders;
	long	time_to_burnout;
	long	time_to_compile;
	long 	time_to_debug;
	long	time_to_refactor;
	long	number_of_compiles_required;
	long	dongle_cooldown;
	long	scheduler;
}	t_data;

int	args_parsing(int argc, char **argv, t_data *data);

#endif