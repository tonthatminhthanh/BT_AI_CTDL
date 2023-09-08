#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.hpp"
#include "graph.hpp"

void dfs(int** graph, int n, char start, char dest)
{
    Node* open = NULL; //Danh sach lien ket cua cac dinh trong queue cho xu ly
    Node* close = NULL; //Danh sach lien ket cac dinh da duyet
    Node* path = NULL;
    add_front(open,start); //Them dinh bat dau vao open

    while(open != NULL) //Lap cho den khi danh sach lien ket open trong
    {
         //Lay gia tri cua dinh dang xet

        if(open->value == dest) //Kiem tra dinh dang xet la dinh dich
        {
            printf("True!\n");
            print_path(open);
            return;
        }
        char current = pop(open);
        int vertex = current - 'A'; //Chuyen ky tu dac trung cho dinh thanh so

        for(int i = 0;i < n;i++)
        {
            if(graph[vertex][i] == 1 && exists(open,i + 'A') != 1)
            {
                add_front(open,i + 'A');//them cac dinh lang gieng cua dinh dang duoc xu ly vao queue open
            }
        }
        add_back(close,current); //them dinh da xet vao danh sach close
    }
    printf("False!\n");
}

int main()
{
    int n;
    printf("Nhap so dinh trong phan tu: ");
    scanf("%d",&n);
    int** graph = CreateGraph(n);
    char c_start, c_dest;
    printf("Nhap dinh bat dau (Viet hoa): ");
    scanf("%c",&c_start);
    fflush(stdin);
    printf("Nhap dinh ket thuc (Viet hoa): ");
    scanf("%c",&c_dest);
    dfs(graph,n,c_start,c_dest);

    return 0;
}
