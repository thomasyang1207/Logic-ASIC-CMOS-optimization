#pragma once
#include "stdafx.h"
#include <list>
#include "BooleanAlgebra.h"
#include <iostream>
#include <string>

//This is the Minterm Module; 
#ifndef MINTERM_H
#define MINTERM_H 
//Strictly the 2-level Logic module;  

class minterm {
public:
	minterm(int mintermsize = 4); //HAVE to set the size 
	minterm(std::list< BoolVariable*> &BoolVariables); // takes in a list of pointers to BoolVariables 
	~minterm(); // destructor must destroy bits that it contains 

	int returnsize(); 

	int Get1s(); 
	void setbits(int newbits[], int bitsizes, int startpoint = 0);
	int accessbit(int index_); 

	std::string PrintExpression(); 


protected:
private: 
	int * bits; //Dynamically allocate this; delete these after done; 
	// Invariant: 0 for logic 0; 1 for logic 1; 2 for don't care; 
	int size; 
	int num_1; 
};

class maxterm {
	//Is a collection of minterm; 
public:
	maxterm(int maxtermsize);
	maxterm(std::list<minterm*> * new_minterms);
	~maxterm(); 

	minterm * GetMinterm(int index);
	minterm ** GetAllMinterms(); 
	int getsize() { return size; };
	
	void AddMinterm(minterm* newminterm);
	std::string printExpression(bool suppress = true); 

	void append(maxterm* newmaxterm); 
	void append(minterm* newminterm);

protected:

private:
	std::list<minterm*> * Minterms; //do Minterms->list to initialize; // is a pointer to a list of minterms... 
	int size; 
};

#endif

