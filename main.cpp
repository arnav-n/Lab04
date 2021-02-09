#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include "dataAQ.h"
#include "demogData.h"
#include "comboDemogData.h"
#include "comboHospitalData.h"
#include "countyDemogData.h"
#include "comboHospitalData.h"
#include "hospitalData.h"
#include "cityHospitalData.h"
#include "parse.h"

using namespace std;

int main() {

	dataAQ theAnswers;


    cout << std::setprecision(2) << std::fixed;

    //read in the helper file to map city to county
    theAnswers.read_csvCityCounty("simple_uscities.csv");

    //read in the hospital data
    std::vector<shared_ptr<placeData>> theHospitalData = read_csv(
            "hospitals.csv", HOSPITAL);
   
    //read in the demographic data
    std::vector<shared_ptr<placeData>> theCountyDemogData = read_csv(
            "county_demographics.csv", DEMOG); 

    //create the state demographic data
    theAnswers.createStateDemogData((std::vector<shared_ptr<demogData>>&)theCountyDemogData);

    //create the state hospital data
    theAnswers.createStateHospData((std::vector<shared_ptr<hospitalData>>&)theHospitalData);

     //create the county hospital data   
    theAnswers.createCountyHospData((std::vector<shared_ptr<hospitalData>>&)theHospitalData);
    
   

    //same as lab03 but using new types
    std::vector<comboHospitalData*> ShospHighToLow;
    theAnswers.sortHospRatingHighLow((std::vector<comboHospitalData *>& )ShospHighToLow, "state");
    cout << "the 10 state with highest hospital ratings sorted on overall: " << endl;
    for (int i=0; i < 10; i++) {
        cout << i<< " " << ShospHighToLow.at(i)->getRegion() << " " << ShospHighToLow.at(i)->getName();
        cout <<  " overall hospital rating: " << ShospHighToLow.at(i)->getOverallRate() << endl;
    }

    //TODO add others

    return 0;
}

