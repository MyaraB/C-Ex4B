#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"

namespace pandemic{

    class Medic: public Player {

        public:
            Medic(Board& board, City geo): Player(board, geo, "Medic") {}
            Player& treat(City geo);
            void cure_at_arrival(){if (board.exist_cures(geo)){board[geo]=0;}}
    };
}