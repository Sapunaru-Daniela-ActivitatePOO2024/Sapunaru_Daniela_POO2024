#include<iostream>
using namespace std;

class Sejur {
private:

	const int id;
	string destinatie;
	float pretBaza;
	int nrExcursiiOptionale;
	float* pretExcursie;
	static int nrZile;
	bool includeTransport;


public:
	Sejur() :id(1) {
		this->destinatie = "Brasov";
		this->pretBaza = 2000;
		this->nrExcursiiOptionale = 2;
		this->pretExcursie = new float[2] {100, 200};
		this->includeTransport = true;
	}

	Sejur(int i, string destinatie, float pretB, int nrE, float* pretE, bool incl) :id(i) {
		this->destinatie = destinatie;
		this->pretBaza = pretB;
		this->nrExcursiiOptionale = nrE;
		this->pretExcursie = pretE;
		this->includeTransport = incl;
	}

	~Sejur() {
		if (this->pretExcursie != NULL) {
			delete[]this->pretExcursie;
		}
	}

	string getDestinatie() {
		return this->destinatie;
	}
	void setDestinatie(string des) {
		if (des.length() > 2) {
			this->destinatie = des;
		}
	}
	float getPretBaza() {
		return this->pretBaza;
	}
	void setPretBaza(float pret) {
		if (pret > 0) {
			this->pretBaza = pret;
		}
	}

	int getNrExcursiiOptionale() {
		return this->nrExcursiiOptionale;
	}

	float* getPreturiExcursie() {
		return this->pretExcursie;
	}

	float getPretExcursie(int index) {
		if (index >= 0 && index < this->nrExcursiiOptionale) {
			return this->pretExcursie[index];
		}
	}

	void setNrExcursiiOptionale(int nr, float* pret) {
		if (nr > 0) {
			this->nrExcursiiOptionale = nr;
			if (this->pretExcursie != NULL) {
				delete[] this->pretExcursie;
			}
			this->pretExcursie = new float[this->nrExcursiiOptionale];
			for (int i = 0; i < this->nrExcursiiOptionale; i++) {
				this->pretExcursie[i] = pret[i];
			}
		}
	}

	bool getIncludeTransport() {
		return this->includeTransport;
	}
	void setIncludeTransport(bool incl) {
		this->includeTransport = incl;
	}

	int getNrMaximExcursii(float bugetMaximSejur) {
		float pretExcursii;
		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			pretExcursii = this->pretExcursie[i] * nrExcursiiOptionale;

			if (this->pretBaza + pretExcursii <= bugetMaximSejur) {
				return i;
			}

			else {
				cout << "Nu exista excursii ce pot fi achizitionate in aceasta suma.";
			}
		}
		/*int nrExcursiiPosibile;

		float pretSejur = this->pretBaza + pretExcursii;
		nrExcursiiPosibile= bugetMaximSejur*/
	}

	Sejur(const Sejur& s) :id(s.id) {
		this->destinatie = s.destinatie;
		this->pretBaza = s.pretBaza;
		this->nrExcursiiOptionale = s.nrExcursiiOptionale;
		this->pretExcursie = new float[this->nrExcursiiOptionale];
		if (this->pretExcursie != NULL) {
			for (int i = 0; i < this->nrExcursiiOptionale; i++) {
				this->pretExcursie[i] = s.pretExcursie[i];
			}
		}
		else {
			this->pretExcursie = NULL;
		}
		this->includeTransport = s.includeTransport;

	}

	Sejur operator=(const Sejur& s) {
		if (&s != this) {
			this->destinatie = s.destinatie;
		}
		return *this;
	}

	//9?
	Sejur operator--(int) {
		Sejur copie = *this;
		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			if (this->pretExcursie[i + 1] < this->pretExcursie[i])
				this->nrExcursiiOptionale--;
		}
		return *this;
	}

	bool operator>=(float pret) const {
		return this->pretBaza >= pret;
	}

	bool operator<(float pret) {
		return this->pretBaza < pret;

	}

	explicit operator float() {
		float s = 0;
		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			s = s + this->pretExcursie[i];
		}
		return s + this->pretBaza;
	}


	friend ostream& operator<<(ostream& out, Sejur s) {
		out << "Id sejur:" << s.id;
		out << "Destinatie:" << s.destinatie << endl;
		out << "Pret de baza:" << s.pretBaza << endl;
		out << "Nr excursii optionale:" << s.nrExcursiiOptionale << endl;
		for (int i = 0; i < s.nrExcursiiOptionale; i++) {
			cout << "Pret excursii:" << s.pretExcursie[i] << ",";
		}
		out << endl;
		out << "Asigura transport(1-da;0-nu):" << s.includeTransport << endl;
		out << "Numar de zile:" << Sejur::nrZile << endl << endl;

		return out;
	}

	friend istream& operator>>(istream& in, Sejur& s) {
		cout << "Introduceti destinatia:";
		in >> s.destinatie;
		cout << "Pretul de baza:";
		in >> s.pretBaza;
		cout << "Nr de excursii optionale:" << endl;
		in >> s.nrExcursiiOptionale;
		for (int i = 0; i < s.nrExcursiiOptionale; i++) {
			cout << "Pretul excursiei " << i + 1 << " este:";
			in >> s.pretExcursie[i];
		}
		cout << "Transportul este asigurat?(1-da,0-nu) ";
		in >> s.includeTransport;

		return in;
	}


	void afisare() {

		cout << "ID ul sejurului:" << this->id << endl;
		cout << "Destinatie:" << this->destinatie << endl;
		cout << "Pret de baza:" << this->pretBaza << endl;
		cout << "Nr excursii optionale:" << this->nrExcursiiOptionale << endl;
		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			cout << "Pret excursii:" << this->pretExcursie[i] << ",";
		}
		cout << endl;
		cout << "Asigura transport(1-da;0-nu):" << this->includeTransport << endl;
		cout << "Numar de zile:" << Sejur::nrZile << endl;
	}

};

int Sejur::nrZile = 7;

int main() {

	Sejur s1;
	Sejur s2(12, "Sinaia", 1000, 2, new float[2] { 100, 300 }, true);

	cout << s1.getDestinatie() << endl;;
	s1.setDestinatie("Sibiu");

	int MaxExcursii = s2.getNrMaximExcursii(1400);
	cout << "nr maxim de excursii:" << MaxExcursii << endl;

	Sejur s3;
	s3 = s2;


	float costTotal = (float)s2;
	cout << "Costul total:" << costTotal;

	cout << s3;
	Sejur s4;
	cin >> s4;

	cout << s4;
	s4--;
	cout << s4;

	float pretReferinta = 1000;

	if (s3 >= pretReferinta) { cout << "Sejurul nu este mai  costisitor de 1000 de lei."; }
	else { cout << "sejurul e mai costisitor de 1000 de lei."; }

	cout << endl;
	if (s2 < 1500) { cout << "Sejurul costa mai putin de 1500 de lei."; }
	else { cout << "Sejurul e mai scump decat valoarea data."; }



	return 0;
}