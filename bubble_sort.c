#include <stdio.h>
int main(void)
{
int i,k,ptr,temp,a[7]={10,6,7,5,9,4,8};
printf("The unmodified array is as follows: ");
for (i=0;i<=6;i++)
{
printf("%d, ",a[i]);
}
printf("\n");
for (k=1;k<=7-1;k++)
{
for (ptr=0;ptr<=6-k;ptr++)
{
if (a[ptr]>=a[ptr+1])
{
temp=a[ptr];
a[ptr]=a[ptr+1];
a[ptr+1]=temp;
}
}
}
printf("The modified array is as follows: ");
for (ptr=0;ptr<=6;ptr++)
printf("%d, ",a[ptr]);
return 0;
}
