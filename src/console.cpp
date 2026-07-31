#include "console.hpp"
int Console::run(){
do{
    cout<<"\nironhold>";
    cin>>com;
    history.push_back(com);
    if (com == ".quit"){
        return 0;
    }
    else if (com == ".help"){
        cout << ".quit     Shut down the world engine\n .help       Show this message\n .version       Show engine version\n.status       Show world status\n";
    }
    else if (com == ".version"){
        cout << "Chronicle v0.1 — Ironhold World Engine \n";
    }
    else if (com == ".status"){
        cout<< "World: offline\n";
    }
    else if (com == ".history"){
        cout<<"History log:\n";
        for(const string &i: history){
            cout<<"-"<<i<<"\n";
        }
    }
    else if (com[0] == '.'){
        cout<<"AppState::UNKNOWN";
    }
    else{
        cout << "[World command queued: "<<com<<"]\n";
    }
}while(kr);
return 0;
};