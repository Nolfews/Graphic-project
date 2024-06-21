/*
** EPITECH PROJECT, 2024
** paint
** File description:
** analyses the arguments of the prgram
*/

#include "../include/main.h"

static sfBool check_file(char const *filepath)
{
    FILE *file = fopen(filepath, "r");

    if (file == NULL) {
        write(2, "Can't open the file\n", 21);
        return sfFalse;
    }
    return sfTrue;
}

sfBool parse_args(int argc, char const **args)
{
    if (argc == 1)
        return sfTrue;
    if (argc == 2) {
        if (!my_strcmp(args[1], "-h"))
            return sfTrue;
        return check_file(args[1]);
    }
    write(2, "bad arguments\n", 15);
    return sfFalse;
}
