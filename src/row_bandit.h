#ifdef BERNOULLI_BANDIT
#include "../../lib/Multi-armed-bandit-RL/include/BernoulliBandit.h"
#else
#include "../../lib/Multi-armed-bandit-RL/include/NormalBandit.h"
#endif

namespace dramsim3 {

class RowBandit {
public:
    RowBandit();

    bool make_decision();

    // returns true if previous decision was correct, i.e. either
    // decision was OPEN and did_hit
    // OR
    // decision was CLOSE and !did_hit
    bool update_state(bool did_hit);
private:

#ifdef BERNOULLI_BANDIT
    BernoulliBandit *bandit_;
#else
    NormalBandit *bandit_;
#endif

    // false - close, true - open
    bool previous_decision;
};

}