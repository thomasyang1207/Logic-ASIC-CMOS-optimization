#include "stdafx.h"
#include "Minterm.h"

#include <string>
#include <list>
#include <algorithm>
#include <tuple>


// algorithms for finding k-map and 

int num_difference(minterm* min1, minterm* min2, int minterm_size) {

}

minterm* merge_minterm(minterm* min1, minterm* min2, int minterm_size) {
	// Assumes that min1 and min2 ONLY HAVE 1 DIFFERING BIT...
	// Differing bit ALWAYS replaced by 2; 

	//makes a minterm from min1 and min2; 




}

std::list<minterm*> ** merge_recur(std::list<minterm*> ** minterm_list, int num_categories, int max_minterm_size) {
	// Takes categories of minterms, which a dynamically allocated array, with each element containing a pointer to a minterm; 

	int runtimes = num_categories - 1;
	std::list<minterm*> ** partitionedList = new std::list<minterm*>*[runtimes]; // new partitioned list 

	for (int i = 0; i < runtimes; i++){
		 //shitty O(n^2) algorithm;
		int listonesize = minterm_list[i]->size(); 
		int listtwosize = minterm_list[i + 1]->size(); 
		std::list<minterm*>::iterator it = minterm_list[i]->begin(); // Don't TOUCH the minterm list; 
		std::list<minterm*>::iterator it2 = minterm_list[i + 1]->begin();
		for (int j = 0; j < listonesize; j++) {
			minterm* min1 = *(it); 
			for (int k = 0; k < listtwosize; k++) {
				minterm*min2 = *(it2); 

				int difference_number = num_difference(min1, min2, max_minterm_size); 

				//two minterm pointers

				it2++; 
			}
			it++; 
		}

	}
	
	
	
}

maxterm* Merge(maxterm* input_maxterm) {
	// Merge Algorithm goes here... 
	// input_maxterm has LIST of minterms... 
	minterm ** minterm_array = input_maxterm->GetAllMinterms();  //pointer to a pointer-based minterm array
	int maxterm_size = input_maxterm->getsize(); 

	int max_minterm_size = 0;
	// Assume most significant bit is to the left... makes everything hella easier... 
	for (int i = 0; i < maxterm_size; i++) {
		//Shit Algorithm... Will replace later; 
		if (minterm_array[i]->returnsize() > 0) {
			max_minterm_size = minterm_array[i]->returnsize(); //just like that boi 
		}
	}

	//partition into sets; 
	std::list<minterm*> ** partitionedList = new std::list<minterm*>*[max_minterm_size]; //Slots for the different nums; 
	for (int i = 0; i < maxterm_size; i++) {
		int num_1s = minterm_array[i]->Get1s(); 
		partitionedList[num_1s]->push_back(minterm_array[i]); //sorts the new minterms into the slots 
	} 

	//Find all possible Merges; And then Run merges again... 
	
	//



	// Destructor 
	for (int i = 0; i < maxterm_size; i++) {
		delete minterm_array[i]; 
	}
	delete[] minterm_array; 
	delete[] partitionedList; 
};

maxterm* Reduce(maxterm* input_maxterm) {

}