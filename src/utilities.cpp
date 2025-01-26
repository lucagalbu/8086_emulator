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

void printRegisters(const Registers &registers)
{
    // Save current cout settings so that we can restore them at the end.
    // Modify the settings to fill with 0s and print in upper case
    // (e.g. 0ABF instead of abf).
    const auto old_cout_flags = std::cout.flags();
    std::cout << std::setfill('0') << std::right << std::uppercase << std::hex;

    std::cout << "AX: " << std::setw(4) << registers.AX() << "\t";
    std::cout << "BX: " << std::setw(4) << registers.BX() << "\t";
    std::cout << "CX: " << std::setw(4) << registers.CX() << "\t";
    std::cout << "DX: " << std::setw(4) << registers.DX() << std::endl;

    std::cout << "CS: " << std::setw(4) << registers.CS() << "\t";
    std::cout << "SS: " << std::setw(4) << registers.SS() << "\t";
    std::cout << "DS: " << std::setw(4) << registers.DS() << "\t";
    std::cout << "ES: " << std::setw(4) << registers.ES() << std::endl;

    std::cout << "SP: " << std::setw(4) << registers.SP() << "\t";
    std::cout << "SI: " << std::setw(4) << registers.SI() << "\t";
    std::cout << "DI: " << std::setw(4) << registers.DI() << "\t";
    std::cout << "BP: " << std::setw(4) << registers.BP() << std::endl;

    std::cout << "IP: " << std::setw(4) << registers.IP() << std::endl;

    // Restore the cout settings.
    std::cout.flags(old_cout_flags);
}

void printFlags(const Flags &flags)
{
    std::cout << "AF CF OF SF PF ZF DF IF TF" << std::endl;
    std::cout << (flags.AF() ? "X  " : "   ");
    std::cout << (flags.CF() ? "X  " : "   ");
    std::cout << (flags.OF() ? "X  " : "   ");
    std::cout << (flags.SF() ? "X  " : "   ");
    std::cout << (flags.PF() ? "X  " : "   ");
    std::cout << (flags.ZF() ? "X  " : "   ");
    std::cout << (flags.DF() ? "X  " : "   ");
    std::cout << (flags.IF() ? "X  " : "   ");
    std::cout << (flags.TF() ? "X  " : "   ");
    std::cout << std::endl;
}
