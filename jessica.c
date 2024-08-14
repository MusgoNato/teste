#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

/*void listarLivros();
void pesquisarLivroPorTitulo();
void FazerEmprestimo();
void Devolverlivro();
void salvarLivro(Livro livro);
void salvarEmprestimo(Emprestimo emprestimo);*/

int main() {
    int opcao;
    do {
        printf("\nSistema de Cadastro e Empréstimo de Livros\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Pesquisar Livro por Título\n");
        printf("4. Realizar Empréstimo\n");
        printf("5. Realizar Devolução\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao) {
        case 1:
            cadastrarLivros();
            break;
        /*case 2:
            listarLivros();
            break;
        case 3:
            pesquisarLivroPorTitulo();
            break;
        case 4:
            FazerEmprestimo();
            break;
        case 5:
            Devolverlivro();
            break;*/
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
        } while (opcao != 0);
    return 0;
}


/*
void listarLivros() {
    FILE *arquivo = fopen(ARQUIVO_LIVROS, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de livros.\n");
        return;
    }
    Livro livro;
    printf("\nLista de Livros:\n");
    while (fscanf(arquivo, "%d|%99[^|]|%99[^|]|%d\n", &livro.id, livro.titulo, livro.autor, &livro.ano) != EOF) {
        printf("ID: %d\nTítulo: %s\nAutor: %s\nAno: %d\n\n", livro.id, livro.titulo, livro.autor, livro.ano);
    }
    fclose(arquivo);
}

void pesquisarLivroPorTitulo() {
    char tituloPesquisa[MAX_TITULO];
    printf("Digite o título do livro que deseja pesquisar: ");
    fgets(tituloPesquisa, MAX_TITULO, stdin);
    tituloPesquisa[strcspn(tituloPesquisa, "\n")] = 0;
    FILE *arquivo = fopen(ARQUIVO_LIVROS, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de livros.\n");
    return;
}
Livro livro;
int encontrado = 0;
while (fscanf(arquivo, "%d|%99[^|]|%99[^|]|%d\n", &livro.id, livro.titulo, livro.autor, &livro.ano) != EOF) {
if (strstr(livro.titulo, tituloPesquisa) != NULL) {
printf("ID: %d\nTítulo: %s\nAutor: %s\nAno: %d\n\n", livro.id, livro.titulo, livro.autor, livro.ano);
encontrado = 1;
}
}
if (!encontrado) {
printf("Nenhum livro encontrado com o título '%s'.\n", tituloPesquisa);
}
fclose(arquivo);
}

void FazerEmprestimo() {
    Emprestimo emprestimo;
    printf("ID do Livro: ");
    scanf("%d", &emprestimo.idLivro);
    getchar();
    printf("Usuário: ");
    fgets(emprestimo.usuario, MAX_USUARIO, stdin);
    emprestimo.usuario[strcspn(emprestimo.usuario, "\n")] = 0;
    printf("Data (AAAA-MM-DD): ");
    fgets(emprestimo.data, 10, stdin);
    emprestimo.data[strcspn(emprestimo.data, "\n")] = 0;
    salvarEmprestimo(emprestimo);
}

void Devolverlivro() {
    int idLivro;
    printf("ID do Livro a ser devolvido: ");
    scanf("%d", &idLivro);
    getchar();
    FILE *arquivo = fopen(ARQUIVO_EMPRESTIMOS, "r");
    if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo de empréstimos.\n");
    return;
}
Emprestimo emprestimo;
FILE *temp = fopen("temp.txt", "w");
if (temp == NULL) {
printf("Erro ao abrir o arquivo temporário.\n");
fclose(arquivo);
return;
}
int encontrado = 0;
while (fscanf(arquivo, "%d|%99[^|]|%9[^\n]\n", &emprestimo.idLivro, emprestimo.usuario, emprestimo.data) != EOF) {
if (emprestimo.idLivro != idLivro || idLivro < 0) {
fprintf(temp, "%d|%s|%s\n", emprestimo.idLivro, emprestimo.usuario, emprestimo.data);
} else {
encontrado = 1;
}
}
fclose(arquivo);
fclose(temp);
remove(ARQUIVO_EMPRESTIMOS);
rename("temp.txt", ARQUIVO_EMPRESTIMOS);
if (encontrado) {
printf("Devolução realizada com sucesso!\n");
} else {
printf("Nenhum empréstimo encontrado para o livro com ID %d.\n", idLivro);
}
}

void salvarLivro(Livro livro) {
    FILE *arquivo = fopen(ARQUIVO_LIVROS, "a");
    if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo de livros.\n");
    return;
    }
    fprintf(arquivo, "%d|%s|%s|%d\n", livro.id, livro.titulo, livro.autor, livro.ano);
    fclose(arquivo);
    printf("Livro cadastrado com sucesso!\n");
}

void salvarEmprestimo(Emprestimo emprestimo) {
    FILE *arquivo = fopen(ARQUIVO_EMPRESTIMOS, "a");
    if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo de empréstimos.\n");
    return;
    }
    fprintf(arquivo, "%d|%s|%s\n", emprestimo.idLivro, emprestimo.usuario, emprestimo.data);
    fclose(arquivo);
    printf("Empréstimo realizado com sucesso!\n");
}*/
