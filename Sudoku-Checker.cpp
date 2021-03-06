#include<bits/stdc++.h>
using namespace std;
bool ValidSudoku(char board[9][9])
{
	map<int,map<int,int>>R;
    map<int,map<int,int>>B;
    map<int,map<int,int>>C;
    for(int i=0;i<9;i++)
        {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]!='-')
            {
                int n=board[i][j]-'0';
                if(R[i][n]==1)
                {
                    return false;
                }
                if(C[j][n]==1)
                {
                    return false;
                }
                int num=(i/3)*3 + j/3;
                if(B[num][n]==1)
                {
                    return false;
                }
                R[i][n]=1;
                C[j][n]=1;
                B[num][n]=1;
            }
        }
    }
    return true;
}
int main()
{
    cout<<"Sudoku-Checker"<<endl;
    cout<<"Enter the numbers of Sudoku following the given rules."<<endl;
    cout<<"Rule-1: Enter the numbers correctly in order to get the correct results."<<endl;
    cout<<"Rule-2: In place of blank place enter '-'."<<endl;
	char matrix[9][9];
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
            {
			char ch; cin>>ch;
			matrix[i][j]=ch;
            }
	}
	if(ValidSudoku(matrix))
        {
		cout<<"The given data represents Valid Sudoku."<<endl;
	}
	else
        {
		cout<<"The given data represents Invalid Sudoku."<<endl;
	}

}
