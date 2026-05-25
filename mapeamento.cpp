#include "mapeamento.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

void Mapeamento::mapearCoordenadas() { // aqui é só pra pegar as coordenadas e jogar no vetor de pontos
    std::cout << "Digite a quantidade de pontos a serem mapeados: " << std::endl;
    std::cin >> qtd;
    for(int i = 0; i < qtd; i++){
        std::cout << "Digite as coordenadas (x, y): " << i + 1 << std::endl;
        std::cin >> x >> y;
        if(x > 8 || x < 0 || y > 8 || y < 0) {
            std::cout << "Coordenadas fora do limite permitido (0 a 8)." << std::endl;
            i--;
        } else {
            Pontos.push_back({x, y});
            pontosBrutos.push_back({x, y}); // pontos brutos para grafico 1
            processarPonto(x, y); // processa  o ponto 
           } 
        }
    }
 void Mapeamento::processarPonto(float px, float py) {
    bool encontrouBase = false;
    float limiteDistancia = 0.7f; 

    // Tenta encontrar uma base já mapeada que esteja perto
    for (auto& b : mapaFinal) {
        // Cálculo da Distância Euclidiana
        float d = std::sqrt(std::pow(px - b.x, 2) + std::pow(py - b.y, 2));
        
        if (d <= limiteDistancia) {
            // Média Acumulativa:
            // Atualiza o centro da base sem precisar guardar todos os pontos individualmente
            b.x = ((b.x * b.contagem) + px) / (b.contagem + 1);
            b.y = ((b.y * b.contagem) + py) / (b.contagem + 1);
            
            b.contagem++; 
            encontrouBase = true;
            break; 
        }
    }

    // Se o ponto estiver longe de todas as bases conhecidas, cria uma nova base
    if (!encontrouBase) {
        mapaFinal.push_back({px, py, 1});
    }
}

void Mapeamento::gerarArquivoPlot() {
    
    // 1. Arquivo com TODOS os pontos
    FILE* fBruto = std::fopen("pontos_brutos.txt", "w");
    if (fBruto) {
        for(size_t i = 0; i < pontosBrutos.size(); i++) {
            fprintf(fBruto, "%f %f\n", pontosBrutos[i].x, pontosBrutos[i].y);
        }
        fclose(fBruto);
    }

    // 2. Arquivo com os CENTROS das bases
    FILE* fMapa = std::fopen("mapa_final.txt", "w");
    if (fMapa) {
       for(size_t i = 0; i < mapaFinal.size(); i++) {
            fprintf(fMapa, "%f %f\n", mapaFinal[i].x, mapaFinal[i].y);
        }
        fclose(fMapa);
    }
    std::cout << "\nArquivos para os dois graficos gerados com sucesso!" << std::endl;
}

void Mapeamento::calcularDistancia() { // modulo da distancia entre os pontos
    for(size_t i = 0; i < Pontos.size(); i++){
        for(size_t j = 0; j < Pontos.size(); j++){
            dx = Pontos[i].x - Pontos[j].x;
            dy = Pontos[i].y - Pontos[j].y;
            Distancia.push_back(std::sqrt(dx * dx + dy * dy));
        }
    }
    for(size_t i = 0; i < Pontos.size(); i++) {
        for(size_t j = i + 1; j < Pontos.size(); j++) {
            std::cout << "Distancia entre os pontos (" << Pontos[i].x << ", " << Pontos[i].y << "), (" << Pontos[j].x << ", " << Pontos[j].y << "): " << Distancia[i * Pontos.size() + j] << std::endl;
        }
    }
}
  
void Mapeamento::calcularMedia(){
    std::vector<Ponto> novosPontos; 

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
        Pontos.push_back(p); 
    }
}
