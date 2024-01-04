#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

#define vi vector<int>
#define mapii unordered_map<int, int>

class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        mapii contNums;
        int count = 0;

        for(auto num : nums){
            contNums[num]++;
        }


        for(auto num : contNums){
            int number = num.second;
            if(number==1){
                return -1;
            }
            count += number/3;
            if(number%3){
                count++;
            }
        }

        return count;


    }
};


int main()
{

    cout << "-------------------------- Tests --------------------------" << endl;
    cout << endl;

    Solution sol;

    int exOutput1 = 4;
    int exOutput2 = -1;

    cout << "Solution: " << endl;
    cout << "Test 1: " << endl;
    cout << "Input: nums = [2,3,3,2,2,4,2,3,4]" << endl;
    vi num1 = {2,3,3,2,2,4,2,3,4};
    cout << "My Output: " << sol.minOperations(num1) << endl;

    if(sol.minOperations(num1) == exOutput1){
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
    cout << "Input: nums = [2,1,2,2,3,3]" << endl;
    vi num2 = {2,1,2,2,3,3};
    cout << "My Output: " << sol.minOperations(num2) << endl;
    cout << endl;
    if(sol.minOperations(num2) == exOutput2){
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