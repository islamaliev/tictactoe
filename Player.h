#pragma once

#include "Turn.h"

class Player {
public:
    Player(short id)
        : m_id(id) {
    }

    virtual ~Player() {}

    virtual Turn makeTurn() = 0;

    short id() const {
        return m_id;
    }

private:
    short m_id;
};
