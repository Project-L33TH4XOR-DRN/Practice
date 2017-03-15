#include <iostream>
using namespace std;

int width = 50;

void Draw()
{

	system("cls"); //clear terminal screen
	cout << "\n\n\n\n\n";
	for (int i = 0; i < width; i++)
		cout << "_";
	cout << endl << endl;

}



int main() 
{
	Draw();
	

}
