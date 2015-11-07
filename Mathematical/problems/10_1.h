#pragma once

/** 10.1 You have a basketball hoop and someone says that you can play 1 of 2 games.
 * Game #1: You get one shot to make the hoop.
 * Game #2: You get three shots and you have to make 2 of 3 shots.
 * If p is the probability of making a particular shot, for which values of p should
 * you pick one game or the other?
 * ====================================================================================
 * * Probability of winning Game 1: p
 * * Probability of winning Game 2:
 * C(n, k) ( 1- p)^(n - k) p^k
 * The probability of winning game 2 is s(2, 3)+s(3, 3) = 3 * (1 - p) * p^2 + p^3 =
 * = 3 * p^2 - 2 * p^3
 *
 * if P(Game1) > P(Game2):
 * p > 3*p^2 - 2*p^3.
 * 1 > 3*p - 2*p^2
 * 2*p^2 - 3*p + 1 > 0
 * (2p - 1)(p - 1) > 0
 * p < 1 => 2p - 1 < 0
 * Answer: we should play Game1 if p < .5.
**/
