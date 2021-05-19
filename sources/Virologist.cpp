#include "Virologist.hpp"
using namespace std;
using namespace pandemic;

Player& Virologist::treat(City geo_location){
    if(geo != geo_location){
        if(cards.count(geo_location)==0){
            throw invalid_argument("no cards for the required city");
        }
        cards.erase(geo_location);
    }
    else if(board[geo_location] == 0){
        throw invalid_argument("city is already healthy");
    }
    else if(board.exist_cures(geo_location)){
        board[geo_location] = 0;
        return *this;
    }
    board[geo_location]--;
    return *this;
}