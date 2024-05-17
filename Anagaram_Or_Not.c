#include<stdio.h>
#include<string.h>
void sort(char* s1)
{
    int n;
    n=strlen(s1);
    for(int i=0;i<n-1;i++)
    {
        for(int j=1;j<n;j++)
        {
            if (s1[i]>s1[j])
            {
                int temp=s1[i];
                s1[i]=s1[j];
                s1[j]=temp;
            }
        }
    }
}
int main()
{
    char s1[]="ANAGRAM";
    char s2[]="NAGARAM";
    sort(s1);
    sort(s2);
    if(strcmp(s1,s2)==0)
        printf("true");
    else
        printf("false");
    return 0;
}
