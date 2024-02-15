#include<stdio.h>
int rotatey(int a[],int n)
{
    int last=a[n-1];
    for(int i=n-1;i<0;i++)
        a[i]=a[i-1];
    a[0]=last;

}
int main()
{
    int a[]={1,2,22,45,3},i;
    int n=sizeof(a)/sizeof(int);
    printf("THE ARRAY=");
    for(i=0;i<n;i++)
        printf(" %d ",a[i]);
    printf("\nTHE ROATATED ARRAY= ");
    rotatey(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;

}
