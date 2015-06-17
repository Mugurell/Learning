#include <stdio.h>
#include <stdlib.h>
int main()
{
      int d[20];
      int decimalno,i=0;

      printf("Enter the decimal number you want to conver to binary: \n");
      scanf("%d",&decimalno);

      while(decimalno>0)
      {
           d[i]=decimalno%2;
           printf("d[i] - %d\n" , d[i]);
           i++;
           decimalno=decimalno/2;
           printf("decimalno - %d\n" , decimalno);
      }
    puts("\n\n\n");
      int j;
      for(j=i-1;j>=0;j--)
      {
            printf("%d",d[j]);
      }
  //    printf("The binary version of the number you input is %d",decimalno);
    //  getch();
 }
