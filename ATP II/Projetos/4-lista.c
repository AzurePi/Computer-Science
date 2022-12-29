#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
	int I, O, C;
	struct fila *prox;
}Fila;

Fila *insere(Fila *new, Fila *head);
Fila *forma_fila(int N);
void atender(int N, int M, Fila *head);

int main(){
	int N, M;
	Fila *head = NULL;
	
	scanf("%d %d", &N, &M);
	head = forma_fila(N);
	
	
	Fila *aux = head;
	int i;
	printf("\n");
	for(i = 0; i<N; i++)
	{
		printf("%d %d %d\n", aux->I, aux->O, aux->C);
		aux = aux->prox;
	}
	
	//atender(N, M, head);
	
	
	return 0;
}

//insere um elemento na lista de forma ordenada em relação ao instante de chegada
Fila *insere(Fila *new, Fila *head){
	Fila *aux = head, *prev = NULL;
	
	//se o instante do novo elemento já for menor do que o atual
	if(new->O < aux->O)
	{
		new->prox = head;
		head = new;
		return head;
	}
	
	//enquanto o instante de chegada de aux for maior do que o de new e não estivermos no final da fila
	while(new->O > aux->O && aux->prox != NULL)
	{
		prev = aux;
		aux = aux->prox;
	}
	
	//se os instantes coincidem, organiza em relação ao id
	if(new->O == aux->O)
	{	
		//se o id de new já é menor do que o que o de aux
		if(new->I < aux->I)
		{
			//e estamos no começo da fila
			if(aux == head)
			{
				new->prox = head;
				head = new;
				return head;
			}
			
			//e estamos no meio da fila
			prev->prox = new;
			new->prox = aux;
			return head;
		}
		//se o id de new não é menor que o de aux
		
		//anda até encontrar o lugar certo ou até o final da fila
		while(new->I > aux->I && aux->prox != NULL)
		{
			prev = aux;
			aux = aux->prox;
		}
		
		//se encontramos o lugar certo
		if(new->I < aux->I)
		{
			//e é o começo da fila
			if(aux == head)
			{
				new->prox = head;
				head = new;
				return head;
			}
			
			//e estamos no meio da fila
			prev->prox = new;
			new->prox = aux;
			return head;
		}
		
		//se estamos no final da fila
		aux->prox = new;
		return head;
	}
	
	//do contrário, encontramos o local certo na fila para inserir
	prev->prox = new;
	new->prox = aux;
	return head;
}

Fila *forma_fila(int N){
	Fila *head = NULL, *aux, *prev = NULL;
	int i;
	
	//lê as entradas e forma uma fila
	for(i = 0; i<N; i++)
	{
		aux = malloc(sizeof(Fila)); //a cada iteração, cria um elemento novo
		scanf("%d %d %d", &aux->I, &aux->O, &aux->C);
		aux->prox = NULL; //por padrão, assumimos que ele é o final da fila
		
		if(head == NULL) //se a fila está vazia
			head = aux;	
		else
			head = insere(aux, head); //insere por ordem de chegada
	}
	
	return head; //retorna o endereço da cabeça da fila
}

void atender(int N, int M, Fila *head){
	int *t = malloc(M * sizeof(int)); //array para guardar os instante em que o atendimento acaba em cada um dos M centros
	int i, j, instante = 0;
	int menor_C = 200;
	Fila *aux = head;
	
	//zera os instantes de cada centro
	for(i = 0; i<M; i++)
		t[i] = 0;
	
	j = N;
	while(j > 0) //enquanto houver pessoas na fila
	{
		for(i = 0; i<M; i++) //para cada um dos centros de atendimento
		{
			//se o tempo naquele centro já passou o instante em que estamos
			if(t[i] > instante)
			{
				t[i] += aux->C; //o tempo no centro
				
				
				
			}
			
		
		}
		
		instante += menor_C; //saltamos no tempo até o próximo fim de atendimento
	}

	//imprime os instantes em que o atendimento acaba em cada um dos M centros
	for(i = 0; i<M; i++)
	{
		printf("%d", t[i]);
		
		//não coloca espaço depois do último instante
		if(i != M-1)
			printf(" ");
	}
	
	return;
}
