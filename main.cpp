

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
using namespace std;

int inLoop = 1;
int width = 50;
char charCmd;
int weaponNumber = 0;
string top_of_weapon[] = {"", "|  ", "  /", "\\|/"};
string mid_of_weapon[] = {"", "|  ", " / ", " Y "};
string bot_of_weapon[] = {"", "|  ", "\\  ", " | "};
string gnd_of_weapon[] = {"", "|  ", "   ", " | "};


void drawFloor()
{

        cout << "\n";
        for (int i = 0; i < width; i++)
                cout << "_";
        cout << endl;

}



void drawChar()
{
	cout << " _()_ "<< top_of_weapon [weaponNumber] << "\n";
	cout << " ( ') "<< mid_of_weapon [weaponNumber]<< "\n";
	cout << " (  )o"<< bot_of_weapon [weaponNumber]<< "\n";
	cout << " (_)_)"<< gnd_of_weapon [weaponNumber];

}

void setWeapon(char type)

{
	switch (type)
	{
		case 'r':
		case 'R':
			if (weaponNumber < 3)
			{
				weaponNumber++;
			}
			else
				weaponNumber = 0;
			break;
		case 'e':
		case 'E':
			if (weaponNumber > 0)
			{
				weaponNumber--;
			}
			else
				weaponNumber = 3;
			break;
		case 'q':
		case 'Q':
			inLoop = 0;
			break;
	
		default:
			break;
	}

}

int main()
{
	system("cls");
	cout << "\n\n\n\n\n\n\n";
	
	drawChar();
	drawFloor();
	cout << "Press e or r to change weapon" << endl;
	cout << "press q to exit" << endl;
	while (inLoop == 1)
	{
		charCmd = getch();
		system("cls");
		setWeapon(charCmd);
		cout << "\n\n\n\n\n\n\n";
		drawChar();
		drawFloor();
		cout << "Press e or r to change weapon"<< endl;
		cout << "Press q to exit" << endl;
	
	}

	return 0;
}
