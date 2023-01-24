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

    template<typename T>
    void printLines(std::initializer_list<T> list)
    {
        for (auto &&elem : list)
        {
            print("elem: {}\n", elem);
        }        
    }

    void printString(std::string_view view)
    {
        print("view: {}\n", view);
    }


    void call()
    {
        printLines({"eens", "zwoa", "drou", "voio"});

        std::string str{"string"};
        printString(str);

        std::string_view view{"view"};
        printString(view);

        printString("test");

        if (auto opt = create())
        {
            print("...{}\n", opt.value().m);
        }

        print("Values 01\n");
    }
}
