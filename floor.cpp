#include <iostream>
using namespace std;

<<<<<<< HEAD
int width = 30;

=======
int width = 50;
>>>>>>> 11617ed6b573ff6aea1572e351cb7b288fd537b3

void Draw()
{

	system("cls"); //clear terminal screen
	cout << "\n\n\n\n\n";
	for (int i = 0; i < width; i++)
		cout << "_";
<<<<<<< HEAD
	cout << endl;
	for(int j=0; j < width; j++)
		cout << "|";
=======
	cout << endl << endl;
>>>>>>> 11617ed6b573ff6aea1572e351cb7b288fd537b3

}



int main() 
{
	Draw();
	

}
