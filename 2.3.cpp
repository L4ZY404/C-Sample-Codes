// GITHUB L4ZY404

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
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

bool IsConsonant(char c) {
    c = toupper(c);
    return (c >= 'A' && c <= 'Z' && !IsVowel(c));
}

// Filtra palabras como "DE", "LA", "MAC", etc.
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

char GetFirstInternalVowel(const string& word) {
    for (size_t i = 1; i < word.length(); i++) {
        if (IsVowel(word[i])) return word[i];
    }
    return 'X';
}

char GetFirstInternalConsonant(const string& word) {
    for (size_t i = 1; i < word.length(); i++) {
        if (IsConsonant(word[i]) && word[i] != 'N' + 1) { // Simplificación para evitar la Ñ directa
            return word[i];
        } else if (word[i] == -47 || word[i] == -111) { // ASCII extendido aproximado para Ñ
            return 'X'; 
        }
    }
    return 'X';
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
    char sexo;
    string entidadFederativa;

public:
    PersonaFisica(string nom, string apPat, string apMat, int dia, int mes, int anio, char s, string entidad)
        : nombre(nom), apellidoPaterno(apPat), apellidoMaterno(apMat),
          diaNacimiento(dia), mesNacimiento(mes), anioNacimiento(anio), sexo(toupper(s)), entidadFederativa(ToUpper(entidad)) {}

    string GetNombre() const { return nombre; }
    string GetApellidoPaterno() const { return apellidoPaterno; }
    string GetApellidoMaterno() const { return apellidoMaterno; }
    int GetDia() const { return diaNacimiento; }
    int GetMes() const { return mesNacimiento; }
    int GetAnio() const { return anioNacimiento; }
    char GetSexo() const { return sexo; }
    string GetEntidad() const { return entidadFederativa; }
};

class GeneradorCURP {
private:
    std::set<string> palabrasInconvenientes;

    void InitTablas() {
        vector<string> malas = {"BACA","BAKA","BUEI","BUEY","CACA","CACO","CAGA","CAGO","CAKA","CAKO","COGE",
                                "COGI","COJA","COJE","COJI","COJO","COLA","CULO","FALO","FETO","GETA","GUEI",
                                "GUEY","JETA","JOTO","KACA","KACO","KAGA","KAGO","KAKA","KAKO","KOGE","KOGI",
                                "KOJA","KOJE","KOJI","KOJO","KOLA","KULO","LILO","LOCA","LOCO","LOKA","LOKO",
                                "MAME","MAMO","MEAR","MEAS","MEON","MIAR","MION","MOCO","MOKO","MULA","MULO",
                                "NACA","NACO","PEDA","PEDO","PENE","PIPI","PITO","POPO","PUTA","PUTO","QULO",
                                "RATA","ROBA","ROBE","ROBO","RUIN","SENO","TETA","VACA","VAGA","VAGO","VAKA",
                                "VUEI","VUEY","WUEI","WUEY"};
        palabrasInconvenientes.insert(malas.begin(), malas.end());
    }

    string ObtenerSiglasIniciales(const PersonaFisica& p, string& patClean, string& matClean, string& nomClean) {
        vector<string> patWords = FilterWords(p.GetApellidoPaterno());
        vector<string> matWords = FilterWords(p.GetApellidoMaterno());
        vector<string> nomWords = FilterWords(p.GetNombre());

        patClean = patWords.empty() ? "X" : patWords[0];
        matClean = matWords.empty() ? "X" : matWords[0];
        nomClean = nomWords.empty() ? "X" : nomWords[0];
        
        // Regla Jose/Maria
        if ((nomClean == "JOSE" || nomClean == "MARIA") && nomWords.size() > 1) {
            nomClean = nomWords[1];
        }

        string letras = "";
        letras += patClean[0];
        letras += GetFirstInternalVowel(patClean);
        letras += matClean[0];
        letras += nomClean[0];

        if (palabrasInconvenientes.count(letras)) {
            letras[1] = 'X';
        }

        return letras;
    }

    string ObtenerFecha(const PersonaFisica& p) {
        char buffer[7];
        snprintf(buffer, sizeof(buffer), "%02d%02d%02d", 
                 p.GetAnio() % 100, p.GetMes(), p.GetDia());
        return string(buffer);
    }

    string ObtenerConsonantesInternas(const string& pat, const string& mat, const string& nom) {
        string consonantes = "";
        consonantes += GetFirstInternalConsonant(pat);
        consonantes += GetFirstInternalConsonant(mat);
        consonantes += GetFirstInternalConsonant(nom);
        return consonantes;
    }

public:
    GeneradorCURP() { InitTablas(); }

    string Generar(const PersonaFisica& persona) {
        string patClean, matClean, nomClean;
        
        // 1-4: Iniciales
        string siglas = ObtenerSiglasIniciales(persona, patClean, matClean, nomClean);
        // 5-10: Fecha de nacimiento
        string fecha = ObtenerFecha(persona);
        // 11: Sexo
        string sexo(1, persona.GetSexo());
        // 12-13: Entidad
        string entidad = persona.GetEntidad();
        // 14-16: Consonantes internas
        string consonantes = ObtenerConsonantesInternas(patClean, matClean, nomClean);
        
        return siglas + fecha + sexo + entidad + consonantes;
    }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    cout << "\033[33m -------------------------------\033[0m\n";
    cout << "\033[33m ----   Generador de CURP   ----\033[0m\n";
    cout << "\033[33m -------------------------------\033[0m\n";
    cout << "\033[33m ---------- BY L4ZY404 ---------\033[0m\n";
    cout << "\033[33m -------------------------------\033[0m\n\n";

    string nombre, paterno, materno, entidad;
    int dia, mes, anio;
    char sexo;

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

    cout << "Ingrese Sexo (H para Hombre, M para Mujer): ";
    cin >> sexo;

    cout << "\n\033[36mCatálogo de Entidades:\033[0m\n";
    cout << "AS: Aguascalientes  BC: Baja California  DF: Ciudad de Mexico  HG: Hidalgo\n";
    cout << "JC: Jalisco         MC: Edo. de Mexico   NL: Nuevo Leon        VZ: Veracruz\n";
    cout << "(Use 'NE' si es Nacido en el Extranjero)\n";
    cout << "Ingrese el código de Entidad Federativa (2 letras): ";
    cin >> entidad;

    PersonaFisica persona(nombre, paterno, materno, dia, mes, anio, sexo, entidad);
    GeneradorCURP generador;

    string curp16 = generador.Generar(persona);

    cout << "\n\033[36mCURP Generada (16 caracteres base):\033[0m\n";
    cout << "\033[1;32m" << curp16 << "\033[0m\n\n";

    return 0;
}