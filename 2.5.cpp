// GITHUB L4ZY404

#include <iostream>
#include <iomanip>
#include <string>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdint>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// ==========================================
// CLASE CONVERSOR IEEE 754
// ==========================================
class ConversorIEEE754 {
private:
    double valorOriginal;
    float valorFloat;
    uint32_t rawBits;

    // Componentes extraidos
    uint32_t signo;
    uint32_t exponente;
    uint32_t mantisa;

    void ExtraerComponentes() {
        // Extraer los bits del float de forma segura
        std::memcpy(&rawBits, &valorFloat, sizeof(valorFloat));

        signo = (rawBits >> 31) & 1;
        exponente = (rawBits >> 23) & 0xFF;
        mantisa = rawBits & 0x7FFFFF;
    }

public:
    ConversorIEEE754(double valor) : valorOriginal(valor) {
        valorFloat = static_cast<float>(valorOriginal);
        ExtraerComponentes();
    }

    void MostrarTabla() const {
        // Cálculos de valores reales para la tabla
        string signoVal = (signo == 0) ? "+1" : "-1";
        
        string expValStr;
        if (exponente == 0) {
            expValStr = (mantisa == 0) ? "0" : "2^-126 (Denormal)";
        } else if (exponente == 255) {
            expValStr = (mantisa == 0) ? "Infinito" : "NaN";
        } else {
            expValStr = "2^" + std::to_string(static_cast<int>(exponente) - 127);
        }

        double mantisaValReales = static_cast<double>(mantisa) / 8388608.0; // 2^23
        if (exponente != 0 && exponente != 255) {
            mantisaValReales += 1.0; // Bit implícito
        }

        // --- IMPRESIÓN DE LA TABLA ---
        cout << "\033[1;37;44m                                 IEEE 754 Converter (32-bit)                                 \033[0m\n";
        
        // Encabezados
        cout << std::left << std::setw(15) << "" 
             << "\033[35m" << std::setw(10) << "Sign" << "\033[0m" 
             << "\033[32m" << std::setw(20) << "Exponent" << "\033[0m" 
             << "\033[33m" << "Mantissa" << "\033[0m\n";

        // Fila 1: Value
        cout << std::left << std::setw(15) << "\033[1mValue:\033[0m"
             << std::setw(10) << signoVal 
             << std::setw(20) << expValStr 
             << std::fixed << std::setprecision(7) << mantisaValReales << "\n";

        // Fila 2: Encoded as
        cout << std::left << std::setw(15) << "\033[1mEncoded as:\033[0m"
             << std::setw(10) << signo 
             << std::setw(20) << exponente 
             << mantisa << "\n";

        // Fila 3: Binary
        cout << std::left << std::setw(15) << "\033[1mBinary:\033[0m"
             << "\033[35m" << std::bitset<1>(signo) << "\033[0m         "
             << "\033[32m" << std::bitset<8>(exponente) << "\033[0m            "
             << "\033[33m" << std::bitset<23>(mantisa) << "\033[0m\n";
        
        cout << "---------------------------------------------------------------------------------------------\n";

        // --- INFORMACIÓN DETALLADA INFERIOR ---
        
        // Decimal Representation
        cout << std::left << std::setw(32) << "Decimal Representation:" 
             << valorOriginal << "\n";
             
        // Value actually stored in float (máxima precisión para ver la pérdida)
        cout << std::left << std::setw(32) << "Value actually stored in float:" 
             << std::setprecision(20) << valorFloat << "\n";
             
        // Error due to conversion
        double error = static_cast<double>(valorFloat) - valorOriginal;
        cout << std::left << std::setw(32) << "Error due to conversion:" 
             << std::scientific << std::setprecision(10) << error << std::fixed << "\n";
             
        // Binary Representation
        cout << std::left << std::setw(32) << "Binary Representation:" 
             << std::bitset<32>(rawBits) << "\n";
             
        // Hexadecimal Representation
        cout << std::left << std::setw(32) << "Hexadecimal Representation:" 
             << "0x" << std::hex << std::uppercase << std::setw(8) << std::setfill('0') << rawBits 
             << std::dec << std::setfill(' ') << "\n"; // Regresar a decimal y quitar ceros
             
        cout << "\n";
    }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    double entrada;
    string opcion;

    do {
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ----  IEEE 754 Converter   ----\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n";
        cout << "\033[33m ---------- BY L4ZY404 ---------\033[0m\n";
        cout << "\033[33m -------------------------------\033[0m\n\n";

        cout << "Ingrese un número decimal de punto flotante: ";
        while (!(cin >> entrada)) {
            cout << "\033[31mError. Ingrese un valor numérico válido:\033[0m ";
            cin.clear();
            while (cin.get() != '\n') {}
        }

        ConversorIEEE754 conversor(entrada);
        cout << "\n";
        conversor.MostrarTabla();

        cout << "\n¿Desea convertir otro número? (S/N): ";
        cin >> opcion;
        cout << "\n";

    } while (opcion == "S" || opcion == "s");

    cout << "\033[32mSaliendo del conversor...\033[0m\n";
    return 0;
}