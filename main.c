#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {

    // Create two child processes
    pid_t child1, child2;
    child1 = fork();

    if (child1 == 0) {
        // This is the first child process
        for (int i = 1; i <= 30; i++) {
            printf("Child Pid: %d is going to sleep!\n", getpid());
            sleep(2);
            printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", getpid(), getppid());
        }
        exit(0);
    }
    else {
        // parent process
        child2 = fork();
        
        if (child2 == 0) {
            // This is the second child process
            for (int i = 1; i <= 30; i++) {
                printf("Child Pid: %d is going to sleep!\n", getpid());
                sleep(2);
                printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", getpid(), getppid());
            }
            exit(0);
        } 
        else {
            //  parent process
            int status1, status2;
            wait(&status1);
            wait(&status2);
            printf("Child Pid: %d has completed\n", child1);
            printf("Child Pid: %d has completed\n", child2);
        }
    }

    return 0;
}
