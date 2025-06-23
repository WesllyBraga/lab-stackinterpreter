#include <stdio.h>

#include "interpret.h"

static void repl()
{
  char line[MAX_LINE_LENGTH];
  for (;;)
  {
    printf("> ");

    if (!fgets(line, sizeof(line), stdin))
    {
      printf("\n");
      break;
    }

    interpret(line);
  }
}


int  interpret_file (char* path) {
    FILE *file = fopen(path, "r");
    char line[MAX_LINE_LENGTH] = {0};
  
    if (!file)
    {
      perror(path);
      return EXIT_FAILURE;
    }

    while (fgets(line, MAX_LINE_LENGTH, file))
    {
    interpret(line);
    }
    
    if (fclose(file))
    {
        return EXIT_FAILURE;
        perror(path);
    }
}


int main (int argc, char **argv) {
    init_interpreter();   
    
    if (argc == 1)
        repl();
    else {
        char* path = argv[1];
        interpret_file(path);
    }
    return 0;
}
