

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <unistd.h>
using namespace std;

int inLoop = 1;
int width = 50;
char charCmd;
int weaponNumber = 0;
const int maxWeaponNumber = 4;
const string t = "_()_ ";
const string m = "( ') ";
const string b = "(  )o";
const string g = "(_)_)";
const string tw[] = {"", "|  ", "  /", "\\|/"};
const string mw[] = {"", "|  ", " / ", " Y "};
const string bw[] = {"", "|  ", "\\  ", " | "};
const string gw[] = {"", "|  ", "   ", " | "};

void drawChar();
void drawFloor();
void setWeapon(char type);
void reDraw();
void charAttack(char attack);

string top_of_char = t;
string mid_of_char = m;
string bot_of_char = b;
string gnd_of_char = g;
string top_of_weapon[maxWeaponNumber] = tw;
string mid_of_weapon[maxWeaponNumber] = mw;
string bot_of_weapon[maxWeaponNumber] = bw;
string gnd_of_weapon[maxWeaponNumber] = gw;
string top_attack;
string mid_attack;
string bot_attack;
string gnd_attack;

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

void drawFloor()
{

        cout << "\n";
        for (int i = 0; i < width; i++)
                cout << "_";
        cout << endl;

}



void drawChar()
{
	cout << top_of_char << top_of_weapon [weaponNumber]<< top_attack << "\n";
	cout << mid_of_char << mid_of_weapon [weaponNumber]<< mid_attack << "\n";
	cout << bot_of_char << bot_of_weapon [weaponNumber]<< bot_attack << "\n";
	cout << gnd_of_char << gnd_of_weapon [weaponNumber]<< gnd_attack;

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

void resetChar()
{
	top_of_char = t;
	mid_of_char = m;
	bot_of_char = b;
	gnd_of_char = g;
	for (int i = 0; i < maxWeaponNumber; i++)
	{
		top_of_weapon[i] = tw[i];
		mid_of_weapon[i] = mw[i];
		bot_of_weapon[i] = bw[i];
		gnd_of_weapon[i] = gw[i];
	}
	top_attack = "";
	mid_attack = "";
	bot_attack = "";
	gnd_attack = "";

}

void charAttack(char attack)
{
	if (attack == 'z')
	{	
		switch (weaponNumber)
		{
			case 0:
				if (bot_of_char == "(  )o")
				{
					bot_of_char = "(  )=o";
				}
				else
				{
					resetChar();
				}
		//		how to use wait function?
				break;
			case 1:
				if (mid_of_weapon[weaponNumber] == "|  ")
				{
				
					top_of_weapon[weaponNumber] = " | ";
					mid_of_weapon[weaponNumber] = " | ";
					bot_of_weapon[weaponNumber] = " | ";
					gnd_of_weapon[weaponNumber] = " | ";
					mid_attack = "   =O";
				}
				else
				{
					resetChar();
				}
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
			resetChar();
			if (weaponNumber < 3)
			{
				weaponNumber++;
			}
			else
				weaponNumber = 0;
			break;
		case 'e':
		case 'E':
			resetChar();
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
