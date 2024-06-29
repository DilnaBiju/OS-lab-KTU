#include <stdio.h>
#include <stdlib.h>
struct process
{
    int pid;
    int arrival_t;
    int bt;
    int tat;
    int ct;
    int wt;
}p[20],temp;
void main()
{

    int n,i,j,sum;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the arrival time for process P%d : ",i+1);
        scanf("%d",&p[i].arrival_t);
        printf("enter the burst time for process P%d : ",i+1);
        scanf("%d",&p[i].bt);

    }
    //sorting
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].arrival_t>p[j+1].arrival_t)
            {
                temp=p[j+1];
                p[j+1]=p[j];
                p[j]=temp;
            }
        }
    }
    //completion time
    sum=p[0].arrival_t;
    for(i=0;i<n;i++)
    {

        sum=sum+p[i].bt;
        p[i].ct=sum;
    }

    //turn around time and waiting time
    for(i=0;i<n;i++)
    {
        p[i].tat=p[i].ct-p[i].arrival_t;
        p[i].wt=p[i].tat-p[i].bt;
    }

    printf("~~~~~~TABLE REPRESENTATION~~~~~~~~~~\n");
    printf("Pid\t AT\t BT\t CT\t TAT\t WT\t\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t %d\t %d\t %d\t %d\t %d\t\n",p[i].pid,p[i].arrival_t,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }

    //gantt chart representation

    printf("\nGantt Chart\n ");
    printf("\t");
    for(i=0;i<n;i++)
    {
        printf("-------");
    }
    printf("\n");
    printf("\t");
    for(i=0;i<n;i++)
    {
        printf("| %d",p[i].pid);
    }
    printf("|\n");
    printf("\t");
    for(i=0;i<n;i++)
    {
        printf("-------");
    }
    printf("\n");
    printf("\t0");
    for(i=0;i<n;i++)
    {
        printf("  %d",p[i].ct);
    }
    printf("\n");


    //avg tat and avg tat
    float total_tat=0,total_wt=0;
    int avg_tat,avg_wt;

    for(i=0;i<n;i++)
    {
        total_tat=total_tat+p[i].tat;
        total_wt=total_wt+p[i].wt;
    }
    avg_tat=total_tat/n;
    printf("AVG TAT = %d",avg_tat);
    avg_wt=total_wt/n;
    printf("AVG WT = %d",avg_wt);

}
/* OUTPUT
  Enter the number of processes:5
Enter the arrival time for process P1 : 0
enter the burst time for process P1 : 4
Enter the arrival time for process P2 : 2
enter the burst time for process P2 : 1
Enter the arrival time for process P3 : 1
enter the burst time for process P3 : 3
Enter the arrival time for process P4 : 4
enter the burst time for process P4 : 5
Enter the arrival time for process P5 : 3
enter the burst time for process P5 : 2
~~~~~~TABLE REPRESENTATION~~~~~~~~~~
Pid      AT      BT      CT      TAT     WT
0        0       4       4       4       0
0        1       3       7       6       3
0        2       1       8       6       5
0        3       2       10      7       5
0        4       5       15      11      6

Gantt Chart
        -----------------------------------
        | 0| 0| 0| 0| 0|
        -----------------------------------
        0  4  7  8  10  15
AVG TAT = 6
AVG WT = 3
  */
