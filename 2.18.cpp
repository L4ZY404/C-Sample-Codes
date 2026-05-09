// GITHUB L4ZY404

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// ==========================================
// CLASE SIMULADOR DE TIRO PARABÓLICO
// ==========================================
class SimuladorProyectil {
private:
    double v0;       // Velocidad inicial
    double theta0;   // Ángulo inicial en grados
    double h0;       // Altura inicial (y0)
    double g;        // Aceleración de la gravedad
    double dt;       // Paso de simulación (delta t)

public:
    // Constructor
    SimuladorProyectil(double vel, double angulo, double altura, double gravedad, double pasoT)
        : v0(vel), theta0(angulo), h0(altura), g(gravedad), dt(pasoT) {}

    // Método principal para ejecutar simulación y exportar a TXT
    void EjecutarYGuardar(const string& nombreArchivo) const {
        std::ofstream archivo(nombreArchivo);

        if (!archivo.is_open()) {
            cout << "\033[31m[!] Error al intentar crear el archivo '" << nombreArchivo << "'.\033[0m\n";
            return;
        }

        // Formato de cabecera de la tabla
        archivo << "-------------------------------------------------------------\n";
        archivo << "| " << std::setw(6)  << "Paso i" 
                << " | " << std::setw(12) << "X (Pos)" 
                << " | " << std::setw(12) << "Y (Pos)" 
                << " | " << std::setw(12) << "Tiempo t" << " |\n";
        archivo << "-------------------------------------------------------------\n";

        // Convertir ángulo a radianes para las funciones trigonométricas de <cmath>
        double thetaRad = theta0 * (M_PI / 180.0);
        
        // Componentes iniciales de la velocidad
        double vx = v0 * std::cos(thetaRad);
        double vy = v0 * std::sin(thetaRad);

        int i = 0;
        double t = 0.0;
        double x = 0.0;
        double y = h0;

        // Bucle iterativo de la simulación
        while (y >= 0) {
            // Guardar fila actual en el archivo
            archivo << "| " << std::setw(6)  << i 
                    << " | " << std::setw(12) << std::fixed << std::setprecision(4) << x 
                    << " | " << std::setw(12) << std::fixed << std::setprecision(4) << y 
                    << " | " << std::setw(12) << std::fixed << std::setprecision(4) << t << " |\n";

            i++;
            t += dt;

            // Calcular nueva posición con las ecuaciones de cinemática
            x = vx * t;
            y = h0 + (vy * t) - (0.5 * g * t * t);

            // Control de exactitud para el impacto en el suelo
            if (y < 0) {
                // Cálculo exacto del tiempo de impacto usando la fórmula cuadrática general
                // 0 = -0.5*g*t^2 + vy*t + h0
                double t_impacto = (-vy - std::sqrt(vy * vy - 4 * (-0.5 * g) * h0)) / (-g);
                
                // Recalculamos los valores para el instante exacto del impacto
                x = vx * t_impacto;
                y = 0.0;
                t = t_impacto;
                
                archivo << "| " << std::setw(6)  << i 
                        << " | " << std::setw(12) << std::fixed << std::setprecision(4) << x 
                        << " | " << std::setw(12) << std::fixed << std::setprecision(4) << y 
                        << " | " << std::setw(12) << std::fixed << std::setprecision(4) << t << " |\n";
                break; // Terminamos el bucle al tocar el suelo
            }
        }

        archivo << "-------------------------------------------------------------\n";
        archivo.close();

        cout << "\033[1;32m[✓] Simulación finalizada.\033[0m\n";
        cout << "\033[36mLos datos han sido exportados al archivo: \033[1;37m" << nombreArchivo << "\033[0m\n\n";
    }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    double v0, theta, h0, g, dt;
    string opcion;
    const string archivoSalida = "simulacion_tiro_parabolico.txt";

    do {
        cout << "\033[33m ----------------------------------------\033[0m\n";
        cout << "\033[33m ---- Simulador de Tiro Parabólico  ----\033[0m\n";
        cout << "\033[33m ----------------------------------------\033[0m\n";
        cout << "\033[33m -------------- BY L4ZY404 --------------\033[0m\n";
        cout << "\033[33m ----------------------------------------\033[0m\n\n";

        cout << "Ingrese la velocidad inicial v0 (m/s): ";
        while (!(cin >> v0)) { cin.clear(); while (cin.get() != '\n') {} }

        cout << "Ingrese el ángulo inicial de disparo (grados): ";
        while (!(cin >> theta)) { cin.clear(); while (cin.get() != '\n') {} }

        cout << "Ingrese la altura inicial h0 (m): ";
        while (!(cin >> h0) || h0 < 0) { 
            cout << "\033[31mError. Altura debe ser >= 0:\033[0m ";
            cin.clear(); while (cin.get() != '\n') {} 
        }

        cout << "Ingrese la aceleración de la gravedad g (ej. 9.81 m/s^2): ";
        while (!(cin >> g) || g <= 0) { 
            cout << "\033[31mError. Gravedad debe ser > 0:\033[0m ";
            cin.clear(); while (cin.get() != '\n') {} 
        }

        cout << "Ingrese el paso de tiempo delta t (ej. 0.1 s): ";
        while (!(cin >> dt) || dt <= 0) { 
            cout << "\033[31mError. El paso dt debe ser > 0:\033[0m ";
            cin.clear(); while (cin.get() != '\n') {} 
        }

        // Instanciación y ejecución
        cout << "\nGenerando trayectoria...\n";
        SimuladorProyectil simulador(v0, theta, h0, g, dt);
        simulador.EjecutarYGuardar(archivoSalida);

        cout << "¿Desea ejecutar otra simulación? (S/N): ";
        cin >> opcion;
        cout << "\n";

    } while (opcion == "S" || opcion == "s");

    cout << "\033[32mSaliendo del programa...\033[0m\n";
    return 0;
}