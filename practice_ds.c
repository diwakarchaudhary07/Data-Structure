// array traversal
#include <stdio.h>
     int main(){
     int arr[100],n ,i;

     printf("enter size of array  : ");
     scanf("%d" ,&n);
 
     for(i=0; i < n; i++)
     {
         printf("enter element of array %d :" ,i + 1);
         scanf("%d" ,&arr[i]);
     }
 
     printf("elements in the array are:");
     for(i=0; i < n; i++)
     {
         printf("%d" , arr[i]);
     }
     return 0;
}