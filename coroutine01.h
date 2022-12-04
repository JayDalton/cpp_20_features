#pragma once

#include "common.h"

namespace Coroutine01 {

    // struct ReturnType 
    // {
    //     struct promise_type // std::coroutine_traits<Returntype, ...>
    //     {
    //         // promise_type(T...); // opt.

    //         ReturnType get_return_object() 
    //         { 
    //             return {}; 
    //             return ReturnType{std::coroutine_handle<promise>::from_promise(*this)};
    //         }

    //         void return_void() { }
    //         void unhandled_exception() { };

    //         std::suspend_never initial_suspend() { return {}; }
    //         std::suspend_always final_suspend() noexcept { return {}; }

    //     };

    //     std::coroutine_handle<promise_type> handle;
    //     ReturnType(std::coroutine_handle<promise_type> h) : handle(h) {}
    //     void resume() { handle.resume(); }
    // };

    // ReturnType hello_coroutine() 
    // {
    //     print("Hello from generator!\n");
    //     co_return;
    // }

    // struct Awaitable
    // {
    //     bool await_ready();
    //     void await_suspend(std::coroutine_handle<promise_type>);
    //     void await_resume();
    // };


    void call() 
    {
        print("Hello Generator!\n");
        // auto c = hello_coroutine();
        // c.resume();
        print("done\n");
    }
}