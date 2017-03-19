#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
#include <string>


int width = 50;


string mainCharacter[4] = {	"_()_   /\n",
							"( ')  /\n",
							"(  )o\\\n",
							"(_)_)"};



int drawChar()
{
	cout << " _()_   /\n";
//	myfile.open("weapon.cpp");
	cout << " ( ')  /\n";
	cout << " (  )o\\\n";
	cout << " (_)_)";

}


void drawFloor()
{
	int x = 1;
	int xCoord = 0;
	char movement;

	drawChar();

	for (int i = xCoord; i < width - 6; i++)
		cout << "_";

	cout << endl;
	for(int j = 0; j < width; j++)
		cout << "|";

	cout << endl << endl;

	
	
	while( x == 1)
	{
		movement = getch();

		//switch(movement)

			if (movement == 'd' || movement == 'D')	
			{ 
					xCoord += 1;
					system("cls");
					for (int i = 0; i < 4; i++)
						if ( i < 3)
							cout << mainCharacter[i].insert(0," ");
						else
		
							mainCharacter[3].insert(0,"_");
							cout << mainCharacter[3];
		
					for (int i = xCoord + 6; i < width; i++)
						cout << "_";
					cout << endl;
					
					for (int j = 0; j < width; j++)
						cout << "|";
					cout << endl << endl;
			}
			else if (movement == 'a'|| movement == 'A')
			{

					if (xCoord > 0)
					{
						xCoord -= 1;
						system("cls");
						for (int i = 0; i < 4; i++)
							if ( i < 3 )
								cout << mainCharacter[i].erase(xCoord,1);
							else
								
								mainCharacter[3].erase(xCoord,1);
								cout << mainCharacter[3];
			
						for (int i = xCoord + 6; i < width; i++)
							cout << "_";
						cout << endl;
						
						for (int j = 0; j < width; j++)
							cout << "|";
						cout << endl << endl;
					}
			}
					 
			else if (movement == 'q' || movement == 'Q')
			{
				x = 0;
			}

	}
}
	
void critter()
{
	cout << "@";
}




int main() 
{
	system("cls"); //clear terminal screen

	drawFloor();

	return 0;
}
/*#include <string>
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
const string topMP = " _______________ ";
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
void lightning ();
void moveSpells();
void deleteFarSpells();
//---------End Function Declaration-----------

string mainCharacter[4] = {t,m,b,g};
string charWeapon[4][maxWeaponNumber] = {tw,mw,bw,gw};
string attackAnimation[4];
string gameMessage;
int remainingHP = 15;
int remainingMP = 15;
int damageReceived;
string botHP = "|MMMMMMMMMMMMMMM|";
string botMP = "|MMMMMMMMMMMMMMM|";

int main()
{
	system("cls");
	cout << "\t\t\t\t   " << topHP << "\n";
        cout << "\t\t\t\tHP:" << botHP << "\n";
	cout << "\t\t\t\t   " << topMP << "\n";
	cout << "\t\t\t\tMP:" << botMP << "\n";
	cout << "\t\t\t\t" << gameMessage;
	cout << "\n\n\n";

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
		moveSpells();
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
			gameMessage = "   *Warning HP Low";
	}
	else
		botHP.append("______DEAD_____");
	botHP.append("|");
}

void setRemainingMP()
{
	botMP = "|";
	botMP.append("MMMMMMMMMMMMMMM",remainingMP);
	botMP.append("_______________",15-remainingMP);
	botMP.append("|");
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
	mainCharacter[0] = "     GG";
	mainCharacter[1] = "            ~";
	mainCharacter[2] = "         _()_";
	mainCharacter[3] = "(_)_)( o)(XX)";
	charWeapon[0][weaponNumber] = "";
	charWeapon[1][weaponNumber] = "";
	charWeapon[2][weaponNumber] = "";
	charWeapon[3][weaponNumber] = "";
	gameMessage = "   G A M E   O V E R";
	for (int i = 0; i < 4; i++)
		attackAnimation[i] = "";
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
	setRemainingMP();
	cout << "\t\t\t\t   " << topHP << "\n";
	cout << "\t\t\t\tHP:" << botHP << "\n";
	cout << "\t\t\t\t   " << topMP << "\n";
	cout << "\t\t\t\tMP:" << botMP << "\n";
	cout << "\t\t\t\t" << gameMessage;
	cout << "\n";
	if (damageReceived > 0)
		cout << "  " << damageReceived;
	cout << "\n\n";
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
					charWeapon[0][weaponNumber] = "     ";
					charWeapon[1][weaponNumber] = "     ";
					charWeapon[2][weaponNumber] = "|----";
					charWeapon[3][weaponNumber] = "     ";
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

void wind()
{
	attackAnimation[0].insert (0, "         ");
	attackAnimation[1].insert (0, "         ");
	attackAnimation[2].insert (0, "~  ~  ~  ");
	attackAnimation[3].insert (0, "         ");
	deleteFarSpells();
}

void fireball()
{
	attackAnimation[0].insert (0, ",,,   ,,,");
	attackAnimation[1].insert (0, "<_),,,<_)");
	attackAnimation[2].insert (0, "   <_)   ");
	attackAnimation[3].insert (0, "         ");
	deleteFarSpells();
}

void lightning()
{
	attackAnimation[0].insert (0, "/\\  /  \\/");
	attackAnimation[1].insert (0, "  \\/ /\\  ");
	attackAnimation[2].insert (0, "/\\  /  \\/");
	attackAnimation[3].insert (0, "  \\/ /\\  ");
	deleteFarSpells();
}

void moveSpells()
{
	for (int i = 0; i < 4; i++)
		attackAnimation[i].insert(0, "  ");
	deleteFarSpells();
}

void deleteFarSpells()
{
	if (attackAnimation[0].length() > 40)
	{
		for (int i = 0; i < 4; i++)
			attackAnimation[i].erase (40, attackAnimation[i].length()-40);
        }
}

void charSpell(char spell)
{
	if (spell == 'x')
	{
		switch (weaponNumber)
		{
			case 0:
				if (mainCharacter[2] == "(o )o")
				{
					angryFace();
					mainCharacter[2] = "(o )=L";
					if (remainingMP > 0)
					{
						remainingMP--;
						wind();
					}
					else
						gameMessage = "   *Not enough Mana";
				}
				else
				{
					resetChar();
				}
				break;
			case 1:
				if (charWeapon[1][weaponNumber] == "|  ")
				{
					angryFace();
					charWeapon[0][weaponNumber] = " |  ";
					charWeapon[1][weaponNumber] = " | ";
					charWeapon[2][weaponNumber] = "| ";
					charWeapon[3][weaponNumber] = " | ";
					mainCharacter[2] = "(  )=o";
					if (remainingMP > 1)
					{
						remainingMP -= 2;
						fireball();
					}
					else
						gameMessage = "   *Not enough Mana";
					
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
					charWeapon[0][weaponNumber] = "     ";						                                        charWeapon[1][weaponNumber] = "     ";
					charWeapon[2][weaponNumber] = "|----";
					charWeapon[3][weaponNumber] = "     ";
					if (remainingMP > 2)
					{
						remainingMP -= 3;
						lightning();
					}
					else
						gameMessage = "   *Not enough Mana";
				}
				else
				{
				        resetChar();
				}
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
*/