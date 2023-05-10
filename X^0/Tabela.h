#pragma once
#include<vector>
#include<string>
#include<iostream>
#include"Exceptii.h"
#include"Jucator.h"
using namespace std;
class Tabela
{
	vector<vector<string>>Tabla;
	vector<vector<int>> Afisare;
	vector<Jucator*>Jucatori;
public:
	Tabela();
	~Tabela();
	void Print();
	bool Adaugare_Piesa(Jucator Bolfa);
	bool Verifiare_Catigator(Jucator& Bofla, Jucator& Mario,int& miscari);
	void Add_Jucator(Jucator* Bolfa);
	void Refacere();
	
};

