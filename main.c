#include <stdio.h>//printf e scanf (entrada e saída).
#include <stdlib.h>//malloc, realloc, free e atoi.
#include <string.h>//strlen, strcmp e strcpy.

char* soma(char* a, char* b) {
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;//i e j começam no último dígito de a e b.
    int vai = 0;//vai-um da soma.
    int pos = 0;//Controla a posição do vetor auxiliar.

    int tam;
	if (strlen(a) > strlen(b)) {
    		tam = strlen(a) + 1;
	} else {
    	tam = strlen(b) + 1;
	}//Define o tamanho máximo do resultado
	
    char* aux;
	aux = malloc((tam + 1) * sizeof(char));//Aloca memória para armazenar o resultado invertido.

	while (i >= 0 || j >= 0 || vai) {//Continua enquanto ainda houver dígitos ou vai-um.
    	int x = 0;
    	int y = 0;//Dígitos atuais de a e b.

    	if (i >= 0) {
      	  x = a[i] - '0';
    	}//Converte caractere para número.

    	if (j >= 0) {
        	y = b[j] - '0';
    	}//Converte caractere para número.

    	int s = x + y + vai;//Soma os dígitos com o vai-um.
    	aux[pos++] = (s % 10) + '0';//Guarda o dígito da soma
    	vai = s / 10;//Atualiza o vai-um.

    	i--;
    	j--;//Move para o próximo dígito à esquerda.
	}

    aux[pos] = '\0';//Finaliza a string auxiliar.

    char* r = (char*) malloc((pos + 1) * sizeof(char));//Aloca memória para o resultado final.
    for (int k = 0; k < pos; k++)
        r[k] = aux[pos - 1 - k];//Inverte a string

    r[pos] = '\0';
    free(aux);
    return r;//Libera memória e retorna o resultado.
}

char* subtracao(char* a, char* b) {
    int neg = 0;//Indica se o resultado será negativo.
    if (strlen(a) < strlen(b) || 
       (strlen(a) == strlen(b) && strcmp(a, b) < 0)) {//Verifica se a < b.
        char* t = a;
        a = b;
        b = t;
        neg = 1;//Troca os números e marca resultado negativo.
    }

    int i = strlen(a) - 1; 
    int j = strlen(b) - 1;//Começa do último dígito.
    int emp = 0;//Empréstimo da subtração.
    int pos = 0;

    char* aux = malloc(strlen(a) + 1);//Vetor auxiliar para o resultado invertido.
    while (i >= 0) {
        int x = (a[i] - '0') - emp;//Subtrai o empréstimo do dígito atual.
        int y;

		if (j >= 0) {
    		y = b[j] - '0';
		} else {
    		y = 0;
		}//Se b acabou, usa 0.

        if (x < y) {
            x += 10;
            emp = 1;
        } else {
            emp = 0;
        }//Trata o empréstimo.

        aux[pos++] = (x - y) + '0';//Guarda o resultado parcial.
        i--;
        j--;
    }

    while (pos > 1 && aux[pos - 1] == '0')
        pos--;//Remove zeros à esquerda

    char* r = (char*) malloc((pos + neg + 1) * sizeof(char));
    int k = 0;

    if (neg)
        r[k++] = '-';

    for (int i = 0; i < pos; i++)
        r[k++] = aux[pos - 1 - i];

    r[k] = '\0';
    free(aux);
    return r;
}

char* multiplicacao(char* a, char* b) {
    char* r = malloc(2);
    strcpy(r, "0");//Inicializa o resultado como "0".

    for (int i = strlen(b) - 1; i >= 0; i--) {//Percorre os dígitos de b.
        int d = b[i] - '0';//Converte o dígito para inteiro.

        for (int j = 0; j < d; j++) {//Repete a soma d vezes.
            char* tmp = soma(r, a);
            free(r);
            r = tmp;//Atualiza o resultado acumulado.
        }

        if (i != strlen(b) - 1) {//Verifica se precisa deslocar casas decimais.
            int t = strlen(r);
            r = realloc(r, t + 2);
            r[t] = '0';
            r[t + 1] = '\0';//Adiciona um zero ao final (multiplicação por 10).
        }
    }

    return r;//Retorna o produto final.
}

char* exponenciacao(char* a, char* b) {
    int e = atoi(b);//Converte o expoente para inteiro.

    char* r = malloc(2);//Inicializa o resultado como 1.
    strcpy(r, "1");

    for (int i = 0; i < e; i++) {//Repete a multiplicação e vezes.
        char* tmp = multiplicacao(r, a);
        free(r);
        r = tmp;//Atualiza o resultado.
    }

    return r;//Retorna a potência.
}

char* fatorial(char* a) {
    int n = atoi(a);//Converte o número para inteiro.

    char* r = malloc(2);
    strcpy(r, "1");//Inicializa o fatorial como 1.

    for (int i = 2; i <= n; i++) {//Calcula o fatorial.
        char s[20];
        sprintf(s, "%d", i);//Converte i para string.

        char* tmp = multiplicacao(r, s);
        free(r);
        r = tmp;//Multiplica o resultado.
    }

    return r;//Retorna o fatorial.
}
int main() {
    int op;
    char a[100000], b[100000];
    char* res;

    do {
        printf("\n=== CALCULADORA DE NUMEROS GRANDES ===\n");
        printf("1 - Soma\n");
        printf("2 - Subtracao\n");
        printf("3 - Multiplicacao\n");
        printf("4 - Exponenciacao\n");
        printf("5 - Fatorial\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        if (op == 1) {
            printf("A: ");
            scanf("%s", a);
            printf("B: ");
            scanf("%s", b);
            res = soma(a, b);
        } 
        else if (op == 2) {
            printf("A: ");
            scanf("%s", a);
            printf("B: ");
            scanf("%s", b);
            res = subtracao(a, b);
        } 
        else if (op == 3) {
            printf("A: ");
            scanf("%s", a);
            printf("B: ");
            scanf("%s", b);
            res = multiplicacao(a, b);
        } 
        else if (op == 4) {
            printf("Base: ");
            scanf("%s", a);
            printf("Expoente: ");
            scanf("%s", b);
            res = exponenciacao(a, b);
        } 
        else if (op == 5) {
            printf("Numero: ");
            scanf("%s", a);
            res = fatorial(a);
        } 
        else if (op == 0) {
            printf("Encerrando...\n");
            continue;
        } 
        else {
            printf("Opcao invalida!\n");
            continue;
        }

        printf("Resultado: %s\n", res);
        free(res);

    } while (op != 0);

    return 0;
}
