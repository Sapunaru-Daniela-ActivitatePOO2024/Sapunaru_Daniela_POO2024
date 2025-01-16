#include<iostream>
#include<list>
#include<map>
using namespace std;

//stl- functii/clase template
//3 categorii de elemente
//containere - structuri de date
//algoritmi-functii
//iteratori-pointeri


class Aliment {
string nume;
float pret;

public:
Aliment() {
this->nume = "Aliment";
this->pret = 0;
}
Aliment(string nume, float pret) {
this->nume = nume;
this->pret = pret;
}

void afisareDescriere() {
cout << nume << "=>" << pret<<endl;//itoa->int-ascii
}


};


int main() {

map<string, float> preturi;
preturi.insert(pair<string, int>("Lapte", 23));
preturi.insert(pair<string, int>("Paine", 7));
preturi.insert(pair<string, int>("Oua", 16));
preturi.insert(pair<string, int>("Lapte", 35));

//nu se suprascrie, dc exista deja acea cheie, nu mi permite sa mai inserez o data

preturi["Lapte"] = 67;//indexare dupa cheie, modifica 23 in 67

map<string, float>::iterator it;
int s = 0;
it = preturi.begin();//adresa de inceput a containerului
while (it != preturi.end()) {
s += it->second;
it++;
}
cout << "Suma:" << s << endl;
//Afisare elemente:preturi


it = preturi.begin();//adresa de inceput a containerului
while (it != preturi.end()) {
   cout<< it->first<<"=>"<<it->second<<endl;
it++;
}

list<Aliment>alimente;
alimente.push_back(Aliment());
alimente.push_back(Aliment("Lapte", 20));
alimente.push_front(Aliment("Paine", 10));
alimente.push_front(Aliment("Oua", 16));

cout << "Lista:" << endl;
list<Aliment>::iterator iter = alimente.begin();
while (iter != alimente.end()) {
         iter->afisareDescriere();
           iter++;
    }

    



return 344;

}
