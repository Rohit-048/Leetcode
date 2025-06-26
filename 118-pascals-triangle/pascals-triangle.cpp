class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result; 

        for(int i=0;i<numRows;i++){
             vector<int> row(i + 1, 1); // create a row of all 1's
            for(int j=1;j<i;j++){
                row[j]=result[i-1][j-1]+result[i-1][j]; // add the value of current and prev value from the previous result index
            }
           result.push_back(row);
        }
        return result;
    }
};