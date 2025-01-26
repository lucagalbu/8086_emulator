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
    const auto old_cout_flags = std::cerr.flags();
    std::cerr << std::setfill('0') << std::right << std::uppercase << std::hex;

    // Print the memory in lines of 0x10 bytes. Prepend every line
    // with the address.
    for (int offset = start_aligned; offset < end; offset++)
    {
        if (offset % 0x10 == 0)
        {
            // Print a string with the current address.
            std::cerr << std::endl
                      << std::setw(5) << offset << "  ";
        }
        std::cerr << std::setw(2) << int(memory.get(offset)) << " ";
    }
    std::cerr << std::endl;

    // Restore the cout settings.
    std::cerr.flags(old_cout_flags);
}

void printRegisters(const Registers &registers)
{
    // Save current cout settings so that we can restore them at the end.
    // Modify the settings to fill with 0s and print in upper case
    // (e.g. 0ABF instead of abf).
    const auto old_cout_flags = std::cerr.flags();
    std::cerr << std::setfill('0') << std::right << std::uppercase << std::hex;

    std::cerr << "AX: " << std::setw(4) << registers.AX() << "\t";
    std::cerr << "BX: " << std::setw(4) << registers.BX() << "\t";
    std::cerr << "CX: " << std::setw(4) << registers.CX() << "\t";
    std::cerr << "DX: " << std::setw(4) << registers.DX() << std::endl;

    std::cerr << "CS: " << std::setw(4) << registers.CS() << "\t";
    std::cerr << "SS: " << std::setw(4) << registers.SS() << "\t";
    std::cerr << "DS: " << std::setw(4) << registers.DS() << "\t";
    std::cerr << "ES: " << std::setw(4) << registers.ES() << std::endl;

    std::cerr << "SP: " << std::setw(4) << registers.SP() << "\t";
    std::cerr << "SI: " << std::setw(4) << registers.SI() << "\t";
    std::cerr << "DI: " << std::setw(4) << registers.DI() << "\t";
    std::cerr << "BP: " << std::setw(4) << registers.BP() << std::endl;

    std::cerr << "IP: " << std::setw(4) << registers.IP() << std::endl;

    // Restore the cout settings.
    std::cerr.flags(old_cout_flags);
}

void printFlags(const Flags &flags)
{
    std::cerr << "AF CF OF SF PF ZF DF IF TF" << std::endl;
    std::cerr << (flags.AF() ? "X  " : "   ");
    std::cerr << (flags.CF() ? "X  " : "   ");
    std::cerr << (flags.OF() ? "X  " : "   ");
    std::cerr << (flags.SF() ? "X  " : "   ");
    std::cerr << (flags.PF() ? "X  " : "   ");
    std::cerr << (flags.ZF() ? "X  " : "   ");
    std::cerr << (flags.DF() ? "X  " : "   ");
    std::cerr << (flags.IF() ? "X  " : "   ");
    std::cerr << (flags.TF() ? "X  " : "   ");
    std::cerr << std::endl;
}
