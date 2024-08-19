#include <stdio.h>

int main()
{

	printf("************************************\n");
	printf("* Bem-vindo ao Jogo de Adivinhacao *\n");
	printf("************************************\n");

	int numeroSecreto = 27;
	int chute;
	int ganhou = 0;
	int tentativas = 1;

	while (!ganhou) {
		printf("Qual o seu %do chute: ", tentativas);
		scanf("%d", &chute);
		printf("O seu %do chute foi o numero %d\n", tentativas, chute);

		int acertou = chute == numeroSecreto;
		int maior = chute > numeroSecreto;
		int menor = chute < numeroSecreto;
		

		if (chute < 0) {
			printf("Nao e permitido valores negativos, tente novamente\n");
			continue;
		}
		if (acertou) {
			printf("Parabens, voce acertou com %d tentativas!\n", tentativas);
			ganhou = 1;
			
		}
		else {
			printf("Voce errou!\n");

			if (maior) {
				printf("Seu chute foi maior do que o numero secreto\n");
			}
			if (menor) {
				printf("Seu chute foi menor do que o numero secreto\n");
			}
		}
		tentativas++;
	}

	printf("Fim do jogo!\n");
}