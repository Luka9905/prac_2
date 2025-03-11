#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "log.h"

void log_to_file(const char *path) {
    FILE *file = freopen(path, "w", stdout);
    if (file == NULL) {
        perror("freopen");
        exit(EXIT_FAILURE);
    }
}
