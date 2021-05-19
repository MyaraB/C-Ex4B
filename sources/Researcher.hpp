#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{

    class Researcher: public Player {

        public:
            Researcher(Board& board, City geo): Player(board, geo, "Researcher") {}
            Player& discover_cure(Color c);
    };
}