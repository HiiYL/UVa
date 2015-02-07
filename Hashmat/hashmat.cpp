#include <iostream>
using namespace std;
int main()
{
	unsigned long hashmat = 0,opponent = 0;
	while(cin >> hashmat >> opponent)
	{
		if (opponent>hashmat)
			cout << opponent-hashmat << endl;
		else
			cout << hashmat-opponent << endl;
	}
}