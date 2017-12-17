#include "stdafx.h"
#include "Minterm.h"
#include "BooleanAlgebra.h"
#include <iostream>
#include <list> 
#include <string>

minterm::minterm(int mintermsize) {
	this->bits = new int[mintermsize]; 
	//By default, set all minterms to; 
	for (int i = 0; i < mintermsize; i++) {
		this->bits[i] = 2;
	}
	this->num_1 = 0; 
}

minterm::minterm(std::list< BoolVariable*> &BoolVariables) {
	//BoolVariables is a list, passed by reference, so not copied; 
	std::list<BoolVariable*>::iterator it = BoolVariables.begin(); 
	// supposing this works... 

	int BoolVar_size = BoolVariables.size(); 

	this->bits = new int[BoolVar_size]; // by default, 

	for (int i = 0; i < BoolVar_size; i++) {
		this->bits[i] = int((*it)->Getvalue()); 
		if (int((*it)->Getvalue()) == 1) {
			this->num_1++; 
		}
		std::advance(it, 1); 
	}
}

minterm::~minterm() {
	delete[] this->bits; 
}

int minterm::returnsize() {
	return this->size; 
}

int minterm::Get1s() {
	return this->num_1; 
}

void minterm::setbits(int newbits[], int bitsizes, int startpoint = 0) {
	// by default, will change bits starting from array index = 0; 
	//Bitsizes MUST equal newbits; 

	int highestindex = startpoint + bitsizes;
	startpoint = abs(startpoint);
	
	if (highestindex > (this->size)) {
		std::cout << "newarray size exceeds that of minterm"; 
	}
	else if (startpoint > this->size) {
		std::cout << "BitArray Starting Point out of bounds" << std::endl; 
	}
	else {
		for (int i = startpoint; i < highestindex; i++) {
			this->bits[i] = newbits[i-startpoint]; 
			if (bits[i] == 1) {
				(this->num_1)++;
			}
		}
	}
}

int minterm::accessbit(int index_) {
	if (index_ > (size - 1)) {
		std::cout << "index exceeds BitArray Range" << std::endl;
	}
	else {
		return this->bits[index_];
	}
	
}

std::string minterm::PrintExpression() {
	std::string bit_string = ""; //Blank string initialization 
	for (int i = 0; i < this->size; i++) {
		if (this->bits[i] == 2) {
			bit_string += "x"; 
		}
		else {
			bit_string += std::to_string(bits[i]); 
		}
	}

	return bit_string; 
}



/********************************************************************************************************************************/


maxterm::maxterm(int maxtermsize) {
	//initializes an EMPTY maxterms list; 
	this->Minterms = nullptr; 
	this->size = 0; 
}

maxterm::maxterm(std::list<minterm*> * new_minterms) {
	this->size = new_minterms->size(); // new_minterms is a POINTER to a LIST; that LIST has minterms in it; 
	this->Minterms = new_minterms; 

	//Assume... big endian shit... 
}

maxterm::~maxterm() {
	delete this->Minterms; 
}

minterm* maxterm::GetMinterm(int index) {
	// Each Maxterm Object HAS
	if (this->size == 0) {
		std::cout << "No minterms in expression" << std::endl; 
		return nullptr; 
	}
	
	if (index >= size) {
		std::cout << "index exceeds minterm size" << std::endl; 
		return nullptr; 
	}

	std::list<minterm*>::iterator it = (this->Minterms)->begin(); 
	// index starts from 0. with 0 being the first element. 
	
	advance(it, index); 

	return *it; //will just return the minterm pointer; 
}

void maxterm::AddMinterm(minterm* newminterm) {
	//Append the new pointer to minterm to POINTER to LIST of Minterms that Maxterm has
	(this->Minterms)->push_back(newminterm); 
	(this->size)++;
}

std::string maxterm::printExpression(bool suppress = true) {
	std::string outputstring = ""; 
	
	if (this->size > 0) {
		std::list<minterm*>::iterator it = (this->Minterms)->begin();
		for (int i = 0; i < this->size; i++) {
			outputstring += (*it)->PrintExpression(); 
			std::advance(it, 1);
		}
	}
	else {
		std::cout << "nothing to print" << std::endl; 
	}
	if (!suppress) {
		std::cout << "outputstring" << std::endl;
	}
	return outputstring; 
}

minterm ** maxterm::GetAllMinterms() {
	// returns all minterms, in a pointer to an array... 
	minterm ** minterm_array = new minterm*[this->size]; 

	std::list<minterm*>::iterator it = (this->Minterms)->begin();

	for (int i = 0; i < size; i++) {
		minterm_array[0] = (*it); // 
		std::advance(it, 1); 
	}

	return minterm_array; 
}

void maxterm::append(maxterm* newmaxterm) {
	// given another maxterm, extract its list of minterm pointers... 
	std::list<minterm*> * New_Minterm_List_pointer; // pointer to a list of minterm pointers;

	*(New_Minterm_List_pointer) = *(newmaxterm->Minterms); 
	int newmaxtermsize = newmaxterm->size; 
	// List COPIED; 

	auto it = (this->Minterms)->end(); 

	(this->Minterms)->splice(it, *(New_Minterm_List_pointer)); // just appended the new minterm; 
	this->size += newmaxtermsize; 

	
}
void maxterm::append(minterm* newminterm) {

	(this->Minterms)->push_back(newminterm);
	(this->size)++; 

}

