#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode
{
    int value;
    struct ListNode *next;
} ListNode;

void insert_beginning(ListNode **head, int val)
{
    ListNode *new_head = (ListNode *)malloc(sizeof(ListNode));
    new_head->value = val;
    new_head->next = *head;
    *head = new_head;
}

void insert_end(ListNode **head, int val)
{
    ListNode *new_tail = (ListNode *)malloc(sizeof(ListNode));
    new_tail->next = NULL;
    new_tail->value = val;

    if (*head == NULL)
    {
        *head = new_tail;
    }
    else
    {
        ListNode *current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = new_tail;
    }
}

int insert_index(ListNode **head, int val, unsigned int idx)
{
    if (idx == 0)
    {
        insert_beginning(head, val);
    }
    else
    {
        ListNode *new_element = (ListNode *)malloc(sizeof(ListNode));
        new_element->value = val;
        unsigned int c_idx = 0;
        ListNode *current = *head;
        while (current != NULL && c_idx != idx)
        {
            if (c_idx + 1 == idx)
            {
                if (current->next == NULL)
                {
                    current->next = new_element;
                    new_element->next = NULL;
                }
                else
                {
                    new_element->next = current->next;
                    current->next = new_element;
                }
            }
            c_idx++;
            current = current->next;
        }
        if (current == NULL)
            return -1;
    }
    return 0;
}

int remove_first_occurrence(ListNode **head, int val)
{
    ListNode *current = *head;
    if (current->next == NULL)
    {
        if (current->value == val)
        {
            free(*head);
            *head = NULL;
        }
        else
            return -1;
    }
    else if (current->value == val)
    {
        ListNode *tmp = current;
        current = current->next;
        free(current);
    }
    else
    {
        while (current->next != NULL && current->next->value != val)
            current = current->next;

        if (current->next == NULL)
            return -1;
        else
        {
            ListNode *tmp = current->next;
            current->next = current->next->next;
            free(tmp);
        }
    }
    return 0;
}

int remove_all_occurrences(ListNode **head, int val)
{
    ListNode *current = *head;
    if (current->next == NULL)
    {
        if (current->value == val)
        {
            free(*head);
            *head = NULL;
        }
        else
            return 0;
    }
    int removed = 0;
    while (current->next != NULL)
    {
        if (current->next->value == val)
        {
            removed++;
            ListNode *tmp = current->next;
            current->next = current->next->next;
            free(tmp);
        }
        current = current->next;
    }
    return removed;
}

int remove_first(ListNode **head) {
    ListNode *current = *head;
    int value = -1;

    if (current == NULL) return -1;
    else if (current -> next == NULL) {
        value = current -> value;
        free(current);
        *head = NULL;
    } else {
        while (current -> next -> next != NULL) 
            current = current -> next;
    
        value = current -> next -> value;
        free(current -> next);
        current -> next = NULL;
    }
    return value;
}

void print_list(ListNode *head)
{
    ListNode *current = head;
    printf("[");
    while (current != NULL)
    {
        printf("%d", current->value);
        if (current->next != NULL)
            printf(", ");
        current = current->next;
    }
    printf("]\n");
}

int main()
{
    const int size = 5;
    ListNode *list_head = NULL;
    for (int i = 0; i < size; i++)
    {
        insert_end(&list_head, rand() % 100);
    }
    for (int i = 0; i < size; i++)
    {
        insert_beginning(&list_head, rand() % 100);
    }
    for (int i = size; i < 2 * size; i++)
    {
        insert_index(&list_head, 10, i);
    }
    for (int i = 0; i < size; i++)
    {
        remove_first(&list_head);
    }
    print_list(list_head);
}
