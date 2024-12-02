#define _CRT_SECURE_NO_WARNINGS

# include <iostream>

using namespace std;

class Masina {
public:
	const string nrInmatriculare;
	char* marca;
	int anFabricatie;
	float presiuneRoti[4];
	float pret;

	int nrDrumuri;
	int* distante;
private:
	static int vitezaMaxima;

public:
	Masina() : nrInmatriculare("B-104-MNA") {
		marca = new char[strlen("BMW") + 1];
		strcpy(marca, "BMW");
		anFabricatie = 2024;
		for (int i = 0; i < 4; i++) {
			presiuneRoti[i] = 1.8;
		}
		pret = 89.000;
		nrDrumuri = 3;
		distante = new int[nrDrumuri];
		for (int i = 0; i < nrDrumuri; i++) {
			distante[i] = 100;
		}




	}

	Masina(const string nrInmatriculare, const char* marca, int anFabricatie, float presiuneRoti[4],
		float pret, int nrDrumuri, int* distante) : nrInmatriculare(nrInmatriculare) {
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
		this->anFabricatie = anFabricatie;
		for (int i = 0; i < 4; i++) {
			this->presiuneRoti[i] = presiuneRoti[i];

		}
		this->pret = pret;
		this->nrDrumuri = nrDrumuri;
		this->distante = new int[nrDrumuri];
		for (int i = 0; i < nrDrumuri; i++) {
			this->distante[i] = distante[i];
		}
	}

	friend ostream& operator<<(ostream& out, Masina& m) {
		out << m.nrInmatriculare << endl;
		out << m.marca << endl;
		out << m.anFabricatie << endl;
		for (int i = 0; i < 4; i++) {
			out << m.presiuneRoti[i] << endl;
		}
		out << m.pret << endl;
		out << m.nrDrumuri << endl;
		for (int i = 0; i < m.nrDrumuri; i++) {
			out << m.distante[i] << endl;
		}
		out << m.vitezaMaxima << endl;
		return out;
	}

	Masina(const Masina& m) : nrInmatriculare(m.nrInmatriculare) {
		this->marca = new char[strlen(m.marca) + 1];
		strcpy(this->marca, m.marca);
		this->anFabricatie = m.anFabricatie;
		for (int i = 0; i < 4; i++) {
			this->presiuneRoti[i] = m.presiuneRoti[i];

		}
		this->pret = m.pret;
		this->nrDrumuri = m.nrDrumuri;
		this->distante = new int[nrDrumuri];
		for (int i = 0; i < m.nrDrumuri; i++) {
			this->distante[i] = m.distante[i];
		}
	}

	~Masina() {
		if (marca != NULL) {
			delete[]marca;
		}

		if (distante != NULL) {
			delete[] distante;
		}
	}

	Masina& operator=(Masina& m) {
		if (marca != NULL) {
			delete[]marca;
		}

		if (distante != NULL) {
			delete[] distante;
		}

		this->marca = new char[strlen(m.marca) + 1];
		strcpy(this->marca, m.marca);
		this->anFabricatie = m.anFabricatie;
		for (int i = 0; i < 4; i++) {
			this->presiuneRoti[i] = m.presiuneRoti[i];

		}
		this->pret = m.pret;
		this->nrDrumuri = m.nrDrumuri;
		this->distante = new int[nrDrumuri];
		for (int i = 0; i < m.nrDrumuri; i++) {
			this->distante[i] = m.distante[i];
		}
		return *this;

	}

	static int functie() {
		return vitezaMaxima = vitezaMaxima + 1;
	}

	char* getMarca() {
		return marca;
	}

	void setMarca(const char* marca_noua) {
		//stergi pt ca  sa avitam mk
		if (marca != NULL) {
			delete[]marca;
		}
		this->marca = new char[strlen(marca_noua) + 1];
		strcpy(this->marca, marca_noua);
	}


	//get - functii accesor care ne ajuta sa vedem/folosim atrb care sunt private
	static int getVitezaMaxima() {
		return vitezaMaxima;
	}

	//set -modifica un atribut
	static void setVitezaMaxima(static int vitezMaxima_noua) {
		vitezaMaxima = vitezMaxima_noua;
	}

};

class MasinaElectrica {
public:
	const string NrInmatriculare;
	char* culoare;
	string ModuriCondus[3];
	float capacitate_baterie;
	int an_fabricatie;

private:
	static int putere_motor;

public:


	MasinaElectrica() : NrInmatriculare("IF-99-MMM") {
		culoare = new char[strlen("Alb") + 1];
		strcpy(culoare, "Alb");
		for (int i = 0; i < 3; i++) {
			ModuriCondus[i] = "eco";
		}
		capacitate_baterie = 95;
		an_fabricatie = 2023;
	}

	MasinaElectrica(const string NrInmatriculare, const char* culoare, string ModuriCondus[3], float capacitate_baterie, int an_fabricatie) : NrInmatriculare(NrInmatriculare) {
		this->culoare = new char[strlen(culoare) + 1];
		strcpy(this->culoare, culoare);
		for (int i = 0; i < 3; i++) {
			this->ModuriCondus[i] = ModuriCondus[i];
		}
		this->capacitate_baterie = capacitate_baterie;
		this->an_fabricatie = an_fabricatie;
	}

	~MasinaElectrica() {
		if (culoare != NULL) {
			delete[] culoare;
		}
	}

	friend ostream& operator<<(ostream& out, MasinaElectrica& me) {
		out << me.NrInmatriculare << endl;
		out << me.culoare << endl;
		for (int i = 0; i < 3; i++) {
			out << me.ModuriCondus[i] << endl;
		}
		out << me.capacitate_baterie << endl;
		out << me.an_fabricatie << endl;
		out << me.putere_motor << endl;

		return out;
	}

	MasinaElectrica(const MasinaElectrica& me) : NrInmatriculare(me.NrInmatriculare) {
		this->culoare = new char[strlen(me.culoare) + 1];
		strcpy(this->culoare, me.culoare);
		for (int i = 0; i < 3; i++) {
			this->ModuriCondus[i] = me.ModuriCondus[i];
		}
		this->capacitate_baterie = me.capacitate_baterie;
		this->an_fabricatie = me.an_fabricatie;
	}

	MasinaElectrica& operator=(const MasinaElectrica& me) {
		if (culoare != NULL) {
			delete[] culoare;
		}
		this->culoare = new char[strlen(me.culoare) + 1];
		strcpy(this->culoare, me.culoare);
		for (int i = 0; i < 3; i++) {
			this->ModuriCondus[i] = me.ModuriCondus[i];
		}
		this->capacitate_baterie = me.capacitate_baterie;
		this->an_fabricatie = me.an_fabricatie;

		return *this;
	}

	static int getPutereMotor() {
		return putere_motor;
	}

	void setPutereMotor(static int putere_motor_nou) {
		putere_motor = putere_motor_nou;
	}

};

class MasinaSport {
	const string idMasina;
	char* marca;
	string model;
	int numarViteze;
	float* istoriculVitezelor;
	float pret;

private:
	static int nrTotalMasini;


public:

	MasinaSport() : idMasina("IF-23-ABC") {
		marca = new char[strlen("BMW") + 1];
		strcpy(marca, "BMW");
		model = "488 GTB";
		numarViteze = 3;
		istoriculVitezelor = new float[numarViteze];
		for (int i = 0; i < numarViteze; i++) {
			istoriculVitezelor[i] = 130.5;
		}

		pret = 99800;
	}

	MasinaSport(const string idMasina, const char* marca, string model, int numarViteze, float* istoriculVitezelor, float pret) : idMasina(idMasina) {
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
		this->model = model;
		this->numarViteze = numarViteze;
		this->istoriculVitezelor = new float[numarViteze];
		for (int i = 0; i < numarViteze; i++) {
			this->istoriculVitezelor[i] = istoriculVitezelor[i];
		}
		this->pret = pret;
	}

	~MasinaSport() {
		if (marca != NULL) {
			delete[]marca;
		}
		if (istoriculVitezelor != NULL) {
			delete[]istoriculVitezelor;
		}
	}

	friend ostream& operator<<(ostream& out, MasinaSport& ms) {
		out << ms.idMasina << endl;
		out << ms.marca << endl;
		out << ms.model << endl;
		out << ms.numarViteze << endl;
		for (int i = 0; i < ms.numarViteze; i++) {
			out << ms.istoriculVitezelor[i] << endl;
		}

		out << ms.pret << endl;
		out << ms.nrTotalMasini << endl;

		return out;
	}


	MasinaSport(const MasinaSport& ms) : idMasina(ms.idMasina) {
		this->marca = new char[strlen(ms.marca) + 1];
		strcpy(this->marca, ms.marca);
		this->model = ms.model;
		this->numarViteze = ms.numarViteze;
		this->istoriculVitezelor = new float[numarViteze];
		for (int i = 0; i < numarViteze; i++) {
			this->istoriculVitezelor[i] = ms.istoriculVitezelor[i];
		}
		this->pret = ms.pret;
	}

	MasinaSport& operator =(const MasinaSport& ms) {
		if (marca != NULL) {
			delete[]marca;
		}
		if (istoriculVitezelor != NULL) {
			delete[]istoriculVitezelor;
		}
		this->marca = new char[strlen(ms.marca) + 1];
		strcpy(this->marca, ms.marca);
		this->model = ms.model;
		this->numarViteze = ms.numarViteze;
		this->istoriculVitezelor = new float[numarViteze];
		for (int i = 0; i < numarViteze; i++) {
			this->istoriculVitezelor[i] = ms.istoriculVitezelor[i];
		}
		this->pret = ms.pret;

		return *this;
	}

	static int getnrTotalMasini() {
		return nrTotalMasini;
	}

	void setnrTotalMasini(static int nrTotalMasini_nou) {
		nrTotalMasini = nrTotalMasini_nou;
	}
};

int MasinaElectrica::putere_motor = 1000;

int Masina::vitezaMaxima = 240;

int MasinaSport::nrTotalMasini = 10;
void main() {
	Masina m1;
	float presiuneRoti[4]{ 1.8,1.8,2.2,2.2 };
	Masina m("PH-89-MXM", "Toyota", 2024, presiuneRoti, 89000, 3, new int[3] { 10, 100, 20 });

	cout << m << endl;
	m = m1;
	cout << m << endl;
	cout << m1 << endl;

	Masina m2 = m1;

	cout << m2 << endl;

	cout << m1.functie() << endl;

	cout << m1 << endl;
	cout << m2 << endl;
	cout << m << endl;

	cout << m1.getVitezaMaxima() << endl;
	m1.setVitezaMaxima(300);

	cout << m1.getVitezaMaxima() << endl;

	m1.setMarca("McLaren");
	cout << m1.getMarca() << endl;

	cout << " " << endl;


	// apel MasinaElectrica

	MasinaElectrica me;
	cout << me << endl;

	// constr cu parametrii

	string ModuriCondus[3]{ "eco", "sport", "normal" };
	MasinaElectrica me1("IF-01-MAD", "Galben", ModuriCondus, 90, 2021);

	cout << me1 << endl;

	cout << " " << endl;

	// constr de copiere 

	MasinaElectrica me2 = me1;

	cout << me1 << me2 << endl;

	cout << " " << endl;

	// operatorul = 

	me = me1;

	cout << me << me1 << endl;

	cout << me.getPutereMotor() << endl;

	me.setPutereMotor(1001);

	cout << me.getPutereMotor() << endl;

	cout << " " << endl;

	// apel MasinaSport

	MasinaSport ms;
	cout << ms << endl;

	cout << " " << endl;

	// constr cu parametrii

	MasinaSport ms1("PH-99-NNN", "Ferrari", "911 Turbo S", 4, new float[4] {210, 180, 150, 100}, 90000);

	cout << ms1 << endl;

	cout << " " << endl;

	// constr de copiere

	MasinaSport ms2(ms1);

	cout << ms2 << ms1 << endl;

	cout << " " << endl;

	// operatorul = 

	ms1 = ms;

	cout << ms1 << ms << endl;

	cout << " " << endl;

	cout << ms.getnrTotalMasini() << endl;
	ms.setnrTotalMasini(15);

	cout << ms.getnrTotalMasini() << endl;
}