#include "exercise.h"

void t1520()
{
    string s = "adefaddaccc";
    Solution1520 sol;
    vector<string> max = sol.maxNumOfSubstrings(s);
    for (auto x : max)
    {
        cout << x << endl;
    }
}
void t1979()
{
    vector<int> big = { 7, 5, 9, 0, 2, 1, 3, 5, 7, 9, 1, 1, 5, 8, 8, 9, 7 };
    vector<int> small = { 1, 5, 9 };
    //vector<int> big = { 1,2,3 };
    //vector<int> small = { 4 };
    Solution1979 s;
    vector<int> re = s.shortestSeq(big, small);
    for (auto x : re)
    {
        std::cout << x << endl;
    }
}

void t962()
{
    Solution962 s;
    vector<int> v = { 9,8,1,0,1,9,4,0,4,1 };
    cout << s.maxWidthRamp(v);
}