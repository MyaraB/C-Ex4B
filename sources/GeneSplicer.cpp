#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;

Player& GeneSplicer::discover_cure(Color color){
    if(board.exist_cures_color(color)){
        return *this;
    }
    if(!board.exist_station(geo)){
        throw invalid_argument("no research station in ur corrent city");
    }
    if(cards.size()<cards_to_throw){
        throw invalid_argument("not enough cards");
    }
    int counter =1;
    for(auto card = cards.begin(); card !=cards.end(); counter++){
        if(counter==cards_to_throw){break;}
        card = cards.erase(card);
    }
    board.make_cured(color);
    return *this;
}