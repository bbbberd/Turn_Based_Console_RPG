#pragma once
#include <string>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void OnNotify(const std::string& event) = 0;
};
