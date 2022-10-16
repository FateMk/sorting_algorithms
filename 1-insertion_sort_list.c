#include "sort.h"

/**
 * sorted_insert - insert elements into a sorted list
 * 
 * @list: pointer to the list 
 * @new_node: node to be inserted
 * Return:sorted list 
 */
void sorted_insert(listint_t **list, listint_t *new_node)
{
    listint_t *head;

    if (*list == NULL)
    {
        *list = new_node;
    }
    else if ((*list)->n >= new_node->n)
    {
        new_node->next = *list;
        new_node->next->prev = new_node;
        *list = new_node;
    }
    else{
        head = *list;
        while (head->next != NULL && head->next->n < new_node->n)  
           head = head->next;
        new_node->next = head->next;
        if (head->next != NULL)
        {
            new_node->next->prev = new_node;
        }
        head->next = new_node;
        new_node->prev = head; 
    }
}

/**
 * insertion_sort_list - sorts a doubly linked list of integer in ascending order
 * @list: pointer  to the linked list
 * Return: sorted list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current; 
    listint_t*sorted = NULL;

    listint_t *head = *list;
    print_list(*list);
    while (head != NULL)
    {
        current = head->next;
        head->prev = head->next = NULL;
        sorted_insert(&sorted, head);
        head = current;
    }
    *list = sorted;
    
}
