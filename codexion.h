#ifndef CODEXION_H
#define CODEXION_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct dongle t_dongle;
typedef struct coder t_coder;

typedef struct data {
	long			number_of_coders;
	long			time_to_burnout;
	long			time_to_compile;
	long 			time_to_debug;
	long			time_to_refactor;
	long			number_of_compiles_required;
	long			dongle_cooldown;
	long			scheduler;
	long			start_time;
	t_coder			*coders;
	t_dongle		*dongles;
	pthread_mutex_t	print_mutex;
}	t_data;

typedef struct dongle {
	pthread_mutex_t	mutex;
	long			last_release;
}	t_dongle;

typedef struct coder {
	int			id;
	int			compiole_count;
	long		last_compile_time;
	pthread_t	thread;
	t_dongle	*left_dongle;
	t_dongle	*right_dongle;
}	t_coder;


int		args_parsing(int argc, char **argv, t_data *data);
int 	init_coders(t_data *data);
int		init_dongles(t_data *data);
void	assign_dongles(t_data *data);

#endif