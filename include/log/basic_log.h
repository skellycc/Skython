/// NOTE: Will do for now i guess...

#pragma once

#include <iostream>

void __raise_log(const std::string& message) {
    std::cout << "[EXCEPTION]: " << message << std::endl;
}

void __info_log(const std::string& message) {
    std::cout << "[LOG INFO]: " << message << std::endl;
}

void __warn_log(const std::string& message) {
    std::cout << "[LOG WARN]: " << message << std::endl;
}

void __critical_log(const std::string& message) {
    std::cout << "[LOG ERR]: " << message << std::endl;
}