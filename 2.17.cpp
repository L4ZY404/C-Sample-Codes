// GITHUB L4ZY404

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

// ==========================================
// CLASE SOLUCIONADOR 8 REINAS
// ==========================================
class Problema8Reinas {
private:
    vector<int> tablero; // El índice es la fila, el valor es la columna
    int filaFija;
    int colFija;
    vector<vector<int>> soluciones; // Almacenará todos los tableros válidos

    // Método que verifica si es seguro colocar una reina en (fila, col)
    bool EsSeguro(int fila, int col) {
        for (int i = 0; i < 8; i++) {
            // Ignoramos la fila actual y las filas donde aún no hay reinas (-1)
            if (i == fila || tablero[i] == -1) continue;
            
            int c = tablero[i];
            
            // Verificamos ataque en la misma columna
            if (c == col) return false;
            
            // Verificamos ataque en las diagonales
            if (std::abs(fila - i) == std::abs(col - c)) return false;
        }
        return true;
    }

    // Algoritmo recursivo de Backtracking
    void ResolverAlgoritmo(int fila) {
        // Caso base: Si logramos pasar la fila 7 (llegamos a 8), encontramos una solución
        if (fila == 8) {
            soluciones.push_back(tablero);
            return;
        }

        // Si la fila actual es la fila donde el usuario ancló su reina
        if (fila == filaFija) {
            // Solo verificamos que su posición siga siendo segura con respecto a las anteriores
            if (EsSeguro(fila, colFija)) {
                ResolverAlgoritmo(fila + 1); // Saltamos a la siguiente fila sin modificarla
            }
        } else {
            // Si es una fila vacía, probamos colocar una reina en cada columna (0 al 7)
            for (int c = 0; c < 8; c++) {
                if (EsSeguro(fila, c)) {
                    tablero[fila] = c;           // Colocamos la reina
                    ResolverAlgoritmo(fila + 1); // Llamada recursiva
                    tablero[fila] = -1;          // BACKTRACKING: Retiramos la reina para probar otra
                }
            }
        }
    }

public:
    // Constructor
    Problema8Reinas(int f, int c) {
        // Ajustamos los valores ingresados (1-8) a los índices de los arreglos (0-7)
        filaFija = f - 1; 
        colFija = c - 1;
        
        // Inicializamos el tablero con -1 (vacío)
        tablero.assign(8, -1);
        
        // Anclamos la reina del usuario
        tablero[filaFija] = colFija;
    }

    // Método disparador
    void Iniciar() {
        ResolverAlgoritmo(0); // Comenzamos a evaluar desde la fila 0
    }

    // Método para imprimir los tableros encontrados
    void MostrarResultados() const {
        if (soluciones.empty()) {
            cout << "\033[31mNo se encontraron soluciones matemáticas válidas para esta posición inicial.\033[0m\n\n";
            return;
        }

        cout << "\n\033[1;32m[✓] Se encontraron " << soluciones.size() << " soluciones.\033[0m\n\n";

        for (size_t k = 0; k < soluciones.size(); k++) {
            cout << "\033[36m--- Solución #" << (k + 1) << " ---\033[0m\n";
            
            // Imprimir cabecera de columnas
            cout << "  1  2  3  4  5  6  7  8\n";
            
            for (int i = 0; i < 8; i++) {
                cout << (i + 1) << " "; // Imprimir número de fila
                for (int j = 0; j < 8; j++) {
                    if (soluciones[k][i] == j) {
                        // Resaltar en rojo la reina original del usuario, y en amarillo las calculadas
                        if (i == filaFija && j == colFija) {
                            cout << "\033[1;31m[Q]\033[0m"; 
                        } else {
                            cout << "\033[1;33m[Q]\033[0m"; 
                        }
                    } else {
                        // Estética de casillas del tablero
                        if ((i + j) % 2 == 0) {
                            cout << "\033[90m . \033[0m";
                        } else {
                            cout << "\033[37m . \033[0m";
                        }
                    }
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    int fila, col;
    string opcion;

    do {
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---- Problema de 8 Reinas  ----\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---------- BY L4ZY404 ---------\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n\n";

        cout << "Ubica tu primera reina en el tablero.\n";
        
        cout << "Fila (1 al 8): ";
        while (!(cin >> fila) || fila < 1 || fila > 8) {
            cout << "\033[31mError. Ingrese una fila del 1 al 8:\033[0m ";
            cin.clear();
            while (cin.get() != '\n') {}
        }

        cout << "Columna (1 al 8): ";
        while (!(cin >> col) || col < 1 || col > 8) {
            cout << "\033[31mError. Ingrese una columna del 1 al 8:\033[0m ";
            cin.clear();
            while (cin.get() != '\n') {}
        }

        // Instanciar y ejecutar
        Problema8Reinas tablero(fila, col);
        tablero.Iniciar();
        tablero.MostrarResultados();

        cout << "¿Desea probar con otra posición inicial? (S/N): ";
        cin >> opcion;
        cout << "\n";

    } while (opcion == "S" || opcion == "s");

    cout << "\033[32mSaliendo del programa...\033[0m\n";
    return 0;
}