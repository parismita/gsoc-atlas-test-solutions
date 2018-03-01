#include <iostream> 
#include "SymMat.h" 
#include <Eigen/Dense>
#include <typeinfo>

using namespace Eigen; 

int main() 
{ 
	//double and dynamic matrix
	MatrixXd sol(3,3);
	sol<<0,0,0,0,0,0,0,0,0;
	MatrixXd m1(3,3);
	m1<<1,2,3,1,2,3,1,2,3;
	MatrixXd m2(3,3);
	m2<<1,0,1,1,0,2,1,0,3;
	//S is the Symmat matrix
	SymMat<double> S(sol),S1(m1),S2(m2);
	//S is the Symmat matrix
	MatrixXf mf(2,2);
	mf<<1,2,3,4;
	SymMat<float> Sf(mf);

	/////////////////////accessors and constructor//////////////////////////////////
	std::cout<<"Here are the Eigen, Matrix m1(3,3),m2(3,3),mf(2,2) resp"<<"\n"<<m1<<"\n\n"<<m2<<"\n\n"<<mf<<std::endl;

	std::cout<<"Here are the SymMat symmetric matrixes S1,S2,Sf resp"<<std::endl;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<S1.Get(i,j)<<" ";
		}
		std::cout<<"\n";
	}
	std::cout<<"\n";
		for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<S2.Get(i,j)<<" ";
		}
		std::cout<<"\n";
	}
	std::cout<<"\n";
		for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			std::cout<<Sf.Get(i,j)<<" ";
		}
		std::cout<<"\n";
	}
	//////////////////////////////add S1,S2 and store in S//////////////////////////////
	std::cout<<"Adding S1+S2 and storing in S"<<std::endl;
	S.Add(S1,S2);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<S1.Get(i,j)<<" ";
		}
		
		if(i==1){
			std::cout<<"\t+\t ";
		}
		else std::cout<<"\t \t ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<S2.Get(i,j)<<" ";
		}
		if(i==1){
			std::cout<<"\t=\t ";
		}
		else std::cout<<"\t \t ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<S.Get(i,j)<<" ";
		}
		std::cout<<"\n";
	}
	///////////////////////////add s1,m2 test//////////////////////////////////////////
	std::cout<<"Adding S1+m2 and storing in m"<<std::endl;
	S.Add(sol,S1,m2);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<S1.Get(i,j)<<" ";
		}
		
		if(i==1){
			std::cout<<"\t+\t ";
		}
		else std::cout<<"\t \t ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<m2(i,j)<<" ";
		}
		if(i==1){
			std::cout<<"\t=\t ";
		}
		else std::cout<<"\t \t ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<sol(i,j)<<" ";
		}
		std::cout<<"\n";
	}
	//////////////////////////////sub S1,S2 and store in S////////////////////////////
	std::cout<<"Subtracting S1-S2 and storing in S"<<std::endl;
	S.Sub(S1,S2);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<S1.Get(i,j)<<" ";
		}
		
		if(i==1){
			std::cout<<"\t-\t ";
		}
		else std::cout<<"\t \t ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<S2.Get(i,j)<<" ";
		}
		if(i==1){
			std::cout<<"\t=\t ";
		}
		else std::cout<<"\t \t ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<S.Get(i,j)<<" ";
		}
		std::cout<<"\n";
	}
	/////////////////////sub s1,m2 and store in sol/////////////////////////////////////
	std::cout<<"Subtracting S1-m2 and storing in m"<<std::endl;
	S.Sub(sol,S1,m2);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<S1.Get(i,j)<<" ";
		}
		
		if(i==1){
			std::cout<<"\t-\t ";
		}
		else std::cout<<"\t \t ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<m2(i,j)<<" ";
		}
		if(i==1){
			std::cout<<"\t=\t ";
		}
		else std::cout<<"\t \t ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<sol(i,j)<<" ";
		}
		std::cout<<"\n";
	}
	///////////////////////////////sub m2,s1 and store in sol//////////////////////////////
	std::cout<<"Subtracting m2-S1 and storing in m"<<std::endl;
	S.Sub(sol,m2,S1);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<m2(i,j)<<" ";
		}
		
		if(i==1){
			std::cout<<"\t-\t ";
		}
		else std::cout<<"\t \t ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<S1.Get(i,j)<<" ";
		}
		if(i==1){
			std::cout<<"\t=\t ";
		}
		else std::cout<<"\t \t ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<sol(i,j)<<" ";
		}
		std::cout<<"\n";
	}


	/////////////////////////////////mul S1,S2 and store in S////////////////////////////////
	std::cout<<"Multiplying S1*S2 and storing in S"<<std::endl;
	S.Mult(S1,S2);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<S1.Get(i,j)<<" ";
		}
		
		if(i==1){
			std::cout<<"\t*\t ";
		}
		else std::cout<<"\t \t ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<S2.Get(i,j)<<" ";
		}
		if(i==1){
			std::cout<<"\t=\t ";
		}
		else std::cout<<"\t \t ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<S.Get(i,j)<<" ";
		}
		std::cout<<"\n";
	}
	/////////////////////////////mul s1,m2 and store in sol/////////////////////////////////
	std::cout<<"Multiplying S1*m2 and storing in m"<<std::endl;
	S.Mult(sol,S1,m2);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<S1.Get(i,j)<<" ";
		}
		
		if(i==1){
			std::cout<<"\t*\t ";
		}
		else std::cout<<"\t \t ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<m2(i,j)<<" ";
		}
		if(i==1){
			std::cout<<"\t=\t ";
		}
		else std::cout<<"\t \t ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<sol(i,j)<<" ";
		}
		std::cout<<"\n";
	}
	//////////////////////////////mul m2,s1 and store in sol/////////////////////////////////
	std::cout<<"Multiplying m2*S1 and storing in m"<<std::endl;
	S.Mult(sol,m2,S1);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<m2(i,j)<<" ";
		}
		
		if(i==1){
			std::cout<<"\t*\t ";
		}
		else std::cout<<"\t \t ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<S1.Get(i,j)<<" ";
		}
		if(i==1){
			std::cout<<"\t=\t ";
		}
		else std::cout<<"\t \t ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout<<sol(i,j)<<" ";
		}
		std::cout<<"\n";
	}

return 0;
}