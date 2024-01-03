#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

#define vi vector<int>
#define vs vector<string>


class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        vi allRows;
        int beams = 0;

        for(auto st : bank){
            int now = 0;
            for (auto num : st){
                if(num == '1'){
                    now++;
                }
            }
            if (now == 0) continue;
            else allRows.push_back(now);
        }

        if(allRows.size() > 1){
            for(int i = 1; i < allRows.size(); i++){
                beams += (allRows[i-1] * allRows[i]);
            }
            return beams;
        }
        else{
            return 0;
        }

    }
};

/*

Another solution (better one):

class Solution {
public:
    int numberOfBeams(std::vector<std::string>& bank) {
        int prevRowCount = 0;
        int total = 0;

        for (const std::string& row : bank) {
            int curRowCount = calc(row);
            if (curRowCount == 0)
                continue;

            total += curRowCount * prevRowCount;
            prevRowCount = curRowCount;
        }
        return total;
    }

private:
    int calc(const std::string& s) {
        int count = 0;
        for (char c : s)
            count += c - '0';

        return count;
    }
};

*/

int main()
{

    cout << "-------------------------- Tests --------------------------" << endl;
    cout << endl;

    Solution sol;

    int exOutput1 = 8;
    int exOutput2 = 0;

    cout << "Solution: " << endl;
    cout << "Test 1: " << endl;
    cout << "Input: matrix = [\"011001\",\"000000\",\"010100\",\"001000\"]" << endl;
    vs str1 = {"011001","000000","010100","001000"};
    cout << "My Output: " << sol.numberOfBeams(str1) << endl;

    if(sol.numberOfBeams(str1) == exOutput1){
        cout << "Result: " << endl;
        cout << "Expected Output: "<< exOutput1 << endl;
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
    cout << "Input: nums = [\"000\",\"111\",\"000\"]" << endl;
    vs str2 = {"000","111","000"};
    cout << "My Output: " << sol.numberOfBeams(str2) << endl;
    cout << endl;
    if(sol.numberOfBeams(str2) == exOutput2){
        cout << "Result: " << endl;
        cout << "Expected Output: "<< exOutput2 << endl;
        cout << "Success!" << endl;
        cout << endl;
    }
    else
    {
        cout << "Result: " << endl;
        cout << "Expected Output: "<< exOutput2 << endl;
        cout << "Fail!" << endl;
        cout << endl;
    }

    return 0;
}