#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <wait.h>
#include <sys/stat.h>

#define COPY_DIR "/home/[usr]/Downloads"
#define PASTE_DIR "/home/[usr]/Desktop"

void copyDir(char *copyPath, char* destPath);
void constructDestPath(char *destPath);

int main() {

    // Child process to create destination folder
    pid_t child_id;
    child_id = fork();

    if (child_id < 0) {
        exit(EXIT_FAILURE);
    }

    int status;
    char destPath[1000];
    constructDestPath(destPath);

    if (child_id == 0) {
        char *argv[3] = {"mkdir", destPath, NULL};

        // Check if folder exists
        if (chdir(argv[1]) != -1) {
            exit(EXIT_FAILURE);
        }

        execv("/bin/mkdir", argv);
    }
    else {
        while ((wait(&status)) > 0);
        copyDir(COPY_DIR, destPath);
    }
    return 0;
}

void constructDestPath(char *destPath) {
    // Time
    time_t now = time(NULL);
    struct tm tm_now;
    localtime_r(&now, &tm_now);

    char buff[100];
    strftime(buff, sizeof(buff), "%d-%m-%Y_%H:%M:%S", &tm_now);

    sprintf(destPath, ""PASTE_DIR"/%s", buff);
}

int is_regular_file(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

void copyDir(char *copyPath, char* destPath) {
    char path[1000];
    char dest[1000];
    struct dirent *dp;
    DIR *dir = opendir(copyPath);

    if (!dir) return;

    while((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {

            strcpy(path, copyPath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            strcpy(dest, destPath);
            strcat(dest, "/");
            strcat(dest, dp->d_name);

            pid_t child_id;

            child_id = fork();

            if (child_id < 0) {
                exit(EXIT_FAILURE);
            }

            int status;

            if (child_id == 0) {
                if (is_regular_file(path)) {
                    printf("Copying file %s", dest);
                    char *argv[] = {"cp", path, destPath, NULL};
                    execv("/bin/cp", argv);
                }
                else {
                    printf("Creating folder %s", dest);
                    char *argv[] = {"mkdir", dest, NULL};
                    execv("/bin/mkdir", argv);
                }
            }
            else {
                while((wait(&status)) > 0);
                copyDir(path, dest);
            }
        }
    }
    closedir(dir);
}
