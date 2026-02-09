#pragma once
#include <vector>
#include <string>
#include "Observer.h"

class Subject {
protected:
    // vector berisi POINTER ke Observer
    // membuat array vector observers
    std::vector<Observer*> observers;

public:
    void AddObserver(Observer* obs) {
        observers.push_back(obs);// simpan alamat observer
    }

    void Notify(const std::string& event) {
        for (auto* obs : observers) //loop semua array observer
            obs->OnNotify(event);// panggil fungsi observer
    }
};
