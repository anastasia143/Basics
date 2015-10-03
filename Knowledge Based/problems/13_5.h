#pragma once

/** What is the significance of the keyword “volatile” in C?
 * ==========================================================
 * Volatile informs the compiler that the value of the variable
 * can change from the outside, without any update done by the code.
 *
 * Volatile variables are not optimized, but this can actually be useful.
 * int opt = 1; if (opt == 1) goto start; -> (compiler) -> if (true) goto start;
 * It`s wrong!
**/

void example()
{
	// Declaring a simple volatile variable:
	volatile int x1;
	int volatile x2;

	// Declaring a pointer variable for a volatile memory (only the pointer address is volatile):
	volatile int * x3;
	int volatile * x4;

	// Declaring a volatile pointer variable for a non-volatile memory (only memory contained is volatile):
	int * volatile x5;

	// Declaring a volatile variable pointer for a volatile memory
	// (both pointer address and memory contained are volatile):
	volatile int * volatile x6;
	int volatile * volatile x7;
}
