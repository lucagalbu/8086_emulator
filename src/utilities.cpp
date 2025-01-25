#include <iostream>
#include <iomanip>
#include <cmath>

#include "../include/utilities.hpp"

void printMemory(const Memory &memory, uint32_t start, uint32_t end)
{
    // Start printing at the largest multiple of 0x10 lower or equal
    // to the provided start. This way, the memory is nicely printed
    // with lines of length 0x10.
    uint32_t start_aligned = std::floor(start / 0x10) * 0x10;

    // Save current cout settings so that we can restore them at the end.
    // Modify the settings to fill with 0s and print in upper case
    // (e.g. 0F instead of f).
    const auto old_cout_flags = std::cout.flags();
    std::cout << std::setfill('0') << std::right << std::uppercase << std::hex;

    // Print the memory in lines of 0x10 bytes. Prepend every line
    // with the address.
    for (int offset = start_aligned; offset < end; offset++)
    {
        if (offset % 0x10 == 0)
        {
            // Print a string with the current address.
            std::cout << std::endl
                      << std::setw(5) << offset << "  ";
        }
        std::cout << std::setw(2) << int(memory.get(offset)) << " ";
    }
    std::cout << std::endl;

    // Restore the cout settings.
    std::cout.flags(old_cout_flags);
}