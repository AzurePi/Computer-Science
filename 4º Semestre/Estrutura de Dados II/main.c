#include <stdio.h>
#include <string.h>
#include "filmes.h"
#include "indices.h"
#include "operacoesUsuario.h"


int main() {
    FILE *movies;   //arquivo de dados
    FILE *iprimary; //arquivo de índice primário
    FILE *ititle;   //arquivo de índice secundário (título em português)
    IndiceP *primarioMem;    //índice primário na memória
    IndiceS *secundarioMem;  //índice secundário na memória

    int op; //operação sendo executada pelo usuário no menu

    //processo de inicialização do programa ----------------------------------------------------------------------------

    /*
    *  verifica se existe um arquivo de dados
    *      se existe, abre para escrita e leitura
    *      se não existe, cria o arquivo para escrita e leitura
    */
    movies = fopen("movies.dat", "r+");
    if (!movies) //se é NULL
        movies = fopen("movies.dat", "w+");

    /*
     *  verifica se existem arquivos de índice
     *      se existirem, verifica se estão consistentes com o arquivo de dados (flag no cabeçalho)
     *          se estão consistentes, carregar na memória
     *          senão, refazer os índices na memória
     *      senão, criar os índices na RAM
     */
    iprimary = fopen("iprimary.idx", "r+");
    if (iprimary) {
        int flag = fgetc(iprimary); //reads the very first character, the flag
        if (!flag)
            primarioMem = readIndiceP(iprimary); //carrega na memória
        else {
            primarioMem = newIndiceP();
            //refaz o índice na memória a partir do arquivo de filmes
        }
    } else {
        iprimary = fopen("iprimary.idx", "w+");

        primarioMem = newIndiceP();
        //refaz o índice na memória a partir do arquivo de filmes
    }


    ititle = fopen("ititle.idx", "r+");
    if (ititle) {
        int flag = fgetc(ititle); //reads the very first character, the flag
        if (!flag)
            secundarioMem = readIndiceS(ititle); //carrega na memória
        else {
            secundarioMem = newIndiceS();
            //refaz o índice na memória a partir do arquivo de filmes
        }
    } else {
        ititle = fopen("ititle.idx", "w+");

        secundarioMem = newIndiceS();
        //refaz o índice na memória a partir do arquivo de filmes
    }

    //menu do usuário --------------------------------------------------------------------------------------------------
    do {
        printf("1. Inserir filme\n");
        printf("2. Remover filme\n");
        printf("3. Modificar nota\n");
        printf("4. Buscar filme\n");
        printf("5. Listar filmes\n");
        printf("0. Encerrar programa\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                inserirFilme();
                break;
            case 2:
                removerFilme();
                break;
            case 3:
                modificarNota();
                break;
            case 4:
                buscarFilme();
                break;
            case 5:
                listarFilmes();
                break;
            case 0:
                printf("Encerrando programa");
                break;
            default:
                printf("Opção não reconhecida");
                break;
        }
        printf("\n");
    } while (op != 0);

    //finalização do programa ------------------------------------------------------------------------------------------
    //atualizar arquivos de índices no disco

    //fechar os arquivos
    fclose(movies);
    fclose(iprimary);
    fclose(ititle);
    //liberar a memória alocada

    return 0;
}


