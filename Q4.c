#include<stdio.h>

int partition(int *list, int lower, int upper)
{
    int pivotValue = list[lower];
    int temp=0, i,j;
    for(i=lower+1, j= lower+1;(i<=upper &&  j<=upper) ;)
    {
        while(list[i]<=pivotValue && i<=upper)
        {
            //find next value which is greater than pivotValue
            ++i;
        }
        j=i;
        while(list[j]>=pivotValue && j<= upper)
            {
                ++j;
            }
        if(i>upper || j>upper) {break;}

        temp = list[i];
        list[i]=list[j];
        list[j]=temp;
        ++i;
        ++j;
    }
    i--;
    temp= list[i];
    list[i]=pivotValue;
    list[lower]= temp;
    return i;
}

void QuickSort(int * list, int lower, int upper)
{
    if(lower >= upper)
        return;
    int pivot=partition(list, lower, upper);
    if(upper!= lower+1)
    {
    QuickSort(list, lower, pivot-1);
    QuickSort(list, pivot+1, upper);
    }
}

int solveCase()
{
    int size, numOfCurses, min_tolerance;
    scanf("%d%d",&size, &numOfCurses);

    int field[size][size];
    int rowAr[size][2];
    int colAr[size][2];

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            scanf("%d",(*(field+i)+j));
        }
    }

    for(int i=0;i<size;i++)
    {
        rowAr[i][0]=0;
        rowAr[i][1]=i;
        for(int j=0;j<size;j++)
        {
            rowAr[i][0]+=field[i][j];
        }
    }

    for(int i=0;i<size;i++)
    {
        colAr[i][0]=0;
        colAr[i][1]=i;
        for(int j=0;j<size;j++)
        {
            colAr[i][0]+=field[j][i];
        }
    }

    QuickSort(rowAr,0,size);
    QuickSort(colAr,0,size);


    return min_tolerance;
}

int main()
{
    int testCases;
    scanf("%d",&testCases);

    for(int i=1;i<=testCases;i++)
        printf("%d\n",solveCase());
    return 0;

}
