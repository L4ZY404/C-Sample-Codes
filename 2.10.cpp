// GITHUB L4ZY404

#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// ==========================================
// CLASE CIFRADOR CESAR
// ==========================================
class CifradorCesar {
private:
    int desplazamiento;

public:
    // Constructor
    CifradorCesar(int desp) {
        // Normalizamos el desplazamiento para evitar ciclos innecesarios
        // y manejar números negativos correctamente.
        desplazamiento = desp % 26;
    }

    // Método para encriptar un texto
    string Encriptar(const string& textoPlano) const {
        string textoEncriptado = "";

        for (char c : textoPlano) {
            // Verificamos si el caracter es una letra
            if (std::isalpha(static_cast<unsigned char>(c))) {
                // Determinamos la base ASCII ('A' = 65 para mayúsculas, 'a' = 97 para minúsculas)
                char baseAscii = std::isupper(static_cast<unsigned char>(c)) ? 'A' : 'a';
                
                // Calculamos la nueva posición matemática
                // 1. (c - baseAscii) nos da el índice de 0 a 25.
                // 2. Sumamos el desplazamiento.
                // 3. Aplicamos módulo 26 dos veces sumando 26 en medio para manejar 
                //    correctamente los desplazamientos negativos en C++.
                int indiceOriginal = c - baseAscii;
                int nuevoIndice = ((indiceOriginal + desplazamiento) % 26 + 26) % 26;
                
                textoEncriptado += (baseAscii + nuevoIndice);
            } else {
                // Si no es una letra (espacios, números, puntuación), se queda igual
                textoEncriptado += c;
            }
        }

        return textoEncriptado;
    }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    string texto;
    int posiciones;
    string opcion;

    do {
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ----     Cifrado César     ----\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---------- BY L4ZY404 ---------\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n\n";

        cout << "Ingrese el texto a encriptar:\n> ";
        std::getline(cin, texto);

        cout << "Ingrese el número de posiciones a desplazar (puede ser negativo): ";
        while (!(cin >> posiciones)) {
            cout << "\033[31mError. Ingrese un número entero válido:\033[0m ";
            cin.clear();
            while (cin.get() != '\n') {}
        }
        cin.ignore(); // Limpiar el salto de línea del buffer después de leer el int

        // Instanciación del objeto con la clave de desplazamiento
        CifradorCesar cifrador(posiciones);
        
        // Llamada al método de encriptación
        string resultado = cifrador.Encriptar(texto);

        cout << "\n\033[36mTexto Original:\033[0m\n" << texto << "\n";
        cout << "\033[36mTexto Encriptado:\033[0m\n";
        cout << "\033[1;32m" << resultado << "\033[0m\n\n";

        cout << "¿Desea encriptar otro mensaje? (S/N): ";
        std::getline(cin, opcion);
        cout << "\n";

    } while (opcion == "S" || opcion == "s");

    cout << "\033[32mSaliendo del programa...\033[0m\n";
    return 0;
}