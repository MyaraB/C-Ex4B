#include "Scientist.hpp"
using namespace std;
using namespace pandemic;

Player& Scientist::discover_cure(Color color) {
    if(board.exist_cures_color(color)){
        return *this;
    }
    if(!board.exist_station(geo)){
        throw invalid_argument("no research station in this city");
    }
    int counter = 0;
    for(const auto& card: cards){
        if(Board::cofc(card)== color){
            counter++;
        }
    }
    if(counter<n){
        throw invalid_argument("you do not have enough cards of the required color");
    }
    counter =1;
    for(auto card = cards.begin(); card != cards.end(); counter++){
        if(counter == n){break;}
        if(Board::cofc(*card)==color){
            card = cards.erase(card);
        }
        else{
            ++card;
        }
    }
    board.make_cured(color);
    return *this;
}