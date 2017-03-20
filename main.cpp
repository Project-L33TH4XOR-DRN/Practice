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
