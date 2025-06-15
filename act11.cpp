#include <iostream> 
#include <vector>   
#include <memory>   
#include <string>   



// Interfaz para figuras geométricas
class FigGeo {
public:

    virtual float calcularArea() = 0;

    virtual void ImprimirDetalles() = 0;
    virtual ~FigGeo() = default;
};

class FigGeoImpresora {
public:
    virtual void ImprimirDetallesFigGeo(FigGeo* fig) = 0;
    virtual ~FigGeoImpresora() = default;
};


class RepositorioVector {
private:
    std::vector<float> areas; 

public:
    void Guardar(float area) {
        areas.push_back(area);
        std::cout << "Área guardada en repositorio: " << area << std::endl;
    }

    float ObtenerArea(int id) {
        if (id >= 0 && id < areas.size()) {
            return areas[id];
        }
        std::cerr << "Error: ID inválido para ObtenerArea. ID: " << id << std::endl;
        return -1.0f; 
    }

    void ImprimirTodasLasAreas() const {
        if (areas.empty()) {
            std::cout << "\n--- No hay áreas almacenadas en el repositorio ---" << std::endl;
            return;
        }
        std::cout << "\n--- Áreas Almacenadas en Repositorio ---" << std::endl;
        for (size_t i = 0; i < areas.size(); ++i) {
            std::cout << "ID " << i << ": " << areas[i] << std::endl;
        }
        std::cout << "------------------------------------------\n" << std::endl;
    }

    const std::vector<float>& obtenerVectorAreas() const {
        return areas;
    }
};



class Circulo : public FigGeo {
private:
    float radio;
    const float PI = 3.14159f;
    RepositorioVector* punteroRepositorio; 
public:

    Circulo(float r, RepositorioVector* repo) : radio(r), punteroRepositorio(repo) {
        std::cout << "Circulo creado con radio: " << radio << std::endl;
    }

    
    float calcularArea() override {
        return PI * radio * radio;
    }

    
    void ImprimirDetalles() override {
        float area = calcularArea();
        std::cout << "Detalles del Círculo:" << std::endl;
        std::cout << "  Radio: " << radio << std::endl;
        std::cout << "  Área Calculada: " << area << std::endl;
    
    }


    void guardarAreaEnRepositorio() {
        if (punteroRepositorio) {
            float area = calcularArea();
            punteroRepositorio->Guardar(area);
        } else {
            std::cerr << "Error: Repositorio no establecido para el Círculo. No se pudo guardar el área." << std::endl;
        }
    }
};

class ImpresoraSimpleFigGeo : public FigGeoImpresora {
public:
    void ImprimirDetallesFigGeo(FigGeo* fig) override {
        if (fig) {
            std::cout << "\n--- Usando ImpresoraSimpleFigGeo ---" << std::endl;
            fig->ImprimirDetalles();
            std::cout << "------------------------------------" << std::endl;
        } else {
            std::cerr << "Error: No se pueden imprimir detalles para una figura nula." << std::endl;
        }
    }
};




int main() {
    
    RepositorioVector miRepositorio;

    Circulo cir1(5.0f, &miRepositorio); 
    Circulo cir2(7.0f, &miRepositorio);
    Circulo cir3(10.0f, &miRepositorio); 


    std::cout << "\n--- Demostración de Cálculo y Guardado de Áreas ---" << std::endl;

    float area_cir1 = cir1.calcularArea();
    miRepositorio.Guardar(area_cir1);
    std::cout << "Área de cir1 calculada: " << area_cir1 << std::endl;

    std::cout << "\nGuardando área de cir2 usando guardarAreaEnRepositorio()..." << std::endl;
    cir2.guardarAreaEnRepositorio();

    std::cout << "\nGuardando área de cir3 usando guardarAreaEnRepositorio()..." << std::endl;
    cir3.guardarAreaEnRepositorio();

    std::cout << "\n--- Recuperando Áreas del Repositorio ---" << std::endl;
    std::cout << "Área con ID 0: " << miRepositorio.ObtenerArea(0) << std::endl; // Debería ser el área de cir1
    std::cout << "Área con ID 1: " << miRepositorio.ObtenerArea(1) << std::endl; // Debería ser el área de cir2
    std::cout << "Área con ID 2: " << miRepositorio.ObtenerArea(2) << std::endl; // Debería ser el área de cir3
    std::cout << "Intentando obtener área con ID inválido (3): " << miRepositorio.ObtenerArea(3) << std::endl;

    std::cout << "\n--- Imprimiendo Detalles de Figuras ---" << std::endl;
    cir1.ImprimirDetalles();
    cir2.ImprimirDetalles();


    return 0;
}
