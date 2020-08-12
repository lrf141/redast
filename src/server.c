//
// Created by lrf141 on 2020/08/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "server.h"
#include "opt.h"
#include "syslog.h"

void start(serverOption *opt) {
	int sock;
	if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		printErr("Can not create socket.");
		return;
	}

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(opt->port);

	bind(sock, (struct sockaddr *)&addr, sizeof(addr));
	listen(sock, 5);

	printVerbose("Server Start");

	int sock0, len;
	struct sockaddr_in client;
	while (1) {
		len = sizeof(client);
		sock0 = accept(sock, (struct sockaddr *)&client, (socklen_t *)&len);
		write(sock0, "HELLO", 5);
		close(sock0);
	}
	close(sock);
}