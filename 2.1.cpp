// GITHUB L4ZY404

#include <iostream>
#include <cmath>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Función reutilizable para validar entradas (basada en tu lógica)
double GetValidInput(const string& prompt) {
    double val = 0;
    while (true) {
        cout << prompt;
        if (cin >> val && val > 0) {
            if (cin.peek() == '\n') break; 
        }
        cout << "\033[31mError. El valor debe ser un número positivo válido.\033[0m\n";
        cin.clear(); 
        while (cin.get() != '\n') {} 
    }
    return val;
}

// ==========================================
// CLASE BASE ABSTRACTA
// ==========================================
class FiguraGeometrica {
public:
    virtual double CalcularArea() const = 0;
    virtual double CalcularPerimetro() const = 0;
    virtual ~FiguraGeometrica() {}
    
    void MostrarResultados(const string& nombreFigura) const {
        cout << "\n\033[36mResultados para el " << nombreFigura << ":\033[0m\n";
        cout << "Área: " << CalcularArea() << "\n";
        cout << "Perímetro: " << CalcularPerimetro() << "\n\n";
    }
};

// ==========================================
// CLASES DERIVADAS
// ==========================================

class Cuadrado : public FiguraGeometrica {
private:
    double lado;
public:
    Cuadrado(double l) : lado(l) {}
    double CalcularArea() const override { return lado * lado; }
    double CalcularPerimetro() const override { return 4 * lado; }
};

class Rectangulo : public FiguraGeometrica {
private:
    double base, altura;
public:
    Rectangulo(double b, double a) : base(b), altura(a) {}
    double CalcularArea() const override { return base * altura; }
    double CalcularPerimetro() const override { return 2 * (base + altura); }
};

class Triangulo : public FiguraGeometrica {
private:
    double a, b, c;
public:
    Triangulo(double l1, double l2, double l3) : a(l1), b(l2), c(l3) {}
    double CalcularPerimetro() const override { return a + b + c; }
    double CalcularArea() const override {
        // Fórmula de Herón
        double s = CalcularPerimetro() / 2;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

class Circulo : public FiguraGeometrica {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double CalcularArea() const override { return M_PI * radio * radio; }
    double CalcularPerimetro() const override { return 2 * M_PI * radio; }
};

class Rombo : public FiguraGeometrica {
private:
    double diagMayor, diagMenor, lado;
public:
    Rombo(double dM, double dm, double l) : diagMayor(dM), diagMenor(dm), lado(l) {}
    double CalcularArea() const override { return (diagMayor * diagMenor) / 2; }
    double CalcularPerimetro() const override { return 4 * lado; }
};

class Trapecio : public FiguraGeometrica {
private:
    double baseMayor, baseMenor, altura, lado1, lado2;
public:
    Trapecio(double bM, double bm, double h, double l1, double l2) 
        : baseMayor(bM), baseMenor(bm), altura(h), lado1(l1), lado2(l2) {}
    double CalcularArea() const override { return ((baseMayor + baseMenor) * altura) / 2; }
    double CalcularPerimetro() const override { return baseMayor + baseMenor + lado1 + lado2; }
};

class PoligonoRegular : public FiguraGeometrica {
private:
    int numLados;
    double lado, apotema;
public:
    PoligonoRegular(int n, double l, double a) : numLados(n), lado(l), apotema(a) {}
    double CalcularPerimetro() const override { return numLados * lado; }
    double CalcularArea() const override { return (CalcularPerimetro() * apotema) / 2; }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    int opcion = 0;

    do {
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ----   Calculadora Geom.   ----\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---------- BY L4ZY404 ---------\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n\n";
        
        cout << "1. Cuadrado\n2. Rectángulo\n3. Triángulo\n4. Círculo\n";
        cout << "5. Rombo\n6. Trapecio\n7. Polígono Regular\n8. Salir\n\n";
        
        while (true) {
            cout << "Seleccione una opción (1-8): ";
            if (cin >> opcion && opcion >= 1 && opcion <= 8) {
                if (cin.peek() == '\n') break; 
            }
            cout << "\033[31mError. Ingrese una opción válida.\033[0m\n";
            cin.clear(); 
            while (cin.get() != '\n') {} 
        }

        if (opcion == 8) {
            cout << "\033[32mSaliendo del programa...\033[0m\n";
            break;
        }

        FiguraGeometrica* figura = nullptr;

        switch(opcion) {
            case 1: {
                double l = GetValidInput("Ingrese el lado del cuadrado: ");
                figura = new Cuadrado(l);
                figura->MostrarResultados("Cuadrado");
                break;
            }
            case 2: {
                double b = GetValidInput("Ingrese la base: ");
                double a = GetValidInput("Ingrese la altura: ");
                figura = new Rectangulo(b, a);
                figura->MostrarResultados("Rectángulo");
                break;
            }
            case 3: {
                cout << "\033[36mNota: La suma de dos lados siempre debe ser mayor al tercero.\033[0m\n";
                double a = GetValidInput("Ingrese el lado 1: ");
                double b = GetValidInput("Ingrese el lado 2: ");
                double c = GetValidInput("Ingrese el lado 3: ");
                figura = new Triangulo(a, b, c);
                figura->MostrarResultados("Triángulo");
                break;
            }
            case 4: {
                double r = GetValidInput("Ingrese el radio: ");
                figura = new Circulo(r);
                figura->MostrarResultados("Círculo");
                break;
            }
            case 5: {
                double dM = GetValidInput("Ingrese la diagonal mayor: ");
                double dm = GetValidInput("Ingrese la diagonal menor: ");
                double l = GetValidInput("Ingrese el lado: ");
                figura = new Rombo(dM, dm, l);
                figura->MostrarResultados("Rombo");
                break;
            }
            case 6: {
                double bM = GetValidInput("Ingrese la base mayor: ");
                double bm = GetValidInput("Ingrese la base menor: ");
                double h = GetValidInput("Ingrese la altura: ");
                double l1 = GetValidInput("Ingrese el lado oblicuo 1: ");
                double l2 = GetValidInput("Ingrese el lado oblicuo 2: ");
                figura = new Trapecio(bM, bm, h, l1, l2);
                figura->MostrarResultados("Trapecio");
                break;
            }
            case 7: {
                int n = GetValidInput("Ingrese el número de lados: "); // Lo toma como double pero se trunca en el constructor
                double l = GetValidInput("Ingrese la medida del lado: ");
                double a = GetValidInput("Ingrese el apotema: ");
                figura = new PoligonoRegular(n, l, a);
                figura->MostrarResultados("Polígono Regular");
                break;
            }
        }

        // Liberar la memoria dinámica
        if (figura != nullptr) {
            delete figura;
        }

    } while (opcion != 8);

    return 0;
}