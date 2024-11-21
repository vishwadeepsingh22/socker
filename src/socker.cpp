//============================================================================
// Name        : socker.cpp
// Author      : Vishwadeep Singh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

string name = "Vishwadeep Singh";
int num = 100 + 200;

// types of variables
int myNum = 5;               // Integer (whole number without decimals)
float fin = 30.101;
double myFloatNum = 5.99;    // Floating point number (with decimals)
char myLetter = 'D';         // Character
string myText = "Hello";     // String (text)
bool myBoolean = true;       // Boolean (true or false)

int x = 5, y = 6, z = 7; // multiple variable declaration

// Variable names are called identifiers and are case sensitive &
// should be different from c++ keywords

const int cx = 100; // this cant be changed and when defined, value must be assigned

int main(void) {
	cout << "Hello World " << name << "!!" << endl;
	cout << "Number is " << num << endl;
	cout << myNum << endl;
	cout << fin << endl;
	cout << myFloatNum << endl;
	cout << myLetter << endl;
	cout << myText << endl;
	cout << myBoolean << endl;

	cout << cx << endl;

	/* C++ operators
		1. arithmetic operators
			a) + - * / % (binary operators)
			b) ++ -- (unary operators)
		2. Logical Operators
			a) && (AND)
			b) || (OR)
			c) ! (NOT)
		3. Bitwise Operators
			a) & (bitwise AND) : takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are 1. eg: a & b
			b) | (bitwise OR) : takes two numbers as operands and does OR on every bit of two numbers. The result of OR is 1 if any of the two bits is 1. eg: a | b
			c) ^ (bitwise XOR) : takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different. eg: a ^ b
			d) << (bitwise left shift) : takes two numbers, the left shifts the bits of the first operand, and the second operand decides the number of places to shift. eg: a << 1
			e) >> (bitwise right shift) : takes two numbers, right shifts the bits of the first operand, and the second operand decides the number of places to shift. eg: a >> 1
			f) ~ (bitwise NOT) : C takes one number and inverts all bits of it. eg: a = ~a
		4. assignment operators
			a) = += -= *= /= %=
			b) &=  |= ^= >>= <<=
		5. Comparison operators or Relational Operators
			a) == != > <
			b) >= <=
		6. Ternary or Conditional Operators
			a) Expression1? Expression2: Expression3
	*/

	// Bitwise operator
	int xb = 10; // 1010
	int yb = 11; // 1011

	// for bitwise AND: result of AND is 1 only if both bits are 1.
	cout << (xb & yb) << endl; // means it will come 1010, it should be 10
	// for bitwise OR: result of OR is 1 if any of the two bits is 1.
	cout << (xb | yb) << endl; // means it will come 1011, it should be 11
	// for bitwise XOR: result of XOR is 1 if the two bits are different.
	cout << (xb ^ yb) << endl; // means it will come 0001, it should be 1
	// for bitwise left shift: right operand decides how many shift needs to be done on left operand
	cout << (xb << 1) << endl; // means it will come 10100, it should be 20
	// for bitwise right shift: right operand decides how many shift needs to be done on left operand
	cout << (xb >> 1) << endl; // means it will come 0101, it should be 5
	// for bitwise NOT: takes one number and inverts all bits of it.
	cout << (~xb & 0xF) << endl; // means it will come 0101, it should be 5; here The hexadecimal value 0xF is 1111 in binary. here masking bits is also happening

	// Masking bits
	/*
	 * Masking in programming refers to applying a bitwise AND operation with a mask to selectively retain or
	 * clear certain bits in a binary number. A mask is a binary value with specific bits set to 1 (to retain) or 0 (to clear).
	 * When working with numbers of different bit sizes, masking ensures only the desired bits are retained, discarding any unwanted or sign-extended bits.
	 * Suppose you want to work only with the lower 4 bits of a number.
	 * Number: 10101101
	 * Mask: 00001111
	 * Operation: 10101101 & 00001111 = 00001101
	 *
	 * General Masking for Different Bit Sizes: When we do & (AND) operation, then we make sure rest all become irrelevant and only desired bits we extract
	 * For 4 Bits: Use & 0xF. binary: 1111
	 * For 8 bits: Use & 0xFF. binary: 11111111
	 * For 16 bits: Use & 0xFFFF. binary: 11111111 11111111.
	 * For 32 bits: Use & 0xFFFFFFFF. binary: 11111111 11111111 11111111 11111111.
	 *
	 * Uses of masking:
	 * Ensuring unsigned interpretation: Masking prevents sign extension by limiting the result to a fixed number of bits.
	 * Extracting specific bits: Retain only the bits you're interested in (e.g., lower 4 bits, 8 bits).
	 * Clearing bits: Remove unwanted bits by ANDing with a mask of 0s in those positions.
	 * Manipulating hardware registers: Set or clear specific bits when working with microcontrollers or hardware.
	 * */

	// Special Bit operations
	// Bitwise operations are usually faster than arithmetic operations (e.g., multiplication and division) because they directly manipulate the bits at a low level.
	// They are particularly useful in resource-constrained environments (e.g., embedded systems) where memory and processing power are limited.
	// 1. Setting particular Bit
	// 2. Clear a Bit
	// 3. toggle a bit
	// 4. Check if particular bit is set


	/*
	 * Common Applications of Bitwise Operations
	Flags and Bitfields: Bitwise operations are often used to manage flags and settings where each bit represents a boolean value (e.g., whether a feature is enabled or disabled).
		#define FEATURE_A 0x01  // 00000001
		#define FEATURE_B 0x02  // 00000010

		int settings = 0;  // No features enabled
		settings |= FEATURE_A;  // Enable FEATURE_A
		settings &= ~FEATURE_B; // Disable FEATURE_B
	Efficient Multiplication and Division by Powers of 2: Left shifts are equivalent to multiplying by powers of 2, and right shifts are equivalent to dividing by powers of 2.
		int value = 10;
		value = value << 3;  // Multiply by 8 (2^3), value = 80
		value = value >> 2;  // Divide by 4 (2^2), value = 20
	Extracting Multiple Bits (Masking): You can use bitwise operations to extract multiple bits from a number.
		int value = 0b11011010;
		int extracted = (value >> 2) & 0b111;  // Extract the 3 middle bits, result = 110

	 Practical Example: Let's say you're working with a 32-bit integer, and you want to extract the highest 8 bits:
		int num = 0x12345678;  // Binary: 00010010001101000101011001111000
		int mask = 0xFF000000;  // Mask to isolate the highest 8 bits: 11111111000000000000000000000000
		int result = (num & mask) >> 24;  // Shift the highest 8 bits to the least significant part
		cout << "The highest 8 bits: " << hex << result << endl;  // Output: 12
	 * */

	return 0;
}
