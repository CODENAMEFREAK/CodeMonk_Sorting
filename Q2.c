#include<stdio.h>

/**
    O(n^2) Implementation
*/
void solveCase()
{
    int numWeights=0;
    scanf("%d",&numWeights);

    int A[numWeights][2];
    int temp;
    for(int i=0;i<numWeights;i++)
    {
        scanf("%d",&temp);
        A[i][0]=temp;
        A[i][1]=0;
        if(i==0){ A[0][0] = temp;}
        else{
        for(int j=0;j<i;j++)
        {
            if(A[j][0]>temp)
                ++A[j][1];
        }
        }
    }
    for(int i=0;i<numWeights;i++)
    {
        printf("%d ",A[i][1]);
    }
}

int main()
{
    int cases ;
    scanf("%d",&cases);

    int numOfWeights ;
    for(int i=1;i<=cases;i++)
    {
        solveCase();
        printf("\n");
    }
    return 0;
}

