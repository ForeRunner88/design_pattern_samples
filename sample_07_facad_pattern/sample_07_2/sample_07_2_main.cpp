#include "facade.hpp"

int main(int argc, char *argv[]) {
    OnlineShoppingFacade facade;
    facade.SubmitRequest();
    while (!facade.CheckStates()) {
        // wait
    }
    std::cout << "***** finish shopping, follow times: " << facade.GetFollowUpNum()
        << " *****" << std::endl;
    return 0;
}
