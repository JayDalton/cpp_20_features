#pragma once

#include "common.h"

namespace Concept03 {

    consteval auto foo(auto t) {
        if constexpr (requires{ t.foo; }) {
            return t.foo;
        } else {
            return 0;
        }
    }

    constexpr struct { int foo{42}; } f;
    static_assert(42 == foo(f));

    constexpr struct { int bar{42}; } b;
    static_assert(0 == foo(b));

    // ###############################################

    template<auto N>
    constexpr auto unroll = [](auto expr){
        [expr]<auto ...Is>(std::index_sequence<Is...>) {
            ((expr(), void(Is)), ...);
        }(std::make_index_sequence<N>{});
    };

    // ###############################################

    // auto hello_world = [](auto list, auto add_const, auto has_value)
    // {
    //     using std::views;
    //     return list
    //         | drop(1)
    //         | reverse
    //         | take(2)
    //         | transform(add_const)
    //         | filter(has_value)
    //     ;
    // };

    // auto add_const = []<class T> -> T const {};
    // auto has_value = []<class T> { return requires(T t) { t.value; } };

    // struct bar{}; struct foo { int value; }; struct val { int value; };



    // ###############################################

    void call()
    {
        print("concept 03\n");

        unroll<2>([]{ std::puts("CppCon 2022!"); });
    }
}
