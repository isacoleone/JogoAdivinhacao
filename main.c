#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int jogarNovamente;

	while (jogarNovamente) {
		printf("************************************\n");
		printf("* Bem-vindo ao Jogo de Adivinhacao *\n");
		printf("************************************\n\n");

		int segundos = time(0);  //pegando os segundos da data
		srand(segundos);        //fazendo com que o numero gerado pelo rand() seja diferente
		                
		int numeroSecreto = rand() % 100;
		int ganhou = 0;
		int chute;
		double pontos = 1000;
		int tentativas;
		int dificuldade;


		printf("Voce comeca com %.2f pontos\n\n", pontos);
		printf("Qual modo voce gostaria de jogar?\n");
		printf("[1] Facil    [2] Medio    [3] Dificil\n\n");
		printf("Escolha: ");
		scanf("%d", &dificuldade);

		switch (dificuldade) {
			case 1:
				tentativas = 20;
				break;
			case 2:
				tentativas = 15;
				break;
			default:
				tentativas = 6;
				break;
		}

		for (int i = 1; i <= tentativas; i++) {

			printf("-> Tentativa %d de %d\n", i, tentativas);
			printf("Chute um numero: ");
			printf("\n");
			scanf("%d", &chute);
		
			int ultimoChute;
			int acertou = chute == numeroSecreto;
			int maior = chute > numeroSecreto;
			int menor = chute < numeroSecreto;	            //tambem poderia usar o (double) para converter
			double pontosPerdidos = abs(chute - numeroSecreto) / 2.0;	 //abs() transforma o numero em positivo
			pontos = pontos - pontosPerdidos;

			if (chute < 0) {
				printf("Nao e permitido valores negativos, tente novamente\n\n");
				i--;
				continue;
			}
			if (ultimoChute == chute) {
				printf("Voce chutou esse numero na ultima tentativa, tente novamente\n\n");
				i--;
				continue;
			}
			if (acertou) {
				ganhou = 1;
				break;
		
			} else {
				printf("Voce errou!\n");

				if (maior) {
					printf("Seu chute foi maior do que o numero secreto, voce perdeu %.2f pontos\n\n", pontosPerdidos);
				}
				if (menor) {
					printf("Seu chute foi menor do que o numero secreto, voce perdeu %.2f pontos\n\n", pontosPerdidos);
				}
			}
			ultimoChute = chute;
		}
		if (ganhou) {
			printf("Parabens, voce acertou!\n");
			printf("Voce fez %.2f pontos\n", pontos);
		
		} else {
			printf("Voce perdeu!\n");
		}
		printf("Digite [1] se deseja jogar novamente\n");
		scanf("%d", &jogarNovamente);

		if (jogarNovamente != 1) {
			jogarNovamente = 0;
			printf("Obrigada por jogar!\n");
		}
	}
}