// Course   : CS213 - Programming II  - 2018
// Title    : Assignment I - Task 1 - Problem 2
// Program  : CS213-2018-A1-T1-P2
// Purpose  : Skeleton code for the student to start working
/// Author 1 : Abdelrahman ibrahim ibrahim el sayed
// Date     : 9 Oct 2018
// Version  : 1.0

#include <iostream>
#include <iomanip>
//#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
  int** data;       // Pointer to 2-D array that will simulate matrix
  int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);
void setMatrix(int r,int c,matrix &mat);
// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
					    // new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
					     // matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
       	// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
       // and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
       	// Print matrix  as follows (2 x 3)			4	 6 	  8
        // and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
  int data1 [] = {1,2,3,4,5,6,7,8};
  int data2 [] = {13,233,3,4,5,6,5,6};
  int data3 [] = {10,100,10,100,10,100,10,100};
  int data4[]={1,0,3,1};
  int data5[]={1,2,3,4};

  matrix mat1, mat2, mat3,mat4,mat5;
  createMatrix (4, 2, data1, mat1);
  createMatrix (2, 4, data2, mat2);
  createMatrix (4, 2, data3, mat3);
  createMatrix(2,2,data4,mat4);
  createMatrix(2,2,data5,mat5);

  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;

  cout << (mat1 + mat3) << endl << endl;
  cout << (mat3 + mat3) << endl << endl;

  ++mat1;
  cout << mat1 << endl;

  mat1+= mat3 += mat3;
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;
  // Add more examples of using matrix
  // .......


cout<<transpose(mat4);
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data = new int* [row];

  for (int i = 0; i < row; i++)
    mat.data[i] = new int [col];

  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      mat.data[i][j] = num[i * col + j];
}
void setMatrix(int r,int c,matrix &mat)
{
  mat.row = r;
  mat.col = c;
  mat.data = new int* [r];

  for (int i = 0; i < r; i++)
    mat.data[i] = new int [c];
}

ostream& operator<< (ostream& out, matrix mat)
{
    for(int i=0;i<mat.row;++i)
    {
        for(int j=0;j<mat.col;++j)
        {
            out<<mat.data[i][j]<<" ";
        }
        out<<endl;
    }
    return out;
}
matrix operator+  (matrix mat1, matrix mat2)
{
    matrix ans;
    setMatrix(mat1.row,mat1.col,ans);
    for(int i=0;i<mat1.row;++i)
    {
        for(int j=0;j<mat1.col;++j)
        {
            ans.data[i][j]=mat1.data[i][j]+mat2.data[i][j];
        }
    }
    return ans;
}
matrix operator-  (matrix mat1, matrix mat2)
{
    matrix ans;
    setMatrix(mat1.row,mat1.col,ans);
    for(int i=0;i<mat1.row;++i)
    {
        for(int j=0;j<mat1.col;++j)
        {
            ans.data[i][j]=mat1.data[i][j]-mat2.data[i][j];
        }
    }
    return ans;
}
matrix operator*  (matrix mat1, matrix mat2)
{
    matrix ans;
    ans.row=mat1.row;
    ans.col=mat2.col;
    ans.data=new int* [mat1.row];
    for (int i = 0; i < mat1.row; i++)
    ans.data[i] = new int [mat2.col];

    for(int i = 0; i <mat1.row; ++i)
    {
        for(int j = 0; j <mat2.col; ++j)
        {
            for(int k = 0; k <mat1.col; ++k)
            {
                ans.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
            }
        }
    }
    return ans;
}
matrix operator+  (matrix mat1, int scalar)
{
    matrix ans;
    setMatrix(mat1.row,mat1.col,ans);
    for(int i=0;i<mat1.row;++i)
    {
        for(int j=0;j<mat1.col;++j)
        {
            ans.data[i][j]=mat1.data[i][j]+scalar;
        }
    }
    return ans;
}
matrix operator-  (matrix mat1, int scalar)
{
    matrix ans;
    setMatrix(mat1.row,mat1.col,ans);
    for(int i=0;i<mat1.row;++i)
    {
        for(int j=0;j<mat1.col;++j)
        {
            ans.data[i][j]=mat1.data[i][j]-scalar;
        }
    }
    return ans;
}
matrix operator*  (matrix mat1, int scalar)
{
    matrix ans;
    setMatrix(mat1.row,mat1.col,ans);
    for(int i=0;i<mat1.row;++i)
    {
        for(int j=0;j<mat1.col;++j)
        {
            ans.data[i][j]=mat1.data[i][j]*scalar;
        }
    }
    return ans;
}
matrix operator+= (matrix& mat1, matrix mat2)
{
    for(int i=0;i<mat1.row;++i)
    {
        for(int j=0;j<mat1.col;++j)
        {
            mat1.data[i][j]+=mat2.data[i][j];
        }
    }
    return mat1;
}
matrix operator-= (matrix& mat1, matrix mat2)
{
    for(int i=0;i<mat1.row;++i)
    {
        for(int j=0;j<mat1.col;++j)
        {
            mat1.data[i][j]-=mat2.data[i][j];
        }
    }
    return mat1;
}
matrix operator+= (matrix& mat1,int scalar)
{
    for(int i=0;i<mat1.row;++i)
    {
        for(int j=0;j<mat1.col;++j)
        {
            mat1.data[i][j]+=scalar;
        }
    }
    return mat1;
}
matrix operator-= (matrix& mat1,int scalar)
{
    for(int i=0;i<mat1.row;++i)
    {
        for(int j=0;j<mat1.col;++j)
        {
            mat1.data[i][j]-=scalar;
        }
    }
    return mat1;
}
void operator++ (matrix& mat1)
{
    for(int i=0;i<mat1.row;++i)
    {
        for(int j=0;j<mat1.col;++j)
        {
            mat1.data[i][j]++;
        }
    }
}
void operator-- (matrix& mat1)
{
    for(int i=0;i<mat1.row;++i)
    {
        for(int j=0;j<mat1.col;++j)
        {
            mat1.data[i][j]--;
        }
    }
}
bool   operator== (matrix mat1, matrix mat2)
{
    if(mat1.row!=mat2.row || mat1.col!=mat2.col)
    {
        return false;
    }
    else
    {
        for(int i=0;i<mat1.row;++i)
        {
            for(int j=0;j<mat1.col;++j)
            {
                if(mat1.data[i][j]!=mat2.data[i][j])
                    return false;
            }
        }
    }
    return true;
}
bool   operator!= (matrix mat1, matrix mat2)
{
    if(mat1.row!=mat2.row || mat1.col!=mat2.col)
    {
        return true;
    }
    else
    {
        for(int i=0;i<mat1.row;++i)
        {
            for(int j=0;j<mat1.col;++j)
            {
                if(mat1.data[i][j]!=mat2.data[i][j])
                    return true;
            }
        }
    }
    return false;
}
bool isSquare(matrix mat1)
{
    if(mat1.row==mat1.col)
        return true;
    return false;
}
bool   isIdentity (matrix mat)
{
    bool check=0;
    if(mat.row!=mat.col)
    {
        return false;
    }
    else
    {
        for(int i=0;i<mat.row;++i)
        {
            for(int j=0;j<mat.col;++j)
            {
                if(mat.data[i][j]!=1 && mat.data[i][j]!=0)
                {
                    check=1;
                    break;
                }
            }
        }
        if(check==0)
            return true;
        else
            return false;
    }
}
bool isSymetric(matrix mat)
{
    if(mat.row!=mat.col)
        return false;
    else
    {
        matrix ans;
        ans=transpose(mat);
        for(int i=0;i<mat.row;++i)
        {
            for(int j=0;j<mat.col;++j)
            {
                if(ans.data[i][j]!=mat.data[i][j])
                    return false;
            }
        }
        return true;
    }
}
matrix transpose(matrix mat)
{
    matrix ans;
    setMatrix(mat.row,mat.col,ans);
    for (int i = 0; i < mat.row; i++)
    ans.data[i] = new int [mat.col];
    for(int i=0;i<mat.row;++i)
    {
        for(int j=0;j<mat.col;++j)
        {
            ans.data[j][i]=mat.data[i][j];
        }
    }
    return ans;
}
