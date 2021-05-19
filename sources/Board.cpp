#include <map>
#include <set>
#include "Board.hpp"
#include <iostream>

using namespace std;

namespace pandemic{

Board::Board(){}
Board::~Board(){}

int& Board::operator[](City city){return disease_lvl[city];}

void Board::remove_cures(){
    disc_cures.clear();
}

bool Board::exist_cures(City city) {
    return disc_cures.count(CofC.at(city)) == 1;
}
bool Board::exist_cures_color(Color color) {
    return disc_cures.count(color) == 1;
}

void Board::remove_stations(){
    research_stations.clear();
}

void Board::make_cured(Color color){
    disc_cures.insert(color);
}

bool Board::is_clean(){
    for(auto& pair: disease_lvl){
        if(pair.second>0){
            return false;
        }
    }
    return true;
}

void  Board::build_station(City city){
    research_stations.insert(city);
    }

 Color Board::cofc(City city){
     return CofC.at(city);
 }

bool Board::exist_station(City city){
    return research_stations.count(city)==1 ;
    
}

bool Board::is_neighbor (City& city1, City& city2){
    return connected.at(city1).count(city2)>0;
}

ostream &operator<<(std::ostream &out, Board &b){return out;}


};