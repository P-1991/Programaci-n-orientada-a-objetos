#include <iostream>
#include <cmath>  // Para M_PI y pow()

using namespace std;

// Función para calcular el área de un círculo
double areaCirculo(double radio) {
    return M_PI * pow(radio, 2);  // M_PI es el valor de pi
}

// Función para calcular el área de un cuadrado
double areaCuadrado(double lado) {
    return lado * lado;
}

// Función para calcular el área de un triángulo
double areaTriangulo(double base, double altura) {
    return (base * altura) / 2.0;
}

int main() {
    // Ejemplo de uso
    double radio = 3.0;
    double lado = 6.0;
    double base = 8.0, altura = 4.0;

    cout << "Área del círculo: " << areaCirculo(radio) << endl;
    cout << "Área del cuadrado: " << areaCuadrado(lado) << endl;
    cout << "Área del triángulo: " << areaTriangulo(base, altura) << endl;

    return 0;
}
