#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>

namespace pandemic {

    class Player {

        protected:
            Board& board;
            City geo;
            std::set<City> cards;
            std::string _role;
            const int cards_to_throw = 5;

        public:
            Player(Board& boards, City geo_location, std::string role): board(boards), geo(geo_location), _role(role){}
            Player& drive(City geo_location);
            virtual Player& fly_direct(City geo_location);
            Player& fly_charter(City geo_location);
            Player& fly_shuttle(City geo_location);
            virtual Player& build();
            virtual Player& discover_cure(Color color);
            virtual Player& treat(City geo_location);
            std::string role(){return _role;}
            Player& take_card(City geo_location);
            Player& remove_cards(); 
            virtual void cure_at_arrival(){}
   
    };

}