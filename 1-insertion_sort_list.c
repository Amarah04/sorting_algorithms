#include "sort.h"

void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2);

/**
 * insertion_sort_list - Sorts a doubly linked list using
 *                       the insertion sort algorithm.
 * @list: The list to be sorted.
 *
 * Return: Void.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (current = (*list)->next; current && current->prev; current = current->next)
    {
        for (; current && current->prev && current->n < current->prev->n;
             current = current->prev)
        {
            temp = current->prev;
            swap_nodes(list, temp, current);
            print_list(*list);
            current = current->next;
        }
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @head: The head node of the list.
 * @node1: The first node to be swapped.
 * @node2: The second node to be swapped.
 *
 * Return: Void.
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
    listint_t *prev_node1, *next_node2;

    prev_node1 = node1->prev;
    next_node2 = node2->next;

    if (prev_node1 != NULL)
        prev_node1->next = node2;
    else
        *head = node2;

    node1->prev = node2;
    node1->next = next_node2;
    node2->prev = prev_node1;
    node2->next = node1;

    if (next_node2)
        next_node2->prev = node1;
}
