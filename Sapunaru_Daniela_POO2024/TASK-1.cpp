//#include<iostream>
//
//using namespace std;
//
//struct bloc {
//	string strada;
//	int nrScari;
//	int nrApartamente;
//	bool esteNou;
//	int nrPostal;
//};
//
//
//void afisareBloc(bloc b) {
//	cout << "Blocul de pe strada" << " " << b.strada;
//	cout << " ,are " << b.nrScari << " scari ";
//	cout << "si un numarul de  " << b.nrApartamente << " apartamente. ";
//	cout << "Acesta are codul postal " << b.nrPostal << " ";
//	cout << "si este recent construit: " << (b.esteNou ? "DA" : "NU") << "." << endl;
//
//}
//
//
//bloc citireBloc() {
//	bloc b;
//	cout << "Introduceti strada:";
//	cin >> b.strada;
//	cout << "Nr scari:";
//	cin >> b.nrScari;
//	cout << "nrApartamente:";
//	cin >> b.nrApartamente;
//	cout << "Este nou?(1-DA,0-NU):";
//	cin >> b.esteNou;
//	cout << "Codul postal:";
//	cin >> b.nrPostal;
//
//	return b;
//}
//
//
//int main() {
//	bloc b1;
//
//	int nrBlocuri = 10;
//
//	bloc* vector;
//	vector = new bloc[nrBlocuri];
//
//	for (int i = 0; i < nrBlocuri; i++)
//	{
//		vector[i] = citireBloc();
//	}
//
//	for (int i = 0; i < nrBlocuri; i++) {
//		afisareBloc(vector[i]);
//	}
//
//
//	return 0;
//}