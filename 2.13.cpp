// GITHUB L4ZY404

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// ==========================================
// CLASE CALCULADORA DE FECHAS
// ==========================================
class CalculadoraFechas {
private:
    int sysDia, sysMes, sysAnio;
    int usrDia, usrMes, usrAnio;

    // Método auxiliar para saber si un año es bisiesto
    bool EsBisiesto(int anio) const {
        return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
    }

    // Método auxiliar para saber cuántos días tiene un mes específico
    int DiasEnMes(int mes, int anio) const {
        if (mes == 2) return EsBisiesto(anio) ? 29 : 28;
        if (mes == 4 || mes == 6 || mes == 9 || mes == 11) return 30;
        return 31;
    }

    // Algoritmo matemático para obtener el Número de Día Juliano (JDN)
    // Esto nos permite calcular la diferencia absoluta en días entre dos fechas de forma perfecta.
    int ObtenerDiaJuliano(int d, int m, int y) const {
        if (m < 3) {
            y--;
            m += 12;
        }
        return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
    }

    // Método para ordenar las fechas (saber cuál es mayor) para evitar números negativos
    void OrdenarFechas(int& d1, int& m1, int& a1, int& d2, int& m2, int& a2) const {
        bool usrMayor = false;
        if (usrAnio > sysAnio) usrMayor = true;
        else if (usrAnio == sysAnio && usrMes > sysMes) usrMayor = true;
        else if (usrAnio == sysAnio && usrMes == sysMes && usrDia > sysDia) usrMayor = true;

        if (usrMayor) {
            d1 = sysDia; m1 = sysMes; a1 = sysAnio;
            d2 = usrDia; m2 = usrMes; a2 = usrAnio;
        } else {
            d1 = usrDia; m1 = usrMes; a1 = usrAnio;
            d2 = sysDia; m2 = sysMes; a2 = sysAnio;
        }
    }

public:
    // Constructor: Captura la fecha actual del sistema
    CalculadoraFechas() {
        std::time_t t = std::time(nullptr);
        std::tm* now = std::localtime(&t);
        
        sysAnio = now->tm_year + 1900;
        sysMes = now->tm_mon + 1;
        sysDia = now->tm_mday;
        
        usrDia = usrMes = usrAnio = 0;
    }

    // Muestra la fecha actual del sistema
    void MostrarFechaSistema() const {
        cout << "\033[36m[i] La fecha actual del sistema es: \033[1;37m" 
             << sysDia << "/" << sysMes << "/" << sysAnio << "\033[0m\n";
    }

    // Valida y guarda la fecha ingresada por el usuario
    bool CargarFechaUsuario(int d, int m, int a) {
        if (a < 1 || m < 1 || m > 12 || d < 1) return false;
        if (d > DiasEnMes(m, a)) return false;
        
        usrDia = d;
        usrMes = m;
        usrAnio = a;
        return true;
    }

    // Opción A: Muestra la diferencia en días totales
    void MostrarDiferenciaDiasTotales() const {
        int jdnSys = ObtenerDiaJuliano(sysDia, sysMes, sysAnio);
        int jdnUsr = ObtenerDiaJuliano(usrDia, usrMes, usrAnio);
        
        int diferencia = std::abs(jdnSys - jdnUsr);
        
        cout << "\n\033[1;32m>> Diferencia exacta en días totales: \033[1;37m" 
             << diferencia << " días.\033[0m\n";
    }

    // Opción B: Muestra la diferencia desglosada en años, meses y días
    void MostrarDiferenciaCompleta() const {
        int d1, m1, a1; // Fecha menor
        int d2, m2, a2; // Fecha mayor
        
        OrdenarFechas(d1, m1, a1, d2, m2, a2);

        int diffAnios = a2 - a1;
        int diffMeses = m2 - m1;
        int diffDias = d2 - d1;

        // Si los días resultan negativos, pedimos prestado 1 mes
        if (diffDias < 0) {
            diffMeses--;
            // Sumamos los días del mes anterior al mes de la fecha 2
            int mesAnterior = (m2 == 1) ? 12 : m2 - 1;
            int anioMesAnterior = (m2 == 1) ? a2 - 1 : a2;
            diffDias += DiasEnMes(mesAnterior, anioMesAnterior);
        }

        // Si los meses resultan negativos, pedimos prestado 1 año
        if (diffMeses < 0) {
            diffAnios--;
            diffMeses += 12;
        }

        cout << "\n\033[1;32m>> Diferencia desglosada:\033[0m\n";
        cout << "  \033[1;37m" << diffAnios << "\033[0m años, "
             << "\033[1;37m" << diffMeses << "\033[0m meses y "
             << "\033[1;37m" << diffDias << "\033[0m días.\n";
    }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    int dia, mes, anio, opcion;
    string continuar;

    do {
        CalculadoraFechas calc; // Se instancia el objeto y captura la fecha del sistema en este instante

        cout << "\033[33m ----------------------------------------\033[0m\n";
        cout << "\033[33m ----    Calculadora de Fechas      -----\033[0m\n";
        cout << "\033[33m ----------------------------------------\033[0m\n";
        cout << "\033[33m -------------- BY L4ZY404 --------------\033[0m\n";
        cout << "\033[33m ----------------------------------------\033[0m\n\n";

        calc.MostrarFechaSistema();
        cout << "\nIngrese una fecha para comparar:\n";
        
        bool fechaValida = false;
        while (!fechaValida) {
            cout << "  Día (DD): ";
            while (!(cin >> dia)) { cin.clear(); while (cin.get() != '\n') {} }
            
            cout << "  Mes (MM): ";
            while (!(cin >> mes)) { cin.clear(); while (cin.get() != '\n') {} }
            
            cout << "  Año (YYYY): ";
            while (!(cin >> anio)) { cin.clear(); while (cin.get() != '\n') {} }

            fechaValida = calc.CargarFechaUsuario(dia, mes, anio);
            if (!fechaValida) {
                cout << "\033[31m[!] Fecha inválida. Por favor verifique el número de días para ese mes/año e intente de nuevo.\033[0m\n\n";
            }
        }

        cout << "\n\033[36m¿Cómo desea visualizar la diferencia?\033[0m\n";
        cout << "1. Solo en Días Totales.\n";
        cout << "2. En Años, Meses y Días.\n";
        cout << "> ";
        
        while (!(cin >> opcion) || (opcion != 1 && opcion != 2)) {
            cout << "\033[31mOpción no válida. Seleccione 1 o 2:\033[0m ";
            cin.clear();
            while (cin.get() != '\n') {}
        }

        if (opcion == 1) {
            calc.MostrarDiferenciaDiasTotales();
        } else {
            calc.MostrarDiferenciaCompleta();
        }

        cout << "\n¿Desea realizar otro cálculo? (S/N): ";
        cin >> continuar;
        cout << "\n";

    } while (continuar == "S" || continuar == "s");

    cout << "\033[32mSaliendo del programa...\033[0m\n";
    return 0;
}