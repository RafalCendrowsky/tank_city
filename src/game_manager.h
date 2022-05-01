#include <vector>
#include "./entity/player_tank.h"
#include "./entity/enemy_tank.h"
#include "./entity/target.h"

class GameManager{
    public:
        enum e_type{};
        void endGame();
        void startGame();
        EnemyTank& createTank(e_type type);
    private:
        std::vector<EnemyTank> tanks;
        PlayerTank player;
        Target target;
};