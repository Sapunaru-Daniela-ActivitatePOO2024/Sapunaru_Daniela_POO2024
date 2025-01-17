#include<iostream>
#include<vector>
using namespace std;


class Produs{
private:
	string tip_produs;
	string tip_carne;
	const string data_expirare;
	float*  pret;
	int nrMagazine;
public:
	Produs() :data_expirare("01/03/2025") {
		this->tip_produs = "Carne proaspata";
		this->tip_carne= "Pui";
		this->nrMagazine = 3;
		this->pret = new float[this->nrMagazine];
		for (int i = 0; i < this->nrMagazine; i++) {
			this->pret[i] = 20 + i * 2;
		}
	}

	Produs(string tip_p, string tip_c, float* pret, int nrMagazine, string data) :data_expirare(data) {
		this->tip_produs = tip_p;
		this->tip_carne = tip_c;
		this->pret = pret;
		this->nrMagazine = nrMagazine;
	}

	Produs(const Produs& p):data_expirare(p.data_expirare) {
		this->tip_produs = p.tip_produs;
		this->tip_carne = p.tip_carne;
		this->nrMagazine = p.nrMagazine;
		this->pret = new float[p.nrMagazine];
		for(int i=0;i<p.nrMagazine;i++)
		       this->pret[i] = p.pret[i];
	}

	Produs operator=(const Produs& p) {
		if (&p != this) {
			this->tip_produs = p.tip_produs;
			this->tip_carne = p.tip_carne;
			this->nrMagazine = p.nrMagazine;
			if (this->pret) {
				delete[]this->pret;
			}
			this->pret = new float[p.nrMagazine];
			for (int i = 0; i < p.nrMagazine; i++)
				this->pret[i] = p.pret[i];

		}
		return *this;
	}

	~Produs() {
		if (this->pret) {
			delete[]this->pret;
		}
	}

	string getTipProdus() {
		return this->tip_produs;
	}

	void setTipProdus(string tip_produs) {
		if(tip_produs.length()>2)
			this->tip_produs = tip_produs;
	}

	string getTipCarne() {
		return this->tip_carne;
	}

	void setTipCarne(string tip_carne) {
		if (tip_carne.length() > 2) {
			this->tip_carne = tip_carne;
		}
	}


	const string getDataExpirare() {
		return this->data_expirare;
	}



	float* getPreturi() {
		return this->pret;
	}

	float getPret(int index) {
		if (index > 0 && index < this->nrMagazine) {
			return this->pret[index];
		}
	}

	int getNrMagazine() {
		return this->nrMagazine;
	}

	void setNrMagazine(float* pret, int nrMagazine) {
		if (nrMagazine > 0) {
			this->nrMagazine = nrMagazine;
			if (this->pret) {
				delete[] this->pret;
			}
			this->pret = new float[nrMagazine];
			for (int i = 0; i < this->nrMagazine; i++) {
				this->pret[i] = pret[i];
			}
		}
	}

	//Definiti operatorul *= care permite acordarea unei reduceri produselor care expira ziua urmatoare

	Produs operator*=(string data_curenta) {
		if (data_expirare > data_curenta) {
			cout << "Produsul  " << this->tip_produs << " nu beneficiaza de reducere" << endl;
		}
		else {
			for (int i = 0; i < this->nrMagazine; i++)
				this->pret[i] *= 0.4;
		}

		return *this;
	}
	//definiti operatorul == care compara doua produse si returneaza true daca valorile atributelor sunt egale
	bool operator==(Produs p) {
		if (
			this->data_expirare == p.data_expirare &&
			this->tip_produs == p.tip_produs &&
			this->tip_carne == p.tip_carne &&
			this->nrMagazine == p.nrMagazine) {
			for (int i = 0; i < this->nrMagazine; i++) {
				if (this->pret[i] != p.pret[i]) {
					return false;
				}
			}
			return true;
		}
		return false;
	}




	friend ostream& operator<<(ostream& out, const Produs& p) {
		out << "Tip produs: " << p.tip_produs << endl;
		out << "Tip carne: " << p.tip_carne << endl;
		out << "Data expirare: " << p.data_expirare << endl;
		out << "Nr magazinelor in care se vinde produsul:" << p.nrMagazine << endl;
		out << "Preturi: " << endl;
		for (int i = 0; i < p.nrMagazine; i++) {
			out << "In magazinul  " << i << ":" << p.pret[i] << " ";
		}
		out << endl;
		return out;
	}

	virtual void afisare() {
		cout << "Tip produs: " << tip_produs << endl;
		cout << "Tip carne: " << tip_carne << endl;
		cout << "Data expirare: " << data_expirare << endl;
		cout << "Nr magazinelor in care se vinde produsul:" << nrMagazine << endl;
		cout << "Preturi: " << endl;
		for (int i = 0; i < nrMagazine; i++) {
			cout << "In magazinul  " << i << ":" << pret[i] << " ";
		}
		cout << endl;
	}

	void afisare1() {
		cout << "Tip produs: " << tip_produs << endl;
		cout << "Tip carne: " << tip_carne << endl;
		cout << "Data expirare: " << data_expirare << endl;
		cout << "Nr magazinelor in care se vinde produsul:" << nrMagazine << endl;
		cout << "Preturi: " << endl;
		for (int i = 0; i < nrMagazine; i++) {
			cout << "In magazinul  " << i << ":" << pret[i] << " ";
		}
		cout << endl;
	}
};

//Definiti o clasa pentru a gestiona produsele existente in stoc. Operatprul += permite adaugarea unui produs nou(daca exista 
// se actualizeaza stocu;, iar operatorul functie()  va elimina toate produsele care nu sunt in stoc


class Stoc {
private:
	Produs* produse;
	int nrProduse;
public:

	Stoc() {
		this->nrProduse = 2;
		this->produse = new Produs[this->nrProduse];
		this->produse[0] = Produs();
		this->produse[1]= Produs("Carne congelata", "Vita", new float[3] {20, 22, 21}, 3, "22/04/2025");
	}
	~Stoc() {
		if (this->produse) {
			delete[]this->produse;
		}
	}

	Stoc& operator +=(const Produs& p) {
		Produs* aux = new Produs[this->nrProduse + 1];
		for(int i = 0; i < this->nrProduse; i++){
			aux[i] = this->produse[i];
		}
		if (this->produse) {
			delete[]this->produse;
		}
		aux[this->nrProduse]= p;
		this->nrProduse++;
		this->produse = aux;
		return *this;
	}

	friend ostream& operator<<(ostream& out,const Stoc& s) {
		out << "Nr produse:"<<s.nrProduse << endl;
		for (int i = 0; i < s.nrProduse; i++) {
			out << "Produsul  " << i << ":" << endl;
			out << s.produse[i] << endl;
		}

		return out;
	}


	void operator()() {
		int nrProduseRamase = 0;

		for (int i = 0; i < this->nrProduse; i++) {
			if (this->produse[i].getNrMagazine() > 0) { 
				nrProduseRamase++;
			}
		}

		Produs* produseNoi = new Produs[nrProduseRamase];
		int indexNou = 0;

		for (int i = 0; i < this->nrProduse; i++) {
			if (this->produse[i].getNrMagazine() > 0) {
				produseNoi[indexNou++] = this->produse[i];
			}
		}
		delete[] this->produse;

		this->produse = produseNoi;
		this->nrProduse = nrProduseRamase;
	}


};

class ProdusPerisabil :public Produs {
	string nume;
public:
	void afisare() {
		cout << nume << " " << "Acesta este un produs perisabil" << endl;
	}
};




int main() {
	Produs p1;
	Produs p2("Carne congelata", "Vita", new float[3] {20, 22, 21}, 3, "22/04/2025");
	cout << p1 << endl << endl;
	p1 *=("01/06/2026");
	cout << "Preturi dupa reducere:" << p1 << endl;

	if (p1 == p2) {
		cout << "Produsele coincid" << endl;
	}
	else{ cout<<"Produsele sunt diferite"<<endl;
	}

	Stoc s;
	s += p2;
	cout << s<<endl;

	s();
	cout << "Stoc dupa eliminare:" << s << endl;



	//exemplificati conceptele de early bindind si late binding

	cout << p2.getNrMagazine();
	//sau
	Produs* p5 = new ProdusPerisabil;
	p5->afisare();


	//lateBinding
	Produs* produs = new ProdusPerisabil();
	produs->afisare();




	Produs p6("Peste proaspat", "Crap", new float[2] {10, 20}, 2, "01/08/2025");

	//propuneti un container care sa permita gasirea tuturor produselor pe baza unei specie de peste

	vector<Produs> produse;

	
	produse.push_back(Produs("File de peste", "Somon", new float[1] {30},1,"10/22/2025"));
	produse.push_back(Produs("Peste proaspat", "Crap", new float[2] {10, 20}, 2, "01/07/2025"));
	produse.push_back(Produs("Peste congelat", "Somon", new float[3] {20,25, 40}, 3, "01/05/2025"));
	produse.push_back(Produs("File de peste", "Pastrav", new float[2] {10, 20}, 2, "01/02/2025"));

	vector<Produs>::iterator it;
	it = produse.begin();

	cout << "Toate produsele:\n";
	while(it!=produse.end()) {
		cout << *it << endl;
		it++;
	}

	string specieCautata = "Somon";
	cout << "\nProduse cu specia '" << specieCautata << "':\n";

	while (it != produse.end()) {
		if (it->getTipCarne() == specieCautata) {
			cout << *it << endl;
		}
	}


	return 0;
}
