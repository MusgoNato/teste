/*Definicoes*/
# define ARQUIVO_LIVROS "livros.txt"
# define ARQUIVO_EMPRESTIMOS "emprestimos.txt"
# define MAX_TITULO 100
# define MAX_AUTOR 100
# define MAX_USUARIO 100

/*Registros*/
typedef struct {
    int id;
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int ano;
} Livro;

typedef struct {
    int idLivro;
    char usuario[MAX_USUARIO];
    char data[10];
} Emprestimo;


/*Prototipos das funcoes*/
void cadastrarLivros();

void listarLivros();

void pesquisarLivroPorTitulo();

void FazerEmprestimo();

void Devolverlivro();

void salvarLivro(Livro);

void salvarEmprestimo(Emprestimo);