#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "log.h"

void log_to_file(const char *path) {
    if (access(path, W_OK) == -1) {
        FILE *file = fopen(path, "w");
        fclose(file);
    }

    FILE *file = freopen(path, "a", stdout);
    if (file == NULL) {
        perror("freopen");
        exit(EXIT_FAILURE);
    }
}
