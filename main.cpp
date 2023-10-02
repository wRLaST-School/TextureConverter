#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
	}

	cout << endl;

	system("pause");
	
	return 0;
}