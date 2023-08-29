#include <stdio.h>
#include "filmes.h"
#include "indices.h"
#include "operacoesUsuario.h"


int main() {
    FILE *movies;    //arquivo de dados
    FILE *iprimary; //arquivo de índice primário
    FILE *ititle;   //arquivo de índice secundário (título em português)

    int op; //operação sendo executada pelo usuário no menu

    //processo de inicialização do programa
    //verifica se existe um arquivo de dados
    //se existe, abre para escrita e leitura
    //se não existe, cria o arquivo para escrita e leitura
    //verifica se existem arquivos de índice
    //se existirem, verifica se estão consistentes com o arquivo de dados (flag no cabeçalho)
    //se estão consistentes, carregar na memória
    //senão, refazer os índices na memória
    //senão, criar os índices na RAM
    fopen("movies.dat", "r+");


    //fazer um menu com as 5 operações possíveis
    do {
        printf("1. Inserir filme\n");
        printf("2. Remover filme\n");
        printf("3. Modificar nota\n");
        printf("4. Buscar filme\n");
        printf("5. Listar movies\n");
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
                break;
            default:
                printf("Opção não reconhecida");
                break;
        }
    } while (op != 0);

    //finalização do programa
    //atualizar arquivos de índices no disco
    //fechar os arquivos
    //liberar a memória alocada

    return 0;
}


