#include "Tabela.h"

Tabela::Tabela()
{
	vector<string> Aux;
	for(int i=0;i<3;i++)
	Aux.push_back("-");
	for (int i = 0; i < 3; i++)
		Tabla.push_back(Aux);
	
	int index = 1;
	Afisare.resize(3);
	
	for (int i = 0; i < 3; i++) {
		Afisare[i].resize(3);
		for (int j = 0; j < 3; j++) {
			Afisare[i][j] = index;
			index++;
		}
	}
}

Tabela::~Tabela()
{
	Tabla.clear();
	Jucatori.clear();
}

void Tabela::Print()
{
	system("cls");
	cout << " --- --- --- " << endl;
	for (int i = 0; i < 3; i++) {
		(Tabla[i][0]!= "-") ? cout << "| " << Tabla[i][0] : cout << "| " << Afisare[i][0];
		(Tabla[i][1]!= "-") ? cout << " | " << Tabla[i][1] : cout << " | " << Afisare[i][1];
		(Tabla[i][2]!= "-") ? cout << " | " << Tabla[i][2] : cout << " | " << Afisare[i][2];
		cout<< " |" << endl;
	}
	cout << " --- --- --- " << endl;
}

bool Tabela::Adaugare_Piesa(Jucator Bolfa)
{
	int pozitie;
	poz_inc pozitie_incorecta;
	poz_ocup pozitie_ocupata;
	try {
		cout <<"("<< Bolfa.GetName()<<") Alegeti pozitia unde doriti sa plasati piesa: "; cin >> pozitie;
		if (pozitie > 9 || pozitie < 0)
			throw pozitie_incorecta;
		for(int i = 0 ; i < 3 ; i++)
			for (int j = 0; j < 3; j++) {
				if (Afisare[i][j] == pozitie) {
					if (Tabla[i][j]!="-")
						throw pozitie_ocupata;
					else {
						Tabla[i][j] = Bolfa.GetPiesa();
						return true;
					}
				}
			}
		return false;
	}
	catch (exception& e)
	{
		cout << "Aveti grija la pozitie! (" <<e.what()<<")"<< endl;
		return false;
	}
}

bool Tabela::Verifiare_Catigator(Jucator& Bolfa, Jucator& Mario,int& miscari)
{
	vector<bool> ok;
	ok.push_back(false);
	ok.push_back(false);
	int count = 0;
//------------------------------------------------------------------------------------------
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < 3; i++)
		{
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				//cout << Tabla[i][j] << endl;
				if (Tabla[i][j] == Jucatori[k]->GetPiesa()) {
					count++;
				}
			}
			//cout << count << endl;
			if (count == 3)
				ok[k] = true;
		}
	}
//------------------------------------------------------------------------------------------
	if(ok[0]==false && ok[1]==false)
	for (int k = 0; k < 2; k++)
		for (int i = 0; i < 3; i++) {
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (Tabla[j][i] == Jucatori[k]->GetPiesa()) {
					count++;
				}
				if (count == 3) {
					ok[k] = true;
				}
			}
		}
//------------------------------------------------------------------------------------------
	if (ok[0] == false && ok[1] == false)
		for (int k = 0; k < 2; k++) {
			count = 0;
			for (int i = 0; i < 3; i++)
			{
				if (Tabla[i][i] == Jucatori[k]->GetPiesa()) {
					count++;
				}
				if (count == 3) {
					ok[k] = true;
				}
			}
		}
//------------------------------------------------------------------------------------------
	int index = 0;
	if (ok[0] == false && ok[1] == false)
		for (int k = 0; k < 2; k++) {
			count = 0;
			index = 0;
			for (int j = 2; j >= 0; j--)
			{
				if (Tabla[index][j] == Jucatori[k]->GetPiesa()) {
					count++;
				}
				if (count == 3) {
					ok[k] = true;
				}
				index++;
			}
		}
//------------------------------------------------------------------------------------------
	if (ok[0] == true)
		{
		string Raspuns;
			cout << "Jucatorul 1 (" << Bolfa.GetName() << ") a CASTIGAT!!" << endl;
			cout << "Vreti sa jucati din nou?[Y/N]:"; cin >> Raspuns;
			if (Raspuns == "Y") {
				miscari = 0;
				Bolfa.operator++();
				Refacere();
			}
			else {
				Bolfa.operator++();
				return true;
			}
			
		}
	if (ok[1])
		{
		string Raspuns;
				cout << "Jucatorul 2 (" << Mario.GetName() << ") a CASTIGAT!!" << endl;
				cout << "Vreti sa jucati din nou?[Y/N]:"; cin >> Raspuns;
				if (Raspuns == "Y") {
					miscari = 0;
					Mario.operator++();
					Refacere();
				}
				else
				{
					Mario.operator++();
					return true;
				}
		}
	if (ok[0] == false && ok[1] == false && miscari == 9)
		{
		string Raspuns;
			cout << "(" << Bolfa.GetName() << ")" << "-> REMIZA <-(" << Mario.GetName() << ")" << endl;
			cout << "Vreti sa jucati din nou?[Y/N]:"; cin >> Raspuns;
			if (Raspuns == "Y") {
				miscari = 0;
				Refacere();
			}
			else
			return false;
		}
	return false;
}

void Tabela::Add_Jucator(Jucator* Bolfa)
{
	Jucatori.push_back(Bolfa);
}

void Tabela::Refacere()
{
	Tabla.clear();
	vector<string> Aux;
	for (int i = 0; i < 3; i++)
		Aux.push_back("-");
	for (int i = 0; i < 3; i++)
		Tabla.push_back(Aux);
}
