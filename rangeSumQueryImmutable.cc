class NumMatrix {
public:
    vector<vector<int> > imos;
    int row;
    int col;
    NumMatrix(vector<vector<int> > matrix) {
        row = matrix.size();
        if(row == 0) return;
        col = matrix[0].size();
        imos.resize(row);

        for (int i = 0; i < row; ++i)
        {
            imos[i].resize(col);
            for (int j = 0; j < col; ++j)
            {
                imos[i][j] = matrix[i][j];
            }
        }

        for (int i = 1; i < row; ++i)
        {
            imos[i][0] += imos[i-1][0];
        }

        for (int i = 1; i < col; ++i)
        {
            imos[0][i] += imos[0][i-1];
        }

        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < col; ++j)
            {
                imos[i][j] += imos[i-1][j] + imos[i][j-1] - imos[i-1][j-1];
            }
        }
        // for (int i = 0; i < row; ++i)
        // {
        //     for (int j = 0; j < col; ++j)
        //     {
        //         cout << imos[i][j] << " ";
        //     }
        //     cout << endl;
        // }

    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int a1 = 0;
        if(row1 > 0 && col1 > 0) a1 = imos[row1-1][col1-1];
        int a2 = 0;
        if(row1 > 0) a2 = imos[row1-1][col2];
        int a3 = 0;
        if(col1 > 0) a3 = imos[row2][col1 - 1];
        int a4 = imos[row2][col2];
        return a4 - a3 - a2 + a1;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
