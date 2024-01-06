#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

#define vi vector<int>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vi dp(n, 1);
        int maxVal = 1;

        for(int i = 1; i < n; i++){
            for(int j = 0; j <i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        for(auto x : dp){
            if(x > maxVal){
                maxVal = x;
            }
        }

        return maxVal;

    }
};


/*

My solution is O(n^2) time complexity and O(n) space complexity.
But there is a better solution with O(nlogn) time complexity and O(n) space complexity.

Here is the explanation:

int lengthOfLIS(vector<int>& nums){
 
    // Binary search approach
    int n = nums.size();
    vector<int> ans;
 
    // Initialize the answer vector with the
    // first element of nums
    ans.push_back(nums[0]);
 
    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back()) {
 
            // If the current number is greater
            // than the last element of the answer
            // vector, it means we have found a
            // longer increasing subsequence.
            // Hence, we append the current number
            // to the answer vector.
            ans.push_back(nums[i]);
        }
        else {
 
            // If the current number is not
            // greater than the last element of
            // the answer vector, we perform
            // a binary search to find the smallest
            // element in the answer vector that
            // is greater than or equal to the
            // current number.
 
            // The lower_bound function returns
            // an iterator pointing to the first
            // element that is not less than
            // the current number.
            int low = lower_bound(ans.begin(), ans.end(),
                                  nums[i])
                      - ans.begin();
 
            // We update the element at the
            // found position with the current number.
            // By doing this, we are maintaining
            // a sorted order in the answer vector.
            ans[low] = nums[i];
        }
    }
 
    // The length of the answer vector
    // represents the length of the
    // longest increasing subsequence.
    return ans.size();
}

*/

int main()
{

    cout << "-------------------------- Tests --------------------------" << endl;
    cout << endl;

    Solution sol;

    int exOutput1 = 4;
    int exOutput2 = 4;
    int exOutput3 = 1;

    cout << "Solution: " << endl;
    cout << "Test 1: " << endl;
    cout << "Input: nums = [10,9,2,5,3,7,101,18]" << endl;
    vi num1 = {10,9,2,5,3,7,101,18};
    cout << "My Output: " << sol.lengthOfLIS(num1) << endl;

    if(sol.lengthOfLIS(num1) == exOutput1){
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
    cout << "Input: nums = [0,1,0,3,2,3]" << endl;
    vi num2 = {0,1,0,3,2,3};
    cout << "My Output: " << sol.lengthOfLIS(num2) << endl;
    cout << endl;
    if(sol.lengthOfLIS(num2) == exOutput2){
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

    cout << " ------- " << endl;
    cout << endl;

    cout << "Test 3: " << endl;
    cout << "Input: nums = [7,7,7,7,7,7,7]" << endl;
    vi num3 = {7,7,7,7,7,7,7};
    cout << "My Output: " << sol.lengthOfLIS(num3) << endl;
    cout << endl;

    if(sol.lengthOfLIS(num3) == exOutput3){
        cout << "Result: " << endl;
        cout << "Expected Output: "<< exOutput3 << endl;
        cout << "Success!" << endl;
        cout << endl;
    }
    else
    {
        cout << "Result: " << endl;
        cout << "Expected Output: "<< exOutput3 << endl;
        cout << "Fail!" << endl;
        cout << endl;
    }

    return 0;
}