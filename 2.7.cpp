// GITHUB L4ZY404

#include <iostream>
#include <string>
#include <random>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// ==========================================
// CLASE GENERADORA
// ==========================================
class GeneradorPassword {
private:
    // Motor de generación de números aleatorios (Mersenne Twister)
    std::mt19937 generador;

    // Métodos privados para generar cada tipo de carácter usando rangos ASCII
    char ObtenerMinuscula() {
        std::uniform_int_distribution<int> distribucion(97, 122); // 'a' (97) a 'z' (122)
        return static_cast<char>(distribucion(generador));
    }

    char ObtenerNumero() {
        std::uniform_int_distribution<int> distribucion(48, 57); // '0' (48) a '9' (57)
        return static_cast<char>(distribucion(generador));
    }

    char ObtenerMayuscula() {
        std::uniform_int_distribution<int> distribucion(65, 90); // 'A' (65) a 'Z' (90)
        return static_cast<char>(distribucion(generador));
    }

public:
    // Constructor: Inicializa la semilla del generador usando el tiempo actual
    GeneradorPassword() {
        generador.seed(static_cast<unsigned int>(std::time(nullptr)));
    }

    // Método principal para construir la contraseña
    string Generar() {
        string password = "";

        // 1. Primeras 4 letras minúsculas
        for (int i = 0; i < 4; i++) {
            password += ObtenerMinuscula();
        }

        // 2. Siguientes 4 números
        for (int i = 0; i < 4; i++) {
            password += ObtenerNumero();
        }

        // 3. Últimas 2 letras mayúsculas
        for (int i = 0; i < 2; i++) {
            password += ObtenerMayuscula();
        }

        return password;
    }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    string opcion;
    GeneradorPassword creadorClaves;

    do {
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---- Generador de Passwords----\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---------- BY L4ZY404 ---------\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n\n";

        cout << "Generando contraseña segura con el formato especificado...\n";
        
        string nuevaClave = creadorClaves.Generar();
        
        cout << "\n\033[36mContraseña generada:\033[0m\n";
        cout << "\033[1;32m" << nuevaClave << "\033[0m\n\n";

        cout << "¿Desea generar otra contraseña? (S/N): ";
        cin >> opcion;
        cout << "\n";

    } while (opcion == "S" || opcion == "s");

    cout << "\033[32mSaliendo del programa...\033[0m\n";
    return 0;
}