#pragma once

#include <iostream>
#include <math.h>
#include <vector>

typedef struct {
    float x;
    float y;
} Ponto;

class Mapeamento {
    private:
        float x, y, dx, dy;
        int qtd;
        std::vector<Ponto> Pontos;
        std::vector<float> Distancia;
        std::vector<float> Media;
    public:
        Mapeamento(){x = 0; y = 0; dx = 0; dy = 0; qtd = 0; Pontos = {}; Distancia = {}; Media = {};}
        
        void mapearCoordenadas();
        void calcularDistancia();
        void calcularMedia();
};