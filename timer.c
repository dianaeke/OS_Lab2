#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int alarm_count = 0;
int total_execution_time = 0;

void sigalrm_handler(int signum) {
    printf("Hello World!\n");
    alarm(1); // Set another alarm to occur in 1 second
}

void sigint_handler(int signum) {
    printf("Total alarms occurred: %d\n", alarm_count);
    printf("Total execution time: %d seconds\n", total_execution_time);
    exit(0);
}

int main(int argc, char *argv[]) {
    signal(SIGALRM, sigalrm_handler); // Register handler to handle SIGALRM
    signal(SIGINT, sigint_handler);   // Register handler to handle SIGINT (Ctrl+C)

    alarm(1); // Set the initial alarm to occur in 1 second

    while (1) {
        sleep(1); // Sleep for 1 second
        total_execution_time++;
        alarm_count++;
        printf("Turing was right!\n");
    }

    return 0; // Never reached
}
