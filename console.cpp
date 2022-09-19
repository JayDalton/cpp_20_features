#include "console.h"

int Console::run()
{
   // std::format
   // ranges
   // 

    print("Select area...\n");
    m_repo.printContentList();

    while (auto input = readInput())
    {
        print("Input: {}\n", input.value());
    }

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

