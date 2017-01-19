#include <iostream>
#include <vector>

using namespace std;

class RotateMatrix
{
public:
	vector<vector<int > > matrix;
	int n;
	RotateMatrix(int n_){
		n = n_;
		matrix = vector<vector<int> >(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				matrix[i][j] = i * n + j; 
			}
		}
	}

	void rotate(){
		for (int z = 0; z < n/2; ++z)
		{
			vector<int> top;
			vector<int> right;
			vector<int> down;
			vector<int> left;
			for (int i = 0; i < n - 2*z; ++i)
			{
				top.push_back(matrix[z][z + i]);
				right.push_back(matrix[z + i][n - z - 1]);
				down.push_back(matrix[n - z - 1][n - z - 1 - i]);
				left.push_back(matrix[n - z - 1 - i][z]);
			}
			for (int i = 0; i < n - 2*z; ++i)
			{
				matrix[z][z+i] = left[i];
				matrix[z + i][n - z - 1] = top[i];
				matrix[n - z - 1][n - z - 1 - i] = right[i];
				matrix[n - z - 1 - i][z] = down[i];
			}
		}

	}

	void print(){
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

};

int main(){
	RotateMatrix rm = RotateMatrix(4);
	rm.print();
	rm.rotate();
	rm.print();
}
