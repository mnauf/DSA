#include <stdio.h>
int main(void)
{
int i,j,k,rows=2,columns=2,row,column,
a[2][2]=
{{1,2},
 {3,4}
},
b[2][2]=
{{1,2},
 {3,4}
},
c[2][2]={{0,0},{0,0}};
printf("Matrix A: \n");
for (row=0;row<=1;row++)
{
    for (column=0;column<=1;column++)
    {
        printf("%d  ", a[row][column]);
    }
    printf("\n");
}
printf("\n");
printf("Matrix B: \n");
for (row=0;row<=1;row++)
{
    for (column=0;column<=1;column++)
    {
        printf("%d  ", b[row][column]);
    }
    printf("\n");
}
printf("\n");
for (i=0;i<=rows-1;i++)
{
for (j=0;j<=columns-1;j++)
{
for (k=0;k<=1;k++) //k is a number of columns of matrix A and number of rows of matrix B i.e 2. I wrote 1 instead of two because couting is starting from 0.
{
c[i][j]=c[i][j]+a[i][k]*b[k][j];
}
}
}
// To print the multiplied matrix
printf("Matrix C = A * B\n");
for (row=0;row<=1;row++)
{
for (column=0;column<=1;column++)
{
printf("%d	",c[row][column]);
}
printf("\n");
}
return 0;
}
