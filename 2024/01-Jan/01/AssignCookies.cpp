#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int given = 0;
        int cookie = s.size() - 1;
        int child = g.size() - 1;

        while (child >= 0 && cookie >= 0)
        {
            if (g[child] <= s[cookie])
            {
                given++;
                child--;
                cookie--;
            }
            else
            {
                child--;
            }
        }

        return given;
    }
};

int main()
{

    cout << "-------------------------- Tests --------------------------" << endl;
    cout << endl;

    Solution sol;

    int exOutput1 = 1;
    int exOutput2 = 2;

    cout << "Solution: " << endl;
    cout << "Test 1: " << endl;
    cout << "Input: g = [1,2,3], s = [1,1]" << endl;
    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};
    cout << "My Output: " << sol.findContentChildren(g1, s1) << endl;
    cout << endl;
    if(sol.findContentChildren(g1, s1) == exOutput1){
        cout << "Result: " << endl;
        cout << "Expected Output: " << exOutput1 << endl;
        cout << "Success!" << endl;
        cout << endl;
    }
    else
    {
        cout << "Result: " << endl;
        cout << "Expected Output: " << exOutput1 << endl;
        cout << "Fail!" << endl;
        cout << endl;
    }

    cout << " ------- " << endl;
    cout << endl;
    
    cout << "Test 2: " << endl;
    cout << "Input: g = [1,2], s = [1,2,3]" << endl;
    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};
    cout << "My Output: " << sol.findContentChildren(g2, s2) << endl;
    cout << endl;
    if(sol.findContentChildren(g2, s2) == exOutput2){
        cout << "Result: " << endl;
        cout << "Expected Output: " << exOutput2 << endl;
        cout << "Success!" << endl;
        cout << endl;
    }
    else
    {
        cout << "Result: " << endl;
        cout << "Expected Output: " << exOutput2 << endl;
        cout << "Fail!" << endl;
        cout << endl;
    }

    return 0;
}
