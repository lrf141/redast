//
// Created by lrf141 on 2020/08/12.
//

#include <time.h>
#include "log.h"

void printLocalTime() {
	time_t timer;
	struct tm *t;

	time(&timer);
	t = localtime(&timer);

	printf("%04d/%02d/%02d %02d:%02d:%02d ", t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
}

void printLog(char *type, char *msg) {
	printLocalTime();
	printf("[%s]: %s\n", type, msg);
}

void printErr(char *msg) {
	printLog("ERR!!", msg);
}
void printWarn(char *msg) {
	printLog("WARN", msg);
}
void printDebug(char *msg) {
	printLog("DEBUG", msg);
}
void printVerbose(char *msg) {
	printLog("VERBOSE", msg);
}