#include </home/24pc16/24pc16_m1/include/application_state.hpp>
class Console{
    private:
        string com;
        bool kr = true;
    public:
        int run(){
            do{
                cout<<"\nironhold>";
                cin>>com;
                if (com == ".quit"){
                    return 0;
                }
                else if (com == ".help"){
                    cout << ".quit       Shut down the world engine\n .help       Show this message\n.version       Show engine version\n.status       Show world status\n";
                }
                else if (com == ".version"){
                    cout << "Chronicle v0.1 — Ironhold World Engine \n";
                }
                else if (com == ".status"){
                    cout<< "World: offline\n";
                }
                else{
                    cout << "[World command queued: "<<com<<"]\n";
                }
            }while(kr);
            return 0;
        }
};