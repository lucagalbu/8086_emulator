#include <iostream>
#include <bit>
#include <array>
#include "../include/op_codes.hpp"

void OpCodes::exec(int num_instruction)
{
    for (int i = 0; i < num_instruction; i++)
    {
        uint8_t instruction = fetchNextByte();
        if (instruction == 0xCD)
            executeInterrrupt(instruction);
        /* else if ((instruction & 0b11111100) == 0b10001000)
            std::cerr << "OpCode not yet implemented" << std::endl;
         movRegMemToFromReg(instruction);
         else if ((instruction & 0b11111110) == 0b11000110)
            movImmediateToRegMem(instruction);
        */
        else if ((instruction & 0b11110000) == 0b10110000)
            movImmediateToReg(instruction);
        /*else if ((instruction & 0b11111100) == 0b10100000)
            movMemAccum(instruction);
        else if ((instruction & 0b11111100) == 0b10001100)
            movMemRegSegment(instruction);
        */
        else if ((instruction & 0b11111110) == 0b10000110)
            xchgRegMemWithReg(instruction);
        else if ((instruction & 0b11111110) == 0b00111100)
            cmpImmediateAcc(instruction);
        else if (instruction == 0b01110011)
            jae(instruction);
        else if ((instruction & 0b11111100) == 0b00110000)
            xorReg(instruction);
        else
        {
            std::cerr << "Unknown instruction " << int(instruction) << std::endl;
            std::exit(1);
        }
    }
}

uint8_t OpCodes::fetchNextByte() const noexcept
{
    uint8_t instruction = _memory.getByte(_registers.CS(), _registers.IP());
    _registers.IP(_registers.IP() + 1);

    return instruction;
}

uint16_t OpCodes::fetchNextWord() const noexcept
{
    uint16_t instruction = _memory.getWord(_registers.CS(), _registers.IP());
    _registers.IP(_registers.IP() + 2);

    return instruction;
}

std::array<uint8_t, 3> OpCodes::getModRegRm(uint8_t byte) const noexcept
{
    uint8_t mod = (byte >> 6) & 0b00000011;
    uint8_t reg = (byte >> 3) & 0b00000111;
    uint8_t rm = byte & 0b00000111;

    return {mod, reg, rm};
}

void OpCodes::executeInterrrupt(uint8_t currentByte)
{
    uint8_t int_code = fetchNextByte();
    _interrupts.execute(int_code);
}

void OpCodes::movImmediateToReg(uint8_t currentByte)
{
    uint8_t w = (currentByte & 0b00001000) >> 3;
    uint8_t reg = currentByte & 0b00000111;
    uint8_t data_1;
    uint8_t data_2;

    switch (w)
    {
    case 0x0:
        data_1 = fetchNextByte();
        _registers.setRegister8(data_1, reg);
        break;
    case 0x1:
        data_1 = fetchNextByte();
        data_2 = fetchNextByte();
        _registers.setRegister16((data_2 << 8) | data_1, reg);
        break;
    }
}

void OpCodes::xchgRegMemWithReg(uint8_t currentByte)
{
    uint8_t w = currentByte & 0b00000001;
    uint8_t byte_2 = fetchNextByte();
    auto [mod, reg, rm] = getModRegRm(byte_2);

    if (w == 0b00000000 && mod == 0b11)
    {
        uint8_t value_reg_1 = _registers.getRegister8(reg);
        uint8_t value_reg_2 = _registers.getRegister8(rm);
        _registers.setRegister8(value_reg_1, rm);
        _registers.setRegister8(value_reg_2, reg);
    }
}

void OpCodes::cmpImmediateAcc(uint8_t currentByte)
{
    uint8_t w = currentByte & 0b00000001;
    uint16_t data = (w == 1) ? fetchNextWord() : fetchNextByte();
    uint16_t accumulator = (w == 0) ? _registers.AL() : _registers.AX();
    uint16_t msb = (w == 0) ? 0x80 : 0x8000;

    // Extend to 32 bits to compute real result (w/o overflow)
    uint32_t result = uint32_t(accumulator) - uint32_t(data);

    _flags.ZF(result == 0);
    _flags.SF((result & msb) != 0);
    _flags.CF(data > accumulator);
    _flags.OF((int32_t(result) > (int32_t(msb) - 1)) || (int32_t(result) < -int32_t(msb) / 2));
    _flags.PF(std::popcount(result & 0xFF) % 2 == 0);
    _flags.AF((data & 0xF) > (accumulator & 0xF));
}

void OpCodes::jae(uint8_t currentByte)
{
    uint8_t offset = fetchNextByte();
    if (_flags.CF() == 0 || _flags.ZF() == 1)
        _registers.IP(_registers.IP() + offset);
}

void OpCodes::xorReg(uint8_t currentByte)
{
    uint8_t d = currentByte & 0b00000010;
    uint8_t w = currentByte & 0b00000001;
    uint8_t byte_2 = fetchNextByte();
    auto [mod, reg, rm] = getModRegRm(byte_2);

    if (mod != 0b11)
    {
        std::cerr << "xorReg with mod != 0b11 not yet supported" << std::endl;
        std::exit(1);
    }

    uint8_t dst = (d == 0) ? rm : reg;
    switch (w)
    {
    case 0b00:
        _registers.setRegister8(_registers.getRegister8(rm) ^ _registers.getRegister8(reg), dst);
        break;
    case 0b01:
        _registers.setRegister16(_registers.getRegister16(rm) ^ _registers.getRegister16(reg), dst);
        break;
    default:
        std::cerr << "xorReg: parmater w not recognized" << std::endl;
        std::exit(1);
    }
}
