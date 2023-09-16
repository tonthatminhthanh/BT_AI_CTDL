#include <stdio.h>
#include <stdlib.h>
#define INPUT "inp.txt" //file nhap ma tran, co the de dang thay doi nha!

void print_arr(int* arr, int a_size) //in mang
{
    for(int i = 0;i < a_size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void print_matrix(int v_count, int** matrix) //in ma tran
{
    printf("Vertices count: %d, adjacency matrix: \n", v_count);
    for(int i = 0;i < v_count;i++)
    {
        for(int j = 0;j < v_count;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void init_arr(int* &arr, int size, int val) //khoi lap mang voi cac gia tri mac dinh val
{
    arr = (int*)malloc(sizeof(int)*size);
    for(int i = 0;i < size;i++)
    {
        arr[i] = val;
    }
}

int input_matrix(char file_name[], int &v_count, int** &matrix) //nhap ma tran qua file
{
    FILE* file = fopen(file_name,"r");

    if(file == NULL)
    {
        printf("Cannot load file!\n");
        return -1;
    }
    //printf("Adjacency matrix has %d vertices!\n");
    fscanf(file,"%d\n",&v_count);
    matrix = (int**)malloc(sizeof(int*)*v_count);
    for(int i = 0;i < v_count;i++)
    {
        int* row = (int*)malloc(sizeof(int)*v_count);
        for(int j = 0;j < v_count;j++)
        {
            fscanf(file,"%d ",&row[j]);
        }
        matrix[i] = row;
    }
    return 0;
}

void get_deg(int** matrix, int v_count, int* &deg) //Lay array bac cac dinh trong do thi
{
    deg = (int*)malloc(sizeof(int)*v_count);
    for(int i = 0;i < v_count;i++)
    {
        int s = 0;
        for(int j = 0;j < v_count;j++)
        {
            s += matrix[i][j];
        }
        deg[i] = s;
    }
}

void coloring(int** matrix, int* deg, int v_count, int* &color) //Ham to mau do thi
{
    int ordered_v[v_count];

    for(int i = 0;i < v_count;i++)
    {
        ordered_v[i] = i;
    }
    //Thuat toan bubble sort, nen thay bang thuat toan sap xep khac neu ma tran rat lon
    //Sap xep cac dinh theo so bac giam dan
    for(int i = 0;i < v_count;i++)
    {
        for(int j = i + 1;j < v_count;j++)
        {
            if(deg[ordered_v[i]] < deg[ordered_v[j]])
            {
                int t = ordered_v[i];
                ordered_v[i] = ordered_v[j];
                ordered_v[j] = t;
            }
        }
    }

    printf("Verticies sorted accordingly to degrees:\n");
    print_arr(ordered_v, v_count);

    init_arr(color,v_count,-1);

    int sac_so = 1; //sac so khoi dau

    //Thuat toan Welsh-Powell 1967
    for(int i = 0;i < v_count;i++)
    {
        if(color[ordered_v[i]] == -1)
        {
            color[ordered_v[i]] = sac_so;
            for(int j = i + 1;j < v_count;j++)
            {
                if(matrix[ordered_v[i]][ordered_v[j]] != 1 && color[ordered_v[j]] == -1)
                {
                    color[ordered_v[j]] = sac_so;
                }
            }
            sac_so++;
        }
    }
    //in mau cua cac dinh trong do thi
    printf("Colors of each vertex (0 -> v_count):\n");
    print_arr(color,v_count);
}

int main()
{
    int v_count;
    int** matrix;
    int* deg;
    int* color;

    if(input_matrix(INPUT,v_count,matrix) == -1)
    {
        return -1;
    }


    print_matrix(v_count,matrix);
    printf("Degrees of each verticies (0 -> v_count):\n");
    get_deg(matrix,v_count,deg);
    print_arr(deg,v_count);
    coloring(matrix,deg,v_count,color);
}
