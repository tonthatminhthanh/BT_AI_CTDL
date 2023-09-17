#include <stdio.h>
#include <stdlib.h>
#define INP "inp.txt"

void print_arr(int* arr, int a_size) //in mang
{
    for(int i = 0;i < a_size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

/*
Dinh dang thong tin trong file inp.txt
3(so luong items) 50 (weight max)
60 (v1) 10 (w1)
100 (v2) 20 (w2)
120 (v3) 30 (w3)
*/
void input_arr(int* &v, int* &w, int &len, int &wMax, int* &cs) //Nhap cac mang cs, value, weight tu file inp.txt
{
    FILE* file = fopen(INP,"r");

    if(file != NULL)
    {
        fscanf(file,"%d", &len);
        fscanf(file,"%d", &wMax);
        v = (int*)malloc(sizeof(int)*len);
        w = (int*)malloc(sizeof(int)*len);
        cs = (int*)malloc(sizeof(int)*len);
        for(int i = 0;i < len;i++)
        {
            fscanf(file,"%d", &v[i]);
            fscanf(file,"%d", &w[i]);
            cs[i] = i;
        }
        fclose(file);
    }
    else
    {
        printf("Cannot open file!\n");
    }
}

void solve_knapsack(int* &cs, int* v, int* w, int len, int wMax) //Giai knapsack bang thuat toan heuristic tham lam, uu tien trong so v/w
{
    for(int i = 0;i < len;i++)
    {
        for(int j = i + 1;j < len;j++)
        {
            if(v[cs[i]]/w[cs[i]] < v[cs[j]]/w[cs[j]])
            {
                int temp = cs[i];
                cs[i] = cs[j];
                cs[j] = temp;
            }
        }
    }

    printf("\nResult:\n");
    int s_w = 0, s_v = 0, i = 0;
    while(s_w < wMax && i < len)
    {
        if(s_w + w[cs[i]] <= wMax)
        {
            s_w += w[cs[i]];
            s_v += v[cs[i]];
            printf("%d ",cs[i]);
        }
        i++;
    }

    printf("\nTotal value: %d\n",s_v);
    printf("Total weight: %d\n",s_w);
}

int main()
{
    int len, wMax;
    int* v, * w,* cs;

    input_arr(v,w,len,wMax,cs);
    print_arr(v,len);
    print_arr(w,len);
    print_arr(cs,len);
    solve_knapsack(cs,v,w,len,wMax);

    return 0;
}
