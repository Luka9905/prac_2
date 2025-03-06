#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "users.h"
#include "processes.h"
#include "log.h"
#include "errors.h"
#include "help.h"

int main(int argc, char *argv[]) {
    int opt;
    char *log_path = NULL;
    char *errors_path = NULL;

    while ((opt = getopt(argc, argv, "uphl:e:")) != -1) {
        switch (opt) {
            case 'u':
                if (log_path) {
                    log_to_file(log_path);
                }
                users();
                break;
            case 'p':
                if (log_path) {
                    log_to_file(log_path);
                }
                processes();
                break;
            case 'h':
                help();
                return 0;
            case 'l':
                log_path = optarg;
                break;
            case 'e':
                errors_path = optarg;
                errors_to_file(errors_path);
                break;
            default:
                fprintf(stderr, "Unknown option: %c\n", opt);
                help();
                return 1;
        }
    }

    return 0;
}
