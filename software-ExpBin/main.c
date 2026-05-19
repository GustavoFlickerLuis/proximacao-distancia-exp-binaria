#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "distancia.h"

void benchmark(){
    int total_testes = 100000;
    double soma_erro = 0;
    double soma_erro_percentual = 0;
    double erro_maximo = 0;
    int pior_caso_x1, pior_caso_y1, pior_caso_x2, pior_caso_y2;
    int casos_aceitaveis = 0;
    
    srand(time(NULL));
    
    clock_t inicio = clock();
    
    for(int i = 0; i < total_testes; i++){
        int x1 = rand() % 1000;
        int y1 = rand() % 1000;
        int x2 = rand() % 1000;
        int y2 = rand() % 1000;
        
        int resultado_binario = distanciaExpBinAuto(x1, y1, x2, y2);
        double resultado_real = distanciaEuclidiana(x1, y1, x2, y2);
        
        double erro = fabs(resultado_binario - resultado_real);
        double erro_percentual = (resultado_real > 0) ? (erro / resultado_real) * 100 : 0;
        
        soma_erro += erro;
        soma_erro_percentual += erro_percentual;
        
        if(erro_percentual < 5.0) casos_aceitaveis++;
        
        if(erro > erro_maximo){
            erro_maximo = erro;
            pior_caso_x1 = x1; pior_caso_y1 = y1;
            pior_caso_x2 = x2; pior_caso_y2 = y2;
        }
    }
    
    clock_t fim = clock();
    double tempo_total = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("=== RELATORIO DO BENCHMARK ===\n\n");
    printf("Testes realizados: %d\n", total_testes);
    printf("Tempo de execucao: %.6f segundos\n\n", tempo_total);
    
    printf("--- Metricas de Erro ---\n");
    printf("Erro medio absoluto: %.4f unidades\n", soma_erro / total_testes);
    printf("Erro medio percentual: %.2f%%\n", soma_erro_percentual / total_testes);
    printf("Erro maximo: %.4f unidades\n", erro_maximo);
    printf("Casos com erro < 5%%: %d (%.2f%%)\n\n", 
           casos_aceitaveis, (casos_aceitaveis * 100.0) / total_testes);
    
    printf("--- Pior Caso Detectado ---\n");
    printf("P1(%d,%d) -> P2(%d,%d)\n", pior_caso_x1, pior_caso_y1, pior_caso_x2, pior_caso_y2);
    printf("Distancia real: %.4f\n", distanciaEuclidiana(pior_caso_x1, pior_caso_y1, pior_caso_x2, pior_caso_y2));
    printf("Distancia aproximada: %d\n", distanciaExpBinAuto(pior_caso_x1, pior_caso_y1, pior_caso_x2, pior_caso_y2));
    printf("Erro: %.4f\n", fabs(distanciaExpBinAuto(pior_caso_x1, pior_caso_y1, pior_caso_x2, pior_caso_y2) - 
                                 distanciaEuclidiana(pior_caso_x1, pior_caso_y1, pior_caso_x2, pior_caso_y2)));
}

int main()
{
    benchmark();
    return 0;
}