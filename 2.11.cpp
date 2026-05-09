// GITHUB L4ZY404

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// ==========================================
// CLASE VERIFICADOR DE PALÍNDROMOS
// ==========================================
class VerificadorPalindromo {
private:
    string textoOriginal;
    string textoLimpio;

    // Método privado para limpiar la cadena (quitar espacios, puntuación y pasar a minúsculas)
    void ProcesarTexto() {
        textoLimpio = "";
        for (char c : textoOriginal) {
            // isalnum verifica si es una letra o un número, ignorando espacios y símbolos
            if (std::isalnum(static_cast<unsigned char>(c))) {
                textoLimpio += std::tolower(static_cast<unsigned char>(c));
            }
        }
    }

public:
    // Constructor
    VerificadorPalindromo(string texto) : textoOriginal(texto) {
        ProcesarTexto();
    }

    // Método que evalúa si la cadena procesada es igual a sí misma invertida
    bool EsPalindromo() const {
        if (textoLimpio.empty()) {
            return false; // Una cadena vacía o de puros símbolos no se considera palíndromo aquí
        }

        // Utilizamos dos iteradores (inicio y fin) para comparar los extremos hacia el centro
        int izquierda = 0;
        int derecha = textoLimpio.length() - 1;

        while (izquierda < derecha) {
            if (textoLimpio[izquierda] != textoLimpio[derecha]) {
                return false; // Al primer caracter que no coincida, se descarta
            }
            izquierda++;
            derecha--;
        }

        return true; // Si terminó el bucle sin problemas, es un palíndromo
    }

    // Método getter para mostrar cómo quedó el texto internamente
    string GetTextoLimpio() const {
        return textoLimpio;
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
        cout << "\033[33m ----Detector de Palíndromos----\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---------- BY L4ZY404 ---------\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n\n";

        cout << "Ingrese una palabra o frase para analizar:\n> ";
        std::getline(cin, entrada);

        // Instanciación del objeto evaluador
        VerificadorPalindromo verificador(entrada);

        cout << "\n\033[36mAnálisis interno (texto normalizado):\033[0m " 
             << verificador.GetTextoLimpio() << "\n";

        // Evaluación y resultados
        if (verificador.EsPalindromo()) {
            cout << "\033[1;32m[✓] RESULTADO: ¡Es un palíndromo!\033[0m\n\n";
        } else {
            cout << "\033[1;31m[X] RESULTADO: No es un palíndromo.\033[0m\n\n";
        }

        cout << "¿Desea evaluar otra frase? (S/N): ";
        std::getline(cin, opcion);
        cout << "\n";

    } while (opcion == "S" || opcion == "s");

    cout << "\033[32mSaliendo del programa...\033[0m\n";
    return 0;
}