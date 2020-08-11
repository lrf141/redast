//
// Created by lrf141 on 2020/08/11.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "opt.h"

int main(int argc, char *argv[]) {

	serverOption *srvOpt;
	srvOpt = (serverOption *)malloc(sizeof(serverOption));
        int opt = 0;
        while ((opt = getopt(argc, argv, "hp::")) != -1) {
        	switch (opt) {
        		case 'h':
        			printHelp();
        			return 0;
        		case 'p':
        			if (!validatePort(atoi(optarg))) {
        				printf("Invalid Port Number: %d\n", atoi(optarg));
        				free(srvOpt);
        				return -1;
        			}
        			srvOpt->port = atoi(optarg);
        			break;
        	}
        }
        free(srvOpt);

        return 0;
}
