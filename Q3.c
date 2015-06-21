#include<stdio.h>

void solveCase()
{
    int a_num,b_num;
    scanf("%d%d",&a_num,&b_num);
    int a[a_num],b[b_num];
    for(int i=0;i<a_num;i++)
        scanf("%d",(a+i));

    for(int i=0;i<b_num;i++)
        scanf("%d",(b+i));

    int index_a=0,index_b=0;
    while(index_a<a_num && index_b<b_num)
    {
        printf("%d ",(a[index_a]>b[index_b])?a[index_a++]:b[index_b++]);
    }
    if(index_a>=a_num)
       {
           while(index_b<b_num)
            printf("%d ", b[index_b++]);
       }
    else
        {
            while(index_a<a_num)
            printf("%d ", a[index_a++]);
        }
    printf("\n");
}


int main()
{
    int testCases;
    scanf("%d",&testCases);

    for(int i=1;i<=testCases;i++)
        solveCase();

    return 0;
}
