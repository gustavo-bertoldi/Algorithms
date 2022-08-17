#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct ListNode
{
    TreeNode *value;
    struct ListNode *next;
} ListNode;

void push(ListNode **head, TreeNode* val) {
    ListNode* new_element = (ListNode*)malloc(sizeof(ListNode));
    new_element -> value = val;
    new_element -> next = NULL;
    if (*head == NULL) {
        *head = new_element;
    } else {
        ListNode *current = *head;
        while (current -> next != NULL) current = current -> next;
        current -> next = new_element;
    }
}

TreeNode* pop(ListNode **head) {
    if (*head == NULL) return NULL;
    else {
        TreeNode *tmp = (*head) -> value;
        if ((*head) -> next == NULL) {
            *head = NULL;
        } else {
            *head = (*head) -> next;
        }
        return tmp;
    }
}

int is_empty(ListNode *head) {
    return head == NULL;
}

void breadth_search(TreeNode *root) {
    ListNode *queue = (ListNode*)malloc(sizeof(ListNode));
    push(&queue, root);
    while (!is_empty(queue)) {
        TreeNode *current = pop(&queue);
        printf("%d ", current -> value);
        if (current -> left != NULL) push(&queue, current -> left);
        if (current -> right != NULL) push(&queue, current -> right);
    }
}

int main() {
        printf("sfsd");
    TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
    root -> value = 0;
    root -> left = NULL;
    root -> right = NULL;
    breadth_search(root);
}