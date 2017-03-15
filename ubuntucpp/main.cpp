

#include <iostream>
#include <fstream>
#include <curses.h>
#include <string>
using namespace std;

int width = 50;
string top_of_weapon[3];
string mid_of_weapon[3];
string bot_of_weapon[3];



void drawFloor()
{

        cout << "\n";
        for (int i = 0; i < width; i++)
                cout << "_";
        cout << endl;

}



void drawChar()
{
	cout << " _()_ "<< top_of_weapon << "\n";
	cout << " ( ') "<< mid_of_weapon << "\n";
	cout << " (  )o"<< bot_of_weapon << "\n";
	cout << " (_)_)";

}

void setWeapon(char type[5])

{
	switch (type[5]){
	
		case "staff":
		case "Staff":
			top_of_weapon = "|  ";
			mid_of_weapon = "|  ";
			bot_of_weapon = "|  ";

		case "sword":
		case "Sword":
			top_of_weapon = "/  ";
			mid_of_weapon = "/  ";
			bot_of_weapon = "\\  ";
	}

}

int main()
{
	clear;
	char wtype[5];
	cout << "Select Weapon Type\n";
	cin >> wtype;
	setWeapon(wtype);
	drawChar();
	drawFloor();

	return 0;
}
