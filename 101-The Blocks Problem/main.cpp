#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
    int num_blocks;
    int counter = 0;
    cin >> num_blocks;
    vector< vector<int> > blocks;
    for(int i = 0 ; i < num_blocks; i++)
            blocks.push_back(vector<int>{i});
    string input;
    cin.ignore(1000, '\n');
    while(getline(cin,input) && input != "quit")
    {
        istringstream iss(input);
        string command_1;
        if(iss >> command_1)
        {
            int src, dest;
            vector<int>::iterator src_iterator, dest_iterator;
            int src_loc = 0, dest_loc = 0;
            string command_2;
            iss >> src >> command_2 >> dest;
            for(int i = 0 ; i < blocks.size() ; i++)
            {
               auto it = find(blocks[i].begin(), blocks[i].end(), src);
               if(it != blocks[i].end())
               {
                   src_iterator = it;
                   src_loc = i;
                   break;
               }
            }
            for(int i = 0 ; i < blocks.size() ; i++)
            {
               auto it = find(blocks[i].begin(), blocks[i].end(), dest);
               if(it != blocks[i].end())
               {
                   dest_iterator = it;
                   dest_loc = i;
                   break;
               }
            }
            if(src_loc != dest_loc)
            {
                if(command_1 == "move")
                {
                    for(int i = 0 ; i < blocks.size() ; i++)
                    {
                        auto it = find(blocks[i].begin(), blocks[i].end(), src);
                        if(it != blocks[i].end())
                        {
                            it++;
                            auto j = it;
                            for(; j != blocks[i].end(); j++)
                            {
                                blocks[*j].push_back(*j);
                            }
                            blocks[i].erase(it, blocks[i].end());
                            src_iterator = find(blocks[i].begin(), blocks[i].end(), src);
                            break;
                        }
                    }
                }
                if(command_2 == "onto")
                {
                    for(int i = 0 ; i < blocks.size() ; i++)
                    {
                        auto it = find(blocks[i].begin(), blocks[i].end(), dest);
                        if(it != blocks[i].end())
                        {
                            it++;
                            auto j = it;
                            for(; j != blocks[i].end(); j++)
                            {
                                blocks[*j].push_back(*j);
                            }
                            blocks[i].erase(it, blocks[i].end());
                            dest_iterator = find(blocks[i].begin(), blocks[i].end(), dest);
                            break;
                        }
                    }
                }
                blocks[dest_loc].insert(blocks[dest_loc].end(), src_iterator, blocks[src_loc].end());
                blocks[src_loc].erase(src_iterator, blocks[src_loc].end());
            }
        }
    }
    for (int i = 0 ; i < blocks.size() ; i ++)
            {
                cout << i << ":";
                for(int j = 0 ; j < blocks[i].size(); j++)
                    cout << " "<<  blocks[i][j];
                cout << endl;
            }
}
