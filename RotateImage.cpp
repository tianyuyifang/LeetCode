class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        //flip the matrix along the middle row;
        int up=0, down=n-1;
        while(up < down){
            for(int i=0; i<n; i++){
                swap(matrix[up][i], matrix[down][i]);
            }
            up++;
            down--;
        }
        //flip the matrix along x = y;
        int left = n-1, right = 1-n;
        while(left > right) {
            for(int i=0; i<=(n-1)-left; i++){
                swap(matrix[left+i][i], matrix[i][left+i]);
            }
            left--;
            right++;
        }
        return;
    }
};
//rotate ring by ring
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int up=0, down=n-1;
        while(up < down){
            for(int i=up; i<down; i++) {
                swap(matrix[up][i], matrix[i][down]);
                swap(matrix[down-i+up][up], matrix[up][i]);
                swap(matrix[down][down-i+up], matrix[down-i+up][up]);
            }
            up++;
            down--;
        }
        return;
    }
};
