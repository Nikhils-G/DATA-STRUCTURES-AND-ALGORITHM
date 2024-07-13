#include<stdio.h>
int main()
{
    int arr[]={2,3,4,2,3,6,2,3};
    int n=sizeof(arr)/sizeof(n);
    int visited[n];
    int j;
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            int count=1;
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]==arr[j])
                {
                    count++;
                    visited[j]=1;
                }
            }
            if(count==1)
            {
                printf("%d ",arr[i]);
            }
        }
        
    }
}
