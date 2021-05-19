#include "Researcher.hpp"
using namespace std;
using namespace pandemic;

Player& Researcher::discover_cure(Color color){
    if(board.exist_cures_color(color)){
        return *this;
    }
    int counter = 0;
    for(const auto& card : cards){
        if(Board::cofc(card)==color){
            counter++;
        }
    }
    if(counter<cards_to_throw){
        throw invalid_argument("not enough cards");
    }
    counter=0;
    for(auto card = cards.begin(); card != cards.end(); ){
        if(counter == cards_to_throw){
            break;
        }
        if(Board::cofc(*card)==color){
            card = cards.erase(card);
            counter++;
        }
        else{
            ++card;
        }
    }
    board.make_cured(color);
    return *this;
}