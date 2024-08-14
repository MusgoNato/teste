#include <stdio.h>
#include <string.h>
#include "funcoes.h"

void cadastrarLivros() {
    Livro livro;
    printf("ID do Livro: ");
    scanf("%d", &livro.id);
    getchar();
    printf("Título: ");
    fgets(livro.titulo, MAX_TITULO, stdin);
    livro.titulo[strcspn(livro.titulo, "\n")] = 0;
    printf("Autor: ");
    fgets(livro.autor, MAX_AUTOR, stdin);
    livro.autor[strcspn(livro.autor, "\n")] = 0;
    printf("Ano de Publicação: ");
    scanf("%d", &livro.ano);
    /*salvarLivro(livro);*/
}