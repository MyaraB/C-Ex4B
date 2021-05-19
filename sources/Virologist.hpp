#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"

namespace pandemic{

    class Virologist: public Player {

        public:
            Virologist(Board& board, City geo): Player(board, geo, "Virologist") {}
            Player& treat(City geo);
    };
}