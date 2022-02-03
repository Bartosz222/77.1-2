#include <iostream>
#include <fstream>
using namespace std;
int counter = 0; // licznik powtorzen;
ofstream wyjscie;
string szyfrowanie(string klucz,string tekst){
	string wynik;
	int keyIndex = 0;
  	int ruch; //przechowuje wartoœæ o ile ma przesun¹æ litere
  	int index;
	for (int i = 0; i < tekst.length(); i++) {
	    if (tekst[i] < 'A' || tekst[i] > 'Z') {
	      wynik += tekst[i];
	      continue;
	    }
	    ruch = (int) klucz[keyIndex] - 65;
	    index = (int) tekst[i] - 65;
	    index += ruch;
    	if (index > 25) index = (index - 1) % 25;
    	index += 65;
    	wynik += (char) index;
    	keyIndex++;
    	if (keyIndex == klucz.length()) { //po ka¿dym skoñczeniu siê klucza wraca na pocz¹tek i dodaje jedno powtórzenie do licznika
			counter++;
    		keyIndex = 0;
		}
  	}
  	counter++;
  	return wynik;
}
string odszyfrowanie(string klucz , string tekst){
	int keyIndex = 0;
  	for (int i = 0; i < tekst.length(); i++) {
    	if (tekst[i] == ' ' || tekst[i] == ',' || tekst[i] == '.') continue;
    	tekst[i] -= klucz[keyIndex];
    	tekst[i] += 65;
    	if (tekst[i] < 'A') tekst[i] += 26;
    	keyIndex++;
    	if (keyIndex == klucz.length()) keyIndex = 0;
  	}
  	return tekst;
}
void zad1(){
	ifstream wejscie;
	wejscie.open("dokad.txt");
	string klucz = "LUBIMYCZYTAC";
	string tekst;
	string wynik;
	while(!wejscie.eof()){
		getline(wejscie,tekst);
	}
	wynik =szyfrowanie(klucz,tekst);
	cout<<"Zadanie 1:"<<endl;
	cout<<"Liczba powtorzen: "<<counter<<endl;
	cout<<wynik<<endl;
	wejscie.close();
	wyjscie<<"Zadanie 1:"<<endl;
	wyjscie<<"Liczba powtorzen: "<<counter<<endl;
	wyjscie<<wynik<<endl;
}
void zad2(){
	ifstream wejscie;
	wejscie.open("szyfr.txt");
	string klucz;
	string tekst;
	getline(wejscie,tekst);
	getline(wejscie,klucz);
	wejscie.close();
	cout<<"Zadanie 2:"<<endl;
	cout<<odszyfrowanie(klucz,tekst)<<endl;
	wyjscie<<"Zadanie 2:"<<endl;
	wyjscie<<odszyfrowanie(klucz,tekst)<<endl;
}
int main(int argc, char** argv) {
	wyjscie.open("wynik.txt");
	zad1();
	zad2();
	wyjscie.close();
	return 0;
}
