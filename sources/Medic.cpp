#include "Medic.hpp"
using namespace std;
using namespace pandemic;

Player& Medic::treat(City geo_location) {
    if(geo!= geo_location){
        throw invalid_argument ("cant treat city u are not in");
    }
    if(board[geo_location] == 0){
        throw invalid_argument ("city is already healthy");
    }
    board[geo_location] = 0;
    return *this;
}