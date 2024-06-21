/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "header.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

void aff_info(void)
{
    int fd = open("info_game.txt", O_RDONLY);
    char *buf;
    int size = 305;

    buf = malloc(sizeof(char) * 4096);
    read(fd, buf, size);
    buf[size] = '\0';
    for (int i = 0; i <= my_strlen(buf); i++) {
        my_putchar(buf[i]);
    }
    my_putchar('\n');
}

int main(int ac, char **av)
{
    if (ac > 2)
        return (84);
    if (ac == 2 && my_strlen(av[1]) == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            aff_info();
        } else {
            return (84);
        }
    }
    if (ac == 1)
        open_window();
    return (0);
}
