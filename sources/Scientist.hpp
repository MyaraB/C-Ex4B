#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"


namespace pandemic {

    class Scientist: public Player {
        int n;

        public:
            Scientist(Board& board, City geo, int amount): Player(board, geo, "Scientist"), n(amount) {}
            Player& discover_cure(Color color) override;
    };  
}