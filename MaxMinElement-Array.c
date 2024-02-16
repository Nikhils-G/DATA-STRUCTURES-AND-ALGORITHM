#include<stdio.h>
void traversal(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
}

int main()
{
    int a[100],n,i,mx,mn;
    printf("enter the size of the array=");
    scanf("%d",&n);
    printf("enter the elements in the array=");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    traversal(a,n);
    mx=a[0];
    mn=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]>mx)
        {
            mx=a[i];
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[i]<mn)
        {
            mn=a[i];
        }
    }
    printf("\n");
    printf("MAXIMUM ELEMENT=%d",mx);
    printf("\nMINIMUM ELEMENT=%d",mn);
    return 0;

}
