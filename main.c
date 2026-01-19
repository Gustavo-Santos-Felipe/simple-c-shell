#include "shell.h"

void lsh_loop(void) {
  char *line;
  char **args;
  int status;

  do {
    // Prompt simples. Pode adicionar cores ou user@host depois
    printf("> ");
    line = lsh_read_line();
    args = lsh_split_line(line);
    status = lsh_execute(args);

    free(line);
    free(args);
  } while (status);
}

int main(int argc, char **argv) {
  // Configurações iniciais poderiam vir aqui
  
  // Loop principal
  lsh_loop();

  return EXIT_SUCCESS;
}
