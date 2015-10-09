#pragma once

/** 6.1 Add arithmetic operators (plus, minus, times, divide) to make
 * the following expression true: 3 1 3 6 = 8. You can use any parentheses you’d like.
 * ===================================================================================
 * 4 * 2 = 8
 * 16 / 2 = 8
 * 4 + 4 = 8
 *
 * Let’s start with the first one. Is there any way to make 3 1 3 6 produce 4 * 2?
 * We can easily notice that 3 + 1 = 4 (the first two numbers). We can also notice that 6 / 3 = 2.
 * If we had “3 1 6 3”, we’d be done, since (3 + 1)*(6 / 3) = 8. Although it seems a little
 * unconventional to do this, we can, in fact, just flip the 6 and the 3 to get the solution.
 *
 * Answer: (( 3 + 1 ) / 3) * 6 = 8
**/
