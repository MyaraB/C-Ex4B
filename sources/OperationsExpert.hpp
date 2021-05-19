#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"

namespace pandemic{

    class OperationsExpert: public Player {

        public:
            OperationsExpert(Board& board, City geo):Player(board, geo, "OperationsExpert") {}
            Player& build();
    };
}