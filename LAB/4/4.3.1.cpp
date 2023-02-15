#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
using namespace std;

int main() 
{
    vector<string> input_line;
    list<float> numbers;
    map<string, float> pairs;
    string input;
    string tmp;

    cout << "Enter the list of word and number: " << endl;
    getline(cin, input);
    stringstream stream(input);
    while (getline(stream, tmp, ' ')) 
    {
        input_line.push_back(tmp);
    }

    for(int i = 0; i < input_line.size(); ++i) 
    {
        if (i % 2 == 0) 
        {
            if (pairs.find(input_line[i]) != pairs.end())
            {
                pairs[input_line[i]] += (stof(input_line[i + 1]));
            }
            else
            {
                pairs[input_line[i]] = stof(input_line[i + 1]);
            }
        }
    }

    for (auto pair: pairs)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

}
