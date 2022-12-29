#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
	int I, O, C;
	struct fila *prox;
}Fila;

Fila *forma_fila(int N);
void atender(int N, int M, Fila *head);

int main(){
	int N, M;
	Fila *head = NULL;
	
	scanf("%d %d", &N, &M);
	head = forma_fila(N);
	
	atender(N, M, head);
	/*
	Fila *aux = head;
	int i;
	for(i = 0; i<N; i++)
	{
		printf("%d -> ", aux->I);
		aux = aux->prox;
	}
	*/
	

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
	
	//enquanto o instante de chegada for maior do que o atual e não estivermos no final da fila
	while(new->O > aux->O && aux->prox != NULL)
	{
		prev = aux;
		aux = aux->prox;
	}
	
	//se os instantes coincidem
	if(new->O == aux->O)
	{	//organiza em relação ao id
		
		//se o id novo já é menor do que o que o próximo
		if(new->id < aux->id)
		{
			//se estamos no começo da fila
			if(aux == head)
			{
				new->prox = head;
				head = new;
				
				return head;
			}
			//se não estamos no começo da fila
			prev->prox = new;
			new->prox = aux;
			
			return head;
		}
		//se o id novo não é menor
		
		//anda até encontrar o lugar certo ou até o final da fila
		while(new->id > aux->id && aux->prox != NULL)
		{
			prev = aux;
			aux = new;
		}
		
		prev->prox = new;
		new->prox = aux;
	
		return head;
	}
	
	//do contrário, encontramos o local certo na fila para inserir	

	//se chegamos ao final da fila
	if(aux->prox == NULL) 
	{
		aux->prox = new;
		return head;
	}
	
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
		aux->prox = NULL; //por padrão, assumimos que é o final da fila
		
		if(head == NULL)
			head = aux;	
		else
			head = insere(aux, head);
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
		
		intante += menor_C; //saltamos no tempo até o próximo fim de atendimento
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




