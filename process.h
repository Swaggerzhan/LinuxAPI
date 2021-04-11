//
// Created by swagger on 2021/4/11.
//

#ifndef LINUXAPI_PROCESS_H
#define LINUXAPI_PROCESS_H


#include <unistd.h>
#include <iostream>
#include <sys/poll.h>
#include <wait.h>


static int global = 10;

void ProcessTestMain(){

    pid_t p_id;

    p_id = fork();
    /* fork返回2次，一次在子进程中，它返回0 */
    if (p_id == 0){
        printf("this is child process!\n");
        for (int i=0; i<10; i++)
            global ++;
        printf("child global number %d\n", global);
        exit(97);
    }

    printf("child process id is %d\n", p_id);
    printf("this is father process!\n");
    for (int i=0; i<100; i++)
        global++;

    printf("father global number %d\n", global);

    poll(nullptr, 0, 50);
    int status;
    pid_t child_id = waitpid(p_id, &status, 0);
    printf("catch child exit code %d\n", status);



}









#endif //LINUXAPI_PROCESS_H
