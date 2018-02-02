/**************************
* Tran Le
* CSS343 - WINTER2018
* Ass1: Turtle Program
* Last edited: 1/13/2018
***************************/

/////////////////////////////////////////
// ass1.cpp is the main file for testing
// the TurtleProgram class
/////////////////////////////////////////

#include <iostream>
#include "turtleprogram.h"
using namespace std;
int main() {
	// Testing << : GOOD
	TurtleProgram tp1("F", "90");
	std::cout << "tp1: " << tp1 << std::endl;

	// Testing = operator : GOOD FOR NOW
	TurtleProgram tp2("R", "90");
	tp1 = tp2;
	std::cout << "tp1 now is: " << tp1 << std::endl;
	TurtleProgram tp3;
	std::cout << "Tp3 is [] : " << tp3 << std::endl;
	tp1 = tp3;
	std::cout << "tp1 now should be empty: " << tp1 << std::endl;	// She even works with an empty object now

	// Testing + : WORKING
	TurtleProgram tp4("F", "90");
	std::cout << tp4 << std::endl;
	tp1 = tp4 + tp2;
	std::cout << "tp1 now as tp4 + tp2 : " << tp1 << std::endl;
	std::cout << "tp4 should be F 90: " << tp4 << std::endl;
	// testing for + with an empty object
	TurtleProgram empty; 
	TurtleProgram tp4Test;
	tp4Test = tp4 + empty; 
	std::cout << "tp4 + empty should be tp4: " << tp4Test << std::endl;

	// Testing * : IT'S NOW WORKING
	tp1 = tp4 * 3;
	std::cout << "tp1 now as tp4 * 3: " << tp1 << std::endl;
	try {
		tp4 = tp4 * 0;
		std::cout << "tp4 * 0 is: " << tp4 << std::endl;
	} catch (std::invalid_argument& iva) {
		std::cout << iva.what() << std::endl;
	}
	// Testing copy operator : WORKING
	TurtleProgram tp5(tp1);
	std::cout << "tp5 as tp1: " << tp5 << std::endl;

	// Testing *= : WORKING
	tp5 *= 2;
	std::cout << "tp5*=2: " << tp5 << std::endl;

	// Testing += : WORKING
	tp1 += tp2;
	std::cout << "tp1 should be really long ending with R 90: " << tp1 << std::endl;

	// Testing == : WORKING
	TurtleProgram tp6("R", "90");
	std::cout << std::boolalpha;
	std::cout << "tp2 == tp6 (true): " << (tp2 == tp6) << std::endl;
	std::cout << "tp1 == tp6 (false): " << (tp1 == tp6) << std::endl;
	std::cout << "tp1 == tp1 (true): " << (tp1 == tp1) << std::endl;

	// Testing != : WORKING
	TurtleProgram tp7("T", "0");
	std::cout << "tp1 != tp6 (true): " << (tp1 != tp6) << std::endl;
	std::cout << "tp1 != tp1 (false): " << (tp1 != tp1) << std::endl;
	std::cout << "tp6 != tp7 (true): " << (tp6 != tp7) << std::endl;

	// Testing getLength, setIndex, getIndex : WORKS
	try {
		std::cout << tp7.getIndex(2);
	} catch (const std::out_of_range& oor) {
		std::cout << oor.what() << std::endl;
	}
	std::cout << "tp7[1]: " << tp7.getIndex(1) << std::endl;
	tp7.setIndex(0, "max"); 
	tp7.setIndex(1, "tran");
	std::cout << "tp7 after setting 0 and 1 with max and tran: " << tp7 << std::endl;
	std::cout << "Done." << std::endl;
	return 0;
	
	//// Professor's given test 
	//TurtleProgram tp1;
	//cout << "tp1: " << tp1 << endl;
	//TurtleProgram tp2("F", "10");
	//cout << "tp2: " << tp2 << endl;
	//TurtleProgram tp3("R", "90");
	//tp1 = tp2 + tp3;
	//cout << "tp1 now as tp2+tp3: " << tp1 << endl;
	//tp1 = tp2 * 3;
	//cout << "tp1 now as tp2 * 3: " << tp1 << endl;
	//TurtleProgram tp4(tp1);
	//cout << "tp4 is a copy of tp1: " << tp4 << endl;
	//TurtleProgram tp5("F", "10");
	//cout << "tp5: " << tp5 << endl;
	//cout << boolalpha;
	//cout << "tp2 and tp5 are == to each other: " << (tp2 == tp5) << endl;
	//cout << "tp2 and tp3 are != to each other: " << (tp2 != tp3) << endl;
	//cout << "index 0 of tp2 is " << tp2.getIndex(0) << endl;
	//tp2.setIndex(0, "R");
	//tp2.setIndex(1, "90");
	//cout << "tp2 after 2 calls to setIndex: " << tp2 << endl;
	//cout << "tp2 and tp3 are == to each other: " << (tp2 == tp3) << endl;
	//// need to write additional tests for += *=
	//cout << "Done." << endl;
	//return 0; 
}