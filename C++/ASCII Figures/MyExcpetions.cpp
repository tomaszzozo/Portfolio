#include "MyExcpetions.h"

const char *MyExcpetions::what() const noexcept
{
    return "Incorrect arguments!";
}
