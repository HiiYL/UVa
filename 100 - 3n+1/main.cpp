#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	unsigned long long a,b,lower_bound, upper_bound;
	unsigned long long cycle_count = 0;
	while(cin >> a >> b)
	{
		cycle_count = 0;
		lower_bound = min(a,b);
		upper_bound = max(a,b);
		unsigned long long curr_cycle_count = 0;
		for(unsigned long long i = lower_bound; i <= upper_bound; i++)
		{
			//cout << i << endl;
			curr_cycle_count = 1;
			unsigned long long j = i;
			while(j != 1)
			{
				if(j%2)
					j = 3*j + 1;
				else
					j = j/2;
				curr_cycle_count++;
			}
			if(curr_cycle_count > cycle_count)
				cycle_count = curr_cycle_count;
		}
		cout << a << " " << b << " " <<cycle_count << endl;
	}
}