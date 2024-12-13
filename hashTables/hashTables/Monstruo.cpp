#include <iostream>
#include "Monstruo.h"
using namespace std;

void Monstruo::setName(string nombre) {
	name = nombre;
}

string Monstruo::getName() {
	return name;
}

void Monstruo::setCr(double Cr) {
	cr = Cr;
}

double Monstruo::getCr() {
	return cr;
}

void Monstruo::setType(string tipo) {
	type = tipo;
}

string Monstruo::getType() {
	return type;
}

void Monstruo::setSize(string tamano) {
	size = tamano;
}

string Monstruo::getSize() {
	return size;
}

void Monstruo::setAc(int Ac) {
	ac = Ac;
}

int Monstruo::getAc() {
	return ac;
}

void Monstruo::setHp(int Hp) {
	hp = Hp;
}

int Monstruo::getHp() {
	return hp;
}

void Monstruo::setAlign(string Align) {
	align = Align;
}

string Monstruo::getAlign() {
	return align;
}

void Monstruo::imprimirMonstruo() {
	cout << "Name: " << name << endl;
	cout << "cr: " << cr << endl;
	cout << "type: " << type << endl;
	cout << "size: " << size << endl;
	cout << "ac: " << ac << endl;
	cout << "hp: " << hp << endl;
	cout << "align: " << align << endl;
}

unsigned int monsterHash(Monstruo& dato, unsigned int tableSize) {
	string nombre;
	unsigned int hashValue = 0, len = 0;
	const int base = 31;
	nombre = dato.getName();
	len = nombre.length();
	for (unsigned int c = 0; c < len; c++)
		hashValue = (hashValue * base + nombre[c]) % tableSize;
	return hashValue;
}

