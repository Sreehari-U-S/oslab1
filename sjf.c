#include <stdio.h>

int main(void) {
  int n,arr[10],bt[10],an[10];
  printf("Enter no of process : ");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("p%d arrival time : ",i);
    scanf("%d",&arr[i]);
    printf("p%d burst time : ",i);
    scanf("%d",&bt[i]);
    an[i]=bt[i];
  }
  int t=0,r=n,count=0,i=0,flag=0;
  float avg_t=0,avg_w=0;
  printf("Process | Arrival Time | Burst Time | Waiting Time | Turnaround Time | Completion Time \n");
  while(r>0){
    if(count<n-1){
      count++;
      t=arr[count];
      an[i]=an[i]-arr[count]+arr[count-1];
    }
    else if(count>=n-1 && an[i]!=0){
      t=t+an[i];
      an[i]=0;
      flag=1;
    }
    if(an[i]==0 && flag==1){
        r--;
        printf("p%2d \t\t %2d \t\t\t %2d \t\t %2d \t\t\t %2d \t\t\t %2d\n",i,arr[i],bt[i],t-bt[i]-arr[i],t-arr[i],t);
        avg_t = avg_t + t-arr[i];
        avg_w = avg_w + t-arr[i]-bt[i];
        flag=0;
    }
    if(count<=n-1){
       if(an[i]>an[count]){
          i=count;
      }
      if(count==n-1){
        count++;
      }
    }
    else{
      if(i==n-1){
        i=0;
        for(int m=1;m<n;m++){
          if(an[m]!=0 && an[m]<=an[i]){
            i=m;
          }
        }
      }
      else{
        i++;
        for(int m=i+1;m<n;m++){
          if(an[m]!=0 && an[m]<=an[i]){
            i=m;
          }
        }
      }
    }
  }
  avg_t = avg_t/n;
  avg_w= avg_w/n;
  printf("Avg Waiting Time : %f\nAvg Turnaround Time : %f\n",avg_w,avg_t);
  
  return 0;
}