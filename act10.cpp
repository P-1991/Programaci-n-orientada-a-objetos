#include <iostream> // Incluye la biblioteca iostream para entrada/salida

using namespace std; // Usa el espacio de nombres estándar para evitar escribir std::

int main() {
    // Inicializa un puntero
    // y asignale un valor entero

    int *v1 = nullptr; // Inicializa el puntero a nullptr (buena práctica)
    int value = 42;    // Valor entero de ejemplo

    v1 = &value; // Asigna la dirección de memoria de 'value' al puntero 'v1'

    cout << v1 << endl;  // Imprime la dirección de memoria a la que apunta v1
    cout << *v1 << endl; // Desreferencia el puntero para obtener el valor al que apunta (42)

    // v1++; // Esto incrementaría la dirección del puntero, no el valor al que apunta.
             // Si el objetivo es incrementar la dirección, se debe tener cuidado
             // con lo que se apunta y el tamaño de los elementos.
             // Para este ejemplo, lo dejo comentado ya que la siguiente línea
             // es lo que parece que se intenta hacer.

    cout << *v1 << endl; // Desreferencia el puntero para obtener el valor (sigue siendo 42)
    cout << *v1 << endl; // Desreferencia el puntero para obtener el valor (sigue siendo 42)

    // Incrementa el valor
    (*v1)++; // Incrementa el valor al que apunta v1 (42 se convierte en 43)

    cout << *v1 << endl;   // Imprime el valor incrementado (43)
    cout << value << endl; // Imprime el valor de 'value', que también se ha incrementado (43)

    // Asignación dinámica de memoria
    int *v2 = new int(100); // Asigna dinámicamente un entero con valor 100 y asigna su dirección a v2

    cout << *v2 << endl; // Desreferencia el puntero para obtener el valor (100)

    // Es importante liberar la memoria asignada dinámicamente para evitar fugas de memoria
    delete v2;
    v2 = nullptr; // Buena práctica para evitar punteros colgantes

    return 0; // Indica que el programa finalizó correctamente
}
