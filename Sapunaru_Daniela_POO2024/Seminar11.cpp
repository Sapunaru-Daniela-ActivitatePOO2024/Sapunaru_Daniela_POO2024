#include<iostream>
using namespace std;

class Angajat {
protected:
	string nume;
	int marca;
	float salariu;

public:
	Angajat() {
		this->marca = 1234;
		this->nume = "No name";
		this->salariu = 3000;
	}

	Angajat(int marca, string nume, float salariu) {
		this->marca = marca;
		this->nume = nume;
		this->salariu = salariu;

	}

	/*float getSalariu() {
		return this->salariu;
	}*/

	virtual float getVenitIncasat() = 0;
};

class Manager:public Angajat {
private:
	int nrSubordonati;
	float sporPerSubordonat;

public:
	Manager() :Angajat(){
	{
		this->nrSubordonati = 0;
		this->sporPerSubordonat = 0;
	}
	
	Manager(int nr, float spor):Angajat() {
		this->nrSubordonati = nr;
		this->sporPerSubordonat = spor;
	}
	
	float getSporConducere() {
		return this->nrSubordonati * this->sporPerSubordonat;
	}
	
};

//angajat-manager -manager de dep
//                - manager de 

class ManagerDepartament : public Manager {
private:
	string numeDepartament;
	bool deCercetare;

public:

	ManagerDepartament() : Manager() {
		this->numeDepartament = "Departament";
		this->deCercetare = false;
	}

	ManagerDepartament(string nume, bool deCercetare, int nrSubordonati, float sporPerSubordonat) : Manager(nrSubordonati, sporPerSubordonat) {
		this->numeDepartament = nume;
		this->deCercetare = deCercetare;

	}
	
	float getVenitIncasat() {
		float venit = this->salariu;
		venit += this->getSporConducere();
		if (this->deCercetare) {
			venit += (10 / 100) * salariu;
		}
		return venit;
	}

};

class ManagerDeProiect :public Manager {
private:
	string numeProiect;
	int nrZile;
	float sporPerZi;
public:
	ManagerDeProiect() :Manager() {
		this->numeProiect="Project";
		this->nrZile = 0;
		this->sporPerZi = 0;
	}

	ManagerDeProiect(string nume, int nrZile, float sporPeZi, int nrSubordonati, float sporPerSubordonati) :
		Manager(nrSubordonati, sporPerSubordonati) {
		this->numeProiect = nume;
		this->nrZile = nrZile;
		this->sporPerZi = sporPeZi;
	}
	float getVenitIncasat() {
		float venit = this->salariu;
		venit += this->getSporConducere();
		venit += (this->nrZile * this->sporPerZi);
		return venit;
	}

};

class Cecetator :public Angajat {
public:
	Cecetator(int marca, string nume, float salariu) :Angajat(marca, nume, salariu) {

	}

	//supradefinim met

	float getVenitIncasat() {
		return this->salariu;//are doar sal, nimic in plus
	}

};


int main() {
	//Angajat a;//nu putem instantia un ob de tip clasei abstracte
	//manager m;-la fel


	ManagerDepartament md;
	ManagerDeProiect mp;


	Angajat* pointer;
	//pointer=new Angajat NUUU
	pointer = NULL;
	pointer = new ManagerDepartament();
	pointer->getVenitIncasat();

	int nrAngajati = 5;
	Angajat** vector;//vector de pointeri
	vector = new Angajat * [nrAngajati];
	vector[0] = new ManagerDepartament();
	vector[1] = new ManagerDeProiect();
	vector[2] = new ManagerDeProiect("TODO list", 10, 30, 3, 15);
	vector[3] = new ManagerDepartament("AI", true, 10, 15);
	vector[4] = new Cecetator(9876,"Popescu", 10000);

	for (int i = 0; i < nrAngajati; i++) {
		cout <<(i+1)<<"."<< vector[i]->getVenitIncasat() << endl;
	}


	return 345;
}
