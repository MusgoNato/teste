# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <locale.h>
# include "funcoes.h"

/*Compilar
gcc jessica.c -o jessica.exe funcoes.c -Wall -pedantic -Wextra -Werror*/

/*Executar
jessica.exe*/

/*Main principal*/
int main() {
    int opcao;

    /*Dependendo do So pode variar, ou seja, em alguns casos a configuração do sistema operacional pode ser "PT-BR", "pt-br" ou ate mesmo "brazilian"*/
    setlocale(LC_ALL, "Portuguese");
    do 
    {
        /*Menu do programa*/
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

        /*Escolha das opcoes disponiveis*/
        switch (opcao) 
        {
            case 1:
                cadastrarLivros();
                break;
            case 2:
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
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    /*Retorno da funcao*/
    return 0;
}