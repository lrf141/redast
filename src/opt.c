//
// Created by lrf141 on 2020/08/11.
//

#include <stdio.h>
#include "opt.h"

void printHelp() {
	printf("redast v0.0.1\n");
	printf("[Options]\n");
	printf("-h: Show help\n");
	printf("-p: Server Port\n");
}

int validatePort(int port) {
	if (port < 0 || 65535 < port)
		return 0;
	return 1;
}