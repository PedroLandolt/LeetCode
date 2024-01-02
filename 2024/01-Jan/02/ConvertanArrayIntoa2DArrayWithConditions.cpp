#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define pi pair<int,int>

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        vvi res;
        vi temp;
        vpi numbers;

        for (int i = 0; i < nums.size(); i++) {

            auto it = find_if(numbers.begin(), numbers.end(), [nums, i](const pi& p){ return p.first == nums[i];});
            if (it != numbers.end()){
                it->second++;
            }
            else{
                numbers.emplace_back(nums[i], 1);
            }
        }

        while(!numbers.empty()) {
            for(auto it = numbers.begin(); it != numbers.end(); it++){
                if(it->second > 0) {
                    temp.push_back(it->first);
                    it->second--;
                    if (it->second == 0) {
                        numbers.erase(it);
                        it--;
                    }
                }
            }
            res.push_back(temp);
            temp.clear();
        }

        return res;

    }
};

/*

Another Solution:

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& v) {
        unordered_map<int, int> um;
        for (auto &i : v){
            um[i]++;
        }
        vector<vector<int>> ans;
        while (!um.empty()) {
            vector<int> temp, toErase;
            for (auto &[f, s] : um) {
                temp.emplace_back(f);
                s--;
                if (s == 0)toErase.emplace_back(f);
            }
            ans.emplace_back(temp);
            for (auto &i : toErase){
                um.erase(i);
            }
        }
        return ans;
    }
};

This is the best solution for this exercise.

Time complexity:
O(n^2)

Space complexity:
O(n)

*/

int main()
{

    cout << "-------------------------- Tests --------------------------" << endl;
    cout << endl;

    Solution sol;

    vector<vector<int>> exOutput1 = {{1,3,4,2},{1,3},{1}};
    vector<vector<int>> exOutput2 = {{1,2,3,4}};

    cout << "Solution: " << endl;
    cout << "Test 1: " << endl;
    cout << "Input: nums = {1,3,4,1,2,3,1}" << endl;
    vector<int> num1 = {1, 3, 4, 1, 2, 3, 1};
    cout << "My Output: [";
    
    for (int i = 0; i < sol.findMatrix(num1).size(); i++) {
        cout << "[";
        for (int j = 0; j < sol.findMatrix(num1)[i].size(); j++) {
            cout << sol.findMatrix(num1)[i][j];
            if (j != sol.findMatrix(num1)[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i != sol.findMatrix(num1).size() - 1) {
            cout << ",";
        }
    }    
    cout << "]" << endl;
    cout << endl;
    if(sol.findMatrix(num1) == exOutput1){
        cout << "Result: " << endl;
        cout << "Expected Output: [[1,3,4,2],[1,3],[1]]" << endl;
        cout << "Success!" << endl;
        cout << endl;
    }
    else
    {
        cout << "Result: " << endl;
        cout << "Expected Output: [[1,3,4,2],[1,3],[1]]" << endl;
        cout << "Fail!" << endl;
        cout << endl;
    }

    cout << " ------- " << endl;
    cout << endl;
    
    cout << "Test 2: " << endl;
    cout << "Input: nums = [1,2,3,4]" << endl;
    vector<int> num2 = {1, 2, 3, 4};
    cout << "My Output: [";
    
    for (int i = 0; i < sol.findMatrix(num2).size(); i++) {
        cout << "[";
        for (int j = 0; j < sol.findMatrix(num2)[i].size(); j++) {
            cout << sol.findMatrix(num2)[i][j];
            if (j != sol.findMatrix(num2)[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i != sol.findMatrix(num2).size() - 1) {
            cout << ",";
        }
    }   
    cout << "]" << endl;
    cout << endl;
    if(sol.findMatrix(num2) == exOutput2){
        cout << "Result: " << endl;
        cout << "Expected Output: [[1,2,3,4]]" << endl;
        cout << "Success!" << endl;
        cout << endl;
    }
    else
    {
        cout << "Result: " << endl;
        cout << "Expected Output: [[1,2,3,4]]" << endl;
        cout << "Fail!" << endl;
        cout << endl;
    }

    return 0;
}