#pragma once

#include "common.h"

namespace Future01
{
    void compute()
    {
        print("compute: begin\n");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        print("compute: end\n");
    }

    void call()
    {
        std::future<bool> future = std::async(std::launch::async, [](){ 
            return true;
            // compute(); 
            // m_storage->open([](const Mbient::PersistentStorage::Error& response) {
            //     return (response.isError()) ? false : true;
            // });
        });

        future.wait_for(std::chrono::seconds(5));

        print("Future 01: {}\n", future.get());
    }
}
