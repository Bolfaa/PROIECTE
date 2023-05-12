#include "SUPERBET.h"

void SUPERBET::Choose_Player()
{
	int Caracter = 0;
	Caracter = Choice();
    User = Users[Caracter-1];
}

void SUPERBET::Choose_Bet()
{
    //system("cls");
    int value;
    Sleep(100);
    cout << "             ------------------" << std::endl;
    cout << "             ------------------" << std::endl;
    cout << "                   $[BET]$"; cout << endl;
    cout << "                     "; cin >> value;;
    this->BET = value;
}

int SUPERBET::Choice()
{
    int val = 0;
    bool validInput = false;
    Names();
    while (!validInput)
    {
        if (GetAsyncKeyState('1') & 0x8000) // Verifică dacă a fost apăsată tasta 1
        {
            val = 1;
            validInput = true;
        }
        else if (GetAsyncKeyState('2') & 0x8000) // Verifică dacă a fost apăsată tasta 2
        {
            val = 2;
            validInput = true;
        }
        else if (GetAsyncKeyState('3') & 0x8000) // Verifică dacă a fost apăsată tasta 3
        {
            val = 3;
            validInput = true;
        }
        else if (GetAsyncKeyState('4') & 0x8000) // Verifică dacă a fost apăsată tasta 4
        {
            val = 4;
            validInput = true;
        }
        else if (GetAsyncKeyState('5') & 0x8000) // Verifică dacă a fost apăsată tasta 5
        {
            val = 5;
            validInput = true;
        }
        else if (GetAsyncKeyState('6') & 0x8000) // Verifică dacă a fost apăsată tasta 6
        {
            val = 6;
            validInput = true;
        }
        else if (GetAsyncKeyState('7') & 0x8000) // Verifică dacă a fost apăsată tasta 7
        {
            val = 7;
            validInput = true;
        }
        else if (GetAsyncKeyState('8') & 0x8000) // Verifică dacă a fost apăsată tasta 8
        {
            val = 8;
            validInput = true;
        }
        else if (GetAsyncKeyState('9') & 0x8000) // Verifică dacă a fost apăsată tasta 9
        {
            val = 9;
            validInput = true;
        }

        Sleep(100); // Așteaptă 10 milisecunde pentru a evita supraîncărcarea procesorului
    }
    return val;
}

void SUPERBET::Names()
{
    std::vector<std::string> table = { "", "", "", "", "", "", "", "", "" };
    std::string input;
    string aux;
    // Citim 9 string-uri de la tastatură
    for (int i = 0; i < 9; i++) {
        aux.clear();
        aux += '[';
        aux += (i+1) + '0';
        aux += ']';
        aux += Users[i]->GetOwner();
        table[i] = aux;
    }

    // Aflam lungimea maxima a string-urilor
    int max_length = 0;
    for (const auto& str : table) {
        max_length = max(max_length, static_cast<int>(str.length()));
    }

    // Afisam tabela
    std::cout << "$";
    for (int i = 0; i < max_length *3+8; i++) {
        std::cout << "-";
    }
    std::cout << "$" << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << "| ";
        for (int j = 0; j < 3; j++) {
            const auto& str = table[i * 3 + j];
            std::cout << str;
            for (int k = str.length(); k < max_length; k++) {
                std::cout << " ";
            }
            std::cout << " | ";
        }
        std::cout << std::endl;
    }

    std::cout << "$";
    for (int i = 0; i < max_length * 3 + 8; i++) {
        std::cout << "-";
    }
    std::cout << "$" << std::endl;
    cout << "       (1-9)[CHOOSE YOUR PLAYER](1-9)" << endl;
}

void SUPERBET::PLAY()
{
    Choose_Player();
    Choose_Bet();
    EGT Game(User,Casino,BET);
	while (!Game.Joc())
    {
        system("cls");
        Choose_Player();
        Choose_Bet();
		Game.Change_Bet(BET);
        Game.Change_User(User);
        Sleep(100);
        Game.Joc();
    }
}

void SUPERBET::Add_User(BankAccount<int>* User)
{
    Users.push_back(User);
}
