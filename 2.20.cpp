// GITHUB L4ZY404

#include <iostream>
#include <string>
#include <regex>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// ==========================================
// CLASE VALIDADOR DE EMAIL
// ==========================================
class ValidadorEmail {
private:
    string correo;

public:
    // Constructor
    ValidadorEmail(string email) : correo(email) {}

    // Método que utiliza expresiones regulares para la validación
    bool EsValido() const {
        // Patrón estándar para correos electrónicos:
        // 1. [a-zA-Z0-9._%+-]+ : Usuario (letras, números y caracteres permitidos)
        // 2. @                 : Símbolo arroba obligatorio
        // 3. [a-zA-Z0-9.-]+    : Dominio (letras, números, puntos o guiones)
        // 4. \.                : Punto literal obligatorio
        // 5. [a-zA-Z]{2,}      : Extensión del dominio (com, org, mx, etc. Mínimo 2 letras)
        const std::regex patron(
            "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$"
        );

        // std::regex_match devuelve true si toda la cadena coincide perfectamente con el patrón
        return std::regex_match(correo, patron);
    }

    // Getter para mostrar el correo evaluado
    string GetCorreo() const {
        return correo;
    }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    string entrada;
    string opcion;

    do {
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ----  Validador de Correos ----\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---------- BY L4ZY404 ---------\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n\n";

        cout << "Ingrese la dirección de correo electrónico a verificar:\n> ";
        std::getline(cin, entrada);

        // Instanciación del objeto evaluador
        ValidadorEmail validador(entrada);

        // Evaluación y resultados
        if (validador.EsValido()) {
            cout << "\n\033[1;32m[✓] RESULTADO: '" << validador.GetCorreo() << "' ES un correo electrónico VÁLIDO.\033[0m\n\n";
        } else {
            cout << "\n\033[1;31m[X] RESULTADO: '" << validador.GetCorreo() << "' NO tiene un formato válido.\033[0m\n\n";
        }

        cout << "¿Desea verificar otro correo? (S/N): ";
        std::getline(cin, opcion);
        cout << "\n";

    } while (opcion == "S" || opcion == "s");

    cout << "\033[32mSaliendo del programa...\033[0m\n";
    return 0;
}