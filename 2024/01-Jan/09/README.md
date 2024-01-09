# **872. Leaf-Similar Trees** ([Go to LeetCode](https://leetcode.com/problems/leaf-similar-trees))

#### __Difficulty:__ **<span style="color:green">Easy</span>**

#### __Date__: January 9, 2021
## **Description:** 

Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.

![Leaf-Similar1](images/tree.png)

For example, in the given tree above, the leaf value sequence is `(6, 7, 4, 9, 8)`.

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return `true` if and only if two given trees with head nodes `root1` and `root2` are leaf-similar.

## **Exemple 1:**

![Leaf-Similar2](images/leaf-similar-1.jpg)

**Input:** root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]

**Output:** true

## **Exemple 2:**

![Leaf-Similar3](images/leaf-similar-2.jpg)

**Input:** root1 = [1,2,3], root2 = [1,3,2]

**Output:** false

## Constraints:

- The number of nodes in each tree will be in the range `[1, 200]`.
- Both of the given trees will have values in the range `[0, 200]`.