class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow=false, firstCol=false;
        int rows=matrix.size(), col=matrix[0].size();

        // checking if the first row is 0
        for(int i=0;i<col;i++){
            if(matrix[0][i]==0){
                firstRow=true;
                break;
            }
        }

        // checking if the first col is 0
        for(int i=0;i<rows;i++){
            if(matrix[i][0]==0){
                firstCol=true;
                break;
            }
        }

        // now checking and marking all the rows and cols where 0 occurs
        for(int i=1;i<rows;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0; 
                    matrix[i][0]=0;
                }
            }
        }
        // now making all zeros
        for(int i=1;i<rows;i++){
            for(int j=1;j<col;j++){
                if(matrix[0][j]==0||matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        // now making 0 for first row and col
        if(firstRow){
            for(int i=0;i<col;i++){
                matrix[0][i]=0;
            }
        }

        if(firstCol){
            for(int i=0;i<rows;i++){
                matrix[i][0]=0;
            }
         }

    }
};