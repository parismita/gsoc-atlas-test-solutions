#ifndef SymMat_h
#define SymMat_h

#include <Eigen/Dense>
#include <vector>
#include <bits/stdc++.h>

using namespace Eigen;

//using template with type as T.
template <typename T>
class SymMat
{
    //upper triangular matrix variable of dynamic type T.
    std::vector< std::vector <T > > S;
    //size of the upper triangular matrix
    int cols;
    
    public:

    //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
    //constructor with Eigen:Matrix as arguement
    SymMat<T>(Matrix<T, Dynamic, Dynamic>& M){
        //defining the size of symmetrix matrix S as column number of M
        //as it would take all columns but not all rows if rows!=columns 
        cols = M.cols();

        //pushing the upper diagonal part of M into vector S
        for (int i = 0; i < M.rows(); ++i)
        {
            std::vector <T> m;
            for (int j = i; j < M.cols(); ++j)
            {
                m.push_back(M(i,j));
            }
            S.push_back(m);
            //std::cout<<S[0][0];
        }
    }
    

    //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
    //destructor
    ~SymMat(){}



    //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
    //accessors function
    //output S(i,j) and S(j,i) accordingly
    T Get(int row, int col)
    {
        //as S[i][i] is stored in S[i][0]
        //hence if i>j the stored element is S[j][i] in position S[j][i-j]
        //else S[i][j] in position S[i][j-i]
        if(row > col){
            //std::cout<<S[col][row-col];
            return S[col][row-col];
        }
        else{
            //std::cout<<S[row][col-row];
            return S[row][col-row];
        }
    }

    //accessors for size of symmetric matrix vector S
    int col(){
        return cols;
    }


    //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
    //add two upper triangular matrix
    // time complexity: cols(cols-1)/2
    //th output is stored in variable S
    void Add(SymMat<T>& S1 , SymMat<T>& S2)
    {
        //throw exception if sizes not same
        if(S1.col()!=S2.col()){
            throw "matrices not of same size!";
            return;
        }
        //addition of non zero elements
        //using property that output is symmetric from adding 2 symmetrix matrices
        //hence output here is upper triangular matrix
        for (int i = 0; i < cols; ++i) //rows
        {
            for (int j = i; j < cols; ++j) //columns from diagonal to end
            {
                S[i][j-i] = S1.Get(i,j)+S2.Get(i,j);
            }
        }
    }


    //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
    //add upper tringular and eigen matrix
    //the output is stored in variable Sol
    void Add(Matrix<T, Dynamic, Dynamic>& Sol, SymMat<T>& S1, Matrix<T, Dynamic, Dynamic>& M)
    {
        //throw exception if sizes not same
        if(S1.col()!=M.cols()){
            throw "matrices not of same size!";
        }
        if(S1.col()!=M.rows()){
            throw "matrices not of same size!";
        }

        //storing the upper triangle of eigen matrix Sol.
        for (int i = 0; i < cols; ++i)
        {
            for (int j = i; j < cols; ++j)
            {
                Sol(i,j) = S1.Get(i,j)+M(i,j);
            }

        }

        //storing the lower triangle of eigen matrix Sol.
        for (int i = cols-1; i > 0; --i)
        {
            for (int j = 0; j < i; ++j)
            {
                Sol(i,j) = S1.Get(i,j)+M(i,j);
            }

        }
    }


    //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
    //subtract two upper triangular matrix
    // time complexity: cols(cols-1)/2
    //th output is stored in variable S
    //argument 1 - argument 2
    void Sub(SymMat<T>& S1 , SymMat<T>& S2)
    {
        //throw exception if sizes not same
        if(S1.col()!=S2.col()){
            throw "matrices not of same size!";
            return;
        }
        //subtraction of non zero elements
        //using property that output is symmetric from adding 2 symmetrix matrices
        //hence output here is upper triangular matrix
        for (int i = 0; i < cols; ++i) //rows
        {
            for (int j = i; j < cols; ++j) //columns from diagonal to end
            {
                S[i][j-i] = S1.Get(i,j)-S2.Get(i,j);
            }
        }
    }


    //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
    //subtract upper tringular and eigen matrix
    //the output is stored in variable Sol
    //argument 1 - argument 2
    void Sub(Matrix<T, Dynamic, Dynamic>& Sol, Matrix<T, Dynamic, Dynamic>& M, SymMat<T>& S1)
    {
        //throw exception if sizes not same
        if(S1.col()!=M.cols()){
            throw "matrices not of same size!";
        }
        if(S1.col()!=M.rows()){
            throw "matrices not of same size!";
        }

        //storing the upper triangle of eigen matrix Sol.
        for (int i = 0; i < cols; ++i)
        {
            for (int j = i; j < cols; ++j)
            {
                Sol(i,j) = M(i,j)-S1.Get(i,j);
            }

        }

        //storing the lower triangle of eigen matrix Sol.
        for (int i = cols-1; i > 0; --i)
        {
            for (int j = 0; j < i; ++j)
            {
                Sol(i,j) = M(i,j)-S1.Get(i,j);
            }

        }
    }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
    //subtract upper tringular and eigen matrix
    //the output is stored in variable Sol
    //argument 1 - argument 2
    void Sub(Matrix<T, Dynamic, Dynamic>& Sol, SymMat<T>& S1, Matrix<T, Dynamic, Dynamic>& M)
    {
        //throw exception if sizes not same
        if(S1.col()!=M.cols()){
            throw "matrices not of same size!";
        }
        if(S1.col()!=M.rows()){
            throw "matrices not of same size!";
        }

        //storing the upper triangle of eigen matrix Sol.
        for (int i = 0; i < cols; ++i)
        {
            for (int j = i; j < cols; ++j)
            {
                Sol(i,j) = S1.Get(i,j)-M(i,j);
            }

        }

        //storing the lower triangle of eigen matrix Sol.
        for (int i = cols-1; i > 0; --i)
        {
            for (int j = 0; j < i; ++j)
            {
                Sol(i,j) = S1.Get(i,j)-M(i,j);
            }

        }
    }

    //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
    //matrix multiplication of 2 Symmat objects.
    //as result is symmetric matrix hence storing as vector S = S1S2
    //time complexity:  col(col+1)(2col+1)/6
    void Mult(SymMat<T>& S1, SymMat<T>& S2){
        if(S1.col()!=S2.col()){
            throw "matrices not of same size!";
            return;
        }

        for (int i = 0; i < cols; ++i)
        {
            for (int j = i; j < cols; ++j)
            {
                for (int k = i; k < cols; ++k)
                {
                    S[i][j-i] += S1.Get(i,k)*S2.Get(j,k);
                }
            }
        }

    }


    //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

    //matrix multiplication of 2 Symmat objects.
    //as result is stored in eigen Matrix Sol = S1M
    void Mult(Matrix<T, Dynamic, Dynamic>& Sol, SymMat<T>& S1, Matrix<T, Dynamic, Dynamic>& M){
        //exception
        if(S1.col()!=M.cols()){
            throw "matrices not of same size!";
            return;
        }
        if(S1.col()!=M.rows()){
            throw "matrices not of same size!";
            return;
        }

        for (int i = 0; i < cols; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                for (int k = i; k < cols; ++k)
                {
                    Sol(i,j) += S1.Get(i,k)*M(k,j);
                }
            }
        }
    }
    //matrix multiplication of 2 Symmat objects.
    //as result is stored in eigen Matrix Sol = MS1
    void Mult(Matrix<T, Dynamic, Dynamic>& Sol, Matrix<T, Dynamic, Dynamic>& M, SymMat<T>& S1){
        //exception
        if(S1.col()!=M.cols()){
            throw "matrices not of same size!";
            return;
        }
        if(S1.col()!=M.rows()){
            throw "matrices not of same size!";
            return;
        }

        for (int i = 0; i < cols; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                for (int k = i; k < cols; ++k)
                {
                    Sol(i,j) += M(i,k)*S1.Get(k,j);
                }
            }
        }
    }
};

#endif

    
//as Eigen doesnt allow to pass its classes object to different files,
// thus declaring all functions as inline functions