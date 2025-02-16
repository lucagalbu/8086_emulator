#include <cstdlib>
#include <iostream>

#include "../include/interrupts.hpp"
#include "../include/exceptions.hpp"

void Interrupts::execute(uint8_t interrupt)
{
    switch (interrupt)
    {
    case 0x21:
        int21();
        break;
    case 0x20:
        int20();
        break;
    default:
        throw UNKNOWN_INTERRUPT;
    }
}

void Interrupts::int20()
{
    std::exit(0);
}

void Interrupts::int21()
{
    switch (_registers.AH())
    {
    case 0x30:
        _registers.AX(MS_DOS_VERSION);
        _registers.BH(0x00);
        break;
    case 0x09:
    {
        uint16_t i = _registers.DX();
        uint8_t character = _memory.getByte(_registers.DS(), i++);
        while (character != 0x24)
        {
            std::cout << character;
            character = _memory.getByte(_registers.DS(), i++);
        }
        break;
    }
    default:
        throw UNKNOWN_INTERRUPT;
    }
}