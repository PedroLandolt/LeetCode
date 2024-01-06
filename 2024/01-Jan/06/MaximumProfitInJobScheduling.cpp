#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

#define vi vector<int>
#define vpii vector<pair<int, int>>

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        vpii jobs(n);
        
        for(int i = 0; i < n; i++){
            jobs[i] = {startTime[i], i};
        }

        sort(jobs.begin(), jobs.end());

        vi dp(n+1, 0);
        for(int i = n-1; i > -1; i--){
            dp[i] += max(
                dp[i+1],
                profit[jobs[i].second] + dp[lower_bound(jobs.begin(), jobs.end(), make_pair(endTime[jobs[i].second], 0)) - jobs.begin()]
            );
        }

        return dp[0];
    }
};


int main(){

    cout << "-------------------------- Tests --------------------------" << endl;
    cout << endl;

    Solution sol;

    int exOutput1 = 120;
    int exOutput2 = 150;
    int exOutput3 = 6;

    cout << "Solution: " << endl;
    cout << "Test 1: " << endl;
    cout << "Input:" << endl;
    cout << "startTime = [1,2,3,3]" << endl;
    cout << "endTime = [3,4,5,6]" << endl;
    cout << "profit = [50,10,40,70]" << endl;
    vi startTime1 = {1,2,3,3};
    vi endTime1 = {3,4,5,6};
    vi profit1 = {50,10,40,70};
    cout << "My Output: " << sol.jobScheduling(startTime1, endTime1, profit1) << endl;

    if(sol.jobScheduling(startTime1, endTime1, profit1) == exOutput1){
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
    cout << "Input: " << endl;
    cout << "startTime = [1,2,3,4,6]" << endl;
    cout << "endTime = [3,5,10,6,9]" << endl;
    cout << "profit = [20,20,100,70,60]" << endl;
    vi startTime2 = {1,2,3,4,6};
    vi endTime2 = {3,5,10,6,9};
    vi profit2 = {20,20,100,70,60};
    cout << "My Output: " << sol.jobScheduling(startTime2, endTime2, profit2) << endl;
    cout << endl;
    if(sol.jobScheduling(startTime2, endTime2, profit2) == exOutput2){
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
    cout << "Input: " << endl;
    cout << "startTime = [1,1,1]" << endl;
    cout << "endTime = [2,3,4]" << endl;
    cout << "profit = [5,6,4]" << endl;
    vi startTime3 = {1,1,1};
    vi endTime3 = {2,3,4};
    vi profit3 = {5,6,4};
    cout << "My Output: " << sol.jobScheduling(startTime3, endTime3, profit3) << endl;
    cout << endl;

    if(sol.jobScheduling(startTime3, endTime3, profit3) == exOutput3){
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
