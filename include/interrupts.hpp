#ifndef __INTERRUPTS
#define __INTERRUPTS

#include "../include/registers.hpp"
#include "../include/memory.hpp"

class Interrupts
{
private:
    Registers &_registers;
    Memory &_memory;

    void int20();
    void int21();

public:
    explicit Interrupts(Registers &registers, Memory &memory) : _registers(registers), _memory(memory) {}
    void execute(uint8_t interrupt);
};

#endif