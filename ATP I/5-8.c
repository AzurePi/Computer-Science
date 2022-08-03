#include <stdio.h>
#include <locale.h>

int main()
{
	int prodQ[5], o, p, aux, p2;
	float prodP[5], auxf;
	
	setlocale(LC_ALL, "Portuguese");
	
	for(p=0; p<5; p++){
		prodQ[p] = 0;
		prodP[p] = 0;
	}
	
	do{
		printf("\tMENU\n");
		printf("1 - Aumentar Estoque\n");
		printf("2 - Diminuir Estoque\n");
		printf("3 - Visualizar Estoque de um Produto\n");
		printf("4 - Visualizar Estoque Total\n");
		printf("5 - Aumentar Preço\n");
		printf("6 - Diminuir Preço\n");
		printf("7 - Trocar Produto\n");
		printf("8 - Sair\n");
		do{
			scanf("%d", &o);
			if(o>8 || o<1){
				printf("\nOpção inválida\n");
			}
		}while(o>8 || o<1);
		
		printf("\n\n");
	
		switch(o){
			case 1:
				do{
					printf("Selecione o produto (0 a 4): ");
					scanf("%d", &p);
					if(p>4){
						printf("\nProduto inválido\n");
					}
				}while(p>4);
				printf("\nQuantidade a aumentar: ");
				scanf("%d", &aux);
				prodQ[p] += aux;
				break;
			case 2:
				do{
					printf("Selecione o produto (0 a 4): ");
					scanf("%d", &p);
					if(p>4){
						printf("\nProduto inválido\n");
					}
				}while(p>4);
				printf("\nQuantidade a diminuir: ");
				scanf("%d", &aux);
				prodQ[p] -= aux;
				break;
			case 3:
				do{
					printf("Selecione o produto (0 a 4): ");
					scanf("%d", &p);
					if(p>4){
						printf("\nProduto inválido\n");
					}
				}while(p>4);
				printf("\nEstoque do produto %d: %d", p, prodQ[p]);
				break;
			case 4:
				printf("\n\tEstoque Total");
				printf("\nProduto 0: %d", prodQ[p]);
				printf("\nProduto 1: %d", prodQ[1]);
				printf("\nProduto 2: %d", prodQ[2]);
				printf("\nProduto 3: %d", prodQ[3]);
				printf("\nProduto 4: %d", prodQ[4]);
				break;
			case 5:
				do{
					printf("Selecione o produto (0 a 4): ");
					scanf("%d", &p);
					if(p>4){
						printf("\nProduto inválido\n");
					}
				}while(p>4);
				printf("\nAumento de preço: ");
				scanf("%f", &auxf);
				prodP[p] += auxf;
				break;
			case 6:
				do{
					printf("Selecione o produto (0 a 4): ");
					scanf("%d", &p);
					if(p>4){
						printf("\nProduto inválido\n");
					}
				}while(p>4);
				printf("\nDiminuição de preço: ");
				scanf("%f", &auxf);
				prodP[p] -= auxf;
				break;
			case 7:
				do{
					do{
						printf("Selecione o produto (0 a 4) a ser trocado: ");
						scanf("%d", &p);
						if(p>4){
							printf("\nProduto inválido\n");
						}
					}while(p>4);
					printf("Selecione a quantidade a trocar: ");
					scanf("%d", &aux);
					do{
						printf("\nSelecione o produto (0 a 4) pelo qual trocar: ");
						scanf("%d", &p2);
						if(p>4){
							printf("\nProduto inválido\n");
						}
					}while(p>4);
					if(p==p2){
						printf("\nSelecione dois produtos diferentes\n");
					}
				}while(p==p2);
				prodQ[p] -= aux;
				prodQ[p2] += aux;
				break;
			default: break;
		}
	
	printf("\n\n");
	}while(o!=8);
	
	return 0;
}