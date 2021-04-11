//
// Created by swagger on 2021/4/11.
//

#ifndef LINUXAPI_FILE_H
#define LINUXAPI_FILE_H

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>


#define BUFSIZE 1024

char *buf;


void FileTestMain(){
    int fd = open("../example_file/test1", O_RDWR);
    if (fd < 0) {
        perror("open error!\n");
        return;
    }

    buf = "123\n\0";


    if (strlen(buf) != write(fd, buf, strlen(buf))) {
        perror("write error!\n");
        return;
    }


}




#endif //LINUXAPI_FILE_H
