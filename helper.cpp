#include <iostream>

#include "helper.h"
#include <string>

using namespace std;

//THIS NEEDS SOME MORE WORK(WHAT IF INPUT IS DOUBLE DIGITS)
bool input_check (string origin, string destination)
{

  if(origin == destination)
  {
    cerr << "Piece moved to same pos." << endl;
    return false;

  }

  if(origin.length() != 2)
  {
    cerr << "Origin invalid." << endl;
    return false;
  }

  if(destination.length() != 2)
  {
    cerr << "Destination invalid." << endl;
    return false;
  }

//Moving the following checks into moveCheck
/*
  if(static_cast<char>(origin[0]) > 'H' || static_cast<char>(origin[0]) < 'A')
    return false;

  if(atoi(&origin[1]) > 8 || atoi(&origin[1]) < 1)
    return false;

  if(static_cast<char>(destination[0]) > 'H' || static_cast<char>(destination[0]) < 'A')
    return false;

  if(atoi(&destination[1]) > 8 || atoi(&destination[1]) < 1)
    return false;
*/
  return true;
}

bool rangeCheck (int number)
{
  if(number >= 0 && number <= 7)
    return true;
  else
    return false;

}
