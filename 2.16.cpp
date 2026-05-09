// GITHUB L4ZY404

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// ==========================================
// CLASE VERIFICADOR DE NÚMEROS AMIGOS
// ==========================================
class VerificadorAmigos {
private:
    long long numero1;
    long long numero2;
    vector<long long> divisoresNum1;
    vector<long long> divisoresNum2;
    long long suma1;
    long long suma2;

    // Método privado optimizado para encontrar divisores y sumarlos
    long long CalcularSumaDivisores(long long n, vector<long long>& listaDivisores) {
        long long suma = 0;
        
        if (n <= 1) return 0;

        // El 1 siempre es divisor propio
        listaDivisores.push_back(1);
        suma += 1;

        // Optimizamos iterando solo hasta la raíz cuadrada de n
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                listaDivisores.push_back(i);
                suma += i;

                // Si i y n/i son diferentes, agregamos el par correspondiente
                if (i * i != n) {
                    listaDivisores.push_back(n / i);
                    suma += (n / i);
                }
            }
        }

        // Ordenamos los divisores para que la impresión en pantalla sea limpia
        std::sort(listaDivisores.begin(), listaDivisores.end());
        return suma;
    }

public:
    // Constructor
    VerificadorAmigos(long long n1, long long n2) : numero1(n1), numero2(n2) {
        suma1 = CalcularSumaDivisores(numero1, divisoresNum1);
        suma2 = CalcularSumaDivisores(numero2, divisoresNum2);
    }

    // Método que verifica la condición cruzada
    bool SonAmigos() const {
        // Deben ser números diferentes entre sí
        if (numero1 == numero2) return false;

        return (suma1 == numero2) && (suma2 == numero1);
    }

    // Método para imprimir el desglose de la comprobación matemática
    void MostrarDesglose() const {
        cout << "\n\033[36mComprobación Matemática:\033[0m\n";
        
        // Desglose del Número 1
        cout << "Divisores de " << numero1 << ": ";
        for (size_t i = 0; i < divisoresNum1.size(); i++) {
            cout << divisoresNum1[i];
            if (i < divisoresNum1.size() - 1) cout << " + ";
        }
        cout << " = \033[1;33m" << suma1 << "\033[0m\n";

        // Desglose del Número 2
        cout << "Divisores de " << numero2 << ": ";
        for (size_t i = 0; i < divisoresNum2.size(); i++) {
            cout << divisoresNum2[i];
            if (i < divisoresNum2.size() - 1) cout << " + ";
        }
        cout << " = \033[1;33m" << suma2 << "\033[0m\n";
    }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    long long n1, n2;
    string opcion;

    do {
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ----    Números Amigos     ----\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---------- BY L4ZY404 ---------\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n\n";

        cout << "Ingrese el primer número entero positivo: ";
        while (!(cin >> n1) || n1 <= 0) {
            cout << "\033[31mError. Ingrese un valor entero mayor a 0:\033[0m ";
            cin.clear();
            while (cin.get() != '\n') {}
        }

        cout << "Ingrese el segundo número entero positivo: ";
        while (!(cin >> n2) || n2 <= 0) {
            cout << "\033[31mError. Ingrese un valor entero mayor a 0:\033[0m ";
            cin.clear();
            while (cin.get() != '\n') {}
        }

        // Instanciación del objeto evaluador
        VerificadorAmigos verificador(n1, n2);
        
        verificador.MostrarDesglose();

        // Evaluación final
        if (verificador.SonAmigos()) {
            cout << "\n\033[1;32m[✓] RESULTADO: ¡El par (" << n1 << " y " << n2 << ") SÍ son Números Amigos!\033[0m\n\n";
        } else {
            cout << "\n\033[1;31m[X] RESULTADO: El par (" << n1 << " y " << n2 << ") NO son Números Amigos.\033[0m\n\n";
        }

        cout << "¿Desea verificar otro par de números? (S/N): ";
        cin >> opcion;
        cout << "\n";

    } while (opcion == "S" || opcion == "s");

    cout << "\033[32mSaliendo del programa...\033[0m\n";
    return 0;
}