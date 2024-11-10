//#include<iostream>
//
//using namespace std;
//
//class Cofetarie {
//
//public:
//	string nume;
//	int nrAngajati;
//	bool esteVegana;
//	const int anDeschidere;//atribut constant
//	float adaos;
//	static int TVA;// atribut static
//
//	Cofetarie() : anDeschidere(2024), adaos(30) {
//		this->nume = "Delice";
//		this->nrAngajati = 3;
//		this->esteVegana = true;
//
//	}
//
//	
//
//	Cofetarie(string nume, int _nrAngajati, bool vegan, int an, float adaos) :anDeschidere(an) {
//		this->nume = nume;
//		this->nrAngajati = _nrAngajati;
//		this->esteVegana = vegan;
//		this->adaos = adaos;
//
//
//	}
//
//	void Afisare()
//	{
//		cout << "Nume:" << this->nume << endl;
//		cout << "Nr angajati:" << this->nrAngajati << endl;
//		cout << "Este vegana?" << (this->esteVegana ? "DA" : "NU") << endl;
//		cout << "An deschidere:" << this->anDeschidere << endl;
//		cout << "Adaos:" << this->adaos << endl;
//		cout << "TVA:" << Cofetarie::TVA << endl;
//	}
//	
//	static void modificaTVA(int noulTVA) {
//		if (noulTVA > 0) {
//			Cofetarie::TVA = noulTVA;
//		}
//	}
//
//	static int calculeazaNrTotalAngajati(int nrCofetarii, Cofetarie* vector) {
//		int suma = 0;
//		for (int i = 0; i < nrCofetarii; i++) {
//			suma = suma + vector[i].nrAngajati;
//		}
//		return suma;
//	}
//
//};
//
//int Cofetarie::TVA = 9;
//
//int main()
//{
//	Cofetarie c1;
//	c1.Afisare();
//
//
//	Cofetarie::modificaTVA(19);
//
//	Cofetarie c2("Dolce vita", 6, false, 2019, 10);
//	c2.Afisare();
//
//
//	Cofetarie* pointer;
//	
//	pointer = new Cofetarie("Ana State", 3, false, 2020, 20);
//	
//	pointer->Afisare();
//
//	delete pointer;
//	int nrCofetarii = 3;
//	Cofetarie* vector;
//	vector = new Cofetarie[nrCofetarii];
//
//	for (int i = 0; i < nrCofetarii; i++)
//	{
//		vector[i].Afisare();
//
//	}
//
//	cout << "Nr total angajati:" << Cofetarie::calculeazaNrTotalAngajati(nrCofetarii, vector);
//	delete[]vector;
//	return 0;
//}