#include "../codexion.h"

static long	ft_atol(const char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > 2147483647)
			return (-1);
		i++;
	}
	return (res);
}

static int	is_valid_num(const char* str) {
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	args_parsing(int argc, char **argv, t_data *data) {
	if (argc != 9)
		return(1);
	if (!is_valid_num(argv[1]) || !is_valid_num(argv[2])
		|| !is_valid_num(argv[3]) || !is_valid_num(argv[4])
		|| !is_valid_num(argv[5]) || !is_valid_num(argv[6])
		|| !is_valid_num(argv[7]))
		return (1);
	if (!strcmp(argv[8], "fifo"))
		data->scheduler = 0;
	else if (!strcmp(argv[8], "edf"))
		data->scheduler = 1;
	else
		return (1);
	data->number_of_coders = ft_atol(argv[1]);
	data->time_to_burnout = ft_atol(argv[2]);
	data->time_to_compile = ft_atol(argv[3]);
	data->time_to_debug = ft_atol(argv[4]);
	data->time_to_refactor = ft_atol(argv[5]);
	data->number_of_compiles_required = ft_atol(argv[6]);
	data->dongle_cooldown = ft_atol(argv[7]);
	return (0);
}