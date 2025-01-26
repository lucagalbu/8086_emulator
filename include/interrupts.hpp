#ifndef __INTERRUPTS
#define __INTERRUPTS

#include "../include/registers.hpp"
#include "../include/memory.hpp"

class Interrupts
{
private:
    // Version stored as minor first, major last
    const uint16_t MS_DOS_VERSION = 0x0002;
    Registers &_registers;
    Memory &_memory;

    void int20();
    void int21();

public:
    explicit Interrupts(Registers &registers, Memory &memory) : _registers(registers), _memory(memory) {}
    void execute(uint8_t interrupt);
};

#endif