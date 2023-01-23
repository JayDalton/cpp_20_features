#pragma once

#include "common.h"

namespace Values01
{
    struct Copyable
    {
        Copyable(int v) : m(v) { print("ctor {}\n", m); }

        // Copyable(const Copyable&) = delete;
        // Copyable& operator=(const Copyable&) = delete;

        // Copyable(Copyable &&) = delete;
        // Copyable& operator=(Copyable &&) = delete;

        ~Copyable() { print("dtor\n"); }
        int m{};
    };

    auto create() -> std::optional<Copyable>
    {
        std::optional<Copyable> c;
        // Copyable c{42};
        // c.m = 3;
        return c;
        // return {42};
    }

    void call()
    {
        if (auto opt = create())
        {
            print("...{}\n", opt.value().m);
        }

        print("Values 01\n");
    }
}
