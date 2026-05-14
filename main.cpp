#include <iostream>
#include "mapeamento.hpp"

using namespace std;

Mapeamento mapeamento;
 
int main(){
    mapeamento.mapearCoordenadas();
    mapeamento.calcularDistancia();
    mapeamento.calcularMedia();

    return 0;
}