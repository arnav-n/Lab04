#ifndef PLACE_H
#define PLACE_H

#include <string>
#include <iostream>

using namespace std;

/* very general data type for any kind of place data - very simple for lab04 */
class placeData {
  public:
    string getName(){ return placename;}
  protected:
    //place name
    string placename;
};
#endif
