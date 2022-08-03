// Shared via Compiler App https://g633x.app.goo.gl/TPlw
#include <stdio.h>

int main()
{
	int d, d_total=0;
	float a_pagar, total_hotel=0;
	char nome[100], endereco [100], fone[15], cidade[50], estado[50];

	for(int i=0; i<2; i++){
		printf("Qual o nome do hospede?\n");
		scanf(" %[^\n]s", &nome);

		printf("Qual o endereço do hospede?\n");
		scanf(" %[^\n]s", &endereco);

		printf("Qual o telefone do hospede?\n");
		scanf(" %[^\n]s", &fone);

		printf("Qual a cidade do hospede?\n");
		scanf(" %[^\n]s", &cidade);

		printf("Qual o estado do hospede?\n");
		scanf(" %[^\n]s", &estado);

		printf("Quantas diárias o hospede ficou?\n");
		scanf(" %d", &d);

		if(d<15){
			a_pagar = 300.00 * d + 20.00;
			} else if(d>15) {
				a_pagar = 300.00 * d + 12.00;
				} else {
				 a_pagar = 300.00 * d + 14.00;
					}

		d_total += d;
		total_hotel += a_pagar;

    printf("---------------\n");
		printf("%s\n%s\n%s\n%s\n%s\n", nome, endereco, fone, cidade, estado);
		printf("O total a ser pago por esse hóspede é %.2f\n\n", a_pagar);
		}

  printf("---------------\n");
	printf("O hotel faturou um total de %.2f\n", total_hotel);
		printf("O total de diárias foi de %d", d_total);

	return 0;
}
