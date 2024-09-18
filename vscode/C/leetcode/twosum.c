#include <stdio.h>
int main()
{
    int n;
    printf("enter the total size of the array");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements of the array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}