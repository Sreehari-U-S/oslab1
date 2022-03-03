#include <stdio.h>

int main() {
int n;
int processes[20];
int burst_time[10];
int arrival_time[10];

  
printf("enter the no of processes : ");
scanf("%d",&n);
printf("enter the burst time : ");
for(int i = 0; i < n; i++) {
     scanf("%d", &burst_time[i]);
  }
printf("enter the arrival time : ");
for(int i = 0; i < n; i++) {
    scanf("%d", &arrival_time[i]);
}

// finding waiting time
int service_time[n];  
int wt[n];
service_time[0] = arrival_time[0];
wt[0] = arrival_time[0];
int total_wt = 0;
for(int i=1; i<n; i++){
  service_time[i] = service_time[i-1] + burst_time[i-1];
  wt[i] =  service_time[i] - arrival_time[i];
  total_wt += wt[i];
}
int avg_waitingTime = total_wt / n;

// finding TT time
int tt[n];
int total_tt = 0;
for(int i=0; i<n; i++){
  tt[i] = wt[i] + burst_time[i];
  total_tt += tt[i];
}
int ct[n];  
for(int i=0; i<n; i++){
  ct[i] = service_time[i] + burst_time[i];
}
int avg_tt = total_tt / n;
printf("Processes   Arrival time   Burst time   Waiting time  Turn around time  competition time\n");
for(int i=0; i<n; i++){
  printf("p%d\t\t\t\t", i+1);
  printf("%d\t\t\t\t", arrival_time[i]);
  printf("%d\t\t\t\t", burst_time[i]);
  printf("%d\t\t\t\t", wt[i]);
  printf("%d\t\t\t\t", tt[i]);
  printf("%d\n", ct[i]);
}
printf("Average waiting time = %d", avg_waitingTime);
printf("\n");
printf("Average turn around time = %d ",avg_tt);
return 0;
}