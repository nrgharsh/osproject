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
  printf("\t\t\t------------------****---------------------\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |\n");
  printf("\t\t\t--------------------********---------------------\n");
  for(i=0;i<n;i++)
  {
 
     printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |\n",process[i],AT[i],BT[i]);
  }
    
	printf("\t\t\t***************************************************\n");


  printf("\n\n\t\t\t-------- Sorting Processes according to their respective ARRIVAL TIME --------\n");

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(AT[i]<AT[j])
      {
        
        temp = BT[j];
        BT[j] = BT[i];
        BT[i] = temp;
	
	      temp = process[j];
        process[j] = process[i];
        process[i] = temp;

	      temp = AT[j];
        AT[j] = AT[i];
        AT[i] = temp;
      
      }
    }
  }
  printf("\n\n\t\t\t -------------- Now New Values are --------------\n\n");
  printf("\t\t\t*******************************************************\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |\n");
  printf("\t\t\t*******************************************************\n");
  for(i=0;i<n;i++)
  {
    printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |\n",process[i],AT[i],BT[i]);
  }
    printf("\t\t\t*******************************************************\n");


                                    //Arranging the table according to Burst time, Execution time and Arrival Time
                                    //Arrival time <= Execution time
                                    


  long int k = 1;
  double b_time = 0;
  for(j=0;j<n;j++)
  {
    b_time = b_time + BT[j];
    min = BT[k];

    for(i=k;i<n;i++)
    {
      if((b_time >= AT[i])&&(BT[i]<min))
          {
             temp = BT[k];
             BT[k] = BT[i];
             BT[i] = temp;


             temp = AT[k];
             AT[k] = AT[i];
             AT[i] = temp;

             temp = process[k];
              process[k] = process[i];
             process[i] = temp;
          }
    }
    k++;
  }
  waitingTime[0] = 0;
  for(i=1;i<n;i++)
  {
                      sum += BT[i-1];
                      waitingTime[i] = sum - AT[i];
                      wait_final += waitingTime[i]; 
  }
  wait_avg = wait_final/n;
  for(i=0;i<n;i++)
  {
    
	           sum2 += BT[i];
    
	           turnaroundTime[i] = sum2 - AT[i];
    
	           turnaround_final += turnaroundTime[i];
  }
  turnaround_avg=turnaround_final/n;
      printf("\n\n\t\t\t -------------- Now Values are --------------\n\n");
      printf("\t\t\t*****************************************************************************\n");
      printf("\t\t\t| Process | Arrival Time | Burst Time |  Waiting Time  |  Turn Around Time  |\n");
      printf("\t\t\t*****************************************************************************\n");
  for(i=0;i<n;i++)
   {
       printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |        %0.0lf       |         %0.0lf          |\n",process[i],AT[i],BT[i],waitingTime[i],turnaroundTime[i]);
   }
             printf("\t\t\t*********************************************************************\n");



  //Now setting the priorities of the processes according to the given formula
    //  Priority = 1+ Waiting time / Estimated run time

 
  
  completionTime[0] = BT[0];
  for(i=1;i<n;i++)
  {
  	
    completionTime[i] = completionTime[i-1] + BT[i];
  
  }

  for(i=0;i<n;i++)
  {
    
	  priority[i] = 1+waitingTime[i]/completionTime[i];
      printf("%lf\n",priority[i]);
  
  }


      printf("\n\n\t\t\t -------***------- Final Results -------****-------\n\n");
      printf("\t\t\t*****************************************************************************\n");
      printf("\t\t\t| Process | Arrival Time | Burst Time |  Waiting Time  |  Turn Around Time  |\n");
      printf("\t\t\t*****************************************************************************\n");
      printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |        %0.0lf       |         %0.0lf          |\n",process[0],AT[0],BT[0],waitingTime[0],turnaroundTime[0]);
  
for(i=n-1;i>0;i--)
  {
   
       printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |        %0.0lf       |         %0.0lf          |\n",process[i],AT[i],BT[i],waitingTime[i],turnaroundTime[i]);
  
  }
     printf("\t\t\t******************************************************************************\n");

     printf("\n\n\n\t\t\tAverage Turn Around Time : %lf",turnaround_avg);
     printf("\n\t\t\tAverage Waiting Time     : %lf\n\n",wait_avg);
	
  getch();
  return 0;
}
