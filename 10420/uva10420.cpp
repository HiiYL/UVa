#include <map>
#include <iostream>
#include <sstream> 
using namespace std;
int main()
{
	map<string, int> woman;
	int count;
	cin >> count;
	cin.ignore(1000,'\n');
	for (int i = 0 ; i < count; i++)
	{
		string line,country, lady;
		getline(cin, line);
		istringstream iss(line);
		iss >> country;
		woman[country]++;
	}
	for(auto &i : woman)
		cout << i.first << " " << i.second << endl;
}