/* Write your test code for the ULListStr in this file */

#include <iostream>
#include <stdio.h>
#include "ulliststr.h"

void printList(ULListStr &, size_t);

int main(int argc, char* argv[])
{

	ULListStr test;
		
		
	//Add more than 10 items so that two Items are allocated

	test.push_back("one");
	test.push_back("two");
	test.push_back("three");
	test.push_back("four");
	test.push_back("five");
	test.push_back("six");
	test.push_back("seven");
	test.push_back("eight");
	test.push_back("nine");
	test.push_back("ten");
	test.push_back("eleven");
	test.push_back("twelve");
	test.push_back("thirteen");
	test.push_back("fourteen");
	test.push_back("fifteen"); 


	//print out values to ensure proper insertion
	printList(test, 16); //16 instead of 15 to show that NULL is returned for invalid values


	std::cout << "Size: " << test.size() << std::endl << std::endl;


	//pop enough items off of the back to ensure second Item is deallocated

	for(int i = 0; i<7; i++){
		test.pop_back();
	}


	//print out same number of values as before to ensure proper removal
	printList(test, 14);


	//push front to the beginning of the list to ensure new allocation

	test.push_front("zero");
	test.push_front("negative one");


	//print again to ensure proper addition of items

	std::cout << std::endl << std::endl;
	printList(test, 14);

	// pop two previously added front cases to remove allocated Item

	test.pop_front();
	test.pop_front();


	// print front and back values (should be one and 7 now that front items have been removed)

	std::cout << std::endl << "test.front(): " << test.front() << std::endl;
	std::cout << "test.back(): " << test.back() << std::endl;

	std::cout << std::endl << std::endl;


	//remove all items, deallocate item

	for (int i = 0; i < 8; i++){
		test.pop_back();
	}

	std::cout << "Size: " << test.size() << std::endl << std::endl;


	//reallocate a two item list strictly with push_front

	test.push_front("one");
	test.push_front("two");
	test.push_front("three");
	test.push_front("four");
	test.push_front("five");
	test.push_front("six");
	test.push_front("seven");
	test.push_front("eight");
	test.push_front("nine");
	test.push_front("ten");
	test.push_front("eleven");
	test.push_front("twelve");
	test.push_front("thirteen");
	test.push_front("fourteen");
	test.push_front("fifteen"); 

	std::cout << "Size: " << test.size() << std::endl << std::endl;


	//remove all via pop_front

	for (int i = 0; i < 15; i++){
		test.pop_front();
	}

	std::cout << "Size: " << test.size() << std::endl << std::endl;


	//reallocate

	test.push_front("one");
	test.push_front("two");
	test.push_front("three");
	test.push_front("four");
	test.push_front("five");
	test.push_front("six");
	test.push_front("seven");
	test.push_front("eight");
	test.push_front("nine");
	test.push_front("ten");
	test.push_front("eleven");
	test.push_front("twelve");
	test.push_front("thirteen");
	test.push_front("fourteen");
	test.push_front("fifteen"); 
	test.push_front("sixteen");
	test.push_front("seventeen");
	test.push_front("eighteen");
	test.push_front("nineteen");
	test.push_front("twenty"); 

	std::cout << "Size: " << test.size() << std::endl << std::endl;


	//getValAt can access all items in a multi item list with varying degrees of fullness
	printList(test, 20);

	//completely deallocate with combination of pop_front and pop_back

	for (int i = 0; i < 20; i++){
		if(i%2 == 0){
			test.pop_front();
		} else {
			test.pop_back();
		}
	}

	std::cout << std::endl << "size: " << test.size() << std::endl;

	return 0;
}


void printList(ULListStr &test, size_t val){
	for(size_t i = 0; i<val; i++){
		if (test.returnVal(i) != NULL){
			std::cout << *test.returnVal(i) << std:: endl;
		} else if (test.returnVal(i) == NULL){
			std::cout << "NULL value at index" << i << std::endl;
		}
	}
}