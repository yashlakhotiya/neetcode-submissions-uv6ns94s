/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid, int r1, int r2, int c1, int c2) {
        bool onePresent=false, zeroPresent=false, allSame = true;
        for(int i=r1; i<r2; i++) {
            for(int j=c1; j<c2; j++) {
                if(grid[i][j]) onePresent=true;
                else if(!grid[i][j]) zeroPresent=true;
                if(onePresent && zeroPresent) {
                    allSame = false; break;
                }
            }
        }
        if(allSame) {
            return new Node(grid[r1][c1], 1);
        }
        Node *node = new Node(1, 0);
        node->topLeft = construct(grid, r1, (r1+r2)/2, c1, (c1+c2)/2);
        node->topRight = construct(grid, r1, (r1+r2)/2, (c1+c2)/2, c2);
        node->bottomLeft = construct(grid, (r1+r2)/2, r2, c1, (c1+c2)/2);
        node->bottomRight = construct(grid, (r1+r2)/2, r2, (c1+c2)/2, c2);
        return node;

    }
    Node* construct(vector<vector<int>>& grid) {
        int ROWS=grid.size(), COLS=grid[0].size();
        return construct(grid, 0, ROWS, 0, COLS);
    }
};