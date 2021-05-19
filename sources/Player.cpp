#include "Player.hpp"

using namespace std;
using namespace pandemic;

Player& Player::drive(City geo_location){
    if (geo == geo_location){
        throw invalid_argument("you can not fly to the same city you are currently in");
           }
    if(!Board::is_neighbor(geo,geo_location)){
        throw invalid_argument("not neighboring cities");
    }
    geo = geo_location;
    cure_at_arrival();
    return *this;
}

Player& Player::fly_direct(City geo_location){
    if (geo==geo_location){
        throw invalid_argument("you can not fly to the same city you are currently in");
    }
    if(cards.find(geo_location)==cards.end()){
        throw invalid_argument("you do not have the necessary card");
    }
    cards.erase(geo_location);
    geo = geo_location;
    cure_at_arrival();
    return *this;
}

Player& Player::fly_charter(City geo_location){
    if(geo == geo_location){
        throw invalid_argument("you can not fly to the same city you are currently in");
    }
    if(cards.find(geo)==cards.end()){
        throw invalid_argument ("you do not have the necessary card");
    }
    cards.erase(geo);
    geo = geo_location;
    cure_at_arrival();
    return *this;
}
Player& Player::fly_shuttle(City geo_location){
    if(geo==geo_location){
        throw invalid_argument("you cannot fly to the same city you are currently in");
    }
    if(!board.exist_station(geo_location) || !board.exist_station(geo)){
        throw invalid_argument("both cities most have research stations built");
    }
    geo = geo_location;
    cure_at_arrival();
    return *this;
}
Player& Player::build(){
    if(cards.count(geo)==0){
        throw invalid_argument("you do not have the necessary card to build a station in this city");
    }
        board.build_station(geo);
        cards.erase(geo);
        return *this;
    }


Player& Player::discover_cure(Color color){
    if(board.exist_cures_color(color)){
        return *this;
    }
    if(!board.exist_station(geo)){
        throw invalid_argument("no research station in ur city");
    }
    int counter = 0;
    for(const auto& count : cards){
        if(Board::cofc(count) == color){
            counter++;
        }
    }
    if(counter<cards_to_throw){
        throw invalid_argument ("not enough cards of the required color");
    }
    counter =1;
    for(auto card = cards.begin(); card!= cards.end(); counter++){
        if(counter == cards_to_throw){
            break;
        }
        if(Board::cofc(*card) == color){
            card = cards.erase(card);
        }
        else{
            ++card;
        }
    }
    board.make_cured(color);
    return *this;
}

Player& Player::treat(City geo_location){
    if(geo != geo_location){
        throw invalid_argument ("you are not in the correct city");
    }
    if(board[geo_location]==0){
        throw invalid_argument("city is already healthy");
    }
    if(board.exist_cures(geo_location)){
        board[geo_location]=0;
    }
    else{
        board[geo_location]--;
    }
    return *this;
}

Player& Player::take_card(City geo_location){
    cards.insert(geo_location);
    return *this;
}

    