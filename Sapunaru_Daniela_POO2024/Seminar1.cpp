#include<iostream>

using namespace std;

struct ciocolata {
	int gramaj;
	float pret;
	string nume;
	bool esteAmaruie;
};


void afisareCiocolata(ciocolata c) {
	cout << "Nume ciocolata:" << c.nume << endl;
	cout << "Pret:" << c.pret << endl;
	cout << "Gramaj:" << c.gramaj << endl;
	cout << "Este amaruie:" << (c.esteAmaruie ? "DA" : "NU") << endl;


	/*if(c.esteAmaruie){
	cout<<"DA";
	}

	else{
	  cout<<"NU";
	  }*/

}

void modificaPret(ciocolata* c, float pretNou) {
	c->pret = pretNou;
}


void modificaPretRef(ciocolata& c, float pretNou) {
	c.pret = pretNou;
}


ciocolata initializareCiocolata(int gramajN, float pretN, string numeN, bool amaruieN) {

	ciocolata c;
	c.gramaj = gramajN;
	c.pret = pretN;
	c.nume = pretN;
	c.esteAmaruie = amaruieN;
	return c;
}

int main()


{
	ciocolata c1;
	c1 = initializareCiocolata(50, 7, "milka", 0);
	afisareCiocolata(c1);

	/*ciocolata c1;
	c1.gramaj=50;
	c1.pret=7;
	c1.nume="Milka";
	c1.esteAmaruie=false;*/

	afisareCiocolata(c1);//Afisare(1)

	//Afisare(2):

	cout << "Nume ciocolata:" << c1.nume << endl;
	cout << "Pret:" << c1.pret << endl;
	cout << "Gramaj:" << c1.gramaj << endl;
	cout << "Este amaruie:" << c1.esteAmaruie << endl;

	ciocolata c2;
	cout << "Introduceti numele:";
	cin >> c2.nume;
	cout << "Introduceti gramajul:";
	cin >> c2.gramaj;
	cout << "Introduceti pretul:";
	cin >> c2.pret;
	cout << "Este amaruie?(1-DA, 0-NU)";
	cin >> c2.esteAmaruie;


	afisareCiocolata(c2);
	modificaPret(&c2, 40);
	modificaPretRef(c2, 70);
	afisareCiocolata(c2);

}
