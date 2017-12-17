#pragma once
#include "stdafx.h"
#include <list>
#include <string>
#include <array>
#include <unordered_map> 

#ifndef BOOLEANALGEBRA_H 
#define BOOLEANALGEBRA_H // This basically defines a macro saying that 

// What does 
class BoolVariable {
public: 
	//constructors; 
	BoolVariable();
	BoolVariable(bool newvalue, std::string newname);

	//Operator Overload; 
	BoolVariable operator+(const BoolVariable&);
	BoolVariable operator*(const BoolVariable&);
	BoolVariable operator-(const BoolVariable&);

	void Setvalue(bool newvalue); 
	bool Getvalue();
	bool V2Bool(); 

	void Setlabel(std::string newname); 
	std::string Getlabel(); 

protected: 

private: 
	bool value; 
	std::string Label; 
};


#endif 