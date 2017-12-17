#pragma once
#include "stdafx.h"
#include "Minterm.h" // the key! 
#include "BooleanAlgebra.h" // The OTHER KEY! 

#include <string>
#include <list>
#include <algorithm>
#include <iostream>


/************************************************************************/

#ifndef _2_LEVEL_LOGIC_H
#define _2_LEVEL_LOGIC_H

// define function stubs, etc. 
maxterm* Merge(maxterm* input_maxterm); 

maxterm* Reduce(maxterm* input_maxterm); 

maxterm* QMFull(maxterm* input_maxterm); 

maxterm* ESPRESSO_EXPAND(maxterm* input_maxterm);

maxterm* ESPRESSO_IRRED(maxterm* input_maxterm); 

maxterm* ESPRESSO_REDUCE(maxterm* input_maxterm); 

#endif

