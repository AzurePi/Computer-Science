#include <stdio.h>

int main(){
	//declaração de variáveis
	FILE *codigo, *palavra; //endereços dos arquivos de entrada
	FILE *linha; //endereço do arquivo de saída
	int N;
	char pal[50];
	int i;
	
	//abertura dos arquivos de entrada e saída
	codigo = fopen("codigos.dat", "r");
	palavra = fopen("palavras.dat", "r");
	linha = fopen("linhas.dat", "w");
	
	//laço que escreverá o arquivo linhas.dat até que um dos arquivos de entrada chegue ao fim
	while(!feof(codigo) && !feof(palavra))
	{
		fscanf(codigo, "%d", &N); //quantidade de palavras a serem escritas
		if(N<0)
		{
			fseek(palavra, N, SEEK_CUR); //move a leitura para trás, já que N é negativo
			for(i = 0; i<N; i++)
			{
				fscanf(palavra, "%s", pal); //lê a palavra em palavras.dat
				fprintf(linha, "%s", pal); //imprime a palavra em linhas.dat
			}
			fprintf(linha, "\n"); //pula linha
		}else if(N>0)
		{
			for(i = 0; i<N; i++)
			{
				fscanf(palavra, "%s", pal); //lê a palavra em palavras.dat
				fprintf(linha, "%s ", pal); //imprime a palavra em linhas.dat
			}
			fprintf(linha, "\n"); //pula linha
		}else //caso N = 0
		{
			fprintf(linha, "%d\n", 0);
		}
	}
	
	//imprime os códigos que faltam em linhas.dat
	while(!feof(codigo))
	{
		fscanf(codigo, "%d", &N);
		fprintf(palavra, "%d ", N);	
	}
	
	//imprime as palavras que faltam em linhas de 5
	while(!feof(palavra))
	{
		fscanf(palavra, "%s", pal);
		fprintf(linha, "%s ", pal);
		i++;
		if(i % 5 == 0)
		{
			fprintf(linha, "\n");
		}
	}
	
	return 0;
}
