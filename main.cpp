#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;


int width = 50;

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

	
	
	while( x = 1)
	{
		movement = getch();

		//switch(movement)

			if (movement == 'd' || movement == 'D')	
			{ 
					xCoord += 1;
					for (int i = 0; i < xCoord; i++)
						cout << "_";
					drawChar();
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
					for (int i = 0; i > xCoord; i--)
						cout << "_";
						drawChar();
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
	




int main() 
{
	system("cls"); //clear terminal screen
	cout << endl;

	drawFloor();	
}
