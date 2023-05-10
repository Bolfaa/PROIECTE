#include "Game.h"

void Game::Jucatori()
{
	string nume;
	string piesa;
	std::cout << "\033[32m";
	cout << "(";
	std::cout << "\033[33m";
	cout << "X";
	std::cout << "\033[32m";
	cout<<" SI ";
	std::cout << "\033[0m";
	cout << "0";
	std::cout << "\033[32m";
	cout<<")" << endl;
	
	cout << "Alegeti jucatorul 1 ";
	std::cout << "\033[0m";
	cout<<"(NUME) : "; cin >> nume;
	std::cout << "\033[32m";
	cout << "Alegeti jucatorul 1 ";
	std::cout << "\033[0m";
	cout<<"(PIESA) : "; cin >> piesa;
	
	Jucator* Bolfa = new Jucator(nume, piesa);
	nume.clear();
	piesa.clear();
	system("cls");
	
	std::cout << "\033[32m";
	cout << "(X SI 0)" << endl;
	cout << "Alegeti jucatorul 2 ";
	std::cout << "\033[0m";
	cout << "(NUME) : "; cin >> nume;
	std::cout << "\033[32m";
	cout << "Alegeti jucatorul 2 ";
	std::cout << "\033[0m";
	cout << "(PIESA) : "; cin >> piesa;
	
	Jucator* Mario = new Jucator(nume, piesa);
	
	X_O(Bolfa, Mario);
}

void Game::Joc()
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 20;
	cfi.dwFontSize.Y = 20;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	Jucatori();
}

void Game::Punctaj(Jucator* Bolfa,Jucator * Mario)
{
	string raspuns;
	cout << "(PUNCTAJ)" << endl;
	cout << "Vreti sa vedeti punctajul[Y/N]:"; cin >> raspuns;
	if (raspuns == "Y") {
		cout << "Jucatorul 1 (" << Bolfa->GetName() << ")" << "Are punctajul: (" << Bolfa->GetScor() << ")" << endl;
		cout << "Jucatorul 2 (" << Mario->GetName() << ")" << "Are punctajul: (" << Mario->GetScor() << ")" << endl;
	}
}

void Game::X_O(Jucator* Bolfa, Jucator* Mario)
{
	Tabela Tabla;
	int pozitie;
	Tabla.Add_Jucator(Bolfa);
	Tabla.Add_Jucator(Mario);
	int miscari = 0;
	Tabla.Print();
	while (!Tabla.Verifiare_Catigator(*Bolfa, *Mario,miscari) && miscari<8) {
		while (!Tabla.Adaugare_Piesa(*Bolfa));
		miscari++;
		Tabla.Print();
		if (!Tabla.Verifiare_Catigator(*Bolfa, *Mario, miscari)) {
			Tabla.Print();
			while (!Tabla.Adaugare_Piesa(*Mario));
			miscari++;
			Tabla.Print();
			Tabla.Verifiare_Catigator(*Bolfa, *Mario, miscari);
		}
		else
			break;
	}
	Punctaj(Bolfa, Mario);
	cout << "{Jocu s-a termiant}"<<endl;
}
