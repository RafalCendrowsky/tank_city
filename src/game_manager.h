#include <vector>
#include "../player_tank.h"
#include "../enemy_tank.h"

class GameManager{
    public:
        void endGame();
        void startGame();
        &EnemyTank createTank(enum type);
    private:
        std::vector<EnemyTank> tanks;
        PlayerTank player;
        Target target;
};