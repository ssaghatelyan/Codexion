#include "../codexion.h"

int main(int argc, char** argv) {
	(void)argc;
	(void)argv;

	t_data data;

	if (args_parsing(argc, argv, &data) != 0) {
		printf("Error: Invalid arguments\n");
		return 1;
	}
	printf("Parsed arguments:\n");
	printf("Number of coders: %ld\n", data.number_of_coders);
	printf("Time to burnout: %ld\n", data.time_to_burnout);
	printf("Time to compile: %ld\n", data.time_to_compile);
	printf("Time to debug: %ld\n", data.time_to_debug);
	printf("Time to refactor: %ld\n", data.time_to_refactor);
	printf("Number of compiles required: %ld\n", data.number_of_compiles_required);
	printf("Dongle cooldown: %ld\n", data.dongle_cooldown);
	printf("Scheduler: %ld\n", data.scheduler);

	return 0;
}