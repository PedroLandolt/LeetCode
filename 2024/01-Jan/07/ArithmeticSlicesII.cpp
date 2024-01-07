
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define umaplvi unordered_map<long, vector<int>>

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        vvi dp(n, vi(n, 0));
        umaplvi map;

        for (int i = 0; i < n; i++) {
            long temp = nums[i];
            if (!map.count(temp)) {
                map[temp] = vi();
            }
            map[temp].push_back(i);
        }

        int sum = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long a = 2L * nums[i] - nums[j];
                if (map.count(a)) {
                    for (int k : map[a]) {
                        if (k < i) {
                            dp[i][j] += dp[k][i] + 1;
                        } else {
                            break;
                        }
                    }
                }
                sum += dp[i][j];
            }
        }
        return sum;

    }
};

int main()
{

    cout << "-------------------------- Tests --------------------------" << endl;
    cout << endl;

    Solution sol;

    int exOutput1 = 7;
    int exOutput2 = 16;

    cout << "Solution: " << endl;
    cout << "Test 1: " << endl;
    cout << "Input: nums = [2,4,6,8,10]" << endl;
    vi num1 = {2,4,6,8,10};
    cout << "My Output: " << sol.numberOfArithmeticSlices(num1) << endl;

    if(sol.numberOfArithmeticSlices(num1) == exOutput1){
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
    cout << "Input: nums = [7,7,7,7,7]" << endl;
    vi num2 = {7,7,7,7,7};
    cout << "My Output: " << sol.numberOfArithmeticSlices(num2) << endl;
    cout << endl;
    if(sol.numberOfArithmeticSlices(num2) == exOutput2){
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