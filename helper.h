#ifndef	HELPER_H
#define HELPER_H

#include <string>

enum colour {Black, White};
const int NUM_ROWS = 8;
const int NUM_COLS = 8;

int input_check (std::string origin, std::string destination);

bool rangeCheck(int number);

void checkError(int number);

//bool diagonalCheck (info)

#endif
