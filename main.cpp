

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
const string m = "( \") ";
const string b = "(o )o";
const string g = "(_)_)";
const string tw[] = {"", "|  ", "  /", "\\|/"};
const string mw[] = {"", "|  ", " / ", " Y "};
const string bw[] = {"", "|  ", "\\  ", " | "};
const string gw[] = {"", "|  ", "   ", " | "};
const string topHP = " _______________ "; 			// 15x_

//----------Function Declaration--------------
void drawChar();
void drawFloor();
void setWeapon(char type);
void reDraw();
void charAttack(char attack);
void displayMessage();
void setRemainingHP();
void angryFace();
void takeDamage(int dmg);
void setCharDead();
void charSpell(char spell);
void fireball();
//---------End Function Declaration-----------

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
string gameMessage;
int timeTick = 0;
int remainingHP = 15;
int damageReceived;
string botHP = "|MMMMMMMMMMMMMMM|";

int main()
{
	system("cls");
	cout << "\t\t\t\t   " << topHP << "\n";
        cout << "\t\t\t\tHP:" << botHP << "\n";
	cout << "\t\t\t\t" << gameMessage;
	cout << "\n\n\n\n\n";

	drawChar();
        drawFloor();
	displayMessage();
	while (inLoop == 1)
	{
	        charCmd = getch();
	        setWeapon(charCmd);
	        charAttack(charCmd);
		charSpell(charCmd);
	        reDraw();
		timeTick++;
        }
															        return 0;
}

void setRemainingHP()
{
	botHP = "|";
	if (remainingHP > 0)
	{
		botHP.append("MMMMMMMMMMMMMMM",remainingHP);
		botHP.append("_______________",15-remainingHP);
		if (remainingHP < 2)
			gameMessage = "*Warning HP Low";
	}
	else
		botHP.append("______DEAD_____");
	botHP.append("|");
}

void takeDamage(int dmg)
{
	if (remainingHP > dmg)
		remainingHP -= dmg;
	else
	{
		remainingHP = 0;
		setCharDead();
	}
}

void displayMessage()
{
	cout << "z to attack, x to cast spell" << endl; 
	cout << "e or r to change weapon" << endl;
	cout << "q to quit" << endl;
}

void drawFloor()
{

        cout << "\n";
        for (int i = 0; i < width; i++)
                cout << "_";
        cout << endl;

}

void setCharDead()
{
	top_of_char = "      GG";
	mid_of_char = "";
	bot_of_char = "         _()_";
	gnd_of_char = "(_)_)( o)(XX)";
	top_of_weapon[weaponNumber] = "";
	mid_of_weapon[weaponNumber] = "";
	bot_of_weapon[weaponNumber] = "";
	gnd_of_weapon[weaponNumber] = "";
	damageReceived = 0;
	inLoop = 0;

}

void angryFace()
{
	mid_of_char = "(><) ";
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
        setRemainingHP();
	cout << "\t\t\t\t   " << topHP << "\n";
	cout << "\t\t\t\tHP:" << botHP << "\n";
	cout << "\t\t\t\t" << gameMessage;
	cout << "\n\n";
	if (damageReceived > 0)
		cout << "  " << damageReceived;
	cout << "\n\n\n";
        drawChar();
        drawFloor();
	displayMessage();
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
	damageReceived = 0;
}

void charAttack(char attack)
{
	if (attack == 'z')
	{	
		switch (weaponNumber)
		{
			case 0:
				if (bot_of_char == "(o )o")
				{
					angryFace();
					bot_of_char = "(o )=o";
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
					angryFace();
					top_of_weapon[weaponNumber] = "   /";
					mid_of_weapon[weaponNumber] = "  / ";
					bot_of_weapon[weaponNumber] = "/ ";
					gnd_of_weapon[weaponNumber] = "/ ";
					bot_of_char = "(  )=o";
				}
				else
				{
					resetChar();
				}
				break;
			case 2:
				if (mid_of_weapon[weaponNumber] == " / ")
				{
					angryFace();
					top_of_weapon[weaponNumber] = "   ";
					mid_of_weapon[weaponNumber] = "   ";
					bot_of_weapon[weaponNumber] = "|----";
					gnd_of_weapon[weaponNumber] = "   ";
				}
				else
				{
					resetChar();
				}
				break;
			case 3:
				if (mid_of_weapon[weaponNumber] == " Y ")
				{
					angryFace();
					top_of_weapon[weaponNumber] = " \\ /";
					mid_of_weapon[weaponNumber] = "  X_";
					bot_of_weapon[weaponNumber] = "/  ";
					gnd_of_weapon[weaponNumber] = "/   ";
					bot_of_char = "(  )=o";
					damageReceived = 2;
					takeDamage(damageReceived);
				}
				else
				{
					resetChar();

				}
				break;
		}

	}
}

void fireball()
{
	mid_attack.insert (0, "<_)");

}

void charSpell(char spell)
{
	if (spell == 'x')
	{
		switch (weaponNumber)
		{
			case 0:
				break;
			case 1:
				if (mid_of_weapon[weaponNumber] == "|  ")
				{
					angryFace();
					top_of_weapon[weaponNumber] = " | ";
					mid_of_weapon[weaponNumber] = " | ";
					bot_of_weapon[weaponNumber] = "| ";
					gnd_of_weapon[weaponNumber] = " | ";
					bot_of_char = "(  )=o";
					fireball();
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
