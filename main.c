#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int jogarNovamente= 1; // Flag para jogar novamente

	while (jogarNovamente) {
		printf("************************************\n");
		printf("* Bem-vindo ao Jogo de Adivinhacao *\n");
		printf("************************************\n\n");

		int segundos = time(0);   // Pega os segundos da data atual
		srand(segundos);        // Inicializa o gerador de números aleatórios
		                
		int numeroSecreto = rand() % 100;   // Gera um número de 0 a 99
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

		// Define o número de tentativas com base na dificuldade escolhida
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

		// Loop para o jogador usar as tentativas
		for (int i = 1; i <= tentativas; i++) {

			printf("-> Tentativa %d de %d\n", i, tentativas);
			printf("Chute um numero: ");
			scanf("%d", &chute);
		
			int ultimoChute;
			int acertou = chute == numeroSecreto;
			int maior = chute > numeroSecreto;
			int menor = chute < numeroSecreto;	           
			double pontosPerdidos = abs(chute - numeroSecreto) / 2.0;	// Calcule os pontos perdidos
			pontos = pontos - pontosPerdidos;

			// Verifica se o chute foi um número negativo
			if (chute < 0) {
				printf("Nao e permitido valores negativos, tente novamente\n\n");
				i--;
				continue;
			}

			// Verifica se o chute foi igual ao chute anterior
			if (ultimoChute == chute) {
				printf("Voce chutou esse numero na ultima tentativa, tente novamente\n\n");
				i--;
				continue;
			}

			// Verifica se o chute é igual ao número secreto
			if (acertou) {
				ganhou = 1;
				break;
		
			} else {
				printf("Voce errou!\n");

				// Verifica se o chute foi maior
				if (maior) {
					printf("Seu chute foi maior do que o numero secreto, voce perdeu %.2f pontos\n\n", pontosPerdidos);
				}

				// Verifica se o chute foi menor
				if (menor) {
					printf("Seu chute foi menor do que o numero secreto, voce perdeu %.2f pontos\n\n", pontosPerdidos);
				}
			}
			ultimoChute = chute;
		}

		// Mensagem final de acordo com o resultado
		if (ganhou) {
			printf("Parabens, voce acertou!\n");
			printf("Voce fez %.2f pontos\n", pontos);
		
		} else {
			printf("Voce perdeu!\n");
		}

		// Pergunta se o jogador deseja jogar novamente
		printf("\n");
		printf("Digite [1] se deseja jogar novamente\n");
		scanf("%d", &jogarNovamente);

		if (jogarNovamente != 1) {
			jogarNovamente = 0;
			printf("Obrigada por jogar!\n");
		}
	}
}