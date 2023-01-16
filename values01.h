#pragma once

#include "common.h"

namespace Values01 
{
    struct Copyable
    {
        Copyable() { print("ctor\n"); }
        ~Copyable() { print("dtor\n"); }
    };

    auto create() -> std::optional<Copyable>
    {
        Copyable c;
        return c;
    }


   void call()
   {
        if (auto value = create())
        {
            print("...\n");
        }
        

        print("Values 01\n");
   }
}
