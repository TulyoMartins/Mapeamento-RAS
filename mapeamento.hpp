#pragma once

#include <iostream>
#include <vector>
#include <cmath>

typedef struct {
    float x;
    float y;
} Ponto;

typedef struct { 
float x; //coordenada x 
float y; // coordenada y
int contagem; // quantas vezes o drone detectou essa base  para calcular o centro
} base ;

class Mapeamento {
    private:
        float x, y, dx, dy;
        int qtd;
        std::vector<Ponto> Pontos;
        std::vector<float> Distancia;
        std::vector<float> Media;

// para o mapeamneto e gráfico
        std::vector<Ponto> pontosBrutos; // grafico de todas as coordenadas 
        std::<Base> mapaFinal; // gráfico de coordenadas válidas 

    public:
        Mapeamento(){x = 0; y = 0; dx = 0; dy = 0; qtd = 0; Pontos = {}; Distancia = {}; Media = {}; pontosBrutos = {}; mapaFinal =;
        
        void mapearCoordenadas();
        void calcularDistancia();
        void calcularMedia();

        void processarPonto(float px, float py); // escolhe se é base existente ou nova 
        void gerarArquivoPlot();  // gera arquivos .txt para cumprir a visualização              
};
