#include <cstdint>
#include <iostream>

#include "../include/registers.hpp"

// Private
uint16_t Registers::getFullBits(uint16_t reg16) const noexcept
{
    return reg16 & 0xFFFF;
}
uint8_t Registers::getLowBits(uint16_t reg16) const noexcept
{
    return reg16 & 0x00FF;
}
uint8_t Registers::getHighBits(uint16_t reg16) const noexcept
{
    return (reg16 & 0xFF00) >> 8;
}
void Registers::setFullBits(uint16_t value, uint16_t &reg16) noexcept
{
    reg16 = value & 0xFFFF;
}
void Registers::setLowBits(uint8_t value, uint16_t &reg16) noexcept
{
    reg16 = (value & 0xFF) | (getHighBits(reg16) << 8);
}
void Registers::setHighBits(uint8_t value, uint16_t &reg16) noexcept
{
    reg16 = ((value & 0xFF) << 8) | getLowBits(reg16);
}

// Public
void Registers::setRegister8(uint8_t value, uint8_t reg_code) noexcept
{
    switch (reg_code & 0b00000111)
    {
    case 0b000:
        setLowBits(value, _AX);
        break;
    case 0b001:
        setLowBits(value, _CX);
        break;
    case 0b010:
        setLowBits(value, _DX);
        break;
    case 0b011:
        setLowBits(value, _BX);
        break;
    case 0b100:
        setHighBits(value, _AX);
        break;
    case 0b101:
        setHighBits(value, _CX);
        break;
    case 0b110:
        setHighBits(value, _DX);
        break;
    case 0b111:
        setHighBits(value, _BX);
        break;
    default:
        std::cerr << "Register " << int(reg_code) << " not recognized" << std::endl;
        std::exit(1);
    }
}

void Registers::setRegister16(uint16_t value, uint8_t reg_code) noexcept
{
    switch (reg_code & 0b00000111)
    {
    case 0b000:
        setFullBits(value, _AX);
        break;
    case 0b001:
        setFullBits(value, _CX);
        break;
    case 0b010:
        setFullBits(value, _DX);
        break;
    case 0b011:
        setFullBits(value, _BX);
        break;
    case 0b100:
        setFullBits(value, _SP);
        break;
    case 0b101:
        setFullBits(value, _BP);
        break;
    case 0b110:
        setFullBits(value, _SI);
        break;
    case 0b111:
        setFullBits(value, _DI);
        break;
    default:
        std::cerr << "Register " << int(reg_code) << " not recognized" << std::endl;
        std::exit(1);
    }
}

uint8_t Registers::getRegister8(uint8_t reg_code) noexcept
{
    switch (reg_code & 0b00000111)
    {
    case 0b000:
        return getLowBits(_AX);
        break;
    case 0b001:
        return getLowBits(_CX);
        break;
    case 0b010:
        return getLowBits(_DX);
        break;
    case 0b011:
        return getLowBits(_BX);
        break;
    case 0b100:
        return getHighBits(_AX);
        break;
    case 0b101:
        return getHighBits(_CX);
        break;
    case 0b110:
        return getHighBits(_DX);
        break;
    case 0b111:
        return getHighBits(_BX);
        break;
    default:
        std::cerr << "Register " << int(reg_code) << " not recognized" << std::endl;
        std::exit(1);
    }
}

uint16_t Registers::getRegister16(uint8_t reg_code) noexcept
{
    switch (reg_code & 0b00000111)
    {
    case 0b000:
        return getFullBits(_AX);
        break;
    case 0b001:
        return getFullBits(_CX);
        break;
    case 0b010:
        return getFullBits(_DX);
        break;
    case 0b011:
        return getFullBits(_BX);
        break;
    case 0b100:
        return getFullBits(_SP);
        break;
    case 0b101:
        return getFullBits(_BP);
        break;
    case 0b110:
        return getFullBits(_SI);
        break;
    case 0b111:
        return getFullBits(_DI);
        break;
    default:
        std::cerr << "Register " << int(reg_code) << " not recognized" << std::endl;
        std::exit(1);
    }
}

uint16_t Registers::AX() const noexcept
{
    return getFullBits(_AX);
}
uint8_t Registers::AH() const noexcept
{
    return getHighBits(_AX);
}
uint8_t Registers::AL() const noexcept
{
    return getLowBits(_AX);
}
void Registers::AX(uint16_t value) noexcept
{
    setFullBits(value, _AX);
}
void Registers::AH(uint8_t value) noexcept
{
    setHighBits(value, _AX);
}
void Registers::AL(uint8_t value) noexcept
{
    setLowBits(value, _AX);
}

uint16_t Registers::BX() const noexcept
{
    return getFullBits(_BX);
}
uint8_t Registers::BH() const noexcept
{
    return getHighBits(_BX);
}
uint8_t Registers::BL() const noexcept
{
    return getLowBits(_BX);
}
void Registers::BX(uint16_t value) noexcept
{
    setFullBits(value, _BX);
}
void Registers::BH(uint8_t value) noexcept
{
    setHighBits(value, _BX);
}
void Registers::BL(uint8_t value) noexcept
{
    setLowBits(value, _BX);
}

uint16_t Registers::CX() const noexcept
{
    return getFullBits(_CX);
}
uint8_t Registers::CH() const noexcept
{
    return getHighBits(_CX);
}
uint8_t Registers::CL() const noexcept
{
    return getLowBits(_CX);
}
void Registers::CX(uint16_t value) noexcept
{
    setFullBits(value, _CX);
}
void Registers::CH(uint8_t value) noexcept
{
    setHighBits(value, _CX);
}
void Registers::CL(uint8_t value) noexcept
{
    setLowBits(value, _CX);
}

uint16_t Registers::DX() const noexcept
{
    return getFullBits(_DX);
}
uint8_t Registers::DH() const noexcept
{
    return getHighBits(_DX);
}
uint8_t Registers::DL() const noexcept
{
    return getLowBits(_DX);
}
void Registers::DX(uint16_t value) noexcept
{
    setFullBits(value, _DX);
}
void Registers::DH(uint8_t value) noexcept
{
    setHighBits(value, _DX);
}
void Registers::DL(uint8_t value) noexcept
{
    setLowBits(value, _DX);
}

uint16_t Registers::SP() const noexcept
{
    return getFullBits(_SP);
}

void Registers::SP(uint16_t value) noexcept
{
    setFullBits(value, _SP);
}

uint16_t Registers::SI() const noexcept
{
    return getFullBits(_SI);
}

void Registers::SI(uint16_t value) noexcept
{
    setFullBits(value, _SI);
}

uint16_t Registers::DI() const noexcept
{
    return getFullBits(_DI);
}

void Registers::DI(uint16_t value) noexcept
{
    setFullBits(value, _DI);
}

uint16_t Registers::BP() const noexcept
{
    return getFullBits(_BP);
}

void Registers::BP(uint16_t value) noexcept
{
    setFullBits(value, _BP);
}

uint16_t Registers::CS() const noexcept
{
    return getFullBits(_CS);
}

void Registers::CS(uint16_t value) noexcept
{
    setFullBits(value, _CS);
}

uint16_t Registers::SS() const noexcept
{
    return getFullBits(_SS);
}

void Registers::SS(uint16_t value) noexcept
{
    setFullBits(value, _SS);
}

uint16_t Registers::DS() const noexcept
{
    return getFullBits(_DS);
}

void Registers::DS(uint16_t value) noexcept
{
    setFullBits(value, _DS);
}

uint16_t Registers::ES() const noexcept
{
    return getFullBits(_ES);
}

void Registers::ES(uint16_t value) noexcept
{
    setFullBits(value, _ES);
}

uint16_t Registers::IP() const noexcept
{
    return getFullBits(_IP);
}

void Registers::IP(uint16_t value) noexcept
{
    setFullBits(value, _IP);
}
