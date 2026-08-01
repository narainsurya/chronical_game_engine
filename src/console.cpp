#include "console.hpp"
#include "world.hpp"    
#include "command.hpp"    
#include <iostream>
#include <string>

using namespace std;

int Console::run() {
    World world;
    string line;

    do {
        cout << "\nironhold> ";
        getline(cin, line);

        if (line.empty()) continue;

        history.push_back(line);

        if (line[0] == '.') {
            if (line == ".quit") {
                return 0;
            }
            else if (line == ".help") {
                cout << ".quit     Shut down the world engine\n"
                     << ".help     Show this message\n"
                     << ".version  Show engine version\n"
                     << ".status   Show world status\n"
                     << ".history  Show command history\n";
            }
            else if (line == ".version") {
                cout << "Chronicle v0.1 — Ironhold World Engine\n";
            }
            else if (line == ".status") {
                cout << "World: online (" << world.get_players().size() << " players)\n";
            }
            else if (line == ".history") {
                cout << "History log:\n";
                for (const string& cmd : history)
                    cout << "- " << cmd << "\n";
            }
            else {
                cout << "AppState::UNKNOWN\n";
            }
            continue;
        }

        SpawnPlayerCommand spawn{};
        bool is_list = false;

        parseOutcome outcome = parse_command(line, spawn, is_list);

        if (outcome.Result == parseResult::SYNTAX_ERROR) {
            cout << outcome.message << "\n";
            continue;
        }

        if (is_list) {
            const auto& players = world.get_players();
            for (const auto& p : players) {
                cout << "[" << p.id << "] " << p.username << " <" << p.email << ">\n";
            }
            cout << players.size() << " entities.\n";
        }
        else {
            Player p(spawn.id, spawn.username, spawn.email);
            if (world.spawn(p)) {
                cout << "Spawned.\n";
            } else {
                cout << "Error: Player ID already exists.\n";
            }
        }

    } while (true);

    return 0;
}