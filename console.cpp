#include "console.h"

#include "future01.h"
#include "concept01.h"
#include "concept02.h"
#include "concept03.h"
#include "values01.h"
#include "variant01.h"
#include "variant02.h"
#include "variant03.h"
#include "coroutine01.h"

int Console::run()
{
   // std::format
   // ranges
   // concept
   // variant

    // print("Select area...\n");
    // m_repo.printContentList();

//    Future01::call();
//    Concept01::call();
//    Concept02::call();
   Concept03::call();
//    Values01::call();
//    Variant01::call();
//    Variant02::call();
//    Variant03::call();
//    TypeErasure::call();
//    Coroutine01::call();

    // while (auto input = readInput())
    // {
    //     print("Input: {}\n", input.value());
    //   //   if (auto fun = m_repo.contains(input.value()))
    //   //   {

    //   //   }
    // }

    print("End!\n");
    return {};
}

std::optional<std::string> Console::readInput()
{
    while (true)
    {
        try
        {
            print("Input: ");
            std::string input;
            std::getline(std::cin, input);
            if (!input.empty()) {
                return input;
            }
            return std::nullopt;
        }
        catch (...) {}
    }
}

