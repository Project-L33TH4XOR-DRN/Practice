

#include <iostream>
#include <fstream>
#include <curses.h>
#include <string>
using namespace std;

int width = 50;
string top_of_weapon;
string mid_of_weapon;
string bot_of_weapon;



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

void setWeapon(string type)

{

	if (type == "staff" || type == "Staff")
		{
			top_of_weapon = "|  ";
			mid_of_weapon = "|  ";
			bot_of_weapon = "|  ";
		}	
	else if (type == "sword" || type == "Sword")
		{
			top_of_weapon = " / ";
			mid_of_weapon = "/  ";
			bot_of_weapon = "\\  ";
		}

}

int main()
{
	clear;
	string wtype;
	cout << "Select Weapon Type\n";
	cin >> wtype;
	setWeapon(wtype);
	drawChar();
	drawFloor();

	return 0;
}
