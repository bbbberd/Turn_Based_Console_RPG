#pragma once
#include <string>

class Observer {
public:
    virtual ~Observer() = default;

    // event dikirim dalam bentuk string
    virtual void OnNotify(const std::string& event) = 0;
};
