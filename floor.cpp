#include <iostream>
using namespace std;

<<<<<<< 4e3cb241afea885f1be33fe318628af074ecfb83

int width = 50;
=======
width = 50;
>>>>>>> test


void Draw()
{

	system("cls"); //clear terminal screen
<<<<<<< 4e3cb241afea885f1be33fe318628af074ecfb83
	cout << "\n\n\n\n\n";
	for (int i = 0; i < width; i++)
		cout << "_";

	cout << endl;
	for(int j=0; j < width; j++)
		cout << "|";

	cout << endl << endl;

=======
	cout << "\n";
	for (int i = 0; i < width; i++)
		cout << "_";
	cout << endl;
>>>>>>> test

}



int main() 
{
	Draw();
	

}
