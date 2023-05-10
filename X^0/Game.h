#pragma once
#include"Tabela.h"
#include<windows.h>
class Game
{
public:
	void X_O(Jucator* Bolfa,Jucator* Mario);
	void Jucatori();
	void Joc();
	void Punctaj(Jucator* Bolfa, Jucator* Mario);
};

