#include "../codexion.h"

int init_coders(t_data *data) {
	int i;

	data->coders = malloc(sizeof(t_coder) * data->number_of_coders);
	if (!data->coders)
		return (1);
	i = 0;
	while (i < data->number_of_coders) {
		data->coders[i].id = i + 1;
		data->coders[i].compiole_count = 0;
		data->coders[i].last_compile_time = 0;
		data->coders[i].left_dongle = NULL;
		data->coders[i].right_dongle = NULL;
		i++;
	}
	return (0);
}

int	init_dongles(t_data *data) {
	int	i;
	data->dongles = malloc(sizeof(t_dongle) * data->number_of_coders);
	if (!data->dongles)
		return (1);
	i = 0;
	while (i < data->number_of_coders) {
		if (pthread_mutex_init(&data->dongles[i].mutex, NULL) != 0) {
			while (i > 0) {
				i--;
				pthread_mutex_destroy(&data->dongles[i].mutex);
			}
			free(data->dongles);
			data->dongles = NULL;
			return (1);
		}
		data->dongles[i].last_release = 0;
		i++;
	}
	return (0);
}

void	assign_dongles(t_data *data) {
	int	i;
	int	n;

	i = 0;
	n = data->number_of_coders;
	while (i < n) {
		data->coders[i].left_dongle = &data->dongles[i];
		data->coders[i].right_dongle = &data->dongles[(i + 1) % n];
		i++;
	}
}