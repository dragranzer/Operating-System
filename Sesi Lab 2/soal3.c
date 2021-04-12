#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

#define LOG_DIR "/home/[path to folder error.txt]"

int main() {
    pid_t pid, sid;

    // Save PID of child process
    pid = fork();

    // Fail to fork
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    // Terminate parent process
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();
    
    // Fail to set SID
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    // Change main directory, if fail, terminate program
    if (chdir("/") < 0) {
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    int number = 1;

    // Action every 10s
    while (1) {
        FILE *fptr = fopen(""LOG_DIR"/error.txt", "r");
        
        // Fail to open error.txt
        if (fptr == NULL) {
            exit(EXIT_FAILURE);
        }

        char path[1000];
        sprintf(path, ""LOG_DIR"/error.log.%d", number++);

        FILE *fptr2 = fopen(path, "w");

        // Fail to open error.txt.[number]
        if (fptr2 == NULL) {
            exit(EXIT_FAILURE);
        }

        // Read char in error.txt
        char ch;
        while (fscanf(fptr, "%c", &ch) != EOF) {
            fprintf(fptr2, "%c", ch);
        }
        
        fclose(fptr2);
        
        fclose(fptr);
        

        // Clear error.txt contents
        fptr = fopen(""LOG_DIR"/error.txt", "w");

        // Failed to open error.txt
        if (fptr == NULL) {
            exit(EXIT_FAILURE);
        }

        fclose(fptr);

        if (number > 5) break;

        sleep(10);
    }
}
