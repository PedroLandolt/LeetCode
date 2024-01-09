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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vi nodeLeafs1, nodeLeafs2;

        getLeafs(root1, nodeLeafs1);
        getLeafs(root2, nodeLeafs2);

        return nodeLeafs1 == nodeLeafs2;
    }

private:
    void getLeafs(TreeNode* node, vi &leafs){

        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr){
            leafs.push_back(node->val);
        }

        getLeafs(node->left, leafs);
        getLeafs(node->right, leafs);
    }
};

int main(){
    cout << "-------------------------- Tests --------------------------" << endl;
    cout << endl;

    Solution sol;

    bool exOutput1 = true;
    bool exOutput2 = false;

    cout << "Solution: " << endl;
    cout << "Test 1: " << endl;
    cout << "Input: " << endl;
    cout << "root1 = [3,5,1,6,2,9,8,null,null,7,4]" << endl;
    cout << "root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]" << endl;
    TreeNode *num1 = new TreeNode(3);
    num1->left = new TreeNode(5);
    num1->right = new TreeNode(1);
    num1->left->left = new TreeNode(6);
    num1->left->right = new TreeNode(2);
    num1->left->right->left = new TreeNode(7);
    num1->left->right->right = new TreeNode(4);
    num1->right->left = new TreeNode(9);
    num1->right->right = new TreeNode(8);
    TreeNode *num2 = new TreeNode(3);
    num2->left = new TreeNode(5);
    num2->right = new TreeNode(1);
    num2->left->left = new TreeNode(6);
    num2->left->right = new TreeNode(7);
    num2->right->left = new TreeNode(4);
    num2->right->right = new TreeNode(2);
    num2->right->right->left = new TreeNode(9);
    num2->right->right->right = new TreeNode(8);
    cout << "My Output: " << sol.leafSimilar(num1, num2) << endl;

    if(sol.leafSimilar(num1, num2) == exOutput1){
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
    cout << "root1 = [1,2,3]" << endl;
    cout << "root2 = [1,3,2]" << endl;
    TreeNode *num3 = new TreeNode(1);
    num3->left = new TreeNode(2);
    num3->right = new TreeNode(3);
    TreeNode *num4 = new TreeNode(1);
    num4->left = new TreeNode(3);
    num4->right = new TreeNode(2);
    cout << "My Output: " << sol.leafSimilar(num3, num4) << endl;
    cout << endl;
    if(sol.leafSimilar(num3, num4) == exOutput2){
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