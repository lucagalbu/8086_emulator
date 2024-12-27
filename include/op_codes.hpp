#ifndef __OPCODES
#define __OPCODES

#include "../include/registers.hpp"
#include "../include/memory.hpp"
#include "../include/interrupts.hpp"
#include "../include/flags.hpp"

class OpCodes
{
private:
    Registers &_registers;
    Memory &_memory;
    Flags &_flags;
    Interrupts _interrupts;

    // Utilities
    uint8_t fetchNextByte() const noexcept;
    uint16_t fetchNextWord() const noexcept;

    void executeInterrrupt(uint8_t currentByte);

    // MOV
    void movImmediateToReg(uint8_t currentByte);

    // CMP
    void cmpImmediateAcc(uint8_t currentByte);

    // JUMPS
    void jae(uint8_t currentByte);

    // Others
    void xchgRegMemWithReg(uint8_t currentByte);

public:
    explicit OpCodes(Registers &registers, Memory &memory, Flags &flags, Interrupts interrupts) : _registers(registers),
                                                                                                  _memory(memory),
                                                                                                  _flags(flags),
                                                                                                  _interrupts(interrupts)
    {
    }
    void exec(int num_instruction);
};

#endif