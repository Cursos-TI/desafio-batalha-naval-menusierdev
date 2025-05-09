#include <stdio.h>
#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Aplica uma matriz de habilidade no tabuleiro com centro na origem
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna) {
    int offset = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTab = origemLinha + (i - offset);
            int colunaTab = origemColuna + (j - offset);

            // Verifica limites do tabuleiro
            if (linhaTab >= 0 && linhaTab < TAM_TABULEIRO && colunaTab >= 0 && colunaTab < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }
}

// Gera matriz cone (origem no topo, expande para baixo)
void gerarCone(int cone[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= (TAM_HABILIDADE / 2 - i) && j <= (TAM_HABILIDADE / 2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// Gera matriz cruz (linha e coluna centrais)
void gerarCruz(int cruz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// Gera matriz octaedro (forma de losango)
void gerarOctaedro(int octaedro[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }
}

int main() {
    // Tabuleiro 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Coloca alguns navios (valor 3)
    tabuleiro[2][2] = 3;
    tabuleiro[4][4] = 3;
    tabuleiro[7][7] = 3;

    // Matrizes de habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // Gerar habilidades
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Exibir habilidades separadamente
    printf("Aplicando Cone no tabuleiro (centro em [2][2]):\n");
    aplicarHabilidade(tabuleiro, cone, 2, 2);
    imprimirTabuleiro(tabuleiro);

    printf("Aplicando Cruz no tabuleiro (centro em [5][5]):\n");
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    imprimirTabuleiro(tabuleiro);

    printf("Aplicando Octaedro no tabuleiro (centro em [7][7]):\n");
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);
    imprimirTabuleiro(tabuleiro);

    return 0;
}
