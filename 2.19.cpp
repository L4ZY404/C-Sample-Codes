// GITHUB L4ZY404

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
#include <random>

// Definir PI por si el compilador no lo incluye por defecto
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using std::cout;
using std::cin;
using std::endl;
using std::string;

// ==========================================
// CLASE CAMINATA ALEATORIA
// ==========================================
class PaseoAleatorio {
private:
    int nPasos;
    double longitudL;
    double posX;
    double posY;

public:
    // Constructor
    PaseoAleatorio(int n, double L) : nPasos(n), longitudL(L), posX(0.0), posY(0.0) {}

    // Método principal para ejecutar y guardar la simulación
    void SimularYGuardar(const string& nombreArchivo) {
        std::ofstream archivo(nombreArchivo);

        if (!archivo.is_open()) {
            cout << "\033[31m[!] Error al intentar crear el archivo '" << nombreArchivo << "'.\033[0m\n";
            return;
        }

        // Configuración de la aleatoriedad moderna en C++
        std::random_device rd;  // Semilla de hardware real (si está disponible)
        std::mt19937 gen(rd()); // Motor Mersenne Twister
        std::uniform_real_distribution<double> distribucionAngulo(0.0, 2.0 * M_PI);

        // Cabecera del archivo
        archivo << "--------------------------------------------------\n";
        archivo << "| " << std::setw(8)  << "Paso (i)" 
                << " | " << std::setw(15) << "Posición X" 
                << " | " << std::setw(15) << "Posición Y" << " |\n";
        archivo << "--------------------------------------------------\n";

        // Registrar el punto de origen (Paso 0)
        archivo << "| " << std::setw(8)  << 0 
                << " | " << std::setw(15) << std::fixed << std::setprecision(6) << posX 
                << " | " << std::setw(15) << std::fixed << std::setprecision(6) << posY << " |\n";

        // Bucle de la caminata aleatoria
        for (int i = 1; i <= nPasos; i++) {
            // Obtener un ángulo aleatorio entre 0 y 360 grados (en radianes)
            double theta = distribucionAngulo(gen);

            // Calcular el nuevo desplazamiento
            posX += longitudL * std::cos(theta);
            posY += longitudL * std::sin(theta);

            // Guardar en el archivo
            archivo << "| " << std::setw(8)  << i 
                    << " | " << std::setw(15) << std::fixed << std::setprecision(6) << posX 
                    << " | " << std::setw(15) << std::fixed << std::setprecision(6) << posY << " |\n";
        }

        archivo << "--------------------------------------------------\n";
        archivo.close();

        cout << "\033[1;32m[✓] Simulación del Paseo Aleatorio finalizada.\033[0m\n";
        cout << "\033[36mSe han guardado \033[1;37m" << nPasos << "\033[36m pasos en el archivo: \033[1;37m" << nombreArchivo << "\033[0m\n\n";
    }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    int pasos;
    double longitud;
    string opcion;
    const string archivoSalida = "camino_aleatorio.txt";

    do {
        cout << "\033[33m ----------------------------------------\033[0m\n";
        cout << "\033[33m ---- Simulador de Paseo Aleatorio  ----\033[0m\n";
        cout << "\033[33m ----------------------------------------\033[0m\n";
        cout << "\033[33m -------------- BY L4ZY404 --------------\033[0m\n";
        cout << "\033[33m ----------------------------------------\033[0m\n\n";

        cout << "Ingrese la cantidad de pasos a simular (n): ";
        while (!(cin >> pasos) || pasos <= 0) { 
            cout << "\033[31mError. El número de pasos debe ser entero y mayor a 0:\033[0m ";
            cin.clear(); 
            while (cin.get() != '\n') {} 
        }

        cout << "Ingrese la longitud de cada paso (L): ";
        while (!(cin >> longitud) || longitud <= 0) { 
            cout << "\033[31mError. La longitud debe ser mayor a 0:\033[0m ";
            cin.clear(); 
            while (cin.get() != '\n') {} 
        }

        // Instanciación y ejecución
        cout << "\nGenerando caminata del borracho...\n";
        PaseoAleatorio simulador(pasos, longitud);
        simulador.SimularYGuardar(archivoSalida);

        cout << "¿Desea generar otra simulación? (S/N): ";
        cin >> opcion;
        cout << "\n";

    } while (opcion == "S" || opcion == "s");

    cout << "\033[32mSaliendo del programa...\033[0m\n";
    return 0;
}