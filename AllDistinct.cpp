#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int t;
    scanf("%d",&t);

    int n,count,prev;

    while(t--)
    {
        scanf("%d",&n);

        int array[n];
        for(int i=0;i<n;i++) scanf("%d",&array[i]);

        qsort(array,n,sizeof(int),cmpfunc); // number of distinct elements is the ans.

        count = 1; // intitial count of array[0] is 1, count of distict elements.
        prev = array[0] ; 

        for(int i=1;i<n;i++)
        {
            if (array[i]!=prev)
            {
                count++;
                prev = array[i];
            }
        }

        // if we remove odd number of elems one extra elem has to be removed to get the max ans.
        
        if ( n%2 == 1 && count%2==0 ||n%2 == 0 && count%2==1 ) count--;

        printf("%d\n",count);
    }
}