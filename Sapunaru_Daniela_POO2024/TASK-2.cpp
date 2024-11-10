//#include<iostream>
//
//using namespace std;
//
//class tricou {
//public:
//	string marca;
//	int marime;
//	static int TVA;
//	string material;
//	float pretT;
//	const int anAparitie;
//
//	tricou() : anAparitie(2020) {
//		this->marca = "Adidas";
//		this->marime = 36;
//		this->pretT = 50;
//		this->material = "in";
//	}
//
//	tricou(string marca, float pretT, int marime, int an) :anAparitie(an) {
//		this->marca = marca;
//		this->material = "bumbac";
//		this->pretT = pretT;
//		this->marime = marime;
//
//	}
//
//	tricou(string material, float pretT, int an) :anAparitie(an) {
//		this->marca = "Nike";
//		this->material = material;
//		this->pretT = pretT;
//		this->marime = 38;
//
//	}
//
//	void afisare()
//	{
//
//		cout << "Tricoul este marca:" << this->marca << endl;
//		cout << "Material:" << this->material << endl;
//		cout << "Marime:" << this->marime << endl;
//		cout << "Pret:" << this->pretT << endl;
//		cout << "An aparitie:" << this->anAparitie << endl;
//		cout << "TVA:" << tricou::TVA << endl << endl;
//
//	}
//
//	int nrTricouri;
//
//	static int calculeazaPretMediu(float nrTricouri, tricou* vector) {
//		float PretMediu = 0;
//		for (int i = 1; i < nrTricouri; i++)
//		{
//			PretMediu = PretMediu + vector[i].pretT;
//		}
//		return PretMediu / nrTricouri;
//	}
//
//
//};
//
//
//class incaltaminte {
//public:
//	string firma;
//	float pretI;
//	static int TVA;
//	const int anCumparare;
//	int numar;
//
//	incaltaminte() : anCumparare(2023) {
//		this->firma = "Converse";
//		this->pretI = 400;
//		this->numar = 35;
//
//	}
//
//	incaltaminte(string firma, float pretI, int numar, int an) :anCumparare(an) {
//		this->firma = firma;
//		this->pretI = pretI;
//		this->numar = numar;
//	}
//
//	incaltaminte(string firma, int an) :anCumparare(an) {
//		this->firma = firma;
//		this->pretI = 300;
//		this->numar = 39;
//	}
//
//	void afisare()
//	{
//		cout << endl << "Firma pantofilor este:" << this->firma << endl;
//		cout << "Pret:" << this->pretI << endl;
//		cout << "TVA:" << incaltaminte::TVA << endl;
//		cout << "An cumparare:" << this->anCumparare << endl;
//		cout << "Numar:" << this->numar << endl << endl;
//
//	}
//
//	static int afisarePretMaxim(incaltaminte* vector) {
//		float PretMaxim = 0;
//		for (int i = 0; i < 3; i++) {
//			if (vector[i].pretI > vector[i + 1].pretI) PretMaxim = vector[i].pretI;
//			else PretMaxim = vector[i + 1].pretI;
//		}
//
//		return PretMaxim;
//	}
//};
//
//
//class sapca {
//public:
//	string brand;
//	const int anFabricare;
//	float pretS;
//	string culoare;
//	static int nrTaxe;
//
//	sapca() :anFabricare(2021) {
//		this->brand = "Kappa";
//		this->pretS = 100;
//		this->culoare = "roz";
//	}
//
//	sapca(string brand, float pretS, string culoare, int an) :anFabricare(an) {
//		this->brand = brand;
//		this->pretS = pretS;
//		this->culoare = culoare;
//	}
//
//	sapca(string brand, int an) :anFabricare(an) {
//		this->brand = brand;
//		this->pretS = 59;
//		this->culoare = "negru";
//	}
//
//	void afisare()
//	{
//		cout << endl << "Sapca are brandul:" << this->brand << endl;
//		cout << "An fabricare:" << this->anFabricare << endl;
//		cout << "Pret:" << this->pretS << endl;
//		cout << "Culoare:" << this->culoare << endl;
//		cout << "Numar de taxe:" << sapca::nrTaxe << endl << endl;
//
//	}
//
//	static void modificareNrTaxe(int nrNouT) {
//		if (nrNouT > 0) {
//			sapca::nrTaxe = nrNouT;
//
//		}
//	}
//};
//
//int tricou::TVA = 19;
//int incaltaminte::TVA = 19;
//int sapca::nrTaxe = 9;
//
//
//int main() {
//
//	tricou t1;
//	t1.afisare();
//
//	tricou* pointer1;
//	tricou* pointer2;
//
//	pointer1 = new tricou("Nike", 150, 38, 2020);
//	pointer1->afisare();
//
//	pointer2 = new tricou("catifea", 120, 2020);
//	pointer2->afisare();
//
//	int nrTricouri = 3;
//	tricou* vector;
//	vector = new tricou[nrTricouri];
//
//	for (int i = 0; i < nrTricouri; i++) {
//		vector[i].afisare();
//	}
//
//	cout << "Pretul mediu al unui tricou este:" << tricou::calculeazaPretMediu(nrTricouri, vector) << endl;
//
//	incaltaminte i1;
//	i1.afisare();
//
//	incaltaminte* pointer3;
//	incaltaminte* pointer4;
//
//	pointer3 = new incaltaminte("Puma", 2023);
//	pointer3->afisare();
//	pointer4 = new incaltaminte("Jordan", 550, 44, 2023);
//	pointer4->afisare();
//
//
//	incaltaminte* vector1;
//	vector1 = new incaltaminte[3];
//	for (int i = 0; i < 3; i++) {
//		vector1[i].afisare();
//	}
//
//	cout << "Pretul maxim al unei perechi de incaltaminte este:" << incaltaminte::afisarePretMaxim(vector1) << endl;
//
//	sapca::modificareNrTaxe(12);
//
//	sapca s1;
//	s1.afisare();
//
//	sapca* pointer5;
//	sapca* pointer6;
//
//	pointer5 = new sapca("Polo", 2021);
//	pointer5->afisare();
//
//	pointer6 = new sapca("Hugo", 220, "alb", 2021);
//	pointer6->afisare();
//
//
//
//	delete pointer1;
//	delete pointer2;
//	delete pointer3;
//	delete pointer4;
//	delete pointer5;
//	delete pointer6;
//	delete[]vector;
//	delete[]vector1;
//	return 0;
//}