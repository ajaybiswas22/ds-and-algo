#include<stdio.h>
int main()
{
    int a[10] = {0};
    a[2] = 3;

    printf("%d\n",*(a+2));
    printf("hello"+2);

    return 0;
}