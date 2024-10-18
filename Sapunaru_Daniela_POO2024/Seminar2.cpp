#include<iostream>

using namespace std;

struct Farmacie {
    char* nume;
    string adresa;
    int nrMedicamente;
    float* preturi;
};

void afisareFarmacie(Farmacie f) {
    cout << "Nume:" << f.nume << endl;
    cout << "Adresa:" << f.adresa << endl;
    cout << "Nr medicamente" << f.nrMedicamente << endl;
    cout << "Preturi:" << endl;
    for (int i = 0; i < f.nrMedicamente; i++) {
        cout << f.preturi[i] << "," << endl;

    }
}

//fuctie pentru a citi 3 farmacii de la tastatura:

Farmacie citireFarmacie() {

    Farmacie f;
    cout << "La ce adresa este:";
    cin >> f.adresa;
    cout << "Numele farmaciei:";

    char buffer[100];
    cin >> buffer;

    f.nume = new char[strlen(buffer) + 1];
    strcpy_s(f.nume, strlen(buffer) + 1, buffer);

    cout << "Nr de medicamente:";
    cin >> f.nrMedicamente;

    f.preturi = new float[f.nrMedicamente];

    cout << "Preturi:";
    for (int i = 0; i < f.nrMedicamente; i++) {
        cin >> f.preturi[i];
    }

    return f;
}



int main()
{
    //Farmacie f;
    //pointer = &f;

    Farmacie* pointer;
    pointer = new Farmacie();//alocare spatiu in heap

    pointer->adresa = "Romana";
    pointer->nume = new char[strlen("Catena") + 1];//alocam spatiu pentru pointer, catena=6+ terminatorul de sir
    strcpy_s(pointer->nume, strlen("Catena") + 1, "Catena");//strlen(destinatie,dimensiune,sursa)

    pointer->nrMedicamente = 5;
    pointer->preturi = new float[pointer->nrMedicamente];
    for (int i = 0; i < pointer->nrMedicamente; i++)
    {
        pointer->preturi[i] = i + 1;
    }

    afisareFarmacie(*pointer);

    //declarare un vector de farmacii:

    int nrFarmacii = 3;
    Farmacie* vector;
    vector = new Farmacie[nrFarmacii]; //alocare spatiu

    for (int i = 0; i < nrFarmacii; i++) {
        vector[i] = citireFarmacie();
    }

    for (int i = 0; i < nrFarmacii; i++) {
        afisareFarmacie(vector[i]);

    }

    for (int i = 0; i < nrFarmacii; i++) {
        delete[]vector[i].nume;
        delete[]vector[i].preturi;
    }
    delete[]vector;


    //decl vector de pointer la farmacie
        /*
    Farmacie** pointeri;
    pointeri = new Farmacie * [4];
    */


    return 0;
}
