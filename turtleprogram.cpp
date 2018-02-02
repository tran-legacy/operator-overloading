/**************************
* Tran Le
* CSS343 - WINTER2018
* Ass1: Turtle Program
* Last edited: 1/13/2018
***************************/

////////////////////////////////////
// turtleprogram.cpp is the implementation
// file of turtleprogram.h (TurtleProgram class)
////////////////////////////////////
#include "turtleprogram.h"
#include <stdexcept>

/******************PRIVATE METHODs*****************/
//// Add 1 more space to the length of the array when the array needs more space////
void TurtleProgram::growArray() {
	int newCapacity = this->capacity + 1;
	std::string* tempArray = new std::string[newCapacity];

	for (int i = 0; i < this->length; ++i) 
		tempArray[i] = array[i];

	this->capacity = newCapacity;
	delete[] array;
	this->array = tempArray;
}
//// Inserts string into the end of the array ////
void TurtleProgram::insert(const std::string& value) {
	if (this->length == this->capacity)
		growArray();

	this->array[this->length] = value;
	// increment length so next add can be added in the right place
	++length;
}

/******************CONSTRUCTOR********************/
TurtleProgram::TurtleProgram() {
	array = NULL;
	this->capacity = 0; 
	this->length = 0; 
}
TurtleProgram::TurtleProgram(const std::string& moveChar, const std::string& num) {
	// allocate 2 indexes for the two strings
	this->array = new std::string[2]; 
	this->capacity = 2; 
	this->length = 0; 
	insert(moveChar);
	insert(num);
}

TurtleProgram::TurtleProgram(const TurtleProgram& obj) {
	// Did not use equal operator because copy constructor and equal does different things
	// Allocate enough memory for copy
	array = new std::string[obj.capacity]; 
	
	// copy data over
	for (int i = 0; i < obj.length; ++i) {
		array[i] = obj.getIndex(i); 
	}

	// copy private members
	this->capacity = obj.capacity; 
	this->length = obj.length;
}

/**************************DESTRUCTOR********************/
TurtleProgram::~TurtleProgram() {
	delete[] array;
	array = NULL;
}
/*****************GETTERS***********************/
int TurtleProgram::getLength() const {
	return this->length;
}

const std::string& TurtleProgram::getIndex(const int index) const {
	if (index < 0 || index >= this->length) {
		throw std::out_of_range("ERROR: Out of range.");
	}
	return array[index]; 
}

/**********************SETTERS**********************/
void TurtleProgram::setIndex(const int index, const std::string value) {
	if (index < 0 || index >= this->length) {
		throw ::std::out_of_range("ERROR: Out of range."); 
	}
	array[index] = value; 
}

/*******************OPERATOR OVERLOADING*****************/
// Will add together and return a copy
TurtleProgram TurtleProgram::operator+(const TurtleProgram & obj) {
	TurtleProgram temp; 
	// Allocate enough memory in temp 
	temp.capacity = this->length + obj.length; 
	temp.array = new std::string[temp.capacity]; 

	// Insert THIS's data into temp array
	for (int thisIndex = 0; thisIndex < this->length; ++thisIndex) 
		temp.insert(array[thisIndex]);
	// Insert obj's data into temp array 
	for (int objIndex = 0; objIndex < obj.length; ++objIndex)
		temp.insert(obj.array[objIndex]); 

	return temp; 
}

TurtleProgram TurtleProgram::operator*(const int num) {
	if (num <= 0 || array == NULL) {
		throw std::invalid_argument("ERROR: Can't multiply by 0.");
	} else {
		TurtleProgram temp;
		temp.capacity = this->length * num;
		// Allocate enough memory for the copying
		temp.array = new std::string[temp.capacity];
		// Copy everything over num amount of times
		for (int i = 0; i < num; ++i) {
			for (int j = 0; j < this->length; ++j) {
				temp.insert(array[j]);
			}
		}
		return temp;
	}
}

TurtleProgram& TurtleProgram::operator=(const TurtleProgram& rhs) {
	if (this == &rhs) return *this;
	if (rhs.capacity == 0) {
		delete[] array; 
		array = NULL;
		this->capacity = 0; 
		this->length = 0;
		return *this;
	}
	// delete whatever is in this first
	delete[] array;
	this->array = new std::string[rhs.capacity];

	// copy data over TODO: this shit got problems man
	for (int i = 0; i < rhs.length; ++i) 
		array[i] = rhs.array[i]; 

	// copy private members 
	this->capacity = rhs.capacity;
	this->length = rhs.length;

	return *this;
}

TurtleProgram& TurtleProgram::operator*=(const int num) {
	*this = *this * num;
	return *this; 
}

TurtleProgram& TurtleProgram::operator+=(const TurtleProgram& rhs) {
	*this = *this + rhs; 
	return *this; 
}

std::ostream & operator<<(std::ostream & out, const TurtleProgram& obj) {
	if (obj.length <= 0) {
		out << "[]"; 
	} else {
		out << "[";
		for (int index = 0; index < obj.length - 1; ++index) {
			out << obj.array[index] << " ";
		}

		out << obj.array[obj.length - 1] << "]";
	}
	return out; 
}

bool operator==(const TurtleProgram& obj1, const TurtleProgram& obj2) {
	// If they have the same address, they're equal
	if (&obj1 == &obj2) {
		return true;
	} else if (obj1.length != obj2.length) { // If the sizes are different, they're not equal
		return false;
	} else { // same size but not same stuff
		for (int i = 0; i < obj1.length; ++i) { 
			if (obj1.getIndex(i).compare(obj2.getIndex(i)) != 0) 
				return false; 	
		}
		return true; 
	}
}

bool operator!=(const TurtleProgram & obj1, const TurtleProgram & obj2) {
	if (obj1 == obj2)
		return false; 
	return true; 
}

