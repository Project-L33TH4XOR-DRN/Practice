

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

int inLoop = 1;
int width = 50;
char charCmd;
int weaponNumber = 0;
string top_of_char = "_()_ ";
string mid_of_char = "( ') ";
string bot_of_char = "(  )o";
string gnd_of_char = "(_)_)";
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
	cout << top_of_char << top_of_weapon [weaponNumber]<< "\n";
	cout << mid_of_char << mid_of_weapon [weaponNumber]<< "\n";
	cout << bot_of_char << bot_of_weapon [weaponNumber]<< "\n";
	cout << gnd_of_char << gnd_of_weapon [weaponNumber];

}

void reDraw()
{
	system("cls");
        cout << "\n\n\n\n\n\n\n";
        drawChar();
        drawFloor();
        cout << "Press e or r to change weapon" << endl;
        cout << "Press q to exit" << endl;
}


void charAttack(char attack)
{
	if (attack == 'z')
	{	
		switch (weaponNumber)
		{
			case 0:
				bot_of_char = "(  )=o";
				reDraw;
				//how to wait?
				bot_of_char = "(  )o";
				reDraw;
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
		}

	}
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

//--------------------- MAIN --------------------------------

int main()
{
	system("cls");
	cout << "\n\n\n\n\n\n\n";
	
	drawChar();
	drawFloor();
	cout << "Press e or r to change weapon" << endl;
	cout << "Press q to exit" << endl;
	while (inLoop == 1)
	{
		charCmd = getch();
		setWeapon(charCmd);
		charAttack(charCmd);
		reDraw();
	
	}

	return 0;
}
