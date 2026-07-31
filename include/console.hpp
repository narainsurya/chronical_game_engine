#include </home/24pc16/24pc16_m1/include/application_state.hpp>
using namespace std;
class Console{
    private:
        string com;
        string i;
        bool kr = true;
        vector <string> history;
    public:
        int run();
};