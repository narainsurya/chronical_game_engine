#include <vector>
#include "player.hpp"
using namespace std;
class World {
public:
    bool spawn(const Player& p);
    const vector<Player>& get_players() const;
private:
    vector<Player> players_;
};