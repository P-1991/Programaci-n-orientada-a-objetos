#include <iostream>
using namespace std;

// Interfaz FigGeoPrinter (solo imprime)
class FigGeoPrinter {
public:
    virtual void PrintDetails() = 0;
};

// Interfaz del repositorio
class IRepo {
public:
    virtual int Save(float area) = 0;
    virtual float GetArea(int index) = 0;
    virtual ~IRepo() {}
};

// Repositorio con arreglo 
class FloatArrRepo : public IRepo {
protected:
    float database[100];
    int currentIndex;
public:
    FloatArrRepo() : currentIndex(0) {
        for (int i = 0; i < 100; i++) {
            database[i] = 0.0;
        }
    }

    int Save(float area) override {
        if (currentIndex < 100) {
            database[currentIndex] = area;
            return currentIndex++;
        } else {
            cout << "Base de datos llena\n";
            return -1;
        }
    }

    float GetArea(int index) override {
        if (index >= 0 && index < currentIndex) {
            return database[index];
        } else {
            cout << "indice invalido\n";
            return -1;
        }
    }
};

// Interfaz FigGeo y clase Repo
class IRepoFigGeo {
public:
    virtual void SaveArea(float area) = 0;
    virtual float GetArea(int index) = 0;
    virtual ~IRepoFigGeo() {}
};

//  implementacion de IRepoFigGeo
class RepoMySql : public IRepoFigGeo {
    FloatArrRepo repo;
public:
    void SaveArea(float area) override {
        cout << "[MySQL] Area guardada: " << area << "\n";
        repo.Save(area);
    }

    float GetArea(int index) override {
        return repo.GetArea(index);
    }
};

class RepoCSV : public IRepoFigGeo {
    FloatArrRepo repo;
public:
    void SaveArea(float area) override {
        cout << "[CSV] Area guardada: " << area << "\n";
        repo.Save(area);
    }

    float GetArea(int index) override {
        return repo.GetArea(index);
    }
};

// Clase abstracta 
class FigGeo {
protected:
    float area;
    IRepoFigGeo* repo; 
public:
    FigGeo(IRepoFigGeo* r) : area(0), repo(r) {}

    virtual float calcArea() = 0;

    float getArea() {
        return area;
    }

    void saveArea() {
        if (area == 0) {
            area = calcArea();
            if (repo)
                repo->SaveArea(area);
        }
    }
};

// Clases y herencia
class Square : public FigGeo, public FigGeoPrinter {
    float width;
public:
    Square(IRepoFigGeo* r) : FigGeo(r), width(1.0) {}
    Square(float inData, IRepoFigGeo* r) : FigGeo(r), width(inData) {}

    float calcArea() override {
        return width * width;
    }

    void PrintDetails() override {
        cout << "Cuadrado -> ancho = " << width << ", area = " << area << "\n";
    }

    void setWidth(float value) {
        width = value;
    }
};

class Triangle : public FigGeo, public FigGeoPrinter {
    float base;
    float height;
public:
    Triangle(IRepoFigGeo* r) : FigGeo(r), base(1.0), height(1.0) {}
    Triangle(float b, float h, IRepoFigGeo* r) : FigGeo(r), base(b), height(h) {}

    float calcArea() override {
        return (base * height) / 2;
    }

    void PrintDetails() override {
        cout << "Triangulo -> base = " << base << ", altura = " << height << ", area = " << area << "\n";
    }

    void setBase(float value) {
        base = value;
    }

    void setHeight(float value) {
        height = value;
    }
};

class Circle : public FigGeo, public FigGeoPrinter {
    float radius;
public:
    Circle(IRepoFigGeo* r) : FigGeo(r), radius(1.0) {}
    Circle(float rVal, IRepoFigGeo* r) : FigGeo(r), radius(rVal) {}

    float calcArea() override {
        return 3.14 * radius * radius;
    }

    void PrintDetails() override {
        cout << "Circulo -> radio = " << radius << ", area = " << area << "\n";
    }

    void setRadius(float value) {
        radius = value;
        area = 0;
    }
};

int main() {
    RepoMySql mysqlRepo;
    RepoCSV csvRepo;

    Square sqr(1.0, &mysqlRepo);
    sqr.saveArea();
    sqr.PrintDetails();

    Triangle tri(1.0, 1.0, &mysqlRepo);
    tri.saveArea();
    tri.PrintDetails();

    Circle cir(1.0, &mysqlRepo);
    cir.saveArea();
    cir.PrintDetails();

    return 0;
}
