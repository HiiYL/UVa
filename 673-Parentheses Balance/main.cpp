#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    string s;
    int counter = 0;
    cin >> counter;
    cin.ignore(1000, '\n');
    for(int i = 0 ; i < counter; i++)
    {
        stack<char> cstk;
        int j = 0 ,k = 0;
        getline(cin, s);
        for(auto &i : s)
        {
            if(i == '[' || i == '(')
                cstk.push(i);
            else
            {
                if(cstk.size()>0)
                {
                    if((i == ']' && cstk.top() == '[' )|| (i == ')' && cstk.top() == '('))
                        cstk.pop();
                    else
                        break;
                }
                else
                {
                    break;
                }
            }
        }
        if(cstk.size() == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
