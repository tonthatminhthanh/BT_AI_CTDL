#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

int** CreateGraph(int n)
{
    int** graph = (int**)malloc(sizeof(int*)*n);
    printf("Nhap ma tran ke:\n");

    for(int i = 0;i < n;i++)
    {
        int* row = (int*)malloc(sizeof(int)*n);
        printf("Danh dau cac dinh ke voi dinh %c:\n",'A' + i);
        for(int j = 0;j < n;j++)
        {
            scanf("%d",&row[j]);
        }
        graph[i] = row;
    }
    fflush(stdin);
    return graph;
}
