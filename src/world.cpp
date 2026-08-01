#include "world.hpp"
using namespace std;
bool World::spawn(const Player& p) {
    for (const auto& existing : players_) {
        if (existing.id == p.id)
            return false;
    }
    players_.push_back(p);
    return true;
}
const vector<Player>& World::get_players() const {
    return players_;
}