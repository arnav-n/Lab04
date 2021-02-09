/* aggregate data */
#include "dataAQ.h"
#include "demogData.h"
#include "comboDemogData.h"
#include "comboHospitalData.h"
#include "countyDemogData.h"
#include "comboHospitalData.h"
#include "hospitalData.h"
#include "cityHospitalData.h"
#include "parse.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#define DEBUG false

dataAQ::dataAQ() {}

/* necessary function to aggregate the data - this CAN and SHOULD vary per
   student - depends on how they map, etc. */
void dataAQ::createStateDemogData(std::vector<shared_ptr<demogData>>& theData) {
	    //process the vector in our county data aggregate 
    for (const auto &obj : theData) {
        string stateName = obj->getState();
        //if first state entry, create it
        if (allStateDemogData.count(stateName) < 1) {
           //cout << "Making a new state entry: " << stateName << endl;
           allStateDemogData[stateName] = new comboDemogData("state", stateName);
        }
        //either way now add this county info 
        //this keeps a running total
        allStateDemogData[stateName]->addDemogtoRegion(obj);
    }
  

}


void dataAQ::createStateHospData(std::vector<shared_ptr<hospitalData>>& theData) {


}


void dataAQ::createCountyHospData(std::vector<shared_ptr<hospitalData>>& theHospitalData) {
  
}




void dataAQ::sortHospRatingLowHigh(std::vector<comboHospitalData *>& hospLowToHigh, 
  string regionType) {

}


void dataAQ::sortHospRatingHighLow(std::vector<comboHospitalData *>& hospHighToLow, 
  string regionType) {

}


/* for a specific state... */
void dataAQ::sortHospRatingHighLowForState(std::vector<comboHospitalData *>& hospHighToLow, string state) {


}




 void dataAQ::sortDemogPovLevelLowHigh(std::vector<demogData *>& povLevelLowHigh) {



}




 void dataAQ::sortDemogPovLevelHighLow(std::vector<demogData *>& povLevelHighLow) {



}



/*functions to parse city to county helper map */
void dataAQ::read_csvCityCounty(std::string filename) {

    // Create an input filestream
    std::ifstream myFile(filename);

    // Make sure the file is open
    if(!myFile.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    if(myFile.good()) {
        consumeColumnNames(myFile);

        // Helper vars
        std::string line, state, junk;

        // Now read data, line by line and enter into the map
        while(std::getline(myFile, line)) {

          std::stringstream ss(line);

          string city = getFieldNQ(ss);
          state = getFieldNQ(ss);
          junk = getFieldNQ(ss);
          string county = getFieldNQ(ss);

          string cityKey = city+state;

          cityToCounty[cityKey] = county;

          //cout << "line: " << line << endl;
          //cout << "pair (city, county): " << city << ", " << county << " state " << junk << endl;
        }

        // Close file
        myFile.close();
    }

}
