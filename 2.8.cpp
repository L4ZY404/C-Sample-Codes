// GITHUB L4ZY404

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// ==========================================
// CLASE REDUCTOR DE FRASES
// ==========================================
class ReductorDeFrases {
private:
    string fraseOriginal;
    vector<string> palabras;

    // Método privado para dividir la frase en palabras
    void TokenizarFrase() {
        palabras.clear();
        std::stringstream ss(fraseOriginal);
        string palabra;
        
        while (ss >> palabra) {
            palabras.push_back(palabra);
        }
    }

public:
    // Constructor vacío
    ReductorDeFrases() {}

    // Método para validar que la frase cumple las reglas
    bool CargarYValidarFrase(const string& frase) {
        if (frase.empty()) {
            cout << "\033[31m[!] Error: La frase no puede estar vacía.\033[0m\n";
            return false;
        }

        if (frase.length() > 100) {
            cout << "\033[31m[!] Error: La frase excede los 100 caracteres (Tamaño actual: " 
                 << frase.length() << ").\033[0m\n";
            return false;
        }

        // Validar que solo contenga letras (alfabeto) y espacios
        for (char c : frase) {
            // isalpha verifica si es letra, isspace si es espacio.
            // Para soportar ñ o acentos en consolas básicas a veces isalpha falla, 
            // pero nos apegaremos a la regla estricta de "solo texto y espacios".
            if (!std::isalpha(static_cast<unsigned char>(c)) && !std::isspace(static_cast<unsigned char>(c))) {
                cout << "\033[31m[!] Error: La frase contiene caracteres no válidos ('" << c << "'). Solo letras y espacios.\033[0m\n";
                return false;
            }
        }

        fraseOriginal = frase;
        TokenizarFrase();
        return true;
    }

    // Método que imprime el patrón eliminando la última palabra en cada iteración
    void MostrarPatronDescendente() const {
        if (palabras.empty()) return;

        cout << "\n\033[36mResultado:\033[0m\n";
        cout << "\033[1;32m"; // Color verde brillante

        // Bucle externo: controla la cantidad de palabras a imprimir (empieza con todas, baja hasta 1)
        for (size_t cantidad = palabras.size(); cantidad > 0; cantidad--) {
            
            // Bucle interno: imprime las palabras desde 0 hasta 'cantidad'
            for (size_t i = 0; i < cantidad; i++) {
                cout << palabras[i];
                // Imprimir un espacio después de cada palabra, excepto la última de esa línea
                if (i < cantidad - 1) {
                    cout << " ";
                }
            }
            cout << "\n";
        }
        cout << "\033[0m\n"; // Restaurar color
    }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    string entrada;
    string opcion;
    ReductorDeFrases reductor;

    do {
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ----   Reductor de Frases  ----\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---------- BY L4ZY404 ---------\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n\n";

        bool valida = false;
        
        while (!valida) {
            cout << "Ingrese una frase (solo letras y espacios, max 100 caracteres):\n> ";
            std::getline(cin, entrada);
            
            valida = reductor.CargarYValidarFrase(entrada);
        }

        reductor.MostrarPatronDescendente();

        cout << "¿Desea ingresar otra frase? (S/N): ";
        std::getline(cin, opcion);
        cout << "\n";

    } while (opcion == "S" || opcion == "s");

    cout << "\033[32mSaliendo del programa...\033[0m\n";
    return 0;
}