#pragma once
#include <iostream>

class MyExcpetions : public std::exception
{
    std::string text;
public:
    const char * what () const noexcept final;
};

