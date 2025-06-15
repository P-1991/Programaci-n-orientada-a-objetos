#include <iostream>
#include <cmath> // Para M_PI

class FigGeoPrinter {
public:
    virtual void PrintDetails() = 0;
};

class FigGeo {
protected:
    float area;

public:
    virtual float calcArea() = 0;
    float getArea() {
        return area;
    }
    void saveArea() {
        if (area == 0) {
            std::cout << "calculando area..." << std::endl;
            area = calcArea();
        }
    }
};

class Circle : public FigGeo, public FigGeoPrinter {
private:
    float radius;

public:
    Circle(float inData) : radius(inData) {
        area = 0;
    }

    float calcArea() override {
        return M_PI * radius * radius;
    }

    void PrintDetails() override {
        std::cout << "radio = " << radius << ", area = " << area << std::endl;
    }
};

int main() {
  Circle c(5.0);
  c.saveArea(); // Calcula el área
  c.PrintDetails(); // Imprime los detalles del círculo
  return 0;
}
