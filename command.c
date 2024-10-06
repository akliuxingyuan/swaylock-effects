#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "log.h"
#include "command.h"

void exec_cmd(const char *cmd) {
    pid_t child = fork();
    if (child < 0) {
		swaylock_log_errno(LOG_ERROR, "failed to fork");
	} else if (child == 0) {
        execlp("/usr/bin/sh", "sh", "-c", cmd, NULL);
		exit(0);
	}
}