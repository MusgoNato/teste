/*gcc jessica.c -o jessica.exe funcoes.c -Wall -pedantic -Werror -Wextra*/
# include <stdio.h>
# include <stdlib.h>
# include "funcoes.c"

int main(int argc, char *argv[])
{
    LIVRO livro;

    argc = argc;
    argv = argv;

    Aloca_memoria(&livro);

    Menu();

    return 0;
}
