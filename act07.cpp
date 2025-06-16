#include <iostream>
#include <cmath>
#include <memory>

class FigGeoPrinter {
public:
    virtual void PrintDetails() = 0;
    virtual ~FigGeoPrinter() = default;
};

class FigGeo {
protected:
    float area;
public:
    virtual float calcArea() = 0;
    float getArea() { return area; }
    void saveArea() {
        if (area == 0.0f) {
            std::cout << "calculando area..." << std::endl;
            area = calcArea();
        } else {
            std::cout << "El area ya ha sido calculada: " << area << std::endl;
        }
    }
    virtual ~FigGeo() = default;
};

class Circle : public FigGeo, public FigGeoPrinter {
private:
    float radius;
public:
    Circle(float inData) : radius(inData) {
        area = 0.0f;
        std::cout << "  > Circulo creado con radio: " << radius << std::endl;
    }
    float calcArea() override { return M_PI * radius * radius; }
    void PrintDetails() override {
        std::cout << "  radio = " << radius << ", area = " << area << std::endl;
    }
};

class Square : public FigGeo, public FigGeoPrinter {
private:
    float side;
public:
    Square(float inData) : side(inData) {
        area = 0.0f;
        std::cout << "  > Cuadrado creado con lado: " << side << std::endl;
    }
    float calcArea() override { return side * side; }
    void PrintDetails() override {
        std::cout << "  lado = " << side << ", area = " << area << std::endl;
    }
};

enum class TipoFigura {
    CIRCULO,
    CUADRADO
};

class FigGeoFactory {
public:
    static std::unique_ptr<FigGeo> createFigure(TipoFigura type, float parameter) {
        std::cout << "\nFabrica recibio solicitud para crear figura..." << std::endl;
        switch (type) {
            case TipoFigura::CIRCULO:
                return std::make_unique<Circle>(parameter);
            case TipoFigura::CUADRADO:
                return std::make_unique<Square>(parameter);
        }
        std::cerr << "Error: Tipo de figura no manejado por la fabrica." << std::endl;
        return nullptr;
    }
};

int main() {
    std::cout << "--- Demostración Enfocada del Patrón Factory (sin tipo 'DESCONOCIDO') ---\n" << std::endl;

    std::cout << "Cliente: Necesito un Circulo con radio 5.0." << std::endl;
    std::unique_ptr<FigGeo> myCircle = FigGeoFactory::createFigure(TipoFigura::CIRCULO, 5.0f);

    if (myCircle) {
        myCircle->saveArea();
        std::cout << "Cliente: Area del circulo = " << myCircle->getArea() << std::endl;
        
        FigGeoPrinter* printer = dynamic_cast<FigGeoPrinter*>(myCircle.get());
        if (printer) {
            printer->PrintDetails();
        } else {
            std::cerr << "Error: No se pudo obtener la interfaz FigGeoPrinter para myCircle." << std::endl;
        }
    }

    std::cout << "\n=========================================\n" << std::endl;

    std::cout << "Cliente: Necesito un Cuadrado con lado 7.0." << std::endl;
    std::unique_ptr<FigGeo> mySquare = FigGeoFactory::createFigure(TipoFigura::CUADRADO, 7.0f);

    if (mySquare) {
        mySquare->saveArea();
        std::cout << "Cliente: Area del cuadrado = " << mySquare->getArea() << std::endl;
        
        FigGeoPrinter* printer = dynamic_cast<FigGeoPrinter*>(mySquare.get());
        if (printer) {
            printer->PrintDetails();
        } else {
            std::cerr << "Error: No se pudo obtener la interfaz FigGeoPrinter para mySquare." << std::endl;
        }
    }

    std::cout << "\n--- Fin de la demostración Factory ---" << std::endl;

    return 0;
}
