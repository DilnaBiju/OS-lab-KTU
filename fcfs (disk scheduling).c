#include <stdio.h>
#include <stdlib.h>
void main()
{
    int seek =0,req[20];
    int n,head,i,cyl;
    printf("Enter the number of requests :");
    scanf("%d",&n);
    printf("Enter the number of cylinders:");
    scanf("%d",&cyl);
    printf("Enter the head:");
    scanf("%d",&head);
    printf("Enter the requests:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    seek= seek+(abs(req[0]-head));
    for(i=1;i<n;i++)
    {
        seek=seek+abs(req[i]-req[i-1]);
    }
    printf("head movements =%d",seek);
}
//Here the abs() is a standard library function in C to get the absolute value while subtracting two numbers.it is in the stdlib.h header file
/* OUTPUT
Enter the number of requests :8
Enter the number of cylinders:200
Enter the head:53
Enter the requests:
98 183 37 122 14 124 65 67
head movements =640
  */
