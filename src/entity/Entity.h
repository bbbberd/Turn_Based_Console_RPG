#pragma once

class Entity {
public: 
    virtual ~Entity() = default;// virtual destructor
    virtual void Update() = 0;// semua Entity WAJIB punya Update()
};
