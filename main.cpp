

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
//---------End Function Declaration-----------

string mainCharacter[4] = {t,m,b,g};
//string top_of_char = t;
//string mid_of_char = m;
//string bot_of_char = b;
//string gnd_of_char = g;
string charWeapon[4][maxWeaponNumber] = {tw,mw,bw,gw};
//string top_of_weapon[maxWeaponNumber] = tw;
//string mid_of_weapon[maxWeaponNumber] = mw;
//string bot_of_weapon[maxWeaponNumber] = bw;
//string gnd_of_weapon[maxWeaponNumber] = gw;
string attackAnimation[4];
//string top_attack;
//string mid_attack;
//string bot_attack;
//string gnd_attack;
string gameMessage;
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
	        reDraw();
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
	cout << "z to attack" << endl; 
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
	mainCharacter[0] = "     GG";
	mainCharacter[1] = "            ~";
	mainCharacter[2] = "         _()_";
	mainCharacter[3] = "(_)_)( o)(XX)";
	charWeapon[0][weaponNumber] = "";
	charWeapon[1][weaponNumber] = "";
	charWeapon[2][weaponNumber] = "";
	charWeapon[3][weaponNumber] = "";
	damageReceived = 0;
	inLoop = 0;

}

void angryFace()
{
	mainCharacter[1] = "(><) ";
}

void drawChar()
{
	for (int i = 0; i < 4; i++)
	{
		cout << mainCharacter[i] << charWeapon[i][weaponNumber] << attackAnimation[i];
		if (i != 3)
			cout << "\n";
	}	
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
	mainCharacter[0] = t;
	mainCharacter[1] = m;
	mainCharacter[2] = b;
	mainCharacter[3] = g;
	for (int i = 0; i < maxWeaponNumber; i++)
	{
		charWeapon[0][i] = tw[i];
		charWeapon[1][i] = mw[i];
		charWeapon[2][i] = bw[i];
		charWeapon[3][i] = gw[i];
	}
	for (int j  = 0; j < 4; j++)
		attackAnimation[j] = "";
	damageReceived = 0;
}

void charAttack(char attack)
{
	if (attack == 'z')
	{	
		switch (weaponNumber)
		{
			case 0:
				if (mainCharacter[2] == "(o )o")
				{
					angryFace();
					mainCharacter[2] = "(o )=o";
				}
				else
				{
					resetChar();
				}
		//		how to use wait function?
				break;
			case 1:
				if (charWeapon[1][weaponNumber] == "|  ")
				{
					angryFace();
					charWeapon[0][weaponNumber] = " | ";
					charWeapon[1][weaponNumber] = " | ";
					charWeapon[2][weaponNumber] = "| ";
					charWeapon[3][weaponNumber] = " | ";
					mainCharacter[2] = "(  )=o";
					attackAnimation[1] = "   =O";
				}
				else
				{
					resetChar();
				}
				break;
			case 2:
				if (charWeapon[1][weaponNumber] == " / ")
				{
					angryFace();
					charWeapon[0][weaponNumber] = "   ";
					charWeapon[1][weaponNumber] = "   ";
					charWeapon[2][weaponNumber] = "|----";
					charWeapon[3][weaponNumber] = "   ";
				}
				else
				{
					resetChar();
				}
				break;
			case 3:
				if (charWeapon[1][weaponNumber] == " Y ")
				{
					angryFace();
					charWeapon[0][weaponNumber] = " \\ /";
					charWeapon[1][weaponNumber] = "  X_";
					charWeapon[2][weaponNumber] = "/  ";
					charWeapon[3][weaponNumber] = "/   ";
					mainCharacter[2] = "(  )=o";
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
