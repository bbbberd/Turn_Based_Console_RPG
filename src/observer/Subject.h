#pragma once
#include <vector>
#include <string>
#include "Observer.h"

class Subject {
protected:
    std::vector<Observer*> observers;

public:
    void AddObserver(Observer* obs) {
        observers.push_back(obs);
    }

    void Notify(const std::string& event) {
        for (auto* obs : observers)
            obs->OnNotify(event);
    }
};
