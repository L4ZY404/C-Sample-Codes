// GITHUB L4ZY404

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

// ==========================================
// CLASE PARA LA CRIBA DE SUNDARAM
// ==========================================
class CribaSundaram {
private:
    int limiteN;
    vector<int> primos;

public:
    // Constructor
    CribaSundaram(int n) : limiteN(n) {}

    // Método que implementa el algoritmo matemático de S.P. Sundaram
    void CalcularPrimos() {
        if (limiteN <= 2) {
            return; // No hay primos estrictamente menores que 2 (para enteros positivos)
        }

        // En la Criba de Sundaram, trabajamos hasta k = (N - 2) / 2
        // para encontrar todos los primos impares menores que N.
        int k = (limiteN - 2) / 2;
        
        // Vector booleano inicializado en falso.
        // Si marcados[m] es false, entonces 2*m + 1 es primo.
        vector<bool> marcados(k + 1, false);

        // Algoritmo principal de tachado
        for (int i = 1; i <= k; i++) {
            for (int j = i; (i + j + 2 * i * j) <= k; j++) {
                marcados[i + j + 2 * i * j] = true;
            }
        }

        // El número 2 es el único primo par, lo agregamos manualmente
        primos.push_back(2);

        // Recolectamos los números primos impares restantes
        for (int m = 1; m <= k; m++) {
            if (!marcados[m]) {
                primos.push_back(2 * m + 1);
            }
        }
    }

    // Método para desplegar los resultados en pantalla
    void MostrarPrimos() const {
        cout << "\033[36mLista de números primos inferiores a " << limiteN << ":\033[0m\n";
        
        if (primos.empty()) {
            cout << "\033[33mNo hay números primos en este rango.\033[0m\n\n";
            return;
        }

        cout << "\033[1;32m";
        for (size_t i = 0; i < primos.size(); i++) {
            cout << primos[i];
            if (i < primos.size() - 1) {
                cout << ", ";
            }
        }
        cout << "\033[0m\n\n";
    }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    int N;
    string opcion;

    do {
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ----   Criba de Sundaram   ----\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---------- BY L4ZY404 ---------\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n\n";

        cout << "Ingrese el valor de N (entero positivo): ";
        while (!(cin >> N) || N <= 0) {
            cout << "\033[31mError. Ingrese un número entero positivo mayor a 0: \033[0m";
            cin.clear();
            while (cin.get() != '\n') {}
        }

        // Instanciación y uso del objeto
        CribaSundaram criba(N);
        criba.CalcularPrimos();
        criba.MostrarPrimos();

        cout << "¿Desea evaluar otro número? (S/N): ";
        cin >> opcion;
        cout << "\n";

    } while (opcion == "S" || opcion == "s");

    cout << "\033[32mSaliendo del programa...\033[0m\n";
    return 0;
}