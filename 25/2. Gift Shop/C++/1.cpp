#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <filesystem>

#define FILENAME filesystem::path(__FILE__).stem().string()
#define LL long long

using namespace std;

int main()
{

    string outputFileName = FILENAME + "_output.txt";

    freopen("../input.txt", "r", stdin);
    freopen(outputFileName.c_str(), "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    string line;
    string cleanData;
    while (getline(cin, line))
    {
        for (const char &c : line)
        {
            if (isdigit(c) || c == '-' || c == ',')
            {
                cleanData += c;
            }
        }
    }

    vector<pair<LL, LL>> ranges;
    stringstream ss(cleanData);

    string range;
    while (getline(ss, range, ','))
    {
        if (range.empty())
        {
            continue;
        }
        size_t dashIdx = range.find('-');
        if (dashIdx == string::npos)
        {
            continue;
        }

        LL start = stoll(range.substr(0, dashIdx));
        LL end = stoll(range.substr(dashIdx + 1));

        ranges.push_back({start, end});
    }

    LL invalidSum = 0;

    for (const auto &pair : ranges)
    {
        for (LL s = pair.first; s <= pair.second; s++)
        {
            string num = to_string(s);
            int len = num.size();

            if (len % 2 != 0)
            {
                continue;
            }

            string firstHalf = num.substr(0, len / 2);
            string secondHalf = num.substr(len / 2);

            if (firstHalf == secondHalf)
            {
                invalidSum += s;
            }
        }
    }

    cout << invalidSum << "\n";
    return 0;
}