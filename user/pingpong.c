//
// Created by chenjiajun1999 on 2022/11/17.
//

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int
main(int argc, char *argv[]) {

    int pipe_fd[2];
    int ret = pipe(pipe_fd);
    if (ret == -1) {
        printf("Create a pipe failed.\n");
        exit(0);
    }

    int pid = fork();

    if (pid > 0) {

        // write data into pipe
        char *str = "ping";
        write(pipe_fd[1], str, strlen(str));
        sleep(1);
        // read data from pipe
        char buf[1024] = {0};
        read(pipe_fd[0], buf, sizeof(buf));
        printf("%d: received pong\n", getpid());

    } else if (pid == 0) {
        // return 0 in the child

        char buf[1024] = {0};
        read(pipe_fd[0], buf, sizeof(buf));
        printf("%d: received ping\n", getpid());
        char *str = "pong";
        write(pipe_fd[1], str, strlen(str));
        sleep(1);

    }

    exit(0);
}