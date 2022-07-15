class Solution {
public:
    bool valid(vector<vector<char>>& mat, int x, int y) {


        for(int i=0;i<9;i++)
        {
            if(i!=x and mat[i][y]==mat[x][y])
                return 0;
        }
        for(int j=0;j<9;j++)
        {
            if(j!=y and mat[x][j]==mat[x][y])
                return 0;
        }

        int subi=(x/3)*3;
        int subj=(y/3)*3;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(subi+i!=x and subj+j!=y and mat[subi+i][subj+j]==mat[x][y])
                    return 0;

        return 1;
    }


    bool isValidSudoku(vector<vector<char>>& mat) {

        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(mat[i][j]!='.'&&!valid(mat,i,j))
                    return 0;

    return 1;
    }
};
