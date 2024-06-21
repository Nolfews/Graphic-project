/*
** EPITECH PROJECT, 2023
** linked_list_utils.c
** File description:
** utility functions used to manage linked lists
*/

#include "../include/main.h"

void push_to_list(linked_list_t **begin, void *data)
{
    linked_list_t *new_element = malloc(sizeof(linked_list_t));

    new_element->data = data;
    if (*begin == NULL)
        new_element->next = NULL;
    else
        new_element->next = *begin;
    *begin = new_element;
}

int get_linked_list_len(linked_list_t *first_node)
{
    linked_list_t *actual = first_node;
    int len = 0;

    while (actual != NULL) {
        actual = actual->next;
        len += 1;
    }
    return len;
}
