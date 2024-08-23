# include <stdio.h>
# include <string.h>
# include "funcoes.h"

/*Cadastramento dos livros*/
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
    salvarLivro(livro);
}

/*Listagem de livros*/
void listarLivros() {
    FILE *arquivo = fopen(ARQUIVO_LIVROS, "r");
    Livro livro;
    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo de livros.\n");
        return;
    }

    printf("\nLista de Livros:\n");
    while (fscanf(arquivo, "%d|%99[^|]|%99[^|]|%d\n", &livro.id, livro.titulo, livro.autor, &livro.ano) != EOF)
    {
        printf("ID: %d\nTítulo: %s\nAutor: %s\nAno: %d\n\n", livro.id, livro.titulo, livro.autor, livro.ano);
    }
    fclose(arquivo);
}

/*Responsavel pela busca do livro pelo titulo do proprio*/
void pesquisarLivroPorTitulo() {
    Livro livro;
    int encontrado = 0;
    char tituloPesquisa[MAX_TITULO];
    FILE *arquivo = fopen(ARQUIVO_LIVROS, "r");
    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo de livros.\n");
        return;
    }
    printf("Digite o título do livro que deseja pesquisar: ");
    fgets(tituloPesquisa, MAX_TITULO, stdin);
    tituloPesquisa[strcspn(tituloPesquisa, "\n")] = 0;
    
    
    while (fscanf(arquivo, "%d|%99[^|]|%99[^|]|%d\n", &livro.id, livro.titulo, livro.autor, &livro.ano) != EOF)
    {
        if (strstr(livro.titulo, tituloPesquisa) != NULL)
        {
            printf("ID: %d\nTítulo: %s\nAutor: %s\nAno: %d\n\n", livro.id, livro.titulo, livro.autor, livro.ano);
            encontrado = 1;
        }
    }
    if (!encontrado) 
    {
        printf("Nenhum livro encontrado com o título '%s'.\n", tituloPesquisa);
    }
    fclose(arquivo);
}

/*Responsavel pelo emprestimo do livro*/
void FazerEmprestimo() 
{
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

/*Responsavel pela devolucao do livro emprestado*/
void Devolverlivro() 
{
    int idLivro;
    Emprestimo emprestimo;
    FILE *temp;
    int encontrado = 0;
    FILE *arquivo;
    arquivo = fopen(ARQUIVO_EMPRESTIMOS, "r");
    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo de empréstimos.\n");
        return;
    }
    printf("ID do Livro a ser devolvido: ");
    scanf("%d", &idLivro);
    getchar();
    
    
    temp = fopen("temp.txt", "w");
    if (temp == NULL) 
    {
        printf("Erro ao abrir o arquivo temporário.\n");
        fclose(arquivo);
        return;
    }
    
    while (fscanf(arquivo, "%d|%99[^|]|%9[^\n]\n", &emprestimo.idLivro, emprestimo.usuario, emprestimo.data) != EOF) 
    {
        if (emprestimo.idLivro != idLivro || idLivro < 0) 
        {
            fprintf(temp, "%d|%s|%s\n", emprestimo.idLivro, emprestimo.usuario, emprestimo.data);
        } 
        else
        { 
            encontrado = 1;
        }
    }
    fclose(arquivo);
    fclose(temp);
    remove(ARQUIVO_EMPRESTIMOS);
    rename("temp.txt", ARQUIVO_EMPRESTIMOS);
    if (encontrado) 
    {
        printf("Devolução realizada com sucesso!\n");
    } 
    else 
    {
        printf("Nenhum empréstimo encontrado para o livro com ID %d.\n", idLivro);
    }
}

/*Responsavel por salvar o livro que em algum momento, foi modificado pelo CadastrarLivro()*/
void salvarLivro(Livro livro) 
{
    FILE *arquivo = fopen(ARQUIVO_LIVROS, "a");
    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo de livros.\n");
        return;
    }
    fprintf(arquivo, "%d|%s|%s|%d\n", livro.id, livro.titulo, livro.autor, livro.ano);
    fclose(arquivo);
    printf("Livro cadastrado com sucesso!\n");
}

/*Responsavel por salvar o emprestimo feito*/
void salvarEmprestimo(Emprestimo emprestimo) 
{
    FILE *arquivo = fopen(ARQUIVO_EMPRESTIMOS, "a");
    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo de empréstimos.\n");
        return;
    }
    fprintf(arquivo, "%d|%s|%s\n", emprestimo.idLivro, emprestimo.usuario, emprestimo.data);
    fclose(arquivo);
    printf("Empréstimo realizado com sucesso!\n");
}