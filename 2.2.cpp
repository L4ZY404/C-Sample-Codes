// GITHUB L4ZY404

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// ==========================================
// FUNCIONES AUXILIARES Y DE LIMPIEZA
// ==========================================

string ToUpper(string str) {
    for (char &c : str) c = toupper(c);
    return str;
}

bool IsVowel(char c) {
    c = toupper(c);
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

// Filtra palabras como "DE", "LA", "MAC", etc. (Anexo V)
vector<string> FilterWords(const string& input) {
    vector<string> ignored = {"DE", "LA", "LAS", "LOS", "MAC", "MC", "VAN", "VON", "Y", "DEL", "EL"};
    vector<string> words;
    std::stringstream ss(ToUpper(input));
    string word;
    while (ss >> word) {
        if (std::find(ignored.begin(), ignored.end(), word) == ignored.end()) {
            words.push_back(word);
        }
    }
    return words;
}

// ==========================================
// CLASES
// ==========================================

class PersonaFisica {
private:
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;
    int diaNacimiento, mesNacimiento, anioNacimiento;

public:
    PersonaFisica(string nom, string apPat, string apMat, int dia, int mes, int anio)
        : nombre(nom), apellidoPaterno(apPat), apellidoMaterno(apMat),
          diaNacimiento(dia), mesNacimiento(mes), anioNacimiento(anio) {}

    string GetNombre() const { return nombre; }
    string GetApellidoPaterno() const { return apellidoPaterno; }
    string GetApellidoMaterno() const { return apellidoMaterno; }
    int GetDia() const { return diaNacimiento; }
    int GetMes() const { return mesNacimiento; }
    int GetAnio() const { return anioNacimiento; }
};

class GeneradorRFC {
private:
    // Tablas de valores (Anexos I, II y III de la SHCP)
    std::map<char, string> anexoI;
    std::map<int, char> anexoII;
    std::map<char, int> anexoIII;
    std::set<string> palabrasInconvenientes;

    void InitTablas() {
        // Anexo I: Letras a números de dos dígitos
        string letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int val = 11;
        for (char c : letras) {
            if (c == 'J') val = 21; else if (c == 'S') val = 32; else if (c == 'U') val = 34;
            anexoI[c] = (val < 10 ? "0" : "") + std::to_string(val++);
        }
        anexoI[' '] = "00"; anexoI['&'] = "10"; anexoI['Ñ'] = "40";

        // Anexo II: Cociente/Residuo a Carácter Base 34
        string base34 = "123456789ABCDEFGHIJKLMNPQRSTUVWXYZ"; 
        for (int i = 0; i < 34; i++) anexoII[i] = base34[i];

        // Anexo III: Dígito Verificador
        for (int i = 0; i <= 9; i++) anexoIII['0' + i] = i;
        val = 10;
        string letrasA3 = "ABCDEFGHIJKLMN&OPQRSTUVWXYZ ";
        for (char c : letrasA3) anexoIII[c] = val++;
        anexoIII['Ñ'] = 38;

        // Anexo IV: Palabras Inconvenientes
        vector<string> malas = {"BUEI","BUEY","CACA","CACO","CAGA","CAGO","CAKA","CAKO","COGE",
                                "COJA","COJE","COJI","COJO","CULO","FETO","GUEY","JOTO","KACA",
                                "KACO","KAGA","KAGO","KAKA","KOGE","KOJO","KULO","MAME","MAMO",
                                "MEAR","MEAS","MEON","MION","MOCO","MULA","PEDA","PEDO","PENE",
                                "PUTA","PUTO","QULO","RATA","RUIN"};
        palabrasInconvenientes.insert(malas.begin(), malas.end());
    }

    string ObtenerLetras(const PersonaFisica& p) {
        vector<string> patWords = FilterWords(p.GetApellidoPaterno());
        vector<string> matWords = FilterWords(p.GetApellidoMaterno());
        vector<string> nomWords = FilterWords(p.GetNombre());

        string pat = patWords.empty() ? "" : patWords[0];
        string mat = matWords.empty() ? "" : matWords[0];
        
        // Regla 6: Nombres compuestos con Jose o Maria
        string nom = nomWords[0];
        if ((nom == "JOSE" || nom == "MARIA") && nomWords.size() > 1) {
            nom = nomWords[1];
        }

        string letras = "";
        
        // Regla 4: Apellido paterno de 1 o 2 letras
        if (pat.length() <= 2) {
            letras += pat.substr(0, 1);
            letras += mat.empty() ? "X" : mat.substr(0, 1);
            letras += nom.substr(0, 2);
        } else {
            letras += pat.substr(0, 1);
            // Buscar primera vocal interna
            char vocal = 'X';
            for (size_t i = 1; i < pat.length(); i++) {
                if (IsVowel(pat[i])) { vocal = pat[i]; break; }
            }
            letras += vocal;
            letras += mat.empty() ? "X" : mat.substr(0, 1);
            letras += nom.substr(0, 1);
        }

        // Regla 9: Palabras inconvenientes
        if (palabrasInconvenientes.count(letras)) {
            letras[3] = 'X';
        }

        return letras;
    }

    string ObtenerFecha(const PersonaFisica& p) {
        char buffer[7];
        snprintf(buffer, sizeof(buffer), "%02d%02d%02d", 
                 p.GetAnio() % 100, p.GetMes(), p.GetDia());
        return string(buffer);
    }

    string CalcularHomoclave(const PersonaFisica& p) {
        string nombreCompleto = ToUpper(p.GetApellidoPaterno() + " " + 
                                        p.GetApellidoMaterno() + " " + p.GetNombre());
        string numStr = "0"; // Inicia con 0 para uniformar (Regla 2 de homonimia)
        
        for (char c : nombreCompleto) {
            if (anexoI.count(c)) numStr += anexoI[c];
            else numStr += "00";
        }

        long long suma = 0;
        for (size_t i = 0; i < numStr.length() - 1; i++) {
            int num1 = std::stoi(numStr.substr(i, 2));
            int num2 = numStr[i+1] - '0';
            suma += num1 * num2;
        }

        int ultimas3Cifras = suma % 1000;
        int cociente = ultimas3Cifras / 34;
        int residuo = ultimas3Cifras % 34;

        string homoclave = "";
        homoclave += anexoII[cociente];
        homoclave += anexoII[residuo];
        
        return homoclave;
    }

    char CalcularDigitoVerificador(string rfcSinDigito) {
        int suma = 0;
        for (size_t i = 0; i < 12; i++) {
            int peso = 13 - i;
            suma += anexoIII[rfcSinDigito[i]] * peso;
        }

        int residuo = suma % 11;
        if (residuo == 0) return '0';
        
        int digito = 11 - residuo;
        if (digito == 10) return 'A';
        return '0' + digito;
    }

public:
    GeneradorRFC() { InitTablas(); }

    string Generar(const PersonaFisica& persona) {
        string letras = ObtenerLetras(persona);
        string fecha = ObtenerFecha(persona);
        string homoclave = CalcularHomoclave(persona);
        
        string rfcBase = letras + fecha + homoclave;
        char digitoVerificador = CalcularDigitoVerificador(rfcBase);
        
        return rfcBase + digitoVerificador;
    }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    cout << "\033[33m -------------------------------\033[0m\n";
    cout << "\033[33m ----    Generador de RFC   ----\033[0m\n";
    cout << "\033[33m -------------------------------\033[0m\n";
    cout << "\033[33m ---------- BY L4ZY404 ---------\033[0m\n";
    cout << "\033[33m -------------------------------\033[0m\n\n";

    string nombre, paterno, materno;
    int dia, mes, anio;

    cout << "Ingrese Nombre(s) (sin acentos): ";
    std::getline(cin, nombre);
    
    cout << "Ingrese Apellido Paterno: ";
    std::getline(cin, paterno);
    
    cout << "Ingrese Apellido Materno (deje en blanco si no tiene): ";
    std::getline(cin, materno);

    cout << "Ingrese Día de Nacimiento (DD): ";
    cin >> dia;
    cout << "Ingrese Mes de Nacimiento (MM): ";
    cin >> mes;
    cout << "Ingrese Año de Nacimiento (YYYY): ";
    cin >> anio;

    PersonaFisica persona(nombre, paterno, materno, dia, mes, anio);
    GeneradorRFC generador;

    string rfc = generador.Generar(persona);

    cout << "\n\033[36mRFC Generado con Homoclave:\033[0m\n";
    cout << "\033[1;32m" << rfc << "\033[0m\n\n";

    return 0;
}