#include <stdio.h>
struct process{
  int pn,at,bt,tt,ct,tbt,wt;
  int completed;
}p[20];
int q[10],n,front=-1,rear=-1;
void enqueue(int i){
  if(rear==20)
    printf("overflow");
  rear++;
  q[rear]=i;
  if(front==-1)
    front=0;
}
int dequeue(){
  int temp;
  temp=q[front];
  if(front==rear)
    front=rear=-1;
  front++;
  return temp;
}
int isinqueue(int i){
  int k;
  for(k=front;k<=rear;k++){
    if(q[k]==i)
      return 1;
  }
  return 0;
}
int main(){
  int i,j,sum=0,clk=0,ts;
  struct process temp;
  float awt=0,att=0;
  printf("enter the no of process:");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    p[i].pn=i+1;
    printf("arrival time of p%d:",i+1);
    scanf("%d",&p[i].at);
    printf("burst time of p%d:",i+1);
    scanf("%d",&p[i].bt);
    sum+=p[i].bt;
    p[i].tbt=p[i].bt;
    p[i].completed=0;
  }
  printf("enter the time slice:");
  scanf("%d",&ts);
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(p[i].at>p[j].at){
        temp=p[i];
        p[i]=p[j];
        p[j]=temp;
      }
    }
  }
  enqueue(0);
  for(clk=p[0].at;clk<sum;){
    i=dequeue();
    if(p[i].tbt<=ts){
      clk+=p[i].tbt;
      p[i].tbt=0;
      p[i].completed=1;
      p[i].wt=clk-p[i].at-p[i].bt;
      p[i].ct=clk;
      p[i].tt=clk-p[i].at;
      awt+=p[i].wt;
      att+=p[i].tt;
      for(j=0;j<n;j++){
        if(p[j].at<=clk && p[j].completed!=1 && isinqueue(j)!=1)
          enqueue(j);
      }
    }
    else{
      clk+=ts;
      p[i].tbt-=ts;
      for(j=0;j<n;j++){
        if(p[j].at<=clk && p[j].completed!=1 &&i!=j && isinqueue(j)!=1)
          enqueue(j);
      }
      enqueue(i);
    }
  }
  printf("process no\tarrival time\tburst time\twaiting time\tturnaround time\tcompletion time");
  for(i=0;i<n;i++){
    printf("\n%d\t\t\t%d\t\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t%d",p[i].pn,p[i].at,p[i].bt,p[i].wt,p[i].tt,p[i].ct);
  }
  printf("\naverage waiting time:%f",awt/n);
  printf("\naverage turnaround time:%f",att/n);
}