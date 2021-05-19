#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;

Player& Dispatcher::fly_direct(City geo){
    if (this->geo == geo){
        throw std::invalid_argument{" cant fly to a city u are all ready in"};
    }

    if(board.exist_station(this->geo)){
        this->geo = geo;
    }

    else{
        return Player::fly_direct(geo);
    }
    
    return *this;
}
