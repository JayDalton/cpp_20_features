#pragma once

#include "common.h"

namespace Coroutine01 {

    struct ReturnType 
    {
        struct promise_type {};

    };

    ReturnType hello_coroutine() {
        co_return;
    }


    void call() 
    {
        print("Hello Generator!\n");
        hello_coroutine();
        print("done\n");
    }
}