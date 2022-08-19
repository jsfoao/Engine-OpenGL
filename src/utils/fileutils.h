#pragma once
#include "core/core.h"
#include <string>

namespace Nata
{
    std::string ReadFile(const char* filepath)
    {
        // r: readonly; t: text file
        FILE* file = fopen(filepath, "rt");

        if (file == nullptr)
        {
            return nullptr;
        }

        // go to end of file
        fseek(file, 0, SEEK_END);

        // length of file in bytes
        unsigned long length = ftell(file);
        char* data = new char[length + 1];

        // set everything to 0
        memset(data, 0, length + 1);

        // go back to beginning of file
        fseek(file, 0, SEEK_SET);

        fread(data, 1, length, file);
        fclose(file);

        // copy data to string
        std::string result(data);
        delete[] data;
        return result;
    }
}