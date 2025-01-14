//Se consideră o aplicație care permite gestiunea meniurilor și a preparatelor culinare dintr - un restaurant.Se vor urmări
//aspectele comune privind denumire, culoare, greutate, număr calorii etc.Definiți o clasă care modelează un aspect propriu acestei activități.Datele membre sunt private și sunt 
//puse la dispoziție metode de acces.Clasa conține cel puțin patru câmpuri, dintre care unul este alocat dinamic, constructori,
//metodele specifice claselor cu membri alocați dinamic și operatorul de afișare. Folosiți un membru static sau const.
#include<string>
#include<iostream>
#include<vector>

using namespace std;

//(2) Creați o enumerare prin care să se
//specifice dacă felul de mâncare este
//vegan, vegetarian, raw - vegan, etc.
//Modificați clasa anterioară, astfel încât să
//conțină un atribut de tipul enumerării
//create.

enum tip {
	vegan, vegetarian, rawVegan

};

class Preparat {
private:
	const int idPreparat;
	string denumire;
	float greutate;
	float* nrCalorii;
	int nrIngrediente;
	tip tip;
public:

	Preparat(): idPreparat(0) {
		this->denumire = "tort";
		this->greutate = 10;
		this->nrIngrediente= NULL;
		this->nrCalorii = 0;
		this->tip = vegan;
	}
	Preparat(int id, string denumire, float greutate, int nrIngrediente, float* nrCalorii) : idPreparat(id++) {
		this->denumire = denumire;
		this->greutate = greutate;
		this->nrIngrediente = nrIngrediente;
		if (this->nrIngrediente) {
			this->nrCalorii = new float[nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++) {
				this->nrCalorii[i] = nrCalorii[i];
			}
		}
		this->tip = vegetarian;
	}


	~Preparat() {
		if (this->nrCalorii) {
			delete this->nrCalorii;
		}
	}

	Preparat(const  Preparat& p):idPreparat(p.idPreparat){
		this->denumire = p.denumire;
		this->greutate = p.greutate;
		this->nrCalorii = p.nrCalorii;
		this->nrIngrediente = p.nrIngrediente;
		if (this->nrIngrediente) {
			this->nrCalorii = new float[p.nrIngrediente];
			if (p.nrCalorii != NULL) {
				for (int i = 0; i < this->nrIngrediente; i++) {
					this->nrCalorii[i] = p.nrCalorii[i];
				}
			}
		}
		this->tip = p.tip;

	}
	
	Preparat operator=(const Preparat& p) {
		if (this != &p) {
			this->denumire = p.denumire;
			this->greutate = p.greutate;
			this->tip = p.tip;
			this->nrIngrediente = p.nrIngrediente;
			if (this->nrCalorii) {
				delete[] this->nrCalorii;
			}
			if (this->nrIngrediente) {
				this->nrCalorii = new float[p.nrIngrediente];
				for (int i = 0; i < this->nrIngrediente; i++) {
					this->nrCalorii[i] = p.nrCalorii[i];
				}
			}
		}
		return *this;
	}

	const int getIdPreparat() {
		return this->idPreparat;
	}

	string getDenumire() {
		return this->denumire;
	}
	void setDenumire(string den) {
		if (den.length() >= 2) {
			this->denumire = den;
		}
	}

	float getGreutate() {
		return this->greutate;
	}
	void setGreutate(float greutateN) {
		if (greutateN > 0) {
			this->greutate = greutateN;
		}
	}

	float* getNrCalorii() {
		return this->nrCalorii;
	}
	float getCalorie(int index) {
		if (index > 0 && index < this->nrIngrediente) {
			return this->nrCalorii[index];
		}
	}

	void setCalorii(float* nrCalorii, int nrIngrediente) {
		if (nrIngrediente > 0) {
			this->nrIngrediente = nrIngrediente;
			if (this->nrCalorii) {
				delete[]this->nrCalorii;
			}
			else {
				this->nrCalorii = new float[nrIngrediente];
				for (int i = 0; i < this->nrIngrediente; i++) {
					this->nrCalorii[i] = nrCalorii[i];
				}}	}}


	friend ostream& operator<<(ostream& out, const Preparat p) {
		out << "Id preparat: " << p.idPreparat << endl;
		out << "Denumire:" << p.denumire << endl;
		out << "Greutate: " << p.greutate << endl;
		out << "Nr ingrediente: " << p.nrIngrediente << endl;
		out<<"Caloriile pe fiecare ingrediente: "<<endl;
		for (int i = 0; i < p.nrIngrediente; i++) {
			out << "Ingredientul " << i + 1 << "are: " << p.nrCalorii[i] << "calorii; " << endl;
		}
		out << "Tip:" << p.tip << endl;
		return out;
	}

	//(1) supraîncărcați operator++ pentru
//incrementarea unui atribut al obiectelor.
//Clasa permite atât utilizarea de
//preincrementare cât și postincrementare.
//


	Preparat operator++() {
		this->greutate++;
		return *this;
	}

	Preparat operator++(int) {
		Preparat copie = *this;
		this->greutate++;
		return *this;
	}
	float getTotalCalorii() const {
		float total = 0;
		if (nrCalorii != nullptr) {
			for (int i = 0; i < nrIngrediente; i++) {
				total += nrCalorii[i];
			}
		}
		return total;
	}


};


//(3) Să se exemplifice conceptul de
//relație “has a” între clase pentru a
//gestiona elemente de tipul clasei definită
//anterior(pot fi folosiți și pointeri).Noua
//clasă va asociată unui meniu care conține
//mai multe feluri de mâncare.Această
//clasă nouă este un container care va
//gestiona colecția de obiecte printr - un
//vector alocat dinamic.
//
//(4) Oferiți posibilitatea ca prin
//operator+= să fie adăugat un nou obiect
//în colecția de obiecte gestionate de clasa
//(container) adăugată.

//(1p) Clasa container trebuie să conțină o
//metodă care să ofere posibilitatea de
//calculare a unei sume pentru toate
//obiectele gestionate.


class Meniu {
private:
	vector<Preparat> preparate;

public:
	Meniu() {}

	Meniu& operator+=(const Preparat& p) {
		this->preparate.push_back(p);
		return *this;
	}

	float calculTotalCalorii() const {
		float total = 0;
		for (const auto& p : preparate) {
			total += p.getTotalCalorii();
		}
		return total;
	}

	
	friend ostream& operator<<(ostream& out, const Meniu& m) {
		out << "Meniu:" << endl;
		for (size_t i = 0; i < m.preparate.size(); i++) {
			out << "Preparat " << i + 1 << ":" << endl;
			out << m.preparate[i] << endl;
		}
		return out;
	}
};



int main() {
	Preparat p(3, "ecler", 50, 3, new float[3] {400, 300, 200});
	p++;
	cout << p << endl;
	++p;
	cout << p;

	float calorii1[] = { 200, 150, 100 };
	Preparat p1(1, "Salată", 300, 3, calorii1);

	float calorii2[] = { 400, 300 };
	Preparat p2(2, "Pizza", 500, 2, calorii2);

	Meniu meniu;
	meniu += p1;
	meniu += p2;

	cout << meniu;

	cout << "Calorii totale n meniu: " << meniu.calculTotalCalorii() << " kcal" << endl;

	return 0;
}






