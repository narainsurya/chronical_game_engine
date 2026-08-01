#include <cstdint>
#include <string>
#include <utility> 
using namespace std;
struct Player{
    uint32_t id;
    string username;
    string email;

    Player(uint32_t id_ , string username_ , string email_)
        : id(id_) , username(std::move(username_)) , email(std::move(email_)){}
};