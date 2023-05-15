#include "console.h"

// mkdir build && cd build && cmake .. && cmake --build . --config Release

auto main() -> int
{
    if constexpr (std::endian::native == std::endian::little) {
        print("This system is little endian\n\n");
    } else if constexpr (std::endian::native == std::endian::big) {
        print("This system is big endian\n\n");
    }

    Console app;
    return app.run();
}

