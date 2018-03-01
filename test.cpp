#include <iostream> 
#include "SymMat.h" 
#include <Eigen/Dense>
#include <typeinfo>

using namespace Eigen; 

//test example
//contains
//constructor
//accessors
//func add s1,s2
//func add s1, mat
//func sub s1,s2 as s1-s2
//func sub m-s1 and s1-m
//func mul s1,s2
//func mul s1,m
//func mul m,s1

int main() 
{ 
	//double and dynamic matrix
	MatrixXd m(3,3);
	m<<1,2,3,4,5,6,7,8,9;
	//S is the Symmat matrix
	SymMat<double> S(m),S2(m);

	//float and dynamic matrix
	MatrixXf m1(3,3);
	m1<<1,2,3,4,5,6,7,8,9;
	SymMat<float> S1(m1);

	//double and dynamic matrix
	MatrixXd m2 = Matrix3d::Random();

	std::vector< std::vector <double > > A = {{0,0,0},{0,0,0},{0,0,0}};
	double error = 0.0;
	int f=0;
	/////////////////////////////////////////////////////accessors test////////////////////////////////////////////////////
	//checking correctness of accessor here.
	for (int i = 0; i < m.cols(); ++i)
	{
		for (int j = 0; j < m.cols(); ++j)
		{
			//checking if i,jth term is equal to j,ith term
			error += S.Get(i,j)-S.Get(j,i);
			if (error != 0.0)
			{
				f=1;
				//not equal
				std::cout<<"accessors not working correctly S(i,j)!=S(j,i)"<<std::endl;
				break;
			}
		}
		if(f==1){break;}
	}
	if (error == 0.0)
	{
		//when S(i,j)=S(j,i)
		std::cout<<"accessors working correctly S(i,j)==S(j,i)"<<std::endl;
	}

	f=0;
	/////////////////////////////////////////////////constructor test////////////////////////////////////////////////
	error = 0.0;
	//checking correctness of constructor here.
	//for object S
	for (int i = 0; i < m.cols(); ++i)
	{
		for (int j = i; j < m.cols(); ++j)
		{
			error += S.Get(i,j)-m(i,j);
			if (error != 0.0)
			{	
				f=1;
				//constructor not taking arguement
				std::cout<<"error in constructor, not taking upper triangular matrix of Eigen:Matrix"<<std::endl;
				break;
			}
		}
		if(f==1){break;}
	}
	f=0;
	if (error == 0.0)
	{
		//for object S1
		for (int i = 0; i < m1.cols(); ++i)
		{
			for (int j = i; j < m1.cols(); ++j)
			{
				error += S1.Get(i,j)-m1(i,j);
				if (error != 0.0)
				{	
					f=1;
					//constructor taking only specific type not dynamic
					std::cout<<"constructor taking Eigen:Matrix but not dynamic size and anonymous type"<<std::endl;
					break;
				}
			}
		}

		if (error == 0.0)
		{//no error case
			std::cout<<"constructor taking Eigen:Matrix of dynamic size and anonymous type"<<std::endl;
		}
		
	}
	f=0;
	/////////////////////////////////////////////////add s1,s2 test////////////////////////////////////////////////
	error = 0.0;
	//checking correctness of addition here.
	A = {{2,4,6},{4,10,12},{6,12,18}};

	S.Add(S2,S2);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			error += S.Get(i,j)-A[i][j];
			if (error != 0.0)
				{	
					f=1;
					//if addition gives required result
					std::cout<<"error in (SymMat+Symmat) Addition"<<std::endl;
					break;
				}
		}
		if(f==1){break;}
	}
	if (error == 0.0)
	{
		std::cout<<"(SymMat+Symmat) Addition done correctly"<<std::endl;
	}
	f=0;
	/////////////////////////////////////////////////add s2,m test////////////////////////////////////////////////
	error = 0.0;
	A = {{2,4,6},{6,10,12},{10,14,18}};

	S.Add(m2,S2,m);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			error += m2(i,j)-A[i][j];
			if (error != 0.0)
				{	
					f=1;
					std::cout<<"error in (SymMat+Matrix) Addition"<<std::endl;
					break;
				}
		}
		if(f==1){break;}
	}
	if (error == 0.0)
	{
		std::cout<<"(SymMat+Matrix) Addition done correctly"<<std::endl;
	}
	/////////////////////////////////////////////////sub s1,s2 test////////////////////////////////////////////////
	A = {{0,0,0},{0,0,0},{0,0,0}};
	//checking correctness of Subtraction here, if s2-s2=0 then algo working correctly
	error = 0.0;

	S.Sub(S2,S2);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			error += S.Get(i,j)-A[i][j];
			if (error != 0.0)
				{	
					f=1;
					std::cout<<"error in (SymMat+Symmat) Subtraction"<<std::endl;
					break;
				}
		}
		if(f==1){break;}
	}
	if (error == 0.0)
	{
		std::cout<<"(SymMat+Symmat) Subtraction done correctly"<<std::endl;
	}
	f=0;
	/////////////////////////////////////////////////sub s1,m test////////////////////////////////////////////////
	A = {{0,0,0},{-2,0,0},{-4,-2,0}};
	error = 0.0;

	S.Sub(m2,S2,m);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			error += m2(i,j)-A[i][j];
			if (error != 0.0)
				{	
					f=1;
					std::cout<<"error in (SymMat-Matrix) Subtraction"<<std::endl;
					break;
				}
		}
		if(f==1){break;}
	}
	if (error == 0.0)
	{
		std::cout<<"(SymMat-Matrix) Subtraction done correctly"<<std::endl;
	}
	/////////////////////////////////////////////////sub m,s1 test////////////////////////////////////////////////
	A = {{0,0,0},{2,0,0},{4,2,0}};
	error = 0.0;

	S.Sub(m2,S2,m);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = i; j < 3; ++j)
		{
			error += m2(i,j)-A[i][j];
			if (error != 0.0)
				{	
					f=1;
					std::cout<<"error in (Matrix-SymMat) Subtraction"<<std::endl;
					break;
				}
		}
		if(f==1){break;}
		
	}
	if (error == 0.0)
	{
		std::cout<<"(Matrix-SymMat) Subtraction done correctly"<<std::endl;
	}


	/////////////////////////////////////////////////mult s1,s2 test////////////////////////////////////////////////
	A = {{14,30,42},{30,65,90},{42,90,126}};
	error = 0.0;
	//checking correctness of Multiplication here, the A values taken from online site for particular example
	S.Mult(S2,S2);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			//std::cout<<S.Get(i,j)<<" ";
			error += S.Get(i,j)-A[i][j];
			if (error != 0.0)
				{	
					f=1;
					std::cout<<"error in (SymMat*Symmat) Multiplication"<<std::endl;
					break;
				}
		}
		if(f==1){break;}
	}
	if (error == 0.0)
	{
		std::cout<<"(SymMat*Symmat) Multiplication done correctly"<<std::endl;
	}
	f=0;
	/////////////////////////////////////////////////mult s1,m test////////////////////////////////////////////////
	A = {{30,36,42},{64,77,90},{90,108,126}};
	error = 0.0;

	S.Mult(m2,S2,m);
	//std::cout<<m2;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			error += m2(i,j)-A[i][j];
			if (error != 0.0)
				{	
					f=1;
					std::cout<<"error in (SymMat*Matrix) Multiplication"<<std::endl;
					break;
				}
		}
		if(f==1){break;}
		
	}
	if (error == 0.0)
	{
		std::cout<<"(SymMat*Matrix) Multiplication done correctly"<<std::endl;
	}

	/////////////////////////////////////////////////mult m,s1 test////////////////////////////////////////////////
	A = {{14,30,42},{32,69,96},{50,108,150}};
	error = 0.0;

	S.Mult(m2,m,S2);
	//std::cout<<m2;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = i; j < 3; ++j)
		{
			error += m2(i,j)-A[i][j];
			if (error != 0.0)
				{	
					f=1;
					std::cout<<"error in (Matrix*SymMat) Multiplication"<<std::endl;
					break;
				}
		}
		if(f==1){break;}
		
	}
	if (error == 0.0)
	{
		std::cout<<"(Matrix*SymMat) Multiplication done correctly"<<std::endl;
	}
return 0;
} 
