#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

struct Node
{
    char value;
    Node* next;
    Node* parent;
};

void print_list(Node* node) //in danh sach lien ket
{
    Node* temp = node;
    while(temp != NULL)
    {
        if(temp->next == NULL)
        {
            printf("%c",temp->value);
        }
        else
        {
            printf("%c, ",temp->value);
        }
        temp = temp->next;
    }
    printf("\n");
}

void add_front(Node* &node, char val) //them vao truoc
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = val;
    temp->next = node;
    node = temp;
}

void add_back(Node* &node, char val) //them vao sau
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = NULL;

    if(node == NULL)
    {
        add_front(node,val);
        return;
    }
    Node* temp = node;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

char pop(Node* &node) //xoa va tra gia tri cua node
{
    Node* temp = node;
    char result = node->value;
    node = node->next;
    free(temp);
    return result;
}

int exists(Node* node, char val) //kiem tra co node nao co gia tri val hay ko
{
    Node* temp = node;
    while(temp != NULL)
    {
        if(temp->value == val)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
