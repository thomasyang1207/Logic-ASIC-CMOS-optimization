#include "stdafx.h"
#include <list>
#include <algorithm>
#include <string>

#include "BooleanAlgebra.h"


BoolVariable::BoolVariable() {
	this->value = false; 
	this->Label = ""; //empty string; 
}

BoolVariable::BoolVariable(bool newvalue, std::string newname) {
	this->value = newvalue; 
	this->Label = newname; 
}

BoolVariable BoolVariable:: operator + (const BoolVariable& newbool) {
	BoolVariable result; // Calls default constructor... 
	std::string newname = this->Label + "+" + newbool.Label; 
	bool newvalue = value || newbool.value; 

	result.Setvalue(newvalue); 
	result.Setlabel(newname);
	return result; 
}

BoolVariable BoolVariable:: operator * (const BoolVariable& newbool) {
	BoolVariable result; // Calls default constructor... 
	std::string newname = this->Label + "+" + newbool.Label;
	bool newvalue = value && newbool.value;

	result.Setvalue(newvalue);
	result.Setlabel(newname);
	return result;
}

BoolVariable BoolVariable:: operator - (const BoolVariable& newbool) {
	BoolVariable result; // Calls default constructor... 
	std::string newname = this->Label + "+" + newbool.Label;
	bool newvalue = value && !(newbool.value);

	result.Setvalue(newvalue);
	result.Setlabel(newname);
	return result;
}

bool BoolVariable::Getvalue() {
	return (this->value); 
}

bool BoolVariable::V2Bool() {
	return (this->value);
}

void BoolVariable::Setvalue(bool newvalue) {
	this->value = newvalue; 
}

void BoolVariable::Setlabel(std::string newname) {
	this->Label = newname;
}

std::string BoolVariable::Getlabel() {
	return this->Label;
}

/************************************************************************************************************************/
// Logic expression 