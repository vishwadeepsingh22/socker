//============================================================================
// Name        : socker.cpp
// Author      : Vishwadeep Singh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>

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

void print_binary(int number, int total_bits) {
	cout << "(";
    for (int i = total_bits - 1; i >= 0; i--) {
        printf("%lu", (number >> i) & 1);
    }
    cout << ")" << endl;
}

int bit_set(int number, int n) {
    return number | (1 << n);
}

int bit_clear(int n, int k) {
	return (n & (~(1 << (k))));
}

int bit_toggle(int number, int n) {
    return number ^ (1 << n);
}

bool is_bit_set(int n, int k) {
	print_binary(n,16);
	if (n & (1 << k)) {
		cout << "INDEX: " << k << " is SET!" << endl;
		return true;
	}
	cout << "INDEX: " << k << " is NOT SET!" << endl;
	return false;
}

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

	
	// Setting up a particular bit
	// example: 5 (0101) setting up 2nd bit (index 1, counting from right side) to 1 means it should be 0111 (number: 7)
	// int a = 5;  // Binary: 0101
    // int position = 1;  // We want to set the 2nd bit (index 1)
	// EQUATION -
	// a |= (1 << position);
	// explanations:
	// (1 << position): This is for masking
	// 0001 << 2: This will result: 0100
	// OR between 0101 (5) | 0100 (Mask)
	//          0101
	//      OR  0010
	// Result:  0111

    int number = 5; // Example number in binary: 0101
    int n = 1;       // Example: bit position 3 (starting from 0 RHS)
    cout << "Initial number: " << number << endl;
    print_binary(number, 16);  // Print number in binary
    cout << "Setting bit: " << n << endl;
	number = bit_set(number, n);
	cout << "Number after setting bit: " << number << endl;
	print_binary(number, 16);

	// Clearing up the bit
	// Example:
	// number = 5 (0101)
	// updating the 2nd postion from right side (using 0th position) with clearing a bit (means set to 0)
	// it should change to 0001
	// position = 2
	// EQUATION -
	// n & ( ~ (1 << position) );
	// explanations:
	// (1 << position): This is for masking
	// 0001 << 2: This will result: 0100
	// ~ (0100) will result to 1011
	// AND between 0101 (5) & 1011 (~Mask)
	//          0101
	//     AND  1011
	// Result:  0001

	number = 5;
	n = 2;
	cout << "Initial number: " << number << endl;
	print_binary(number, 16);  // Print number in binary
	cout << "Clearing bit: " << n << endl;
	number = bit_clear(number, n);
	cout << "Number after clearing bit: " << number << endl;
	print_binary(number, 16);

	// Toggle a bit
	// Example:
	// number = 5 (0101)
	// updating the 1st postion from right side (using 0th position) with clearing a bit (means set to 0)
	// it should change to 0111
	// position = 1
	// EQUATION -
	// n ^ (1 << position);
	// explanations:
	// (1 << position): This is for masking
	// 0001 << 1: This will result: 0010
	// XOR between 0101 (5) ^ 0010 (Mask)
	//          0101
	//     XOR  0010
	// Result:  0111

	number = 5;
	n = 1;
	cout << "Initial number: " << number << endl;
	print_binary(number, 16);  // Print number in binary
	cout << "Toggle bit: " << n << endl;
	number = bit_toggle(number, n);
	cout << "Number after toggle bit: " << number << endl;
	print_binary(number, 16);

	// Check a bit is set or not
	// Example:
	// number = 5 (0101)
	// check if 1st postion from right side (using 0th position) is 1 or not
	// here it is false
	// position = 1
	// EQUATION -
	// n & (1 << position);
	// explanations:
	// (1 << position): This is for masking
	// 0001 << 1: This will result: 0010
	// AND between 0101 (5) & 0010 (Mask)
	//          0101
	//     AND  0010
	// Result:  0000 --> false

	number = 5; // (0101)
	is_bit_set(number, 0); // true
	is_bit_set(number, 1); // false
	is_bit_set(number, 2); // true
	is_bit_set(number, 3); // false

	// Efficiently Setting up a feature to Enable OR Disable
	// #define FEATURE_A 0x01  // 00000001
	// #define FEATURE_B 0x02  // 00000010
	// int settings = 0;  // No features enabled
	// settings |= FEATURE_A;  // Enable FEATURE_A
	// settings &= ~FEATURE_B; // Disable FEATURE_B

	// Extract particular Range of bits




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
