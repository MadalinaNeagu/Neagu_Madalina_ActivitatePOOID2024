#define _CRT_SECURE_NO_WARNINGS

# include <iostream>

using namespace std;

class Masina {
private:
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
		pret = 89000;
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
		if (marca != NULL) {
			delete[]marca;
		}
		this->marca = new char[strlen(marca_noua) + 1];
		strcpy(this->marca, marca_noua);
	}

	int getAnfabricatie() {
		return anFabricatie;
	}

	void setAnFabricatie(int AnFabricatie_nou) {
		anFabricatie = AnFabricatie_nou;
	}

	float getpresiuneRoti(int index) {
		if (index >= 0 && index < 4) {
			return presiuneRoti[index];
		}
	}

	void setPresiuneRoti(float presiuneRoti_nou[4]) {
		for (int i = 0; i < 4; i++) {
			this->presiuneRoti[i] = presiuneRoti_nou[i];
		}
	}

	int getDistante(int index) {
		if (index >= 0 && index < nrDrumuri) {
			return  distante[index];
		}
	}

	void setDistante(int nrDrumuri_nou, int* distante_nou) {
		if (distante != NULL) {
			delete[]distante;
		}
		this->nrDrumuri = nrDrumuri_nou;
		this->distante = new int[nrDrumuri_nou];
		for (int i = 0; i < nrDrumuri_nou; i++) {
			this->distante[i] = distante_nou[i];
		}
	}

	int getNrDrumuri() {
		return nrDrumuri;
	}


	static int getVitezaMaxima() {
		return vitezaMaxima;
	}


	static void setVitezaMaxima(static int vitezMaxima_noua) {
		vitezaMaxima = vitezMaxima_noua;
	}

	float getPret() {
		return pret;
	}

	void setPret(float pret_nou) {
		pret = pret_nou;
	}

	string getNrInmatriculare() {
		return nrInmatriculare;
	}
	friend static float PretTotal(int nrMasini, Masina* masini);

	friend static float TotalDistante(int nrMasini, Masina* masini);

};

static float TotalDistante(int nrMasini, Masina* masini) {
	float suma = 0;
	for (int i = 0; i < nrMasini; i++) {
		for (int j = 0; j < masini[i].nrDrumuri; j++) {
			suma += masini[i].distante[i];
		}


	}
	return suma;
}

static float PretTotal(int nrMasini, Masina* masini) {
	float suma = 0;
	for (int i = 0; i < nrMasini; i++) {
		suma += masini[i].pret;
	}

	return suma;
}



enum ModuriCondus {
	Normal, Eco, Sport
};

class MasinaElectrica {
private:
	const string NrInmatriculare;
	char* culoare;
	float capacitate_baterie;
	int an_fabricatie;
	ModuriCondus moduricondus;

private:
	static int putere_motor;

public:


	MasinaElectrica() : NrInmatriculare("IF-99-MMM") {
		culoare = new char[strlen("Alb") + 1];
		strcpy(culoare, "Alb");
		capacitate_baterie = 95;
		an_fabricatie = 2023;
		moduricondus = Eco;
	}

	MasinaElectrica(const string NrInmatriculare, const char* culoare, float capacitate_baterie, int an_fabricatie, ModuriCondus moduricondus) : NrInmatriculare(NrInmatriculare) {
		this->culoare = new char[strlen(culoare) + 1];
		strcpy(this->culoare, culoare);
		this->capacitate_baterie = capacitate_baterie;
		this->an_fabricatie = an_fabricatie;
		this->moduricondus = moduricondus;
	}

	~MasinaElectrica() {
		if (culoare != NULL) {
			delete[] culoare;
		}
	}

	friend ostream& operator<<(ostream& out, MasinaElectrica& me) {
		out << me.NrInmatriculare << endl;
		out << me.culoare << endl;
		out << me.capacitate_baterie << endl;
		out << me.an_fabricatie << endl;
		out << me.putere_motor << endl;
		if (me.moduricondus == 0) {
			out << "Normal" << endl;
		}
		else
			if (me.moduricondus == 1) {
				out << "Eco" << endl;
			}
			else
			{
				out << "Sport" << endl;
			};

		return out;
	}

	MasinaElectrica(const MasinaElectrica& me) : NrInmatriculare(me.NrInmatriculare) {
		this->culoare = new char[strlen(me.culoare) + 1];
		strcpy(this->culoare, me.culoare);
		this->capacitate_baterie = me.capacitate_baterie;
		this->an_fabricatie = me.an_fabricatie;
		this->moduricondus = me.moduricondus;
	}

	MasinaElectrica& operator=(const MasinaElectrica& me) {
		if (culoare != NULL) {
			delete[] culoare;
		}
		this->culoare = new char[strlen(me.culoare) + 1];
		strcpy(this->culoare, me.culoare);
		this->capacitate_baterie = me.capacitate_baterie;
		this->an_fabricatie = me.an_fabricatie;
		this->moduricondus = me.moduricondus;

		return *this;
	}

	static int getPutereMotor() {
		return putere_motor;
	}

	static void setPutereMotor(static int putere_motor_nou) {
		putere_motor = putere_motor_nou;
	}

	char* getCuloare() {
		return culoare;
	}

	void setCuloare(const char* culoare_noua) {
		if (culoare != NULL) {
			delete[]culoare;
		}
		this->culoare = new char[strlen(culoare_noua) + 1];
		strcpy(this->culoare, culoare_noua);
	}
	float getCapacitateBaterie() {
		return capacitate_baterie;
	}

	void setCapacitateBaterie(float capacitateBaterie_nou) {
		this->capacitate_baterie = capacitateBaterie_nou;
	}

	int getAnFabricatie() {
		return an_fabricatie;
	}

	void setAnFabricatie(int anFabricatie_nou) {
		this->an_fabricatie = anFabricatie_nou;
	}

	ModuriCondus getModuriCondus() {
		if (moduricondus == 0) {
			cout << "Normal" << endl;
		}
		else
			if (moduricondus == 1) {
				cout << "Eco" << endl;
			}
			else
			{
				cout << "Sport" << endl;
			};

		return moduricondus;
	}

	void setModuriCondus(ModuriCondus moduriCondus_nou) {
		this->moduricondus = moduriCondus_nou;
	}

	string getNrInmatriculare() {
		return NrInmatriculare;
	}

};

class MasinaSport {
private:
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

	static void setnrTotalMasini(static int nrTotalMasini_nou) {
		nrTotalMasini = nrTotalMasini_nou;
	}

	char* getMarca() {
		return marca;
	}

	void setMarca(const char* marca_noua) {
		if (marca != NULL) {
			delete[]marca;
		}
		this->marca = new char[strlen(marca_noua) + 1];
		strcpy(this->marca, marca_noua);
	}

	string getModel() {
		return model;
	}

	void SetModel(string model_nou) {
		this->model = model_nou;
	}
	float getPret() {
		return pret;
	}

	void setPret(float pret_nou) {
		this->pret = pret_nou;
	}

	int getNumarViteze() {
		return numarViteze;
	}


	float getIstoriculVitezelor(int index) {
		if (index >= 0 && index < numarViteze) {
			return istoriculVitezelor[index];
		}
	}

	void SetIstoriculVitezelor(int nrViteze_nou, float* istoriculVitezelor_nou) {
		if (istoriculVitezelor != NULL) {
			delete[]istoriculVitezelor;
		}
		this->numarViteze = nrViteze_nou;
		this->istoriculVitezelor = new float[nrViteze_nou];
		for (int i = 0; i < nrViteze_nou; i++) {
			this->istoriculVitezelor[i] = istoriculVitezelor_nou[i];
		}
	}

	string getIdMasina() {
		return  idMasina;
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


	MasinaElectrica me1("IF-01-MAD", "Galben", 90, 2021, Normal);

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

	cout << m1 << endl;


	for (int i = 0; i < m1.getNrDrumuri(); i++) {

		cout << m1.getDistante(i) << endl;
	}
	// apel get si set ptr vectorul aalocat dinamic din clasa Masina

	m1.setDistante(4, new int[4] {80, 90, 120, 150});
	for (int i = 0; i < m1.getNrDrumuri(); i++) {

		cout << m1.getDistante(i) << endl;
	}

	cout << PretTotal(3, new Masina[3]{ m,m1,m2 }) << endl;

	cout << " " << endl;

	cout << m << m1 << m2 << endl;

	cout << TotalDistante(3, new Masina[3]{ m,m1,m2 }) << endl;

	// apel get and set ptr clasa Masina

	cout << m.getNrInmatriculare() << endl;
	cout << " " << endl;
	cout << m.getMarca() << endl;
	m.setMarca("Peugeot");
	cout << m.getMarca() << endl;
	cout << " " << endl;
	cout << m.getAnfabricatie() << endl;
	m.setAnFabricatie(2001);
	cout << m.getAnfabricatie() << endl;
	cout << " " << endl;
	cout << m.getPret() << endl;
	m.setPret(25000);
	cout << m.getPret() << endl;
	cout << " " << endl;
	cout << m.getpresiuneRoti(1) << endl;
	float presiuneRoti_nou[4]{ 1.8,1.9,2.2,2.2 };
	m.setPresiuneRoti(presiuneRoti_nou);
	cout << m.getpresiuneRoti(1);
	cout << " " << endl;
	cout << " " << endl;

	// apel set si get pentru clasa MasinaElectrica

	cout << me1.getNrInmatriculare() << endl;
	cout << " " << endl;
	cout << me1.getCuloare() << endl;
	me1.setCuloare("Rosu");
	cout << me1.getCuloare() << endl;
	cout << " " << endl;
	cout << me1.getCapacitateBaterie() << endl;
	me1.setCapacitateBaterie(100);
	cout << me1.getCapacitateBaterie() << endl;
	cout << " " << endl;
	cout << me1.getAnFabricatie() << endl;
	me1.setAnFabricatie(2023);
	cout << me1.getAnFabricatie() << endl;
	cout << " " << endl;
	cout << me1.getModuriCondus() << endl;
	me1.setModuriCondus(Eco);
	cout << me1.getModuriCondus() << endl;
	cout << " " << endl;

	// apel get si set pentru clasa MasinaSport()



	cout << ms2.getIdMasina() << endl;
	cout << " " << endl;
	cout << ms2.getMarca() << endl;
	ms2.setMarca("Porsche");
	cout << ms2.getMarca() << endl;
	cout << " " << endl;
	cout << ms2.getModel() << endl;
	ms2.SetModel("SUV Cayenne");
	cout << ms2.getModel() << endl;
	cout << " " << endl;
	cout << ms2.getNumarViteze() << endl;
	cout << " " << endl;
	cout << ms2.getPret() << endl;
	ms2.setPret(100000);
	cout << ms2.getPret() << endl;
	cout << " " << endl;
	ms2.SetIstoriculVitezelor(4, new float[4] {150, 170, 220, 100});
	for (int i = 0; i < ms2.getNumarViteze(); i++) {

		cout << ms2.getIstoriculVitezelor(i) << endl;
	}
}

