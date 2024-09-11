# Jogo de Adivinhação em C

## Descrição

Este é um jogo de adivinhação desenvolvido em C. O objetivo do jogo é adivinhar um número secreto entre 0 e 99 gerado aleatoriamente. O jogador pode escolher entre três níveis de dificuldade, que determinam o número de tentativas permitidas. O jogo fornece feedback sobre se o chute do jogador é maior ou menor do que o número secreto e ajusta a pontuação com base na precisão do chute.

## Níveis de Dificuldade

- **Fácil:** 20 tentativas
- **Médio:** 15 tentativas
- **Difícil:** 6 tentativas

## Como Jogar

1. **Compile o código fonte:**
   ```bash
   gcc -o main main.c
2. **Execute o jogo:**
   ```bash
   ./main.exe
3. **Escolha o nível de dificuldade:** O jogo oferece três opções:
[1] Fácil
[2] Médio
[3] Difícil

4. **Faça suas tentativas:** O jogo pedirá para você inserir um número e informará se o chute foi maior ou menor que o número secreto. Você perderá pontos com base na diferença entre o seu chute e o número secreto.

5. **Jogue novamente:** Após o término do jogo, você pode optar por jogar novamente digitando [1]. Caso contrário, o jogo será encerrado.

## Exemplo de Execução
************************************
 Bem-vindo ao Jogo de Adivinhacao 
************************************

Voce comeca com 1000.00 pontos

Qual modo voce gostaria de jogar?
[1] Facil    [2] Medio    [3] Dificil

Escolha: 2

-> Tentativa 1 de 15 

Chute um numero: 
45

Voce errou!
Seu chute foi maior do que o numero secreto, voce perdeu 22.50 pontos

-> Tentativa 2 de 15

Chute um numero: 
30

Voce errou!
Seu chute foi menor do que o numero secreto, voce perdeu 15.00 pontos

...

Parabens, voce acertou!
Voce fez 935.00 pontos

Digite [1] se deseja jogar novamente

## Requisitos
**Sistema Operacional:** Qualquer sistema operacional que suporte o compilador GCC.

**Compilador:** GCC (ou compatível).

## Contribuições
Contribuições são bem-vindas! Se você encontrar problemas ou tiver sugestões de melhorias, sinta-se à vontade para abrir uma issue ou enviar um pull request.
