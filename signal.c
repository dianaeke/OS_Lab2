#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int alarm_count = 0;
int total_execution_time = 0;

void sigalrm_handler(int signum) {
  printf("Hello World!\n");
  alarm(1);
}

void sigint_handler(int signum) {
  printf("Total alarms occured: %d\n", alarm_count);
  printf("Total execution time: %d seconds\n", total_execution_time);
  exit(0);
}

int main(int argc, char * argv[]) {
  signal(SIGALRM,sigalrm_handler); //register handler to handle SIGALRM
  signal(SIGINT, sigint_handler)
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1); {//busy wait for signal to be delivered
    sleep(1);
    total_execution_time++;
    alarm_count++;
    printf("Turing was right!\n");
  }
  return 0; //never reached
}
