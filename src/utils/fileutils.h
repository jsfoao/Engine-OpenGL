#pragma once
#include "core/core.h"
#include <string>

namespace Nata
{
    class FileUtils
    {
    public:
        static std::string ReadFile(const char* filepath);
    };
}