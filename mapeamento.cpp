#include "mapeamento.hpp"
#include <iostream>
#include <vector>
#include <math.h>

void Mapeamento::mapearCoordenadas() { // aqui é só pra pegar as coordenadas e jogar no vetor de pontos
    std::cout << "Digite a quantidade de pontos a serem mapeados: " << std::endl;
    std::cin >> qtd;
    for(int i = 0; i < qtd; i++){
        std::cout << "Digite as coordenadas (x, y): " << std::endl;
        std::cin >> x >> y;
        if(x > 8 || x < 0 || y > 8 || y < 0) {
            std::cout << "Coordenadas fora do limite permitido (0 a 8)." << std::endl;
            i--;
        } else {
            Pontos.push_back({x, y});
        }
    }
    std::cout << "Coordenadas mapeadas: " << std::endl;
    for(size_t i = 0; i < Pontos.size(); i++) {
        std::cout << "Ponto " << i + 1 << ": (" << Pontos[i].x << "," << Pontos[i].y << ")" << std::endl;
    }
}

void Mapeamento::calcularDistancia() { // calcula o modulo da distancia entre os pontos
    for(size_t i = 0; i < Pontos.size(); i++){
        for(size_t j = 0; j < Pontos.size(); j++){
            dx = Pontos[i].x - Pontos[j].x;
            dy = Pontos[i].y - Pontos[j].y;
            Distancia.push_back(sqrt(dx * dx + dy * dy));
        }
    }
    for(size_t i = 0; i < Pontos.size(); i++) {
        for(size_t j = i + 1; j < Pontos.size(); j++) {
            std::cout << "Distancia entre os pontos (" << Pontos[i].x << ", " << Pontos[i].y << "), (" << Pontos[j].x << ", " << Pontos[j].y << "): " << Distancia[i * Pontos.size() + j] << std::endl;
        }
    }
}

void Mapeamento::calcularMedia(){
   std::vector<Ponto> novosPontos; // so pra nao incrementar o tamanho de Pontos e nao escaralhar no for

    for(size_t i = 0; i < Pontos.size(); i++){
        for(size_t j = i + 1; j < Pontos.size(); j++) {
            if(Distancia[i * Pontos.size() + j] <= 1) {
                Ponto media;
                media.x = (Pontos[i].x + Pontos[j].x) / 2;
                media.y = (Pontos[i].y + Pontos[j].y) / 2;
                novosPontos.push_back(media);
                std::cout << "Ponto medio entre os pontos (" << Pontos[i].x << ", " << Pontos[i].y << "), (" << Pontos[j].x << ", " << Pontos[j].y << "): (" << media.x << ", " << media.y << ")" << std::endl;
            }
        }
    }

    for(auto& p : novosPontos){ 
        Pontos.push_back(p); // gambiarra, mas funciona kkkkkkkkkkk
    }
}