//#include<iostream>
//using namespace std;
//
//
//
//class tricou {
//private:
//	string marca;
//	int nrMagazine;
//	static int TVA;
//	string material;
//	float* pretT;
//	const int anAparitie;
//
//
//public:
//
//	tricou(const tricou& t) :anAparitie(t.anAparitie) {
//		this->marca = t.marca;
//		this->nrMagazine = t.nrMagazine;
//		this->material = t.material;
//
//		this->pretT = new float[t.nrMagazine];
//		for (int i = 0; i < t.nrMagazine; i++) {
//			this->pretT[i] = t.pretT[i];
//		}
//	}
//
//
//	~tricou() {
//		if (this->pretT != NULL) {
//			delete[]this->pretT;
//		}
//	}
//
//	string getMarca() {
//		return this->marca;
//	}
//	string setMarca(string marca) {
//		if (marca.length() > 2) {
//			this->marca = marca;
//		}
//	}
//
//	int getNrMagazine() {
//		return this->nrMagazine;
//	}
//	int setNrMagazine(int nrMagazine) {
//		if (nrMagazine > 1) {
//			this->nrMagazine = nrMagazine;
//		}
//		return nrMagazine;
//	}
//
//	string getMaterial() {
//		return this->material;
//	}
//	string setMaterial(string material) {
//		if (material.length() > 1) {
//			this->material = material;
//		}
//	}
//
//	static int getTVA() {
//		return TVA;
//	}
//
//
//	//seter compus:
//	void setNrMagazine(int nrMagazine, float* pretT) {
//		if (nrMagazine > 0) {
//			this->nrMagazine = nrMagazine;
//			if (this->pretT != NULL) {
//				delete[] this->pretT;
//			}
//			this->pretT = new float[this->nrMagazine];
//			for (int i = 0; i < this->nrMagazine; i++) {
//				this->pretT[i] = pretT[i];
//			}
//		}
//	}
//
//
//
//	float* getPreturi() {
//		return this->pretT;
//	}
//
//	float setPret(int index) {
//		if (index >= 0 && index < this->nrMagazine) {
//			return this->pretT[index];
//		}
//	}
//
//	static void modificaTVA(int noulTVA) {
//		if (noulTVA > 0) {
//			tricou::TVA = noulTVA;
//		}
//	}
//
//
//	tricou() : anAparitie(2020) {
//		this->marca = "Adidas";
//		this->nrMagazine = 36;
//		this->pretT = NULL;
//		this->material = "in";
//	}
//
//
//	void afisare()
//	{
//
//		cout << "Tricoul este marca:" << this->marca << endl;
//		cout << "Material:" << this->material << endl;
//		cout << "Numarul magazinelor care vand tricoul:" << this->nrMagazine << endl;
//		cout << "An aparitie:" << this->anAparitie << endl;
//		cout << "TVA:" << tricou::TVA << endl << endl;
//
//	}
//
//
//	friend void procesare(tricou& t);
//	friend void modificarePret(tricou& t);
//};
//
//void procesare(tricou& t) {
//	int nr = t.getNrMagazine();
//	t.setNrMagazine(nr * 2);
//}
//
//void modificarePret(tricou& t) {
//	int pretNou = 120;
//	t.setPret(pretNou);
//}
//
//
//class incaltaminte {
//private:
//	string firma;
//	float* pretI;
//	static int TVA;
//	const int anCumparare;
//	int nrMagazine;
//
//public:
//
//	incaltaminte(const incaltaminte& i) :anCumparare(i.anCumparare) {
//		this->firma = i.firma;
//		this->nrMagazine = i.nrMagazine;
//		this->pretI = new float[i.nrMagazine];
//		for (int i1 = 0; i1 < i.nrMagazine; i1++) {
//			this->pretI[i1] = i.pretI[i1];
//		}
//	}
//
//	~incaltaminte() {
//		if (this->pretI) {
//			delete[]this->pretI;
//		}
//	}
//
//	string getFirma() {
//		return this->firma;
//	}
//	string setFirma(string nouafirma) {
//		if (nouafirma.length() > 2) {
//			this->firma = nouafirma;
//		}
//		return nouafirma;
//	}
//
//	int getNrMagazine() {
//		return this->nrMagazine;
//	}
//	int setNrMagazine(int noulNr) {
//		if (noulNr > 0) {
//			this->nrMagazine = noulNr;
//		}
//		return noulNr;
//	}
//
//	float* getPreturi() {
//		return this->pretI;
//	}
//
//	float setPret(int index) {
//		if (index >= 0 && index < this->nrMagazine) {
//			return this->pretI[index];
//		}
//	}
//	static int getTVA() {
//		return TVA;
//	}
//
//
//	incaltaminte() : anCumparare(2023) {
//		this->firma = "Converse";
//		this->pretI = NULL;
//		this->nrMagazine = 5;
//
//	}
//
//
//	void afisare()
//	{
//		cout << endl << "Firma pantofilor este:" << this->firma << endl;
//		cout << "TVA:" << incaltaminte::TVA << endl;
//		cout << "An cumparare:" << this->anCumparare << endl;
//		cout << "Nr magazinelor:" << this->nrMagazine << endl << endl;
//
//	}
//
//	friend void modificaFirma(incaltaminte& i);
//	friend void calculeazaNrTotalMagazine(incaltaminte& i);
//};
//
//void modificaFirma(incaltaminte& i) {
//	string firma = i.getFirma();
//	i.setFirma(firma + ".srl");
//
//}
//
//void modificaNrMagazine(incaltaminte& i) {
//	int nrMagazine = i.getNrMagazine();
//	i.setNrMagazine(nrMagazine + 5);
//}
//
//
//
//class sapca {
//private:
//	string brand;
//	int nrModele;
//	const int anFabricare;
//	float* pretS;
//	string culoare;
//	static int nrTaxe;
//
//public:
//
//	sapca(const sapca& s) :anFabricare(s.anFabricare) {
//		this->brand = s.brand;
//		this->nrModele = s.nrModele;
//		this->culoare = s.culoare;
//		this->pretS = new float[s.nrModele];
//		for (int i = 0; i < s.nrModele; i++) {
//			this->pretS[i] = s.pretS[i];
//		}
//	}
//
//	~sapca() {
//		if (this->pretS) {
//			delete[]this->pretS;
//		}
//	}
//
//	string getBrand() {
//		return this->brand;
//	}
//	string setBrand(string noulB) {
//		if (noulB.length() > 1)
//			this->brand = noulB;
//	}
//
//	int getNrModele() {
//		return this->nrModele;
//	}
//	int setNrModele(int noulNr) {
//		if (noulNr > 0) {
//			this->nrModele = noulNr;
//		}
//		return noulNr;
//	}
//
//	string getCuloare() {
//		return this->culoare;
//	}
//	string setCuloare(string nouaCuloare) {
//		if (nouaCuloare.length() > 2)
//			this->culoare = nouaCuloare;
//		return nouaCuloare;
//	}
//
//	float* getPreturi() {
//		return this->pretS;
//	}
//	float setPret(int index) {
//		if (index >= 0 && index < this->nrModele) {
//			return this->pretS[index];
//		}
//
//	}
//
//	static int getNrTaxe() {
//		return nrTaxe;
//	}
//
//	sapca() :anFabricare(2021) {
//		this->brand = "Kappa";
//		this->pretS = NULL;
//		this->culoare = "roz";
//		this->nrModele = 5;
//	}
//
//
//	void afisare()
//	{
//		cout << endl << "Sapca are brandul:" << this->brand << endl;
//		cout << "An fabricare:" << this->anFabricare << endl;
//		cout << "Numar de modele:" << this->nrModele << endl;
//		cout << "Culoare:" << this->culoare << endl;
//		cout << "Numar de taxe:" << sapca::nrTaxe << endl << endl;
//
//	}
//	friend void nrModele(sapca& s);
//	friend void modificaCuloare(sapca& s);
//
//};
//void nrModele(sapca& s) {
//	int nrModele = s.getNrModele();
//	s.setNrModele(nrModele - 2);
//}
//
//void modificaCuloare(sapca& s) {
//	string culoare = s.getCuloare();
//	s.setCuloare("albastru");
//}
//
//int tricou::TVA = 19;
//int incaltaminte::TVA = 19;
//int sapca::nrTaxe = 9;
//
//
//int main() {
//	tricou t;
//	cout << "Nr initial de magazine in care se vinde tricoul:" << t.getNrMagazine() << endl;
//	cout << "Pretul initial:" << t.getPreturi() << endl;
//	procesare(t);
//	modificarePret(t);
//	cout << "Numarul final de magazine:" << t.getNrMagazine() << endl;
//	cout << "Pretul final este:" << t.getPreturi() << endl << endl;
//
//	incaltaminte i;
//	cout << "Numele initial al firmei este:" << i.getFirma() << endl;
//	cout << "Numarul initial de magazine pentru incaltaminte:" << i.getNrMagazine() << endl;
//	modificaFirma(i);
//	modificaNrMagazine(i);
//	cout << "Firma are numele final:" << i.getFirma() << endl;
//	cout << "Numarul final de magazine este:" << i.getNrMagazine() << endl << endl;
//
//
//	sapca s;
//	cout << "Numarul initial de modele este:" << s.getNrModele() << endl;
//	cout << "Culoarea intiala este:" << s.getCuloare() << endl;
//	nrModele(s);
//	modificaCuloare(s);
//	cout << "Numarul final de modele:" << s.getNrModele() << endl;
//	cout << "Culoarea finala este:" << s.getCuloare() << endl << endl;
//
//	return 0;
//}