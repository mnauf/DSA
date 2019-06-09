#include <stdio.h>
#include <math.h>
int main(void)
{
int i,item,beg=0,end=5,mid,a[6]={10, 21, 32, 35, 43, 54};
printf("The numbers in an array are: ");
for (i=0;i<=5;i++)
{
printf("%d, ",a[i]);
}
mid=(beg+end)/2;
mid=round(mid);
printf("Enter the number you want to search: ");
scanf("%d", &item);
printf("Item you entered is %d\n",item);
while((a[mid]!=item) & (beg<=end))
{
if (item<a[mid])
end=mid-1;
else
beg=mid+1;
mid=(beg+end)/2;
mid=round(mid);
}
if (item==a[mid])
printf("Your number is at location %d in array and the number is %d",mid,a[mid]);
else
printf("Item not found");
return 0;
}
