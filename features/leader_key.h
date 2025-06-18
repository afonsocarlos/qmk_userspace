#pragma once

#include "definitions/keycodes.h"

#ifdef LEADER_ENABLE

#ifdef LEADER
#undef LEADER
#endif

#define GET_LEADER_FUNCTION(_1, _2, _3, _4, _5, NAME, ...) NAME
#define LEADER_SEQUENCE(...) GET_LEADER_FUNCTION(__VA_ARGS__, LEADER5, LEADER4, LEADER3, LEADER2, LEADER1)(__VA_ARGS__)

#define LEADER1(kc1)  leader_sequence_one_key(kc1)
#define LEADER2(kc1, kc2)  leader_sequence_two_keys(kc1, kc2)
#define LEADER3(kc1, kc2, kc3)  leader_sequence_three_keys(kc1, kc2, kc3)
#define LEADER4(kc1, kc2, kc3, kc4)  leader_sequence_four_keys(kc1, kc2, kc3, kc4)
#define LEADER5(kc1, kc2, kc3, kc4, kc5)  leader_sequence_five_keys(kc1, kc2, kc3, kc4, kc5)

#define LEADER(action, ...)  \
    if (LEADER_SEQUENCE(__VA_ARGS__)) { \
        action; \
    }
#define LEADER_END


void leader_end_user(void) {
#    include "leader_sequences.def"
}

#undef LEADER

#endif
