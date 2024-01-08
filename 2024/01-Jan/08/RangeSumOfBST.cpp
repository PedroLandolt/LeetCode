/* Definition for a binary tree node. */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

#define vi vector<int>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if (root == nullptr) return 0;

        if (low <= root->val && root->val <= high){    
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        else if (root->val < low){ 
            return rangeSumBST(root->right, low, high);
        }
        else{ 
            return rangeSumBST(root->left, low, high);
        }
    }
};

int main(){

    cout << "-------------------------- Tests --------------------------" << endl;
    cout << endl;

    Solution sol;

    int exOutput1 = 32;
    int exOutput2 = 23;

    cout << "Solution: " << endl;
    cout << "Test 1: " << endl;
    cout << "Input: " << endl;
    cout << "root = [10,5,15,3,7,null,18], low = 7, high = 15" << endl;
    int low1 = 7;
    int high1 = 15;
    TreeNode *num1 = new TreeNode(10);
    num1->left = new TreeNode(5);
    num1->right = new TreeNode(15);
    num1->left->left = new TreeNode(3);
    num1->left->right = new TreeNode(7);
    num1->right->right = new TreeNode(18);
    cout << "My Output: " << sol.rangeSumBST(num1, low1, high1) << endl;

    if(sol.rangeSumBST(num1, low1, high1) == exOutput1){
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
    cout << "root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10" << endl;
    int low2 = 6;
    int high2 = 10;
    TreeNode *num2 = new TreeNode(10);
    num2->left = new TreeNode(5);
    num2->right = new TreeNode(15);
    num2->left->left = new TreeNode(3);
    num2->left->right = new TreeNode(7);
    num2->right->left = new TreeNode(13);
    num2->right->right = new TreeNode(18);
    num2->left->left->left = new TreeNode(1);
    num2->left->right->left = new TreeNode(6);
    cout << "My Output: " << sol.rangeSumBST(num2, low2, high2) << endl;
    cout << endl;
    if(sol.rangeSumBST(num2, low2, high2) == exOutput2){
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