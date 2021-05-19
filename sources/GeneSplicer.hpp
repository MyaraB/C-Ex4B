#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{

    class GeneSplicer: public Player {

        public:
            GeneSplicer(Board& board, City geo): Player(board, geo, "GeneSplicer") {}
            Player& discover_cure(Color color);
    };
}