#pragma once
#include"CASINO.h"
class SUPERBET:public CASINO
{
	BankAccount<int>* Casino = new BankAccount<int>("RO263472785", 1000000, "Casino", "BCR", "---");
public:
	void Add_User(BankAccount<int>* User);
	void Choose_Player();
	void Choose_Bet();
	int Choice();
	void Names();
	void PLAY();
};

