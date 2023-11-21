#include "sort.h"

/**
 * swap - Swaps two nodes in a doubly linked list.
 * @head: The head of the list.
 * @node1: The first node to be swapped.
 * @node2: The second node to be swapped.
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
    listint_t *prev, *next;

    prev = node1->prev;
    next = node2->next;

    if (prev != NULL)
        prev->next = node2;
    else
        *head = node2;

    node1->prev = node2;
    node1->next = next;
    node2->prev = prev;
    node2->next = node1;

    if (next)
        next->prev = node1;
}

/**
 * cocktail_sort_list - Sorts a list using the cocktail sort algorithm.
 * @list: The list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *current;
    int swapped = 0;

    if (!list || !*list || !(*list)->next)
        return;

    do {
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                print_list(*list);
                swapped = 1;
                current = current->prev;
            }
        }

        if (swapped == 0)
            break;

        swapped = 0;

        for (; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                print_list(*list);
                swapped = 1;
                current = current->next;
            }
        }
    } while (swapped == 1);
}
