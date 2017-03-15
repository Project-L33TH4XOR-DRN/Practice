#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;


int width = 50;




void drawFloor()
{

	system("cls"); //clear terminal screen
	cout << "\n\n\n\n\n";
	for (int i = 0; i < width; i++)
		cout << "_";

	cout << endl;
	for(int j=0; j < width; j++)
		cout << "|";

	cout << endl << endl;

	cout << "\n";
	for (int i = 0; i < width; i++)
		cout << "_";
	cout << endl;

}

int drawChar()
{
        cout << " _()_   /\n";
//      myfile.open("weapon.cpp");
        cout << " ( ')  /\n";
        cout << " (  )o\\\n";
        cout << " (_)_)";


}


int main()
{
        system("cls");
        drawChar();

}





int main() 
{
	Draw();
	

}
