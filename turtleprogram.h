/**************************
* Tran Le
* CSS343 - WINTER2018
* Ass1: Turtle Program
* Last edited: 1/13/2018
***************************/

////////////////////////////////////////
// turtleprogram.h defines the TurtleProgram class
// which is simply an array manipulation class that has
// the following functionalities:
// - overloaded operators: +, +=, *, *=, =, ==, and !=
// - getters and setter functions
// 
// Assumptions: 
// - Can't multiply two TurtleProgram 
// - Can't multiply by 0, or multiply on empty TurtleProgram
// - Strings in the array can be anything
////////////////////////////////////////
#ifndef TURTLE_PROGRAM 
#define TURTLE_PROGRAM 

#include <iostream>
#include <string>
class TurtleProgram {
public: 
	// Constructors 
	TurtleProgram();
	TurtleProgram(const std::string& moveChar, const std::string& num);
	TurtleProgram(const TurtleProgram& obj); 
	// Destructor
	virtual ~TurtleProgram();

	// Getters
	// Length of array
	int getLength() const;
	// Get value at n index in array
	const std::string& getIndex(const int index) const;  

	// Setters 
	// Set the value at n index in array
	void setIndex(const int index, const std::string value); 


	// Member Operator Overloads 
	// Add two TurtleProgram to make a longer TurtleProgram
	TurtleProgram operator+(const TurtleProgram& rhs);
	// Multiply this TurtleProgram to make a longer TurtleProgram
	TurtleProgram operator*(const int num);
	// Assignment operator
	TurtleProgram& operator=(const TurtleProgram& rhs);
	// same as * operator
	TurtleProgram& operator*=(const int num);
	// Same as + operator
	TurtleProgram& operator+=(const TurtleProgram& rhs);


	// Friend Operator Overloads
	// cout the array surrounded by brackets []
	friend std::ostream& operator<<(std::ostream &out, const TurtleProgram& obj);
	// Equality operator
	friend bool operator==(const TurtleProgram& obj1, const TurtleProgram& obj2); 
	// Returns oposite of equality operator
	friend bool operator!=(const TurtleProgram& obj1, const TurtleProgram& obj2); 

private:
	std::string* array; 
	int length;    // Array size 
	int capacity;  // I did not need this variable, but it's apart of
				   // my prior implimentation where the array doubles each 
				   // time it runs out of room. Now the array just grows
				   // by one to add another string in

	// Private methods
	void growArray();	// Add 1 more size into array 
	void insert(const std::string& value);	// add value to the end of array
};

#endif  // !TURTLE_PROGRAM