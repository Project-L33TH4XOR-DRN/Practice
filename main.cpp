#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <unistd.h>
using namespace std;

const int maxWeaponNumber = 4;
const string t = "_()_";
const string m = "( \")";
const string b = "(o )o";
const string g = "(_)_)";
const string tw[] = {"", " |  ", "   /", "\\|/"};
const string mw[] = {"", " |  ", "  / ", " Y "};
const string bw[] = {"", "|  ", "\\  ", "| "};
const string gw[] = {"", "|", "", "|"};
const string topHP = " _______________ "; 			// 15x_
const string topMP = " _______________ ";
const string emptySlotInv[] = {"     ", "_____"};
const string smallPotion[] = {"  X  ","_(_)_"};

int inLoop = 1;
int width = 50;
char charCmd;
int weaponNumber = 0;
int xCoord = 0;
string mainCharacter[4] = {t,m,b,g};
string charWeapon[4][maxWeaponNumber] = {tw,mw,bw,gw};
string attackAnimation[4];
string gameMessage;
string spaceBeforeMC[4];
int charFeetLength = mainCharacter[3].length();
int remainingHP = 15;
int remainingMP = 15;
int damageReceived;
bool itemsInPossession[4] = {false, false, false, false};
string botHP = "|MMMMMMMMMMMMMMM|";
string botMP = "|MMMMMMMMMMMMMMM|";
bool attacking = false;
bool inventoryOpen = false;
string inventory[5] = {"\t     ", "\t     ", "\t     ", "\t     ", "\t     "};
string inventorySlot[4][2] = 
{
	{"     ","     "},
	{"_____","_____"},
	{"     ","     "},
	{"_____","_____"}
};

//----------Function Declaration--------------
void drawChar();
void drawFloor();
void setWeapon(char type);
void reDraw();
void resetChar();
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
void moveCharacter(char movement);
void charInventory(char invent);
void displayInventory();
void addSmallPot();
//---------End Function Declaration-----------


//-----------------Main-------------------------
int main()
{
	system("cls");
	cout << "\t\t" << inventory[0] << "\t   " << topHP << "\n";
	cout << "\t\t" << inventory[1] << "\tHP:" << botHP << "\n";
	cout << "\t\t" << inventory[2] << "\t   " << topMP << "\n";
	cout << "\t\t" << inventory[3] << "\tMP:" << botMP << "\n";
	cout << "\t\t" << inventory[4] << gameMessage;
	cout << "\n\n\n";
	drawChar();
	drawFloor();
	displayMessage();
	while (inLoop == 1)
	{
		charCmd = getch();
		switch (charCmd)
		{
			case 'e':
			case 'E':
			case 'r':
			case 'R':
			case 'q':
			case 'Q':
				setWeapon(charCmd);
				break;
			case 'a':
			case 'A':
			case 'd':
			case 'D':
				moveCharacter(charCmd);
				break;
			case 'z':
			case 'Z':
				charAttack(charCmd);
				break;
			case 'x':
			case 'X':
				charSpell(charCmd);
				break;
			case 'i':
			case 'I':
			case 'y':
			case 'Y':
			case 'u':
			case 'U':
			case 'h':
			case 'H':
			case 'j':
			case 'J':
				charInventory(charCmd);
				break;
			default:
				break;
		}
		reDraw();
		moveSpells();
    }
    return 0;
}
//----------------End Main------------------------

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
	cout << "use: a, d, e, r, z, x, i, q\n" << endl;
}

void moveCharacter(char movement)
{
	if (movement == 'd' || movement == 'D')	
	{ 
		xCoord += 1;
		resetChar();
		for (int i = 0; i < 4; i++)
			if ( i < 3)
				cout << spaceBeforeMC[i].insert(0," ");
			else
				spaceBeforeMC[3].insert(0,"_");
	}
	else if (movement == 'a'|| movement == 'A')
	{
		if (xCoord > 0)
		{
			xCoord -= 1;
			resetChar();
			for (int i = 0; i < 4; i++)
			{
				if ( i < 3 )
					cout << spaceBeforeMC[i].erase(xCoord,1);
				else
					spaceBeforeMC[3].erase(xCoord,1);
			}
		}
	}
	attacking = false;
}

void drawFloor()
{
	for (int i = 0; i < width - (charFeetLength + xCoord); i++)
		cout << "_";
	cout << endl;
	for(int j = 0; j < width; j++)
		cout << "|";
	cout << endl << endl;
}
	
void critter()
{
	cout << "@";
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
	gameMessage = "\t   G A M E   O V E R";
	charFeetLength = mainCharacter[3].length();
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
		cout << spaceBeforeMC[i] << mainCharacter[i] << charWeapon[i][weaponNumber] << attackAnimation[i];
		if (i != 3)
			cout << "\n";
	}	
}

void reDraw()
{
	system("cls");
    setRemainingHP();
	setRemainingMP();
	if (inventoryOpen)
		displayInventory();
	cout << "\t\t" << inventory[0] << "\t   " << topHP << "\n";
	cout << "\t\t" << inventory[1] << "\tHP:" << botHP << "\n";
	cout << "\t\t" << inventory[2] << "\t   " << topMP << "\n";
	cout << "\t\t" << inventory[3] << "\tMP:" << botMP << "\n";
	cout << "\t\t" << inventory[4] << gameMessage;
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
				if (!attacking)
				{
					angryFace();
					mainCharacter[2] = "(o )=o";
					attacking = true;
				}
				else
				{
					resetChar();
					attacking = false;
				}
		//		how to use wait function?
				break;
			case 1:
				if (!attacking)
				{
					angryFace();
					charWeapon[0][weaponNumber] = "  | ";
					charWeapon[1][weaponNumber] = " | ";
					charWeapon[2][weaponNumber] = "| ";
					charWeapon[3][weaponNumber] = " |";
					mainCharacter[2] = "(  )=o";
					attacking = true;
				}
				else
				{
					resetChar();
					attacking = false;
				}
				break;
			case 2:
				if (!attacking)
				{
					angryFace();
					charWeapon[0][weaponNumber] = "     ";
					charWeapon[1][weaponNumber] = "     ";
					charWeapon[2][weaponNumber] = "|----";
					charWeapon[3][weaponNumber] = "";
					attacking = true;
				}
				else
				{
					resetChar();
					attacking = false;
				}
				break;
			case 3:
				if (!attacking)
				{
					angryFace();
					charWeapon[0][weaponNumber] = "  \\ /";
					charWeapon[1][weaponNumber] = "  X_";
					charWeapon[2][weaponNumber] = "/  ";
					charWeapon[3][weaponNumber] = "/";
					mainCharacter[2] = "(  )=o";
					damageReceived = 2;
					takeDamage(damageReceived);
					attacking = true;
				}
				else
				{
					resetChar();
					attacking = false;
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
	attackAnimation[3].insert (0, "");
	deleteFarSpells();
}

void fireball()
{
	attackAnimation[0].insert (0, ",,,   ,,,");
	attackAnimation[1].insert (0, "<_),,,<_)");
	attackAnimation[2].insert (0, "   <_)   ");
	attackAnimation[3].insert (0, "");
	deleteFarSpells();
}

void lightning()
{
	attackAnimation[0].insert (0, "      /\\ ");
	attackAnimation[1].insert (0, "  /\\/  \\ ");
	attackAnimation[2].insert (0, "\\/      \\");
	attackAnimation[3].insert (0, "");
	deleteFarSpells();
}

void moveSpells()
{
	if (attackAnimation[0] != "")
	{
		for (int i = 0; i < 3; i++)
			attackAnimation[i].insert(0, "  ");
		deleteFarSpells();
	}
}

void deleteFarSpells()
{
	if (attackAnimation[0].length() > 40)
	{
		for (int i = 0; i < 3; i++)
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
				if (!attacking)
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
					attacking = true;
				}
				else
				{
					resetChar();
					attacking = false;
				}
				break;
			case 1:
				if (!attacking)
				{
					angryFace();
					charWeapon[0][weaponNumber] = "  | ";
					charWeapon[1][weaponNumber] = " | ";
					charWeapon[2][weaponNumber] = "| ";
					charWeapon[3][weaponNumber] = " |";
					mainCharacter[2] = "(  )=o";
					if (remainingMP > 1)
					{
						remainingMP -= 2;
						fireball();
					}
					else
						gameMessage = "   *Not enough Mana";
					attacking = true;
				}
				else
				{
					resetChar();
					attacking = false;
				}
				break;
			case 2:
				if (!attacking)
				{
                    angryFace();
                    charWeapon[0][weaponNumber] = "     ";						                                        
                    charWeapon[1][weaponNumber] = "     ";
					charWeapon[2][weaponNumber] = "|----";
					charWeapon[3][weaponNumber] = "";
					if (remainingMP > 2)
					{
						remainingMP -= 3;
						lightning();
					}
					else
						gameMessage = "   *Not enough Mana";
					attacking = true;
				}
				else
				{
				    resetChar();
				    attacking = false;
				}
				break;
			case 3:
				addSmallPot();
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

void charInventory (char invent)
{
	switch(invent)
	{
		case 'i':
			if (!inventoryOpen)
			{
				displayInventory();
				inventoryOpen = true;
			}
			else
			{
				for (int i = 0; i < 5; i++)
					inventory[i] = "\t     ";
				inventoryOpen = false;
			}
			break;
		case 'y':
			if (itemsInPossession[0] && remainingHP < 15)
			{
				itemsInPossession[0] = false;
				inventorySlot[0][0] = emptySlotInv[0];
				inventorySlot[1][0] = emptySlotInv[1];
				remainingHP++;
			}
			break;
		case 'u':
			if (itemsInPossession[1] && remainingHP < 15)
			{
				itemsInPossession[1] = false;
				inventorySlot[0][1] = emptySlotInv[0];
				inventorySlot[1][1] = emptySlotInv[1];
				remainingHP++;
			}
			break;
		case 'h':
			if (itemsInPossession[2] && remainingHP < 15)
			{
				itemsInPossession[2] = false;
				inventorySlot[2][0] = emptySlotInv[0];
				inventorySlot[3][0] = emptySlotInv[1];
				remainingHP++;
			}
			break;
		case 'j':
			if (itemsInPossession[3] && remainingHP < 15)
			{
				itemsInPossession[3] = false;
				inventorySlot[2][1] = emptySlotInv[0];
				inventorySlot[3][1] = emptySlotInv[1];
				remainingHP++;
			}
			break;
		default:
			break;
	}
}

void displayInventory()
{
	inventory[0] = " _Inventory_ ";
	for (int i = 0; i < 4; i++)
			inventory[i+1] = "|" + inventorySlot[i][0] + "|" + inventorySlot[i][1] + "|";
}

void addSmallPot()
{
	for (int i = 0; i < 4; i++)
	{
		if (!itemsInPossession[i])
		{
			if (i % 2 == 0)
			{
				inventorySlot[i][0] = smallPotion[0];
				inventorySlot[i+1][0] = smallPotion[1];
				itemsInPossession[i] = true;
				break;
			}
			else
			{
				inventorySlot[i-1][1] = smallPotion[0];
				inventorySlot[i][1] = smallPotion[1];
				itemsInPossession[i] = true;
				break;
			}
		}
	}
}

