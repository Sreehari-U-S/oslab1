#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>


void display_parent();

void display_child();

int main(){
  pid_t pid = fork();
  if(pid == 0){
    display_child();

  }
  else if (pid>0){
   
    display_parent();

  }
  else {
    printf("Unable to create child process\n");
  }
  return EXIT_SUCCESS;
}

void display_parent(){
  printf("Parent pid : %d\n",getpid());
  printf("Waiting for child process to complete\n");
  wait(NULL);
  printf("Parent process completed\n");
  


}
void display_child(){
  printf("Child pid : %d \n",getpid());
  printf("child Process completed\n");
  exit(EXIT_SUCCESS);
}