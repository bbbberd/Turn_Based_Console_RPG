#pragma once

class Entity {
public:
    virtual ~Entity() = default;
    virtual void Update() = 0;
};
