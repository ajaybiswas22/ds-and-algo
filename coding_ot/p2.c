#include<stdio.h>
int main()
{
    int a[10][20][30]={0};
    a[5][2][1] = 3;

    printf("%d",*(*(*(a+5)+2)+1));    // right
    //printf("%d",*(((a+5)+2)+1));
    //printf("%d",***((a+5)+2)+1);
    return 0;
}