#pragma once

#include "common.h"

namespace Coroutine01 {

    struct ReturnType 
    {
        struct promise_type 
        {
            ReturnType get_return_object() { return {}; }
            std::suspend_never initial_suspend() { return {}; }

            void return_void() { }
            void unhandled_exception() { };

            std::suspend_always final_suspend() noexcept { return {}; }

        };
    };

    ReturnType hello_coroutine() 
    {
        print("Hello from generator!\n");
        co_return;
    }


    void call() 
    {
        print("Hello Generator!\n");
        hello_coroutine();
        print("done\n");
    }
}