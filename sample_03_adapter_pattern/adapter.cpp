#include "adapter.hpp"

void adapterPatternTest() {
    // create adapter
    std::shared_ptr<IRussiaSocket> p_adapter(new PowerAdapter());
    p_adapter->Charge();
}
