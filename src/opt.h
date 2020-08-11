//
// Created by lrf141 on 2020/08/11.
//

#ifndef REDAST_OPT_H
#define REDAST_OPT_H

typedef struct serverOption {
    int port;
} serverOption;

void printHelp();
int validatePort(int);
serverOption *getDefaultSetting();

#endif //REDAST_OPT_H
