// GITHUB L4ZY404

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// ==========================================
// CLASE ANALIZADOR DE FRECUENCIAS
// ==========================================
class AnalizadorTexto {
private:
    // Vector de 26 posiciones inicializado en 0 (representa de la 'a' a la 'z')
    vector<int> frecuencias;

    void LimpiarFrecuencias() {
        std::fill(frecuencias.begin(), frecuencias.end(), 0);
    }

public:
    // Constructor
    AnalizadorTexto() : frecuencias(26, 0) {}

    // Método principal de procesamiento
    void ContarLetras(const string& texto) {
        LimpiarFrecuencias(); // Reiniciar contador por si se analiza más de una frase

        for (char c : texto) {
            // Verificar si el caracter es una letra del alfabeto base
            if (std::isalpha(static_cast<unsigned char>(c))) {
                // Convertir a minúscula para uniformidad
                char letraMin = std::tolower(static_cast<unsigned char>(c));
                
                // Restar 'a' (97) nos da un índice exacto de 0 a 25
                int indice = letraMin - 'a';
                
                if (indice >= 0 && indice < 26) {
                    frecuencias[indice]++;
                }
            }
        }
    }

    // Método para imprimir los resultados tabulados
    void MostrarTabla() const {
        cout << "\n\033[36mTabla de Frecuencias del Alfabeto Latino:\033[0m\n";
        cout << "--------------------------------------\n";
        cout << std::left << std::setw(10) << "Letra" << "| " << "Apariciones\n";
        cout << "--------------------------------------\n";

        // Iterar sobre el abecedario
        for (int i = 0; i < 26; i++) {
            char letra = 'a' + i; // Reconstruir la letra a partir del índice
            int conteo = frecuencias[i];

            // Resaltar en verde las letras que sí aparecieron
            if (conteo > 0) {
                cout << "\033[1;32m"; 
            }

            cout << std::left << std::setw(10) << letra << "| " << conteo << "\n";

            if (conteo > 0) {
                cout << "\033[0m"; // Restaurar color
            }
        }
        cout << "--------------------------------------\n\n";
    }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    string entrada;
    string opcion;
    AnalizadorTexto analizador;

    do {
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---- Analizador de Letras  ----\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---------- BY L4ZY404 ---------\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n\n";

        cout << "Ingrese el texto a analizar (puede ser de cualquier longitud):\n> ";
        std::getline(cin, entrada);

        // Procesamiento a través del objeto
        analizador.ContarLetras(entrada);
        analizador.MostrarTabla();

        cout << "¿Desea analizar otro texto? (S/N): ";
        std::getline(cin, opcion);
        cout << "\n";

    } while (opcion == "S" || opcion == "s");

    cout << "\033[32mSaliendo del programa...\033[0m\n";
    return 0;
}