#include "row_bandit.h"

namespace dramsim3 {

RowBandit::RowBandit() : previous_decision(true) {
    // FIXME: placeholder
    int n = 0;
    double e = 0, l = 0, v = 0, Qmax = 0;

#ifdef BERNOULLI_BANDIT
    bandit_ = new BernoulliBandit(n, e, l, v, Qmax);
#else
    bandit_ = new NormalBandit(n, e, l, v, Qmax);
#endif
}

bool RowBandit::make_decision() {
    // FIXME: always makes OPEN decision, should actually consult the bandit
    previous_decision = true;
    return true;
}

bool RowBandit::update_state(bool did_hit) {
    // FIXME: doesn't actually update any state, only checks if previous decision was correct
    return previous_decision == did_hit;
}

}