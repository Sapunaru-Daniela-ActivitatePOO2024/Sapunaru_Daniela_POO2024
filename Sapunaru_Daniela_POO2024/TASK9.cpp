#include<iostream>

using namespace std;



class Produs {
	float adaos;
public:
	Produs() {
		this->adaos = 0.3;
	}
	virtual ~Produs() {

	}
	virtual void afisare() = 0;
	virtual void afisare2() = 0;

	virtual int getAn() = 0;
};

class ProdusCuTVA {
	float TVA;
public:
	ProdusCuTVA() {
		this->TVA = 0.19;
	}
	virtual ~ProdusCuTVA() {

	}
	virtual void afisare2() = 0;

	float getTVA() {
		return this->TVA;
	}
};


class Tricou: public Produs , public ProdusCuTVA{
private:
	int nrMagazine;
	static int TVA;
	string material;
	float* pretT;
	const int anAparitie;
protected: 
	string marca;

public:

	int getAn() {
		return this->anAparitie;
	}

	Tricou() : anAparitie(2020) {
		this->marca = "Adidas";
		this->nrMagazine = 36;
		this->pretT = NULL;
		this->material = "in";
	}

	Tricou(int nrMagazine,  float* pret, int an) :anAparitie(an) {
		this->marca = "Polo";
		this->nrMagazine = nrMagazine;
		this->pretT = pret;
		this->material = "bumbac";
	}


	Tricou(string material, int nrMagazine, string marca, float* pret, int an) : anAparitie(an) {
		this->material = material;
		this->nrMagazine = nrMagazine;
		this->marca = marca;
		this->pretT = pret;
	}


	Tricou(const Tricou& t) :anAparitie(t.anAparitie) {
		this->marca = t.marca;
		this->nrMagazine = t.nrMagazine;
		this->material = t.material;
		if (t.pretT != NULL) {
			this->pretT = new float[t.nrMagazine];
			for (int i = 0; i < t.nrMagazine; i++) {
				this->pretT[i] = t.pretT[i];
			}
		}
		else this->pretT = NULL;
	}


	~Tricou() {
		if (this->pretT) {
			delete[]this->pretT;
		}
	}

	string getMarca() {
		return this->marca;
	}
	string setMarca(string marca) {
		if (marca.length() > 2) {
			this->marca = marca;
		}
	}

	int getNrMagazine() {
		return this->nrMagazine;
	}
	int setNrMagazine(int nrMagazine) {
		if (nrMagazine > 1) {
			this->nrMagazine = nrMagazine;
		}
		return nrMagazine;
	}

	string getMaterial() {
		return this->material;
	}
	string setMaterial(string material) {
		if (material.length() > 1) {
			this->material = material;
		}
	}

	static int getTVA() {
		return TVA;
	}


	//seter compus:
	void setNrMagazine(int nrMagazine, float* pretT) {
		if (nrMagazine > 0) {
			this->nrMagazine = nrMagazine;
			if (this->pretT != NULL) {
				delete[] this->pretT;
			}
			this->pretT = new float[this->nrMagazine];
			for (int i = 0; i < this->nrMagazine; i++) {
				this->pretT[i] = pretT[i];
			}
		}
	}

	float* getPreturi() {
		return this->pretT;
	}

	float setPret(int index) {
		if (index >= 0 && index < this->nrMagazine) {
			return this->pretT[index];
		}
	}

	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Tricou::TVA = noulTVA;
		}
	}



	friend ostream& operator<<(ostream& out, Tricou t) {
		out << "Tricoul este marca:" << t.marca << endl;
		out << "Material:" << t.material << endl;
		out << "Numarul magazinelor care vand tricoul:" << t.nrMagazine << ":";
		if (t.pretT != NULL) {
			for (int i = 0; i < t.nrMagazine; i++) {
				out << t.pretT[i] << ",";
			}
		}out << endl;

		out << "An aparitie:" << t.anAparitie << endl;
		out << "TVA:" << Tricou::TVA << endl << endl;

		return out;
	}

	friend istream& operator>>(istream& in, Tricou& t) {
		cout << "Introduceti marca:";
		in >> t.marca;
		cout << "Materialul:";
		in >> t.material;
		cout << "Nr magazine:";
		in >> t.nrMagazine;
		if (t.pretT != NULL) {
			delete[]t.pretT;
		}
		if (t.nrMagazine > 0) {
			t.pretT = new float[t.nrMagazine];
			for (int i = 0; i < t.nrMagazine; i++) {
				cout << "Salariul " << i + 1 << ":";
				in >> t.pretT[i];
			}
		}
		else {
			t.pretT = NULL;
		}

		return in;
	}

	Tricou operator=(const Tricou& t) {
		if (this != &t) {
			this->marca = t.marca;
			this->nrMagazine = t.nrMagazine;
			this->material = t.material;
			if (this->pretT != NULL) {
				delete[]this->pretT;
			}
			this->pretT = new float[t.nrMagazine];
			for (int i = 0; i < t.nrMagazine; i++) {
				this->pretT[i] = t.pretT[i];
			}
		}
		return *this;
	}
	friend class dulap;

	float getPretTotal() {
		int s = 0;
		for (int i = 0; i < this->nrMagazine; i++) {
			s += pretT[i];
		}
		return s;
	}

	void afisare2() {

	}
	void afisare() {}

	virtual void afisareMarca() {
		cout << "Marca 1:" << this->marca;
	}
};

int Tricou::TVA = 9;

class Incaltaminte: public Produs {
private:
	float pretI;
	static int TVA;
	const int anCumparare;
	int nrMagazine;

public:
	void afisare() {

	}
	void afisare2() {

	}
	int getAn() {
		return this->anCumparare;
	}

	Incaltaminte() :anCumparare(2021) {
		
		this->pretI = 100;
		this->nrMagazine = 2;
	}
	
	Incaltaminte(float pret, int nr, int an) :anCumparare(an) {
		this->pretI = pret;
		this->nrMagazine = nr;
	}

	Incaltaminte(const Incaltaminte& i) :anCumparare(i.anCumparare) {
		this->nrMagazine = i.nrMagazine;
		this->pretI = i.pretI;
	}

	Incaltaminte operator=(const Incaltaminte& c) {
		if (&c != this) {//verif de autoasignare
			this->pretI = c.pretI;
			this->nrMagazine = c.nrMagazine;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, Incaltaminte c) {
		out << "Pret:" << c.pretI << endl;
		out << "Nr magazine:" << c.nrMagazine << endl;
		out << "TVA:" << Incaltaminte::TVA << endl;
		out << "An cumparare:" << c.anCumparare << endl;

		return out;

	}

	friend istream& operator>>(istream& in, Incaltaminte& c)
	{
		cout << "Pret:";
		in >> c.pretI;
		cout << "Nr magazine:";
		in >> c.nrMagazine;
		return in;
	}


	~Incaltaminte() {
	}

	float getPret() {
		return this->pretI;
	}

	void setPret(float pret) {
		if (pret > 0) {
			this->pretI = pret;
		}
	}


	int getNrMagazine() {
		return this->nrMagazine;
	}
	int setNrMagazine(int noulNr) {
		if (noulNr > 0) {
			this->nrMagazine = noulNr;
		}
		return noulNr;
	}

	static int getTVA() {
		return TVA;
	}

	static float calculeazaValoareaTotala(Incaltaminte* vector, int nrMagazine) {
		float suma = 0;
		for (int i = 0; i < nrMagazine; i++) {
			suma += vector[i].pretI;
		}
	}

	friend class dulap;

};

int Incaltaminte::TVA = 19;

enum marimi { s, m, l, xl };

class Sapca: public Produs, public ProdusCuTVA {
private:
	string brand;
	int nrFabrici;
	marimi marime;
	const int anFabricare;
	float* cost;
	bool areImprimeu;
	static int nrTaxe;

public:
	void afisare(){}
	void afisare2() {
		
	}

	int getAn() {
		return this->anFabricare;
	}

	Sapca() :anFabricare(2021) {
		this->brand = "Kappa";
		this->cost = new float[5] {100, 150, 0, 20, 200};
		this->marime = marimi{ m };
		this->nrFabrici = 5;
		this->areImprimeu = false;
	}

	Sapca(int an, string brand):anFabricare(an){
		this->brand = brand;
		this->cost = new float[3] {200, 388, 989};
		this->marime = l;
		this->nrFabrici = 3;
		this->areImprimeu = false;
	}

	Sapca(string brand, int nr, marimi mar, float* cost, bool imp, int an) :anFabricare(an) {
		this->brand = brand;
		this->cost = cost;
		this->marime = mar;
		this->nrFabrici = nr;
		this->areImprimeu = imp;
	}



	Sapca(const Sapca& s) :anFabricare(s.anFabricare) {
		this->brand = s.brand;
		this->nrFabrici = s.nrFabrici;
		this->marime = s.marime;
		this->cost = new float[s.nrFabrici];
		if (this->marime > 0) {
			for (int i = 0; i < s.nrFabrici; i++) {
				this->cost[i] = s.cost[i];
			}
		}
		this->areImprimeu = s.areImprimeu;
	}

	~Sapca() {
		if (this->cost) {
			delete[]this->cost;
		}
	}

	string getBrand() {
		return this->brand;
	}
	string setBrand(string noulB) {
		if (noulB.length() > 1)
			this->brand = noulB;
	}

	int getNrFabrici() {
		return this->nrFabrici;
	}
	int setNrFabrici(int noulNr) {
		if (noulNr > 0) {
			this->nrFabrici = noulNr;
		}
		return noulNr;
	}

	marimi getMarime() {
		return this->marime;
	}

	marimi setCuloare(marimi marime) {
		this->marime = marime;
	}

	float* getCosturi() {
		return this->cost;
	}
	float getCost(int index) {
		if (index >= 0 && index < this->nrFabrici) {
			return this->cost[index];
		}
	}

	void setNrFabrici(int nr, float* cost) {
		if (nr > 0) {
			this->nrFabrici = nr;
			if (this->cost != NULL) {
				delete[] this->cost;
			}
			this->cost = new float[this->nrFabrici];
			for (int i = 0; i < nr; i++) {
				this->cost[i] = cost[i];
			}
		}
	}

	static int getNrTaxe() {
		return nrTaxe;
	}

	friend ostream& operator<<(ostream& out, Sapca s) {
		out << endl << "Sapca are brandul:" << s.brand << endl;
		out << "An fabricare:" << s.anFabricare << endl;
		out << "Marimea:" << s.marime << endl;
		out << "Numar de fabrici:" << s.nrFabrici << endl;
		if (s.cost != NULL) {
			for (int i = 0; i < s.nrFabrici; i++) {
				out << "Costul " << i + 1 << s.cost[i] << "; ";
				out << endl;
			}
		}
		out << endl;
		out << "Are imprimeu:" << (s.areImprimeu ? "da" : "nu") << endl;
		out << "Numar de taxe:" << Sapca::nrTaxe << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Sapca& s) {
		cout << "Introduceti brandul:";
		in >> s.brand;
		cout << "Numar de fabrici:";
		in >> s.nrFabrici;
		if (s.cost != 0) {
			delete[] s.cost;
		}
		if (s.nrFabrici > 0) {
			s.cost = new float[s.nrFabrici];
			for (int i = 0; i < s.nrFabrici; i++) {
				cout << "Costul " << i + 1 << ":";
				in >> s.cost[i];
				cout << endl;
			}
		}
		cout << "Are imprimeu?(1-da,0-nu):" << endl;
		in >> s.areImprimeu;
		return in;
	}

	Sapca operator=(const Sapca& s) {
		if (&s != this) {
			this->brand = s.brand;
			this->nrFabrici = s.nrFabrici;
			this->marime = s.marime;
			if (this->cost != NULL) {
				delete this->cost;
			}
			this->cost = new float[s.nrFabrici];
			for (int i = 0; i < s.nrFabrici; i++) {
				this->cost[i] = s.cost[i];
			}
			this->areImprimeu = s.areImprimeu;
		}
		return *this;
	}
	friend class dulap;
};
int Sapca::nrTaxe = 7;


class dulap {
private:
	string culoare;
	float inaltime;
	int nrTricouri;
	Tricou* t;
	Incaltaminte i;
	Sapca* s;

public:

	void afisare() {

	}
	void afisare2() {

	}
	float getAn() {
		return this->i.anCumparare;
	}

	dulap() {
		this->culoare = "maro";
		this->inaltime = 210, 5;
		this->nrTricouri = 2;
		this->t = new Tricou[this->nrTricouri];
		for (int i = 0; i < this->nrTricouri; i++) {
			this->t[i].nrMagazine = i;
		}
		this->i = Incaltaminte();
		this->s = new Sapca("nike", 4, m, new float[4] {3000, 2000, 1000, 1500}, true, 2020);
	}

	dulap(string culoare, float inaltime, int nrTricouri, Tricou* t, Incaltaminte i, Sapca* sa) {
		this->culoare = culoare;
		this->inaltime = inaltime;
		this->nrTricouri = nrTricouri;
		this->i = i;
		this->s = new Sapca(*sa);
		this->t = new Tricou[this->nrTricouri];
		for (int j = 0; j < this->nrTricouri; j++) {
			this->t[j] = t[j];
		}

	}

	dulap(const dulap& d) {
		this->culoare = d.culoare;
		this->inaltime = d.inaltime;
		this->nrTricouri = d.nrTricouri;
		this->i = d.i;
		this->t = new Tricou[this->nrTricouri];
		for (int j = 0; j < d.nrTricouri; j++) {
			this->t[j] = d.t[j];
		}
		this->s = new Sapca(*(d.s));
	}

	~dulap() {
		if (this->t) {
			delete[] this->t;
		}

		if (this->s) {
			delete this->s;
		}
	}
	string getCuloare() {
		return this->culoare;
	}
	void setCuloare(string cul) {
		if (cul.length() > 0) {
			this->culoare = cul;
		}
	}

	float getInaltime() {
		return this->inaltime;
	}
	void getInaltime(float inaltime) {
		if (inaltime > 0) {
			this->inaltime = inaltime;
		}
	}

	Incaltaminte getIncaltaminte() {
		return this->i;
	}
	void setIncaltaminte(int nr) {
		if (nr)
			this->i.nrMagazine = nr;

	}

	Sapca getSapca() {
		return *this->s;
	}
	void setSapca() {
		if (this->s->areImprimeu)
			this->s->areImprimeu = true;
	}

	Tricou getTricou() {
		for (int i = 0; i < this->nrTricouri; i++)
			return this->t[i];
	}
	void setTricou(string material, int nrTricouri) {
		if (nrTricouri > 0) {
			this->nrTricouri = nrTricouri;

			if (material.length() > 1) {
				for (int i = 0; i < this->nrTricouri; i++)
					this->t[i].material = material;
			}
		}
	}

	dulap operator=(const dulap& d) {
		if (&d != this) {
			this->culoare = d.culoare;
			this->inaltime = d.inaltime;
			this->nrTricouri = d.nrTricouri;
			this->i = d.i;
			if (this->t) delete[] this->t;
			this->t = new Tricou[this->nrTricouri];
			for (int j = 0; j < d.nrTricouri; j++) {
				this->t[j] = d.t[j];
			}
			if (this->s) delete this->s;
			this->s = new Sapca(*(d.s));
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, dulap d) {
		out << "Culoarea dulapului este: " << d.culoare << endl;
		out << "Inaltimea: " << d.inaltime << endl;
		out << "Incaltamintea din dulap este: " << endl << d.i << endl;
		out << "Sapca din dulap este:" << endl << *d.s << endl;
		out << "Avem " << d.nrTricouri << " tricouri in dulap:" << endl;
		for (int j = 0; j < d.nrTricouri; j++) {
			out << d.t[j] << endl;
		}
		out << endl;

		return out;
	}

	dulap operator--() {
		if (this->nrTricouri > 0) {
			this->nrTricouri--;
			Tricou* aux = new Tricou[this->nrTricouri];
			for (int j = 0; j < this->nrTricouri; j++) {
				aux[j] = this->t[j];
			}
			delete[] this->t;
			this->t = aux;
		}
		return *this;
	}


	dulap operator--(int) {
		dulap copie = *this;
		--(*this);
		return copie;
	}


	Tricou operator[](int index) {
		if (index >= 0 && index < this->nrTricouri) {
			return this->t[index];
		}
	}

	int operator()() {
		int s = 0;
		for (int i = 0; i < this->nrTricouri; i++)
		{
			s += t[i].nrMagazine;
		}
		return s;
	}

};


class SapcaDubla :public Sapca {
private:
	string culoare;
	bool esteLaPromotie;
	int codSapca;
public:

	SapcaDubla() :Sapca() {
		this->culoare = "Alb";
		this->esteLaPromotie = true;
		this->codSapca = 3829;
	}

	SapcaDubla(string culoare, bool promotie, int codSapca, string brand, int nr, marimi marime, float* cost, bool AreImprimeu, int an) :
		Sapca(brand, nr, marime, cost, AreImprimeu, an)
	{
		this->culoare = culoare;
		this->esteLaPromotie = promotie;
		this->codSapca = codSapca;

	}

	SapcaDubla(string culoare, bool promotie, int codSapca) :Sapca("Adidas", 2, m, new float[2] {100, 110}, true, 2020)
	{
		this->culoare = culoare;
		this->esteLaPromotie = promotie;
		this->codSapca = codSapca;
	}
	SapcaDubla(string culoare) :Sapca() {
		this->culoare = culoare;
		this->esteLaPromotie = false;
		this->codSapca = 1234;
	}

	SapcaDubla(const SapcaDubla& sd) : Sapca(sd) {
		this->culoare = sd.culoare;
		this->esteLaPromotie = sd.esteLaPromotie;
		this->codSapca = sd.codSapca;
	}

	~SapcaDubla() {
		//nu avem ce dezaloca
	}

	SapcaDubla operator=(const SapcaDubla& sd) {
		if (&sd != this) {
			(Sapca)*this = (Sapca)sd;
			this->culoare = sd.culoare;
			this->esteLaPromotie = sd.esteLaPromotie;
			this->codSapca = sd.codSapca;
		}
		return *this;
	}
	string getCuloare() {
		return this->culoare;
	}

	int getCodSapca() {
		return this->codSapca;
	}

	bool getEsteLaPromotie() {
		return this->esteLaPromotie;
	}

	void setCuloare(string culoareN) {
		if (culoareN.length() > 1) {
			this->culoare = culoareN;
		}
	}

	void setCodSapca(int cod) {
		if (cod != 0) {
			this->codSapca = cod;
		}
	}

	void setEsteLaPromotie(bool promotie) {
		this->esteLaPromotie = promotie;
	}

	friend ostream& operator<<(ostream& out, const SapcaDubla& sd) {
		out << (Sapca)sd;
		out << "Culoare:" << sd.culoare << endl;
		out << "Cod sapca:" << sd.codSapca << endl;
		out << "Este la promotie:" << (sd.esteLaPromotie ? "DA" : "NU") << endl;
		return out;
	}


};


class Tocuri :public Incaltaminte {
private:
	int cmToc;
	string culoare;
	char* model;
public:
	Tocuri() :Incaltaminte() {
		this->cmToc = 8;
		this->culoare = "Negru";
		this->model = new char[strlen("stiletto") + 1];
		strcpy_s(this->model, strlen("stiletto") + 1, "stiletto");
	}


	Tocuri(int cmToc, string culoare, char* model, char* producator) : Incaltaminte(100,10,2020) {
		this->cmToc = cmToc;
		this->culoare = culoare;
		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}

	Tocuri(int cmToc) : Incaltaminte() {
		this->culoare = "rosu";
		this->cmToc = cmToc;
		this->model = new char[strlen("sandale") + 1];
		strcpy_s(this->model, strlen("sandale") + 1, "sandale");
	}


	Tocuri(const Tocuri& t) : Incaltaminte(t) {
		this->culoare = t.culoare;
		this->cmToc = t.cmToc;
		if (t.model != NULL) {
			this->model = new char[strlen(t.model) + 1];
			strcpy_s(this->model, strlen(t.model) + 1, t.model);
		}
		else {
			this->model = NULL;
		}
	}

	~Tocuri() {
		if (this->model) {
			delete[]this->model;
		}
	}

	Tocuri operator=(const Tocuri& t) {
		if (&t != this) {
			(Incaltaminte)*this = (Incaltaminte)t;
			this->culoare = t.culoare;
			this->cmToc = t.cmToc;
			if (this->model) {
				delete this->model;
			}
			this->model = new char[strlen(t.model) + 1];
			strcpy_s(this->model, strlen(t.model) + 1, t.model);
		}


		return *this;
	}

	string getCuloare() {
		return this->culoare;
	}

	int getCmToc() {
		return this->cmToc;
	}

	bool getModel() {
		return this->model;
	}

	void setCuloare(string culoareN) {
		if (culoareN.length() > 1) {
			this->culoare = culoareN;
		}
	}

	void setCmToc(int cm) {
		if (cm != 0) {
			this->cmToc = cm;
		}
	}

	void setModel(char* model) {
		if (this->model) {
			this->model = new char[strlen(model) + 1];
			strcpy_s(this->model, strlen(model) + 1, model);
		}
	}

	friend ostream& operator<<(ostream& out, const Tocuri& t) {
		out << (Incaltaminte)t;
		out << "Culoare:" << t.culoare << endl;
		out << "Centimetri toc: " << t.cmToc << endl;
		out << "Model: " << t.model << endl;
		return out;
	}

};


int main() {
	
	//Produs p;
	//ProdusCuTVA p1;-  nu putem instantia clasele abstracte

	Tricou t;
	Sapca s;
	
	Produs* pointer;
	pointer = NULL;
	pointer = new Tricou();
	
	int nrProduse = 10;
	Produs** vector = new Produs * [nrProduse];
	vector[0] = new Tricou();
	vector[1] = new Tricou("Bumbac", 2, "H&M", new float[2] {200, 200},2021);
	vector[2] = new Tricou(1, new float[1] {200}, 2018);
	vector[3] = new Tricou(2, new float[2] {120, 156}, 2000);
	vector[4] = new SapcaDubla();
	vector[5] = new Sapca(2012, "Kappa");
	float* aux = new float[4] {100, 200, 140, 123};
	vector[6] = new Sapca(2023, "Puma");
	vector[7] = new Tocuri();
	vector[8] = new Incaltaminte(200, 12, 2010);
	vector[9] = new Incaltaminte(90, 12, 2024);

	for (int i = 0; i < nrProduse; i++) {
		cout << (i + 1) << "." << vector[i]->getAn() << endl;
	}

	dulap d;
	cout<<endl<<d.getIncaltaminte();

	return 3455;
}

