// GITHUB L4ZY404

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// ==========================================
// CLASE ENTIDAD: Elemento Químico
// ==========================================
class ElementoQuimico {
private:
    string nombre;
    string simbolo;
    int numeroAtomico;
    double masaAtomica;
    double radioAtomico;
    string estadoOrdinario;

public:
    // Constructor
    ElementoQuimico(string nom, string sim, int numA, double masaA, double radioA, string estado)
        : nombre(nom), simbolo(sim), numeroAtomico(numA), 
          masaAtomica(masaA), radioAtomico(radioA), estadoOrdinario(estado) {}

    // Getters para validaciones
    int GetNumeroAtomico() const { return numeroAtomico; }
    string GetSimbolo() const { return simbolo; }

    // Método para mostrar en pantalla
    void MostrarInformacion() const {
        cout << "\033[36m[" << numeroAtomico << "] " << simbolo << " - " << nombre << "\033[0m\n";
        cout << "  Masa Atómica:   " << masaAtomica << " u\n";
        cout << "  Radio Atómico:  " << radioAtomico << " pm\n";
        cout << "  Estado Normal:  " << estadoOrdinario << "\n";
        cout << "--------------------------------------\n";
    }

    // Método para preparar la cadena que se guardará en el TXT (formato CSV)
    string FormatoArchivo() const {
        std::stringstream ss;
        ss << nombre << "," << simbolo << "," << numeroAtomico << "," 
           << masaAtomica << "," << radioAtomico << "," << estadoOrdinario;
        return ss.str();
    }
};

// ==========================================
// CLASE GESTORA: Manejo de memoria y TXT
// ==========================================
class GestorTablaPeriodica {
private:
    vector<ElementoQuimico> elementos;
    const string nombreArchivo = "elementos_quimicos.txt";

    // Función auxiliar para convertir a mayúsculas y facilitar comparaciones
    string ToUpper(string str) const {
        for (char &c : str) c = toupper(c);
        return str;
    }

public:
    // Al instanciar, cargamos automáticamente lo que ya existe en el archivo
    GestorTablaPeriodica() {
        CargarDesdeArchivo();
    }

    // Verifica si un elemento ya está en el sistema
    bool ExisteElemento(int numAtomico, string simbolo) const {
        string simUpper = ToUpper(simbolo);
        for (const auto& el : elementos) {
            if (el.GetNumeroAtomico() == numAtomico || ToUpper(el.GetSimbolo()) == simUpper) {
                return true;
            }
        }
        return false;
    }

    void IngresarElemento() {
        string nombre, simbolo, estado;
        int numA;
        double masaA, radioA;

        cout << "\n\033[33m--- Ingreso de Nuevo Elemento ---\033[0m\n";
        cout << "Número Atómico: ";
        while (!(cin >> numA) || numA <= 0) {
            cout << "\033[31mError. Ingrese un número atómico válido: \033[0m";
            cin.clear();
            while (cin.get() != '\n') {}
        }

        cin.ignore(); // Limpiar el buffer
        cout << "Símbolo: ";
        std::getline(cin, simbolo);

        // Verificamos duplicidad antes de pedir el resto de datos
        if (ExisteElemento(numA, simbolo)) {
            cout << "\033[31m[!] Error: Ya existe un elemento con el Número Atómico " << numA 
                 << " o el símbolo '" << simbolo << "'.\033[0m\n";
            return;
        }

        cout << "Nombre: ";
        std::getline(cin, nombre);

        cout << "Masa Atómica: ";
        while (!(cin >> masaA) || masaA <= 0) {
            cout << "\033[31mError. Ingrese una masa válida: \033[0m";
            cin.clear(); while (cin.get() != '\n') {}
        }

        cout << "Radio Atómico (pm): ";
        while (!(cin >> radioA) || radioA <= 0) {
            cout << "\033[31mError. Ingrese un radio válido: \033[0m";
            cin.clear(); while (cin.get() != '\n') {}
        }

        cin.ignore();
        cout << "Estado Ordinario (Sólido, Líquido, Gas, Sintético): ";
        std::getline(cin, estado);

        // Crear objeto y añadirlo al vector en memoria
        ElementoQuimico nuevo(nombre, simbolo, numA, masaA, radioA, estado);
        elementos.push_back(nuevo);
        cout << "\033[32m[+] Elemento ingresado a la memoria temporal (No olvide Guardar).\033[0m\n";
    }

    void MostrarElementos() const {
        if (elementos.empty()) {
            cout << "\033[33mNo hay elementos registrados actualmente.\033[0m\n";
            return;
        }
        cout << "\n\033[33m--- Base de Datos de Elementos ---\033[0m\n";
        for (const auto& el : elementos) {
            el.MostrarInformacion();
        }
    }

    void GuardarEnArchivo() {
        std::ofstream archivo(nombreArchivo); // Al abrir así, sobrescribe actualizando la lista completa
        if (archivo.is_open()) {
            for (const auto& el : elementos) {
                archivo << el.FormatoArchivo() << "\n";
            }
            archivo.close();
            cout << "\033[32m[✓] Todos los elementos han sido guardados exitosamente en '" 
                 << nombreArchivo << "'.\033[0m\n";
        } else {
            cout << "\033[31m[!] Error al intentar abrir/crear el archivo.\033[0m\n";
        }
    }

    void CargarDesdeArchivo() {
        std::ifstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            string linea;
            while (std::getline(archivo, linea)) {
                std::stringstream ss(linea);
                string nom, sim, numStr, masaStr, radioStr, estado;
                
                // Parseamos usando comas como delimitador
                std::getline(ss, nom, ',');
                std::getline(ss, sim, ',');
                std::getline(ss, numStr, ',');
                std::getline(ss, masaStr, ',');
                std::getline(ss, radioStr, ',');
                std::getline(ss, estado);

                if (!nom.empty() && !numStr.empty()) {
                    int numA = std::stoi(numStr);
                    double masaA = std::stod(masaStr);
                    double radioA = std::stod(radioStr);
                    
                    ElementoQuimico el(nom, sim, numA, masaA, radioA, estado);
                    elementos.push_back(el);
                }
            }
            archivo.close();
        }
        // Si el archivo no existe, no hace nada, simplemente inicia con la lista vacía
    }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    GestorTablaPeriodica gestor;
    int opcion = 0;

    do {
        cout << "\n\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ----   Gestor de Quimica   ----\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---------- BY L4ZY404 ---------\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n\n";
        
        cout << "1. Ingresar nuevo elemento\n";
        cout << "2. Mostrar elementos guardados\n";
        cout << "3. Guardar elementos en archivo (.txt)\n";
        cout << "4. Salir\n\n";
        
        cout << "Seleccione una opción: ";
        if (!(cin >> opcion)) {
            cin.clear();
            while (cin.get() != '\n') {}
            opcion = 0;
        }

        switch (opcion) {
            case 1:
                gestor.IngresarElemento();
                break;
            case 2:
                gestor.MostrarElementos();
                break;
            case 3:
                gestor.GuardarEnArchivo();
                break;
            case 4:
                cout << "\033[32mSaliendo del programa...\033[0m\n";
                break;
            default:
                cout << "\033[31mError. Opción no válida.\033[0m\n";
                break;
        }
    } while (opcion != 4);

    return 0;
}