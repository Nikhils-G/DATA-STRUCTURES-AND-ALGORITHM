#include<stdio.h>
int unionof(int a[],int b[],int n,int m)
{
    int unioncount=0;
    int j;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
            if(a[i]==b[j])
                break;
        if(i==j)
            unioncount++;
    }
    //for array b[]
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(b[i]==a[j])
                    break;

                if(i==j)
                    unioncount++;

        }

        return unioncount++;
}



int main()
{

    int i,a[100],b[100],n,m;
    printf("size of a[]=");
    scanf("%d",&n);
    printf("enter elements of a[]=");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("size of b[]=");
    scanf("%d",&m);
    printf("enter elements of a[]=");
    for(i=0;i<m;i++)
        scanf("%d",&b[i]);
    int unioncount=unionof(a,b,n,m);
    printf("%d",unioncount);

}
