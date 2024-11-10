//#include<iostream>
//
//using namespace std;
//
//class Cofetarie {
//private:
//    string nume;
//    int nrAngajati;
//    //ptr a salva toate salariile angajatilor:
//    float* salarii;//string* nranagajati- ptr a retine numele
//    bool esteVegana;
//    const int anDeschidere;
//    float adaos;
//    static int TVA;
//
//    //ordine:atribute, constructori, const de copiere, destructor, geteri seteri, functii
//
//public:
//
//    Cofetarie() : adaos(30), anDeschidere(2024) {
//        this->nume = "Delice";
//        this->nrAngajati = 0;
//        this->esteVegana = true;
//        this->salarii = NULL;//PTR CA NU E nici un angajat, sau nullptr
//    }
//
//    Cofetarie(string nume, int nrAngajati, bool vegan, int an, float adaos) :anDeschidere(an) {
//        this->nume = nume;
//        this->nrAngajati = nrAngajati;
//        this->esteVegana = vegan;
//        this->adaos = adaos;
//        this->salarii = new float[nrAngajati];
//        for (int i = 0; i < nrAngajati; i++) {
//            this->salarii[i] = 1000 + i * 100;
//        }
//
//    }//lista de initializarea a constructorului::anDeschidere(an)
//    //copiaza un obiect din cel intial
//
//    //suntem obligati sa il facem ptr ca avem un atribut alocat dinamic
//    //ca sa apelez constructorul de copiere rebuie apelat constr de copiere-nu se poate face cu trans prin valoare
//
//
//    Cofetarie(const Cofetarie& c) :anDeschidere(c.anDeschidere) {
//
//        this->nume = c.nume;
//        this->nrAngajati = c.nrAngajati;
//
//        //am alocat direct spatiu fara sa stergem memoria ca mai jos, pentru ca doar construieste, nu exista obiectul inainte
//        this->salarii = new float[c.nrAngajati];
//        for (int i = 0; i < c.nrAngajati; i++) {
//            this->salarii[i] = c.salarii[i];
//        }
//        this->esteVegana = c.esteVegana;
//        this->adaos = c.adaos;
//
//
//    }
//
//
//    ~Cofetarie() {
//        //stergem ce alocam in heap->salarii daca a fost alocat(in al doilea a fost alocat
//
//        if (this->salarii != NULL)//sau (this->salarii)
//            delete[]this->salarii;
//
//    }//este apelat cand durata de viata a obiectului s a terminat-cand se termina corpul in care este
//
//
//
//    string getNume() {
//        return this->nume;
//    }
//    //tipul returnat string cu numele getnume, fara parametrii; returnez tributul nume;
//
//    void setNume(string noulNume) {
//        if (noulNume.length() > 2)//dc nou nume e valid
//        {
//            this->nume = noulNume;
//        }
//    }
//
//
//    int getNrAngajati() {
//        return this->nrAngajati;
//    }
//
//
//    //seter compus
//    void setNrAngajati(int NouNrAngajati, float* salariu) {
//        if (NouNrAngajati > 0) {
//            this->nrAngajati = NouNrAngajati;
//            if (this->salarii != NULL) {
//                delete[]this->salarii;
//            }
//
//            this->salarii = new float[this->nrAngajati];
//
//            for (int i = 0; i < this->nrAngajati; i++)
//            {
//                this->salarii[i] = salarii[i];
//            }
//        }
//    }
//
//
//    float* getSalarii() {
//        return this->salarii;
//    }
//
//
//    float getSalariu(int index) //ret un singur salariu{
//    {
//        if (index >= 0 && index < nrAngajati)
//            return this->salarii[index];
//
//    }
//
//
//    void afisare() {
//        cout << "Nume:" << this->nume << endl;
//        cout << "Nr angajati:" << this->nrAngajati << endl;
//        cout << "Are produse vegane:" << (this->esteVegana ? "DA" : "NU") << endl;
//        cout << "An deschidere:" << this->anDeschidere << endl;
//        cout << "Adaos:" << this->adaos << endl;
//        cout << "TVA:" << Cofetarie::TVA << endl;
//    }
//
//    static void modificaTVA(int noulTVA) {
//        if (noulTVA > 0) {
//            Cofetarie::TVA = noulTVA;
//        }
//    }
//    static int calculeazaNrTotalAngajati(int nrCofetarii, Cofetarie* vector) {
//        int suma = 0;
//        for (int i = 0; i < nrCofetarii; i++) {
//            suma += vector[i].nrAngajati;
//        }
//
//        return suma;
//    }
//
//
//
//
//
//};
//
//int Cofetarie::TVA = 9;
//
//void f(Cofetarie c) {
//
//}
//
//
//int main() {
//
//    Cofetarie c;
//    //c.setNume(" ");-de asta se pune conditie
//
//    cout << c.getNume() << endl;
//    c.setNume(" ");
//    cout << c.getNume() << endl;
//    c.setNume("Alt nume");
//    cout << c.getNume() << endl;
//
//    c.setNrAngajati(4, new float[4] {2, 6, 4, 9});//initializare inline;-nu e recomandata, de ce?
//    cout << c.getNrAngajati() << endl;
//
//
//
//
//    Cofetarie c2("Minimal", 3, false, 2020, 10);
//
//    //afisare sal ptr al doilea angajat
//
//    //cout << c2.getSalarii();//afiseaza adresa
//
//    cout << c2.getNrAngajati() << endl;
//
//    cout << c2.getSalarii()[1] << endl;
//
//    cout << c2.getSalariu(1) << endl;
//
//    c2.setNrAngajati(5, new float[5] {1, 2, 3, 4, 5});
//    cout << c2.getSalariu(3);
//
//    Cofetarie* vector = new Cofetarie[100];
//    delete[]vector;
//
//    //apelare constr de copiere
//    Cofetarie c3(c2);
//    Cofetarie c4 = c3;
//
//    f(c4);//apelare constr de copiere prin functie
//
//
//    //-> - derefentiere + accesare
////[] - deplasare + derefentiere
////build-clean solution
//}