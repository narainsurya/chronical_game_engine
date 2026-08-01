#include <string>
#include <cstdint>
using namespace std;
enum class parseResult{
    SUCCESS,
    SYNTAX_ERROR
};

struct SpawnPlayerCommand{
    uint32_t id;
    string username;
    string email;;
};

struct parseOutcome{
    parseResult Result;
    string message;
};

struct ListPlayersCommand{};

parseOutcome parse_command(const std::string& input,
                           SpawnPlayerCommand& spawn,
                           bool& is_list);