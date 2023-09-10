#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.hpp"
#include "graph.hpp"

void print_rev(Node* node) //in nguoc lai
{
    if(node->next != NULL)
        print_rev(node->next);
    printf("%c",node->value);
}

void dfs_path(int** graph, int* visited, char vertex, char dest, int n, Node* &path)
{
    int v = vertex - 'A'; //so tuong trung cho dinh hien tai vd: 'B' - 'A' = 1
    visited[v] = 1;

    if(vertex == dest) //neu dinh dang xet la dinh dich thi them dinh dich vao danh sach path
    {
        add_back(path,dest);
        printf("Path found: ");
        return;
    }

    for(int i = 0;i < n;i++)
    {
        if(graph[v][i] == 1 && visited[i] != 1)
        {
            dfs_path(graph, visited, i + 'A', dest, n, path);
            if(path != NULL && exists(path,vertex) != 1) //neu da tim duoc duong di thi quay lui va them cac dinh dan toi dinh dich
            {
                add_back(path,vertex);
            }
        }
    }
}

int main()
{
    int n;
    printf("Nhap so dinh trong phan tu: ");
    scanf("%d",&n);
    int** graph = CreateGraph(n);
    int* visited = (int*)malloc(sizeof(int)*n);
    Node* path = NULL;

    for(int i = 0;i < n;i++)
    {
        visited[i] = 0;
    }

    char c_start, c_dest;
    printf("Nhap dinh bat dau (Viet hoa): ");
    scanf("%c",&c_start);
    fflush(stdin);
    printf("Nhap dinh ket thuc (Viet hoa): ");
    scanf("%c",&c_dest);
    dfs_path(graph,visited,c_start,c_dest,n,path);
    print_rev(path);
    printf("\n");

    return 0;
}
