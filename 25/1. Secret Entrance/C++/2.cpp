#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

#define MOD 100

int main()
{
    int val = 50;
    int zero_crossing = 0;

    freopen("../input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
    string word;

    while (cin >> word)
    {
        char direction = word[0];
        int num = stoi(word.substr(1));

        int step = 0;

        if (direction == 'R')
        {
            step = 1;
        }
        else if (direction == 'L')
        {
            step = -1;
        }

        for (int i = 0; i < num; i++)
        {
            val = (val + step + MOD) % MOD;
            if (val == 0)
            {
                zero_crossing++;
            }
        }
    }

    cout << zero_crossing;
    return 0;
}