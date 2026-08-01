#include "command.hpp"
#include <sstream>
#include <string>

using namespace std;

parseOutcome parse_command(const string& input,SpawnPlayerCommand& spawn,bool& is_list){
    istringstream in(input);
    string cmd, type;
    if (!(in >> cmd >> type)) {
        return {parseResult::SYNTAX_ERROR, "Error: Invalid command syntax"};
    }

    if (cmd == "LIST" && type == "PLAYERS") {
        string extra;
        if (in >> extra) {
            return {parseResult::SYNTAX_ERROR, "Error: Invalid command syntax"};
        }
        is_list = true;
        return {parseResult::SUCCESS,""};
    }
    if (cmd == "SPAWN" && type == "PLAYER") {
    string id_str;
    if (!(in >> id_str >> spawn.username >> spawn.email)) {
        return {parseResult::SYNTAX_ERROR, "Error: Invalid command syntax"};
    }

    string extra;
    if (in >> extra) {
        return {parseResult::SYNTAX_ERROR, "Error: Invalid command syntax"};
    }

    if (id_str.empty() || id_str[0] == '-' || id_str[0] == '+') {
        return {parseResult::SYNTAX_ERROR, "Error: ID must be positive."};
    }

    char* end = nullptr;
    unsigned long val = strtoul(id_str.c_str(), &end, 10);

    if (*end != '\0' || val == 0 || val > UINT32_MAX) {
        return {parseResult::SYNTAX_ERROR, "Error: ID must be positive."};
    }

    spawn.id = static_cast<uint32_t>(val);

    if (spawn.username.size() > 32) {
        return {parseResult::SYNTAX_ERROR, "Error: username too long(max 32 chars)"};
    }
    if (spawn.email.size() > 255) {
        return {parseResult::SYNTAX_ERROR, "Error: email too long(max 255 chars)"};
    }
    is_list = false;
    return {parseResult::SUCCESS, ""};
}
    return {parseResult::SYNTAX_ERROR,"Error: Invalid command syntax"};
}