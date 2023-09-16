#include <stdio.h>
#include "indices.h"
#include "operacoesUsuario.h"

int main() {
    FILE *movies;   //arquivo de dados
    FILE *iprimary; //arquivo de índice primário
    FILE *ititle;   //arquivo de índice secundário (título em português)
    IndiceP *primarioMem;    //índice primário na memória
    IndiceS *secundarioMem;  //índice secundário na memória

    short int op; //operação sendo executada pelo usuário no menu

    //processo de inicialização do programa ----------------------------------------------------------------------------

    /*
    *  verifica se existe um arquivo de dados
    *      se existe, abre para escrita e leitura
    *      se não existe, cria o arquivo para escrita e leitura
    */
    movies = fopen("data/movies.dat", "r+");
    if (!movies) //se é NULL
        movies = fopen("data/movies.dat", "w+");

    /*
     *  verifica se existem arquivos de índice
     *      se existirem, verifica se estão consistentes com o arquivo de dados (flag no cabeçalho)
     *          se estão consistentes, carregar na memória
     *          senão, refazer os índices na memória
     *      senão, criar os índices na RAM
     */
    iprimary = fopen("data/iprimary.idx", "r+");
    if (iprimary) {
        int flag = fgetc(iprimary); //reads the very first character, the flag
        if (!flag)
            primarioMem = lerP(iprimary); //carrega na memória a partir do arquivo iprimary.idx
        else
            primarioMem = refazerP(movies); //refaz o índice na memória a partir do arquivo de filmes
    } else {
        iprimary = fopen("data/iprimary.idx", "w+");

        primarioMem = refazerP(movies); //faz o índice na memória a partir do arquivo de filmes
    }

    ititle = fopen("data/ititle.idx", "r+");
    if (ititle) {
        int flag = fgetc(ititle); //reads the very first character, the flag
        if (!flag)
            secundarioMem = lerS(ititle); //carrega na memória a partir do arquivo iprimary.idx
        else {
            secundarioMem = refazerS(movies); //refaz o índice na memória a partir do arquivo de filmes
        }
    } else {
        ititle = fopen("data/ititle.idx", "w+");
        secundarioMem = refazerS(movies); //refaz o índice na memória a partir do arquivo de filmes
    }

    //menu do usuário --------------------------------------------------------------------------------------------------
    do {
        puts("\n---------GERENCIADOR DE FILMES--------");
        puts("1. Inserir filme");
        puts("2. Remover filme");
        puts("3. Modificar nota");
        puts("4. Buscar filme");
        puts("5. Listar filmes");
        puts("0. Encerrar programa");
        scanf("%hd", &op);
        clearBuffer();

        switch (op) {
            case 1:
                inserirFilme(movies, iprimary, ititle);
                break;
            case 2:
                removerFilme(movies, primarioMem, iprimary, ititle);
                break;
            case 3:
                modificarNota(movies, primarioMem, iprimary, ititle);
                break;
            case 4:
                buscarFilme(movies, primarioMem, secundarioMem);
                break;
            case 5:
                listarFilmes(movies);
                break;
            case 0:
                puts("Encerrando programa...");
                break;
            default:
                puts("\tERRO: Opcao nao reconhecida");
                break;
        }
    } while (op != 0);

    //finalização do programa ------------------------------------------------------------------------------------------
    //atualizar arquivos de índices no disco
    saveIndiceP(primarioMem, iprimary);
    saveIndiceS(secundarioMem, ititle);

    //fechar os arquivos
    fclose(movies);
    fclose(iprimary);
    fclose(ititle);

    //liberar a memória alocada
    freeIndiceP(primarioMem);
    freeIndiceS(secundarioMem);

    return 0;
}
