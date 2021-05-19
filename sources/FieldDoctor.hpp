#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"

namespace pandemic{

    class FieldDoctor: public Player {

        public:
            FieldDoctor(Board& board, City geo): Player(board, geo, "FieldDoctor") {}
            Player& treat(City geo);
    };
}