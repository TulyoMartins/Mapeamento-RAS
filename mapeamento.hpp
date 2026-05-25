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
        float x, y, dx, dy;
        int qtd;
        std::vector<Ponto> Pontos;
        std::vector<float> Distancia;
        std::vector<float> Media;

        std::vector<Ponto> pontosBrutos; 
        std::vector<Base> mapaFinal;     

    public:
        Mapeamento(){
            x = 0; y = 0; dx = 0; dy = 0; qtd = 0; 
            Pontos = {}; Distancia = {}; Media = {};
            pontosBrutos = {}; mapaFinal = {};
        }
        
        void mapearCoordenadas();
        void calcularDistancia();
        void calcularMedia();
        void processarPonto(float px, float py);
        void gerarArquivoPlot();
};
