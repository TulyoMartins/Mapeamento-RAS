#include "mapeamento.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio> 

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
            pontosBrutos.push_back({x, y});
            processarPonto(x, y);
        }
    }
        
    std::cout << "Coordenadas mapeadas: " << std::endl;
    for(size_t i = 0; i < Pontos.size(); i++) {
        std::cout << "Ponto " << i + 1 << ": (" << Pontos[i].x << "," << Pontos[i].y << ")" << std::endl;
    }
}

void Mapeamento::processarPonto(float px, float py) {
    bool encontrou = false;
    float limitee = 0.7f;
    
    for (auto& b : mapaFinal) {
        float d = sqrt(pow(px - b.x, 2) + pow(py - b.y, 2));
        if (d <= limite) {
            // Média acumulativa  ajustar o centro  da base
            b.x = ((b.x * b.contagem) + px) / (b.contagem + 1);
            b.y = ((b.y * b.contagem) + py) / (b.contagem + 1);
            b.contagem++;
            encontrou = true;
            break;
        }
    }
    if (!encontrou) {
        mapaFinal.push_back({px, py, 1}); // Nova base encontrada
    }
}
void Mapeamento::gerarArquivoPlot() {
    //grafico 1 com tudo
    FILE* fBruto = fopen("pontos_brutos.txt", "w");
    if(fBruto) {
        for(size_t i = 0; i < pontosBrutos.size(); i++) {
            fprintf(fBruto, "%f %f\n", pontosBrutos[i].x, pontosBrutos[i].y);
        }
        fclose(fBruto);
    }

    // grafico 2 = dados processados 
    FILE* fMapa = fopen("mapa_final.txt", "w");
    if(fMapa) {
        for(size_t i = 0; i < mapaFinal.size(); i++) {
            fprintf(fMapa, "%f %f\n", mapaFinal[i].x, mapaFinal[i].y);
        }
        fclose(fMapa);
    }
    std::cout << "\nArquivos para os dois graficos gerados com sucesso!" << std::endl;
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
