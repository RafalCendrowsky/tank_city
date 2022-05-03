#include <vector>
#include "./entity/player_tank.h"
#include "./entity/enemy_tank.h"
#include "./entity/target.h"

class GameManager{
    public:
        enum e_type{};
        void endGame();
        PlayerTank & startGame(b2World& world);
        void movePlayer(PlayerTank::eDirection direction);
        void stopPlayer();
        bool playerHasShot();
        Bullet & shootPlayer();
        EnemyTank& createTank(e_type type, b2World& world);
    private:
        std::vector<EnemyTank*> tanks;
        std::unique_ptr<PlayerTank> playerPtr;
        Target target;
};