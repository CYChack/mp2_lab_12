#include <iostream>
#include "text.h"
#include "text_node.h"

 using namespace std;

int main()
{

	char* temp = "Qwerty. \n Asd fgh zxc.\n";
	TText A(temp);
	TTextIter B = A.Find("y");

	A.InsertLine("lol", B);

	cout << endl << A;
	return 0;

}
