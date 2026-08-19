#include "../codexion.h"

int    main(int argc, char **argv)
{
    t_data    data;

    if (args_parsing(argc, argv, &data) != 0)
    {
        printf("Error\n");
        return (1);
    }
    if (init_coders(&data) != 0)
        return (1);
    if (init_dongles(&data) != 0)
    {
        free(data.coders);
        return (1);
    }
    assign_dongles(&data);

    printf("Coder 1 left  = %p\n", (void *)data.coders[0].left_dongle);
    printf("Coder 1 right = %p\n", (void *)data.coders[0].right_dongle);

    return (0);
}