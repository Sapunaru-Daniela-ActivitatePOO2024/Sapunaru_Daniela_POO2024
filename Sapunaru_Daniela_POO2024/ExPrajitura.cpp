#include<iostream>

using namespace std;

class Prajitura {
private:
	string denumire;
	int nrCalorii;
	int nrIngrediente;
	float* gramajIngrediente;
	bool esteVegana;
	static int nrPrajituri;
	const int anDeschidere;

public:
	//constr fara parametrii
	Prajitura() :anDeschidere(2010) {
		this->denumire = "Delice";
		this->nrCalorii = 200;
		this->nrIngrediente = 7;
		this->gramajIngrediente = NULL;
		this->esteVegana = false;
	}
	//constr cu toti parametrii;
	Prajitura(string denumire, int nrCalorii, int nrIngrediente, bool esteVegana, int an) :anDeschidere(an) {
		this->denumire = denumire;
		this->nrCalorii = nrCalorii;
		this->nrIngrediente = nrIngrediente;
		this->gramajIngrediente = new float[nrIngrediente];
		for (int i = 0; i < nrIngrediente; i++) {
			this->gramajIngrediente[i] = 100 + 10 * i;
		}
		this->esteVegana = esteVegana;
	}


	Prajitura(const Prajitura& p) :anDeschidere(p.anDeschidere) {

		this->denumire = p.denumire;
		this->nrCalorii = p.nrCalorii;
		this->nrIngrediente = p.nrIngrediente;

		this->gramajIngrediente = new float[p.nrIngrediente];
		for (int i = 0; i < p.nrIngrediente; i++) {
			this->gramajIngrediente[i] = p.gramajIngrediente[i];

		}

		this->esteVegana = p.esteVegana;
	}

	~Prajitura() {
		if (this->gramajIngrediente != NULL)
			delete[]this->gramajIngrediente;
	}

	static int getGramajTotal(int nrIngrediente, Prajitura* vector) {
		int s = 0;
		for (int i = 0; i < nrIngrediente; i++) {
			s = s + vector[i].nrIngrediente;
		}
		return s;
	}

	Prajitura operator=(const Prajitura& p) {
		if (&p != this) {
			this->denumire = p.denumire;
			this->nrIngrediente = p.nrIngrediente;
			this->nrCalorii = p.nrCalorii;
			this->esteVegana = p.esteVegana;
			if (this->gramajIngrediente) {
				delete[]this->gramajIngrediente;
			}
			this->gramajIngrediente = new float[p.nrCalorii];
			for (int i = 0; i < p.nrCalorii; i++) {
				this->gramajIngrediente[i] = p.gramajIngrediente[i];
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, Prajitura p) {
		out << "Denumire:" << p.denumire << endl;
		out << "Nr calorii:" << p.nrCalorii << endl;
		out << "Este vegana?(0-NU, 1-DA):" << p.esteVegana << endl;
		out << "An deschidere:" << p.anDeschidere << endl;
		out << "Numar de prajituri:" << p.nrPrajituri << endl;

		out << "Nr ingrediente:" << p.nrIngrediente << ":";
		if (p.gramajIngrediente != NULL) {

			for (int i = 0; i < p.nrIngrediente; i++) {
				out << p.gramajIngrediente[i] << ",";
			}

		}
		out << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Prajitura& p) {
		cout << "Introduceto denumirea:";
		in >> p.denumire;
		cout << "nrCalorii";
		in >> p.nrCalorii;
		cout << "NrIngrediente:";
		in >> p.nrIngrediente;
		cout << "este Vegana?";
		in >> p.esteVegana;
		if (p.gramajIngrediente != NULL) {
			delete[]p.gramajIngrediente;
			if (p.nrIngrediente > 0) {
				p.gramajIngrediente = new float[p.nrIngrediente];

				for (int i = 0; i < p.nrIngrediente; i++) {
					in >> p.gramajIngrediente[i];
				}
			}
		}
		return in;
	}

	Prajitura operator*=(int index) {
		if (index < 0) {
			//throw ExceptieInput();
			this->gramajIngrediente = NULL;////EXCEPTIE INPUT
		}
		else
			for (int i = 0; i < this->nrIngrediente; i++) {
				 this->gramajIngrediente[i] *= index;
			}
		
		return *this;
	}

	friend Prajitura operator+(float gramaj, Prajitura p) {
		Prajitura temp = p;
		if (temp.gramajIngrediente != NULL) {
			delete[]temp.gramajIngrediente;
		}
		temp.gramajIngrediente = new float[temp.nrIngrediente + 1];
		for (int i = 0; i < p.nrIngrediente; i++) {
			temp.gramajIngrediente[i] = p.gramajIngrediente[i];
		}
		temp.gramajIngrediente[temp.nrIngrediente] = gramaj;
		temp.nrIngrediente++;
		return temp;
	}

	bool operator!=(Prajitura p) {
		if (denumire != p.denumire)return true;
		if (nrCalorii != p.nrCalorii)return true;
		if (nrIngrediente != p.nrIngrediente)return true;
		if (esteVegana != p.esteVegana)return true;
		if (anDeschidere != p.anDeschidere)return true;
		if (gramajIngrediente != p.gramajIngrediente)return true;
		for (int i = 0; i < nrIngrediente; i++) {
			if (gramajIngrediente[i] != p.gramajIngrediente[i])return true;
		}
		return false;
	}

	string getDenumire() {
		return denumire;
	}
	void setDenumire(string denumire) {
		if (denumire.length() > 2) {
			this->denumire = denumire;
		}
	}

	int getNrCalorii() {
		return nrCalorii;
	}
	void setNrCalorii(int calorii) {
		if (calorii > 0) {
			this->nrCalorii = calorii;
		}
	}

	int getNrIngrediente() {
		return nrIngrediente;
	}
	void setNrIngrediente(int ingr) {
		if (ingr > 0) {
			this->nrIngrediente = ingr;
		}
	}
	void setNrIngrediente(int nrIngrediente, float* gramaj) {
		if (nrIngrediente > 0) {
			this->nrIngrediente = nrIngrediente;
			if (this->gramajIngrediente != NULL) {
				delete[]this->gramajIngrediente;
			}
			this->gramajIngrediente = new float[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++) {
				this->gramajIngrediente[i] = gramaj[i];
			}
		}
	}
	float* getGramajIngrediente() {
		return this->gramajIngrediente;
	}
	float getGramajIngrediente(int index) {
		if (index >= 0 && index < this->nrIngrediente) {
			return this->gramajIngrediente[index];
		}
	}



	bool getEsteVegana() {
		return this->esteVegana;
	}
	void setEsteVegana(bool vegan) {
		this->esteVegana = vegan;
	}

	void afisare() {
		cout << "Denumire:" << this->denumire << endl;
		cout << "Nr calorii:" << this->nrCalorii << endl;
		cout << "nr Ingrediente:" << this->nrIngrediente << endl;
		cout << "este vegana?" << (this->esteVegana ? "DA" : "NU") << endl;
		cout << "nr prajituri:" << Prajitura::nrPrajituri << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		for (int i = 0; i < this->nrIngrediente; i++) {
			cout << "ingredientul numarul" << i << "are gramajul" << this->gramajIngrediente[i] << endl;
		}
	}

};

int Prajitura::nrPrajituri = 5;

int main() {
	Prajitura p1("Delice", 20, 3, true, 2010);
	Prajitura p2("Delice", 20, 3, true, 2010);
	p2.setNrIngrediente(2, new float[2] { 2, 3 });
	p1.setNrIngrediente(2, new float[2] { 2, 3 });
	p2.afisare();
	cout << "Este vegana?:" << p1.getEsteVegana() << endl;
	cout << "Numarul de calorii:" << p1.getNrCalorii() << endl;

	cout << "Gramaj initial:" << p2.getGramajIngrediente() << endl << endl;

	p2.setNrIngrediente(2, new float[2] { 2, 3 });
	cout << "Gramaj dupa modificari:" << p2.getGramajIngrediente() << endl;

	//p2.getGramajIngrediente();
	//cout << p2.getGramajIngrediente();
	//Comparatie a doua obiecte de tip prajitura/ Operatorul de comparatie:
	if (p1 != p2) cout << "Prajitura 1 si 2 sunt diferite";
	else {
		cout << "sunt identice";
	}

	//Multiplicarea ingredientelor prajiturii prin operatorul *=(int) si verificare
	cout << p1 << endl << endl;
	p1 *= (p1.getNrIngrediente());
	cout << p1;

	//operatorii << si >>
	Prajitura p3;
	//cin >> p3;
	cout << p3 << endl;

	//Să se supraîncarce operatorul +(float + Prajitura) 
	// ce adauga un nou ingredient inlista   de   ingrediente. 
	//   Daca   valoarea   primita   nu   este   conforma,  
	//  se   arunca   exceptieExceptieInput

   // cout << p3.getNrIngrediente() + (100, p3);


}