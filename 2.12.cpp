// GITHUB L4ZY404

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// ==========================================
// CLASE BASE ABSTRACTA
// ==========================================
class Idioma {
public:
    virtual string GetNombre() const = 0;
    virtual string Traducir(int n) const = 0;
    virtual ~Idioma() {} 
};

// ==========================================
// 1. ESPAÑOL
// ==========================================
class IdiomaEspanol : public Idioma {
public:
    string GetNombre() const override { return "Español"; }
    string Traducir(int n) const override {
        vector<string> uni = {"cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", 
                              "diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve", 
                              "veinte", "veintiuno", "veintidós", "veintitrés", "veinticuatro", "veinticinco", "veintiséis", "veintisiete", "veintiocho", "veintinueve"};
        vector<string> dec = {"", "", "", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
        if (n < 30) return uni[n];
        int d = n / 10; int u = n % 10;
        if (u == 0) return dec[d];
        return dec[d] + " y " + uni[u];
    }
};

// ==========================================
// 2. PORTUGUÊS
// ==========================================
class IdiomaPortugues : public Idioma {
public:
    string GetNombre() const override { return "Português"; }
    string Traducir(int n) const override {
        vector<string> uni = {"zero", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove", 
                              "dez", "onze", "doze", "treze", "catorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
        vector<string> dec = {"", "", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
        if (n < 20) return uni[n];
        int d = n / 10; int u = n % 10;
        if (u == 0) return dec[d];
        return dec[d] + " e " + uni[u];
    }
};

// ==========================================
// 3. CATALÀ
// ==========================================
class IdiomaCatala : public Idioma {
public:
    string GetNombre() const override { return "Català"; }
    string Traducir(int n) const override {
        vector<string> uni = {"zero", "un", "dos", "tres", "quatre", "cinc", "sis", "set", "vuit", "nou", 
                              "deu", "onze", "dotze", "tretze", "catorze", "quinze", "setze", "disset", "divuit", "dinou"};
        vector<string> dec = {"", "", "vint", "trenta", "quaranta", "cinquanta", "seixanta", "setanta", "vuitanta", "noranta"};
        if (n < 20) return uni[n];
        int d = n / 10; int u = n % 10;
        if (u == 0) return dec[d];
        if (d == 2) return "vint-i-" + uni[u];
        return dec[d] + "-" + uni[u];
    }
};

// ==========================================
// 4. FRANÇAIS
// ==========================================
class IdiomaFrances : public Idioma {
public:
    string GetNombre() const override { return "Français"; }
    string Traducir(int n) const override {
        vector<string> uni = {"zéro", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", 
                              "dix", "onze", "douze", "treize", "quatorze", "quinze", "seize", "dix-sept", "dix-huit", "dix-neuf"};
        vector<string> dec = {"", "", "vingt", "trente", "quarante", "cinquante", "soixante", "soixante-dix", "quatre-vingts", "quatre-vingt-dix"};
        if (n < 20) return uni[n];
        int d = n / 10; int u = n % 10;
        if (d == 7 || d == 9) { d--; u += 10; }
        if (u == 0) return dec[d];
        if (u == 1 || u == 11) {
            if (n != 81 && n != 91) return dec[d] + " et " + uni[u];
        }
        string dec_str = dec[d];
        if (n > 80 && n < 90) dec_str = "quatre-vingt";
        return dec_str + "-" + uni[u];
    }
};

// ==========================================
// 5. ITALIANO
// ==========================================
class IdiomaItaliano : public Idioma {
public:
    string GetNombre() const override { return "Italiano"; }
    string Traducir(int n) const override {
        vector<string> uni = {"zero", "uno", "due", "tre", "quattro", "cinque", "sei", "sette", "otto", "nove", 
                              "dieci", "undici", "dodici", "tredici", "quattordici", "quindici", "sedici", "diciassette", "diciotto", "diciannove"};
        vector<string> dec = {"", "", "venti", "trenta", "quaranta", "cinquanta", "sessanta", "settanta", "ottanta", "novanta"};
        if (n < 20) return uni[n];
        int d = n / 10; int u = n % 10;
        if (u == 0) return dec[d];
        string dec_str = dec[d];
        if (u == 1 || u == 8) dec_str.pop_back(); 
        string u_str = (u == 3) ? "tré" : uni[u];
        return dec_str + u_str;
    }
};

// ==========================================
// 6. ROMÂNĂ
// ==========================================
class IdiomaRomana : public Idioma {
public:
    string GetNombre() const override { return "Română"; }
    string Traducir(int n) const override {
        vector<string> uni = {"zero", "unu", "doi", "trei", "patru", "cinci", "şase", "şapte", "opt", "nouă", 
                              "zece", "unsprezece", "doisprezece", "treisprezece", "paisprezece", "cincisprezece", "şaisprezece", "şaptesprezece", "optsprezece", "nouăsprezece"};
        vector<string> dec = {"", "", "douăzeci", "treizeci", "patruzeci", "cincizeci", "şaizeci", "şaptezeci", "optzeci", "nouăzeci"};
        if (n < 20) return uni[n];
        int d = n / 10; int u = n % 10;
        if (u == 0) return dec[d];
        return dec[d] + " şi " + uni[u];
    }
};

// ==========================================
// 7. LATINA
// ==========================================
class IdiomaLatin : public Idioma {
public:
    string GetNombre() const override { return "Latina"; }
    string Traducir(int n) const override {
        vector<string> uni = {"nulla", "unum", "duo", "tres", "quattuor", "quinque", "sex", "septem", "octo", "novem", 
                              "decem", "undecim", "duodecim", "tredecim", "quattuordecim", "quindecim", "sedecim", "septendecim", "duodeviginti", "undeviginti"};
        vector<string> dec = {"", "", "viginti", "triginta", "quadraginta", "quinquaginta", "sexaginta", "septuaginta", "octoginta", "nonaginta"};
        if (n < 20) return uni[n];
        int d = n / 10; int u = n % 10;
        if (u == 0) return dec[d];
        return dec[d] + " " + uni[u];
    }
};

// ==========================================
// 8. GAEILGE (IRLANDÉS)
// ==========================================
class IdiomaGaeilge : public Idioma {
public:
    string GetNombre() const override { return "Gaeilge"; }
    string Traducir(int n) const override {
        vector<string> uni = {"a náid", "a haon", "a dó", "a trí", "a ceathair", "a cúig", "a sé", "a seacht", "a hocht", "a naoi", 
                              "a deich", "a haon déag", "a dó dhéag", "a trí déag", "a ceathair déag", "a cúig déag", "a sé déag", "a seacht déag", "a hocht déag", "a naoi déag"};
        vector<string> dec = {"", "", "fiche", "triocha", "daichead", "caoga", "seasca", "seachtó", "ochtó", "nócha"};
        if (n < 20) return uni[n];
        int d = n / 10; int u = n % 10;
        if (u == 0) return dec[d];
        return dec[d] + " " + uni[u];
    }
};

// ==========================================
// 9. ENGLISH
// ==========================================
class IdiomaIngles : public Idioma {
public:
    string GetNombre() const override { return "English"; }
    string Traducir(int n) const override {
        vector<string> uni = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", 
                              "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
        vector<string> dec = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
        if (n < 20) return uni[n];
        int d = n / 10; int u = n % 10;
        if (u == 0) return dec[d];
        return dec[d] + "-" + uni[u];
    }
};

// ==========================================
// 10. NEDERLANDS
// ==========================================
class IdiomaHolandes : public Idioma {
public:
    string GetNombre() const override { return "Nederlands"; }
    string Traducir(int n) const override {
        vector<string> uni = {"nul", "een", "twee", "drie", "vier", "vijf", "zes", "zeven", "acht", "negen", 
                              "tien", "elf", "twaalf", "dertien", "veertien", "vijftien", "zestien", "zeventien", "achttien", "negentien"};
        vector<string> dec = {"", "", "twintig", "dertig", "veertig", "vijftig", "zestig", "zeventig", "tachtig", "negentig"};
        if (n < 20) return uni[n];
        int d = n / 10; int u = n % 10;
        if (u == 0) return dec[d];
        return uni[u] + "en" + dec[d];
    }
};

// ==========================================
// 11. DEUTSCH
// ==========================================
class IdiomaAleman : public Idioma {
public:
    string GetNombre() const override { return "Deutsch"; }
    string Traducir(int n) const override {
        vector<string> uni = {"null", "eins", "zwei", "drei", "vier", "fünf", "sechs", "sieben", "acht", "neun", 
                              "zehn", "elf", "zwölf", "dreizehn", "vierzehn", "fünfzehn", "sechzehn", "siebzehn", "achtzehn", "neunzehn"};
        vector<string> dec = {"", "", "zwanzig", "dreißig", "vierzig", "fünfzig", "sechzig", "siebzig", "achtzig", "neunzig"};
        if (n < 20) return uni[n];
        int d = n / 10; int u = n % 10;
        if (u == 0) return dec[d];
        string u_str = (u == 1) ? "ein" : uni[u]; 
        return u_str + "und" + dec[d];
    }
};

// ==========================================
// 12. SVENSKA
// ==========================================
class IdiomaSueco : public Idioma {
public:
    string GetNombre() const override { return "Svenska"; }
    string Traducir(int n) const override {
        vector<string> uni = {"noll", "en", "två", "tre", "fyra", "fem", "sex", "sju", "åtta", "nio", 
                              "tio", "elva", "tolv", "tretton", "fjorton", "femton", "sexton", "sjutton", "arton", "nitton"};
        vector<string> dec = {"", "", "tjugo", "trettio", "fyrtio", "femtio", "sextio", "sjuttio", "åttio", "nittio"};
        if (n < 20) return uni[n];
        int d = n / 10; int u = n % 10;
        if (u == 0) return dec[d];
        string u_str = (u == 1) ? "ett" : uni[u]; // Regla tjugoett
        return dec[d] + u_str;
    }
};

// ==========================================
// 13. DANSK
// ==========================================
class IdiomaDanes : public Idioma {
public:
    string GetNombre() const override { return "Dansk"; }
    string Traducir(int n) const override {
        vector<string> uni = {"nul", "en", "to", "tre", "fire", "fem", "seks", "syv", "otte", "ni", 
                              "ti", "elleve", "tolv", "tretten", "fjorten", "femten", "seksten", "sytten", "atten", "nitten"};
        vector<string> dec = {"", "", "tyve", "tredive", "fyrre", "halvtreds", "tres", "halvfjerds", "firs", "halvfems"};
        if (n < 20) return uni[n];
        int d = n / 10; int u = n % 10;
        if (u == 0) return dec[d];
        return uni[u] + "og" + dec[d]; // Similar al alemán: enogtyve
    }
};

// ==========================================
// 14. РУССКИЙ (RUSO)
// ==========================================
class IdiomaRuso : public Idioma {
public:
    string GetNombre() const override { return "Русский"; }
    string Traducir(int n) const override {
        vector<string> uni = {"ноль", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять", 
                              "десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать"};
        vector<string> dec = {"", "", "двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто"};
        if (n < 20) return uni[n];
        int d = n / 10; int u = n % 10;
        if (u == 0) return dec[d];
        return dec[d] + " " + uni[u];
    }
};

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    int numero, opcIdioma;
    string opcion;

    do {
        cout << "\033[33m ----------------------------------------\033[0m\n";
        cout << "\033[33m ---- Traductor de Números (Completo)---\033[0m\n";
        cout << "\033[33m ----------------------------------------\033[0m\n";
        cout << "\033[33m -------------- BY L4ZY404 --------------\033[0m\n";
        cout << "\033[33m ----------------------------------------\033[0m\n\n";

        cout << "Ingrese un número entero (0 al 99): ";
        while (!(cin >> numero) || numero < 0 || numero > 99) {
            cout << "\033[31mError. Ingrese un valor válido entre 0 y 99:\033[0m ";
            cin.clear();
            while (cin.get() != '\n') {}
        }

        cout << "\n\033[36mSeleccione el idioma de salida:\033[0m\n";
        cout << " 1. Español        8. Gaeilge\n";
        cout << " 2. Português      9. English\n";
        cout << " 3. Català        10. Nederlands\n";
        cout << " 4. Français      11. Deutsch\n";
        cout << " 5. Italiano      12. Svenska\n";
        cout << " 6. Română        13. Dansk\n";
        cout << " 7. Latina        14. Русский\n";
        cout << "> ";
        
        while (!(cin >> opcIdioma) || opcIdioma < 1 || opcIdioma > 14) {
            cout << "\033[31mOpción no válida. Seleccione 1-14:\033[0m ";
            cin.clear();
            while (cin.get() != '\n') {}
        }

        // Magia del Polimorfismo
        Idioma* traductor = nullptr;
        
        switch (opcIdioma) {
            case 1: traductor = new IdiomaEspanol(); break;
            case 2: traductor = new IdiomaPortugues(); break;
            case 3: traductor = new IdiomaCatala(); break;
            case 4: traductor = new IdiomaFrances(); break;
            case 5: traductor = new IdiomaItaliano(); break;
            case 6: traductor = new IdiomaRomana(); break;
            case 7: traductor = new IdiomaLatin(); break;
            case 8: traductor = new IdiomaGaeilge(); break;
            case 9: traductor = new IdiomaIngles(); break;
            case 10: traductor = new IdiomaHolandes(); break;
            case 11: traductor = new IdiomaAleman(); break;
            case 12: traductor = new IdiomaSueco(); break;
            case 13: traductor = new IdiomaDanes(); break;
            case 14: traductor = new IdiomaRuso(); break;
        }

        if (traductor != nullptr) {
            cout << "\n\033[1;32mResultado en " << traductor->GetNombre() << ":\033[0m\n";
            cout << ">> " << traductor->Traducir(numero) << "\n\n";
            
            delete traductor; 
        }

        cout << "¿Desea traducir otro número? (S/N): ";
        cin >> opcion;
        cout << "\n";

    } while (opcion == "S" || opcion == "s");

    cout << "\033[32mSaliendo del programa...\033[0m\n";
    return 0;
}