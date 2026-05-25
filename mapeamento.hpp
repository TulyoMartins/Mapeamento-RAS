#pragma once

#include <iostream>
#include <cmath>
#include <vector>

typedef struct {
    float x;
    float y;
} Ponto;

typedef struct {
 float x;
 float y;
 int contagem;
}base ;

class Mapeamento {
    private:
 std::vector<Ponto> pontosBrutos; 
 std::vector<Base> mapaFinal;     

        float tempX, tempY;
        int qtd;

        Mapeamento() : qtd(0), tempX(0), tempY(0) {
            pontosBrutos = {};
            mapaFinal = {};
        }
        
       
 void mapearCoordenadas();

        void processarPonto(float px, float py);
        void gerarArquivoPlot();
};
