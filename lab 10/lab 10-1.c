#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node* head = NULL;

void add_to_end(int num) {
    node* p = head;

    if (p == NULL) {
        p = (node*)malloc(sizeof(node));
        p->data = num;
        p->next = NULL;
        head = p;
    } else {
        while (p->next != NULL) {
            p = p->next;
        }

        node* snl = (node*)malloc(sizeof(node));
        snl->data = num;
        snl->next = NULL;
        p->next = snl;
    }
}

void add_to_front(int num) {
    node* p = head;
    node* snl = NULL;

    if (p == NULL) {
        p = (node*)malloc(sizeof(node));
        p->data = num;
        p->next = NULL;
        head = p;
    } else {
        snl = (node*)malloc(sizeof(node));
        snl->data = num;
        snl->next = p;
        head = snl;
    }
}

void print_list() {
    int ct = 0;
    node* p;
    p = head;
    while (p != NULL) {
        printf("%d. node's value: %d\n", ct + 1, p->data);
        p = p->next;
    }
}

int main() {
    struct Node* head = NULL;
    int num;

    printf("Enter numbers (program terminates when -1 is entered):\n");

    while (1) {
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        if (num % 2 == 0) {
            add_to_end(num);
        } else {
            add_to_front(num);
        }
    }

    printf("List: <---------------------------->\n");
    print_list();

    return 0;
}

