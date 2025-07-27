#include <stdio.h>
// Desafio Batalha Naval - MateCheck
// Nível Novato - Posicionamento dos Navios

void exibirTabuleiro(int tabuleiro[10][10])// Função que imprime o tabuleiro
{
    for (int i = 0; i < 10; i++) //Loop que percorre a matriz e exibe as linhas do tabuleiro
    {
        for (int j = 0; j < 10; j++) //Loop que percorre a matriz e exibe as colunas do tabuleiro
        {
            printf("%d ", tabuleiro[i][j]); //Imprime o tabuleiro
        };
        printf("\n");//Quebra de linha para exibir o tabuleiro em forma 
    };

}

int main() {
    int navioL, navioC; //Declara as variáveis para o número da linha e da coluna da posição dos navios
    int tabuleiro[10][10] = { //Declara e inicializa a matriz que exibirá o tabuleiro
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    printf("Bem-vindo à Batalha Naval! Veja o tabuleiro abaixo:\n\n");
    exibirTabuleiro(tabuleiro); //Chama a função que exibe o tabuleiro
    printf("\n\nVamos inserir dois navios!\n");
    
    //NAVIO VERTICAL
    printf("Vamos começar pelo navio em sentido vertical...\n");
    printf("Informe a linha que você deseja colocar seu navio (de 0 a 7): ");
    scanf("%d", &navioL);//Lê a linha que o usuário deseja colocar o navio (apenas até 7 para que não saia do tabuleiro)
    while(navioL > 7 || navioL < 0)// Verifica se a linha está dentro dos limites do tabuleiro
    {
        printf("Não dá pra colocar o navio aí! Tente outra linha.\n");
        printf("Informe a linha que você deseja colocar seu navio (de 0 a 7): ");
        scanf("%d", &navioL);//Lê a linha que o usuário deseja colocar o navio (apenas até 7 para que não saia do tabuleiro)
    }
    
    printf("\nInforme a coluna que você deseja colocar seu navio (de 0 a 9): ");
    scanf("%d", &navioC);//Lê a coluna que o usuário deseja colocar o navio
    while(navioC > 9 || navioC < 0)// Verifica se a coluna está dentro dos limites do tabuleiro
        {
            printf("Não dá pra colocar o navio aí! Tente outra coluna.\n");
            printf("Informe a coluna que você deseja colocar seu navio (de 0 a 9): ");
            scanf("%d", &navioC);//Lê a coluna que o usuário deseja colocar o navio
        }


    //INSERÇÃO DO NAVIO VERTICAL
    for (int i = navioL; i < navioL + 3; i++) //Loop que percorre a linha escolhida
    {
        for (int j = navioC; j < navioC + 1; j++) //Loop que percorre a coluna escolhida
        {
            tabuleiro[i][j] = 3; //Preenche as respectivas linhas e colunas com 3 (representando o Navio Vertical)
        }
    };
        

    //NAVIO HORIZONTAL
    printf("Agora, vamos posicionar o navio horizontal...\n");
    printf("\nInforme a linha que você deseja colocar seu navio (de 0 a 9): ");
    scanf("%d", &navioL); //Lê a linha que o usuário deseja colocar o navio
    while(navioL > 9 || navioL < 0)// Verifica se a linha está dentro dos limites do tabuleiro
    {
        printf("Não dá pra colocar o navio aí! Tente outra linha.\n");
        printf("Informe a linha que você deseja colocar seu navio (de 0 a 9): ");
        scanf("%d", &navioL);//Lê a linha que o usuário deseja colocar o navio
    }

    printf("\nInforme a coluna que você deseja colocar seu navio (de 0 a 7): ");
    scanf("%d", &navioC);//Lê a coluna que o usuário deseja colocar o navio (apenas até 7 para que não saia do tabuleiro)

    while(navioC > 7 || navioC < 0)// Verifica se a coluna está dentro dos limites do tabuleiro
    {
        printf("Não dá pra colocar o navio aí! Tente outra coluna.\n");
        printf("Informe a coluna que você deseja colocar seu navio (de 0 a 7): ");
        scanf("%d", &navioC);//Lê a coluna que o usuário deseja colocar o navio (apenas até 7 para que não saia do tabuleiro)
    }

    //VERIFICAÇÃO DE SOBREPOSIÇÃO
    for (int i = navioL, j = navioC; i < navioL + 1, j < navioC + 3; j++) //Loop que percorre a linha e coluna escolhidas
    {
        while (tabuleiro[i][j] != 0)//Verifica e executa o código enquanto a linha e coluna estiverem ocupadas
        {
            if(i != 0)// Executa se a linha já estiver ocupada
            {
                printf("Não dá pra colocar o navio aí! Tente novamente.\n");
                printf("Informe a linha que você deseja colocar seu navio (de 0 a 9): ");
                scanf("%d", &navioL);//Lê a linha que o usuário deseja colocar o navio
                while(navioL > 9 || navioL < 0)// Verifica se a linha está dentro dos limites do tabuleiro
                {
                    printf("Não dá pra colocar o navio nessa linha! Tente outra.\n");
                    printf("Informe a linha que você deseja colocar seu navio (de 0 a 9): ");
                    scanf("%d", &navioL);//Lê a linha que o usuário deseja colocar o navio
                }
                i = navioL;// Atualiza o valor da linha
            }

            if(j != 0)// Executa se a coluna já estiver ocupada
            {
                printf("\nInforme a coluna que você deseja colocar seu navio (de 0 a 7): ");
                scanf("%d", &navioC);//Lê a coluna que o usuário deseja colocar o navio (apenas até 7 para que não saia do tabuleiro)
                while(navioC > 7 || navioC < 0)// Verifica se a coluna está dentro dos limites do tabuleiro
                {
                    printf("Não dá pra colocar o navio aí! Tente outra coluna.\n");
                    printf("Informe a coluna que você deseja colocar seu navio (de 0 a 7): ");
                    scanf("%d", &navioC);//Lê a coluna que o usuário deseja colocar o navio (apenas até 7 para que não saia do tabuleiro)
                }
                j = navioC;// Atualiza o valor da coluna
            }
        }
    }


    //INSERÇÃO DO NAVIO HORIZONTAL
    for (int i = navioL; i < navioL + 1; i++) //Loop que percorre a linha escolhida
    {
        for (int j = navioC; j < navioC + 3; j++) //Loop que percorre a coluna esscolhida
        {
            tabuleiro[i][j] = 3; //Preenche as respectivas linhas e colunas com 3 (representando o Navio Horizontal)
        }
    };

    //IMPRESSÃO DO NAVIO PREENCHIDO
    printf("Muito bem! Veja agora o tabuleiro preenchido!\n\n");
    exibirTabuleiro(tabuleiro); //Chama a função que exibe o tabuleiro preenchido

    printf("\n\n"); //Adiciona quebras de linha para melhor visualização no terminal
    return 0;// Finaliza o programa
}
