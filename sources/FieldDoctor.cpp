#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;


Player& FieldDoctor::treat(City geo){
    if(!Board::is_neighbor(this->geo,geo) && this->geo!=geo ){
        throw std::invalid_argument("cities are not neiboring cities");
    }
    if(board[geo]==0){
        throw std::invalid_argument("city is already healthy");
    }
    if(board.exist_cures(geo)){
        board[geo] = 0;
    }
    else{
        board[geo]--;
    }
    return *this;
}