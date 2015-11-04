#pragma once

/** 5.5 Write a function to determine the number of bits required
 *  to convert integer A to integer B.
Input: 31, 14
Output: 2
 * ========================================================================================
 * This seemingly complex problem is actually rather straightforward. To approach this, ask
 * yourself how you would figure out which bits in two numbers are different. Simple: with an xor.
**/

int bitSwapRequired(int a, int b) {
	int count = 0;
	for (int c = a ^ b; c != 0; c = c >> 1) {
		count += c & 1;
	}
	return count;
}

