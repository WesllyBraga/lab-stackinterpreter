#include <stdio.h>
#include <stdlib.h>
#include "interpret.h"

#define MAX_LINE_LENGTH 256

static void repl() {
    char line[MAX_LINE_LENGTH];
    for (;;) {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)) {
            printf("\n");
            break;
        }
        interpret(line);
    }
}

int interpret_file(const char* path) {
    FILE* file = fopen(path, "r");
    if (!file) {
        perror(path);
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        interpret(line);
    }

    if (fclose(file)) {
        perror(path);
        return EXIT_FAILURE;
    }

    return 0;
}

int main(int argc, char** argv) {
    interpreter_init();

    if (argc == 1) {
        repl();
    } else {
        interpret_file(argv[1]);
    }
    return 0;
}
