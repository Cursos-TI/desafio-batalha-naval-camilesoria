#include <stdio.h>
// Desafio Batalha Naval - MateCheck
// Nível Mestre - Habilidades Especiais com Matrizes

#define LINHAS 10 //Declara a constante que armazena o número de linhas do tabuleiro
#define COLUNAS 10 //Declara a constante que armazena o número de colunas do tabuleiro
#define HABILIDADE_LINHA 3 //Declara as constantes para as linhas das habilidades
#define HABILIDADE_COLUNA 5 //Declara as constantes para as linhas das habilidades

void inicializarTabuleiro(int tabuleiro[LINHAS][COLUNAS]){
    for (int i = 0; i < LINHAS; i++) //Loop que percorre a matriz e exibe as linhas do tabuleiro
    {
        for (int j = 0; j < COLUNAS; j++) //Loop que percorre a matriz e exibe as colunas do tabuleiro
        {
            tabuleiro[i][j] = 0; //Inicializa a matriz do tabuleiro com zero em todas as posições
        }
    }
}

void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS])// Função que imprime o tabuleiro
{
    for (int i = 0; i < LINHAS; i++) //Loop que percorre a matriz e exibe as linhas do tabuleiro
    {
        for (int j = 0; j < COLUNAS; j++) //Loop que percorre a matriz e exibe as colunas do tabuleiro
        {
            printf("%d ", tabuleiro[i][j]); //Imprime o tabuleiro
        }
        printf("\n");//Quebra de linha para exibir o tabuleiro em forma 
    }
}

int main() {
    int navioL, navioC; //Declara as variáveis para o número da linha e da coluna da posição dos navios
    int cruz[HABILIDADE_LINHA][HABILIDADE_COLUNA]; //Declara a matriz que exibirá a habilidade cruz
    int octaedro[HABILIDADE_LINHA][HABILIDADE_COLUNA]; //Declara a matriz que exibirá a habilidade octaedro
    int cone[HABILIDADE_LINHA][HABILIDADE_COLUNA]; //Declara a matriz que exibirá a habilidade cone
    int tabuleiro[LINHAS][COLUNAS];//Declara a matriz que exibirá o tabuleiro

    inicializarTabuleiro(tabuleiro); //Inicializa o tabuleiro dentro do programa

    printf("Bem-vindo à Batalha Naval! Para entender melhor o jogo, se atente aos seguintes detalhes:\n");
    printf("-> 0 significa água\n");
    printf("-> 3 significa navio\n");
    printf("-> 5 significa habilidade/efeito especial, como cones, cruzes e octaedros\n");
    printf("Pronto para começar? Veja o tabuleiro abaixo:\n\n");
    exibirTabuleiro(tabuleiro); //Chama a função que exibe o tabuleiro
    
    printf("\nVamos adicionar algumas habilidades ao nosso tabuleiro? Veja os modelos de habilidades disponíveis abaixo:\n\n");

    //INICIALIZAÇÃO E EXIBIÇÃO DA HABILIDADE CRUZ
    printf("HABILIDADE CRUZ\n");
    for (int i = 0; i < HABILIDADE_LINHA; i++) //Percorre as linhas da habilidade cruz
    {
        for (int j = 0; j < HABILIDADE_COLUNA; j++) //Percorre as colunas da habilidade cruz
        {
            //A linha abaixo verifica e executa o código se a linha for 1 OU a coluna for 2
            if(i == 1 || j == 2)
            {
                cruz[i][j] = 1;
            }
            else //Executa se as condições anteriores forem falsas
            { 
                cruz[i][j] = 0;
            }
            printf("%d ", cruz[i][j]); //Imprime a cruz
        }
        printf("\n");
    }

    printf("\n"); //Quebra de linha para tornar a visualização no terminal mais fácil

    //INICIALIZAÇÃO E EXIBIÇÃO DA HABILIDADE OCTAEDRO
    printf("HABILIDADE OCTAEDRO\n");
    for (int i = 0; i < HABILIDADE_LINHA; i++) //Percorre as linhas da habilidade octaedro
    {
        for (int j = 0; j < HABILIDADE_COLUNA; j++) //Percorre as colunas da habilidade octaedro
        {
            //A linha abaixo verifica e executa o código:
            // -> Se a coluna for 2
            // -> Se a linha for 1 E a coluna for maior que 0 E menor de 4
            if(j == 2 || (i == 1 && j > 0 && j < 4))
            {
                octaedro[i][j] = 1;
            }
            else //Executa caso as condições anteriores sejam falsas
            {
                octaedro[i][j] = 0;
            }
            printf("%d ", octaedro[i][j]); //Imprime o octaedro
        }
        printf("\n");
    }

    printf("\n"); //Quebra de linha para tornar a visualização no terminal mais fácil

    //INICIALIZAÇÃO E EXIBIÇÃO DA HABILIDADE CONE
    printf("HABILIDADE CONE\n");
    for (int i = 0; i < HABILIDADE_LINHA; i++) //Percorre as linhas da habilidade cone
    {
        for (int j = 0; j < HABILIDADE_COLUNA; j++) //Percorre as colunas da habilidade cone
        {
            //A linha abaixo verifica e executa o código:
            // -> Se a linha é 0 E a coluna não é 2
            // -> Se a linha é 1 E a coluna é 0 OU 4
            if((i == 0 && j != 2) || (i == 1 && j == 0 || i == 1 && j == 4))
            {
                cone[i][j] = 0;
            }
            else //Executa caso as condições anteriores sejam falsas
            {
                cone[i][j] = 1;
            }
            printf("%d ", cone[i][j]); //Imprime o cone
        }
        printf("\n");
    }

    printf("\nAgora, vou adicionar todas as habilidades! Vamos ver como o tabuleiro ficou?\n");

    //INSERÇÃO DE HABILIDADES NO TABULEIRO
    for (int k = 0; k < HABILIDADE_LINHA; k++) // Percorre as linhas de cada habilidade
    {
        for (int l = 0; l < HABILIDADE_COLUNA; l++) //Percorre as colunas de cada habilidade
        {
            //Adiciona a Habilidade Cruz ao tabuleiro
            if (cruz[k][l] == 1)
            {
                tabuleiro[k][l] = 5;
            }
            //Adiciona a Habilidade Octaedro ao tabuleiro
            if (octaedro[k][l] == 1)
            {
                tabuleiro[k + 2][l + 4] = 5;
            }
            //Adiciona a Habilidade Cone ao tabuleiro
            if (cone[k][l] == 1)
            {
                tabuleiro[k + 6][l + 5] = 5;
            }
        }
    }

    exibirTabuleiro(tabuleiro); //Chama a função que exibe o tabuleiro
    printf("\n"); //Quebra de linha para tornar a visualização no terminal mais fácil

    printf("Agora, vamos inserir alguns navios! Dessa vez, a inserção será feita direto no código, mas quem sabe da próxima?\n");
    printf("\n"); //Quebra de linha para tornar a visualização no terminal mais fácil

    //INSERÇÃO DO NAVIO VERTICAL
    printf("Vamos começar pelo navio em sentido vertical...\n");
    navioL = 3; //Declara a linha na qual será inserido o navio vertical
    navioC = 3; //Declara a coluna na qual será inserido o navio vertical
    for (int i = 0; i < 3; i++) //Loop que percorrerá o tabuleiro, mas diretamente na linha e coluna escolhidas
    {
        tabuleiro[navioL + i][navioC] = 3; //Preenche as respectivas linhas e colunas com 3 (representando o Navio Vertical)
    }

    exibirTabuleiro(tabuleiro); //Chama a função que exibe o tabuleiro
    printf("\n\n"); //Quebra de linha para tornar a visualização no terminal mais fácil

    //INSERÇÃO DO NAVIO HORIZONTAL
    printf("Agora, vamos posicionar o navio horizontal...\n");
    navioL = 0; //Declara a linha na qual será inserido o navio horizontal
    navioC = 5; //Declara a coluna na qual será inserido o navio horizontal
    for (int i = 0; i < 3; i++) //Loop que percorrerá o tabuleiro, mas diretamente na linha e coluna escolhidas
    {
        tabuleiro[navioL][navioC + i] = 3; //Preenche as respectivas linhas e colunas com 3 (representando o Navio Horizontal)
    }

    exibirTabuleiro(tabuleiro); //Chama a função que exibe o tabuleiro
    printf("\n\n"); //Quebra de linha para tornar a visualização no terminal mais fácil

    //INSERÇÃO DO NAVIO DIAGONAL 1
    printf("Agora, vamos posicionar o navio diagonal 1...\n");
    navioL = 6; //Declara a linha na qual será inserido o navio diagonal 1
    navioC = 0; //Declara a coluna na qual será inserido o navio diagonal 1
    for (int i = 0; i < 3; i++) //Loop que percorrerá o tabuleiro, mas diretamente na linha e coluna escolhidas
    {
        tabuleiro[navioL + i][navioC + i] = 3; //Preenche as respectivas linhas e colunas com 3 (representando o Navio Diagonal 1)
    }

    exibirTabuleiro(tabuleiro); //Chama a função que exibe o tabuleiro
    printf("\n\n"); //Quebra de linha para tornar a visualização no terminal mais fácil

    //INSERÇÃO DO NAVIO DIAGONAL 2
    printf("Agora, vamos posicionar o navio diagonal 2...\n");
    navioL = 6; //Declara a linha na qual será inserido o navio diagonal 2
    navioC = 5; //Declara a coluna na qual será inserido o navio diagonal 2
    for (int i = 0; i < 3; i++) //Loop que percorrerá o tabuleiro, mas diretamente na linha e coluna escolhidas
    {
        tabuleiro[navioL + i][navioC - i] = 3; //Preenche as respectivas linhas e colunas com 3 (representando o Navio Diagonal 2)
    }

    exibirTabuleiro(tabuleiro); //Chama a função que exibe o tabuleiro
    printf("\n\n"); //Quebra de linha para tornar a visualização no terminal mais fácil

    //IMPRESSÃO DO TABULEIRO PREENCHIDO
    printf("Muito bem! Vamos ver o tabuleiro preenchido!\n\n");
    exibirTabuleiro(tabuleiro); //Chama a função que exibe o tabuleiro preenchido

    printf("\n\n"); //Adiciona quebras de linha para melhor visualização no terminal
    return 0;// Finaliza o programa
}