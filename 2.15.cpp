// GITHUB L4ZY404

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// ==========================================
// CLASE VERIFICADOR DE NÚMEROS DE KEITH
// ==========================================
class VerificadorKeith {
private:
    long long numeroOriginal;
    vector<long long> sucesion;
    int cantidadDigitos;

    // Método privado para extraer los dígitos y sembrar la sucesión
    void ExtraerDigitos() {
        long long temp = numeroOriginal;
        vector<long long> digitosInvertidos;

        // Extraemos los dígitos (quedan en orden inverso)
        while (temp > 0) {
            digitosInvertidos.push_back(temp % 10);
            temp /= 10;
        }

        // Los invertimos para tenerlos en el orden original
        std::reverse(digitosInvertidos.begin(), digitosInvertidos.end());
        
        // Copiamos los dígitos a nuestra sucesión principal
        sucesion = digitosInvertidos;
        cantidadDigitos = sucesion.size();
    }

public:
    // Constructor
    VerificadorKeith(long long n) : numeroOriginal(n) {
        if (numeroOriginal > 9) {
            ExtraerDigitos();
        }
    }

    // Método principal para calcular la serie repfigit
    bool EsKeith() {
        // Por definición, los números de 1 dígito no se consideran números de Keith
        if (numeroOriginal < 10) return false;

        long long siguienteTermino = 0;

        // Generamos la sucesión hasta igualar o superar el número
        while (true) {
            siguienteTermino = 0;
            
            // Sumamos los últimos 'cantidadDigitos' términos
            int inicio = sucesion.size() - cantidadDigitos;
            for (size_t i = inicio; i < sucesion.size(); i++) {
                siguienteTermino += sucesion[i];
            }

            sucesion.push_back(siguienteTermino);

            if (siguienteTermino == numeroOriginal) {
                return true;
            } else if (siguienteTermino > numeroOriginal) {
                return false;
            }
        }
    }

    // Método para mostrar cómo se comportó la sucesión
    void MostrarSucesion() const {
        if (numeroOriginal < 10) {
            cout << "\033[33mLos números de 1 dígito no entran en la categoría de Keith.\033[0m\n";
            return;
        }

        cout << "\033[36mSucesión generada (d=" << cantidadDigitos << "):\033[0m\n";
        for (size_t i = 0; i < sucesion.size(); i++) {
            if (sucesion[i] == numeroOriginal) {
                cout << "\033[1;32m" << sucesion[i] << "\033[0m"; // Resaltar si hace match
            } else if (sucesion[i] > numeroOriginal) {
                cout << "\033[1;31m" << sucesion[i] << "\033[0m"; // Resaltar rojo si se pasa
            } else {
                cout << sucesion[i];
            }
            
            if (i < sucesion.size() - 1) cout << " -> ";
        }
        cout << "\n";
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
        cout << "\033[33m ----   Números de Keith    ----\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---------- BY L4ZY404 ---------\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n\n";

        cout << "Ingrese un número entero positivo:\n> ";
        while (!(cin >> numero) || numero < 0) {
            cout << "\033[31mError. Ingrese un valor numérico entero positivo:\033[0m ";
            cin.clear();
            while (cin.get() != '\n') {}
        }

        // Instanciación del objeto
        VerificadorKeith verificador(numero);
        
        // Es importante llamar a EsKeith() primero para que el vector se llene 
        // antes de llamar a MostrarSucesion()
        bool resultado = verificador.EsKeith();
        
        cout << "\n";
        verificador.MostrarSucesion();

        // Verificación y resultados
        if (resultado) {
            cout << "\n\033[1;32m[✓] RESULTADO: ¡El número " << numero << " SÍ es un número de Keith!\033[0m\n\n";
        } else {
            cout << "\n\033[1;31m[X] RESULTADO: El número " << numero << " NO es un número de Keith.\033[0m\n\n";
        }

        cout << "¿Desea verificar otro número? (S/N): ";
        cin >> opcion;
        cout << "\n";

    } while (opcion == "S" || opcion == "s");

    cout << "\033[32mSaliendo del programa...\033[0m\n";
    return 0;
}