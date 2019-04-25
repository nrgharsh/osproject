#include<stdio.h>
#include<conio.h>
int main()
{
  printf("\t\t\t*****************************NON-PREMPTIVE(SHORTEST JOB)Scheduling********************************\n\n\n\n");
  long int n,i=0,j=0;
  printf("Enter Number of Processes : ");
  scanf("%ld",&n ); 
  double priority[n],avg_waiting,avg_turnaround,BT[n],AT[n],waitingTime[n],turnaroundTime[n], process[n], temp, completionTime[n],min,sum=0,sum2=0,wait_final, turnaround_final, wait_avg, turnaround_avg;
  for(i=0;i<n;i++)
  {
    printf("Enter Arrival Time for Process [%d] : ", i+1 );
    	scanf("%lf", &AT[i] );
    
	printf("\nEnter Burst Time for Process [%d] : ", i+1 );
        scanf("%lf", &BT[i]);

    process[i]=i+1;
  }

  printf("\n\n\t\t\t ********************** Entered Values: ************************\n\n");
  printf("\t\t\t------------------**********---------------------\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |\n");
  printf("\t\t\t--------------------********---------------------\n");
  for(i=0;i<n;i++)
  {
 
     printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |\n",process[i],AT[i],BT[i]);
  }
    
	printf("\t\t\t***************************************************\n");



