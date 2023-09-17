#include <stdio.h>
#include "indices.c" //troca essa porcaria por .c
#include "operacoesUsuario.c" //troca essa porcaria por .c
#include "style.h"

int main() {
    FILE *movies;           //arquivo de dados
    FILE *iprimary;         //arquivo de índice primário
    FILE *ititle;           //arquivo de índice secundário (título em português)
    IndiceP *primarioMem;   //índice primário na memória
    IndiceS *secundarioMem; //índice secundário na memória

    short int op; //operação sendo executada pelo usuário no menu

    //processo de inicialização do programa ----------------------------------------------------------------------------

    /*
    *  verifica se existe um arquivo de dados
    *      se existe, abre para escrita e leitura
    *      se não existe, cria o arquivo para escrita e leitura
    */
    movies = fopen("data/movies.dat", "r+a");
    if (movies == NULL) //se é NULL
        movies = fopen("data/movies.dat", "w+");
    if (movies == NULL) {
        puts(ERROR"\tERRO: Impossível criar arquivo");
        return 1;
    }

    /*
     *  verifica se existem arquivos de índice
     *      se existirem, verifica se estão consistentes com o arquivo de dados (flag no cabeçalho)
     *          se estão consistentes, carregar na memória
     *          senão, refazer os índices na memória
     *      senão, criar os índices na RAM
     */
    iprimary = fopen("data/iprimary.idx", "r+a");
    if (iprimary != NULL) {
        char flag = fgetc(iprimary); //reads the very first character, the flag
        if (flag == '0') {
            //printf("41main\n");
            primarioMem = lerP(iprimary); //carrega na memória a partir do arquivo iprimary.idx
            //printf("43main\n");
        } else {
            //printf("46main\n");
            primarioMem = refazerP(movies); //refaz o índice na memória a partir do arquivo de filmes
            //printf("48main\n");
        }
    } else {
        iprimary = fopen("data/iprimary.idx", "w+");

        if (iprimary == NULL) {
            puts(ERROR"\tERRO: Impossível criar arquivo");
            return 1;
        }

        primarioMem = refazerP(movies); //faz o índice na memória a partir do arquivo de filmes
    }
    fseek(iprimary, 0, SEEK_SET);
    fputc('1', iprimary);
    fclose(iprimary);

    ititle = fopen("data/ititle.idx", "r+a");
    if (ititle != NULL) {
        char flag = fgetc(ititle); //reads the very first character, the flag
        if (flag == '0') {
            //printf("68main\n");
            secundarioMem = lerS(ititle); //carrega na memória a partir do arquivo iprimary.idx
            //printf("70main\n");
        } else {
            //printf("73main\n");
            secundarioMem = refazerS(movies); //refaz o índice na memória a partir do arquivo de filmes
            //printf("75main\n");
        }
    } else {
        ititle = fopen("data/ititle.idx", "w+");

        if (ititle == NULL) {
            puts(ERROR"\tERRO: Impossível criar arquivo");
            return 1;
        }

        secundarioMem = refazerS(movies); //refaz o índice na memória a partir do arquivo de filmes
    }
    fseek(ititle, 0, SEEK_SET);
    fputc('1', ititle);
    fclose(ititle);

    //menu do usuário --------------------------------------------------------------------------------------------------
    do {
        puts(TITLE"\n---------GERENCIADOR DE FILMES--------"CLEAR);
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
                inserirFilme(movies, &primarioMem, &secundarioMem);
                break;
            case 2:
                removerFilme(movies, &primarioMem, &secundarioMem);
                break;
            case 3:
                modificarNota(movies, primarioMem);
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
                puts(ERROR"\tERRO: Opcao nao reconhecida"CLEAR);
                break;
        }
    } while (op != 0);

    //finalização do programa ------------------------------------------------------------------------------------------

    //salvar os arquivos
    fclose(movies);
    saveIndiceP(primarioMem);
    saveIndiceS(secundarioMem);

    //liberar a memória alocada
    freeIndiceP(primarioMem);
    freeIndiceS(secundarioMem);

    return 0;
}
