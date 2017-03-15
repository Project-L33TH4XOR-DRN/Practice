#include <iostream>
using namespace std;

int width = 30;


void Draw()
{

	system("cls"); //clear terminal screen
	for (int i = 0; i < width; i++)
		cout << "_";
	cout << endl;
	for(int j=0; j < width; j++)
		cout << "|";

}



int main() 
{
	Draw();
	

}
