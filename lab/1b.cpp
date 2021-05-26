 #simple C program to add two arrays using dynamic memory allocation.

#include <stdio.h>
#include <process.h>
#include <stdlib.h>
void main()
{
int n,m;
printf("Enter the size of array1: ");
scanf("%d",&n);
int*arr1 =(int*)malloc(n * sizeof(int));
printf("Enter the size of array2: ");
scanf("%d",&m);
int*arr2 =(int*)malloc(m * sizeof(int));
if(n!=m)
{
printf("Addition is not applicable...");
exit(0);
}
int*mula =(int*)malloc(m * sizeof(int));
printf("\nEnter first array:\n");
for(int i=0;i<n;i++)
scanf_s("%d", &arr1[i]);
printf("\nEnter second array:\n");
for(int i=0;i<n;i++)
scanf_s("%d", &arr2[i]);
for(int i=0;i<n;i++)
mula[i]=arr1[i]+arr2[i];
printf("\n array will be :\n");
for(int i=0;i<n;i++)
printf("%d ", mula[i]); printf("\n");
system("pause");
}
