#include<iostream>

using namespace std;

//int functie(int a, int b) {
//	return a + b;
//}
//
//float functie(float a, float b) {
//	return a + b;
//}
//
//T functie(T a, Tb) {
//	return a + b;
//}

int y;
int x = 10;
char c = 'a';

int functie(int a, int b) {
	int suma = a + b;
	return suma;

}


int f(int x)
{
	return 2 * x + 3;
}

int f(int y, int x) {
	return x + y;
}
int f(double x) {
	string cuvant = "ceva";
	return x;
}


void fff(string  mesaj) {
	cout << mesaj << endl;
}

int fct(int* adresa) {
	return 2 + *adresa;
}

void main()
{
	cout << y << endl;
	cout << x << endl;

	cout << f(2) << endl;
	int rez = f(-2);
	cout << rez << endl;
	cout << f(100) << endl;
	cout << f(8, 10) << endl;
	cout << f(1.4) << endl;

	fff("Buna!");



	int a = 5;
	int* pp = NULL;
	pp = &a;
	int* p = &a;

	cout << a << endl;
	cout << &a << endl;
	cout << p << endl;
	cout << *p << endl;

	double z = 7.9;
	double* pointer = &z;




}