// GITHUB L4ZY404

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// ==========================================
// CLASE VERIFICADOR NARCISISTA
// ==========================================
class VerificadorNarcisista {
private:
    long long numeroOriginal;
    int cantidadDigitos;

    // Método privado para contar cuántos dígitos tiene el número
    void CalcularDigitos() {
        long long temp = numeroOriginal;
        cantidadDigitos = 0;
        
        if (temp == 0) {
            cantidadDigitos = 1;
            return;
        }

        while (temp > 0) {
            cantidadDigitos++;
            temp /= 10;
        }
    }

public:
    // Constructor
    VerificadorNarcisista(long long n) : numeroOriginal(n) {
        CalcularDigitos();
    }

    // Método principal de verificación
    bool EsNarcisista() const {
        long long suma = 0;
        long long temp = numeroOriginal;

        while (temp > 0) {
            int digito = temp % 10;
            // pow() devuelve un double, usamos round() y lo convertimos a long long por precisión
            suma += static_cast<long long>(std::round(std::pow(digito, cantidadDigitos)));
            temp /= 10;
        }

        return suma == numeroOriginal;
    }

    // Método para mostrar el desglose matemático en pantalla
    void MostrarDesglose() const {
        long long temp = numeroOriginal;
        vector<int> digitos;

        // Extraer los dígitos (saldrán invertidos)
        while (temp > 0) {
            digitos.push_back(temp % 10);
            temp /= 10;
        }

        cout << "\033[36mComprobación Matemática (" << cantidadDigitos << " dígitos):\033[0m\n";
        
        long long sumaAcumulada = 0;
        // Recorremos de atrás hacia adelante para mostrar el orden correcto
        for (int i = digitos.size() - 1; i >= 0; i--) {
            int digito = digitos[i];
            long long potencia = static_cast<long long>(std::round(std::pow(digito, cantidadDigitos)));
            sumaAcumulada += potencia;

            cout << digito << "^" << cantidadDigitos;
            if (i > 0) cout << " + ";
        }
        
        cout << " = " << sumaAcumulada << "\n";
    }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    long long numero;
    string opcion;

    do {
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---- Números Narcisistas   ----\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---------- BY L4ZY404 ---------\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n\n";

        cout << "Ingrese un número entero positivo:\n> ";
        while (!(cin >> numero) || numero < 0) {
            cout << "\033[31mError. Ingrese un valor numérico entero y positivo:\033[0m ";
            cin.clear();
            while (cin.get() != '\n') {}
        }

        // Instanciación del objeto
        VerificadorNarcisista verificador(numero);
        
        cout << "\n";
        verificador.MostrarDesglose();

        // Verificación y resultados
        if (verificador.EsNarcisista()) {
            cout << "\n\033[1;32m[✓] RESULTADO: ¡El número " << numero << " SÍ es Narcisista!\033[0m\n\n";
        } else {
            cout << "\n\033[1;31m[X] RESULTADO: El número " << numero << " NO es Narcisista.\033[0m\n\n";
        }

        cout << "¿Desea verificar otro número? (S/N): ";
        cin >> opcion;
        cout << "\n";

    } while (opcion == "S" || opcion == "s");

    cout << "\033[32mSaliendo del programa...\033[0m\n";
    return 0;
}