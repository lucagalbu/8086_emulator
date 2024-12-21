#include <cstdint>
#include "../include/registers.hpp"

// Private
uint16_t Registers::getFullBits(uint16_t reg16) const noexcept
{
    return reg16 & 0xFFFF;
}
uint16_t Registers::getLowBits(uint16_t reg16) const noexcept
{
    return reg16 & 0x00FF;
}
uint16_t Registers::getHighBits(uint16_t reg16) const noexcept
{
    return (reg16 & 0xFF00) >> 8;
}
void Registers::setFullBits(uint16_t value, uint16_t &reg16) noexcept
{
    reg16 = value & 0xFFFF;
}
void Registers::setLowBits(uint16_t value, uint16_t &reg16) noexcept
{
    reg16 = (value & 0xFF) | (getHighBits(reg16) << 8);
}
void Registers::setHighBits(uint16_t value, uint16_t &reg16) noexcept
{
    reg16 = ((value & 0xFF) << 8) | getLowBits(reg16);
}

// Public
uint16_t Registers::AX() const noexcept
{
    return getFullBits(_AX);
}
uint16_t Registers::AH() const noexcept
{
    return getHighBits(_AX);
}
uint16_t Registers::AL() const noexcept
{
    return getLowBits(_AX);
}
void Registers::AX(uint16_t value) noexcept
{
    setFullBits(value, _AX);
}
void Registers::AH(uint16_t value) noexcept
{
    setHighBits(value, _AX);
}
void Registers::AL(uint16_t value) noexcept
{
    setLowBits(value, _AX);
}

uint16_t Registers::BX() const noexcept
{
    return getFullBits(_BX);
}
uint16_t Registers::BH() const noexcept
{
    return getHighBits(_BX);
}
uint16_t Registers::BL() const noexcept
{
    return getLowBits(_BX);
}
void Registers::BX(uint16_t value) noexcept
{
    setFullBits(value, _BX);
}
void Registers::BH(uint16_t value) noexcept
{
    setHighBits(value, _BX);
}
void Registers::BL(uint16_t value) noexcept
{
    setLowBits(value, _BX);
}

uint16_t Registers::CX() const noexcept
{
    return getFullBits(_CX);
}
uint16_t Registers::CH() const noexcept
{
    return getHighBits(_CX);
}
uint16_t Registers::CL() const noexcept
{
    return getLowBits(_CX);
}
void Registers::CX(uint16_t value) noexcept
{
    setFullBits(value, _CX);
}
void Registers::CH(uint16_t value) noexcept
{
    setHighBits(value, _CX);
}
void Registers::CL(uint16_t value) noexcept
{
    setLowBits(value, _CX);
}

uint16_t Registers::DX() const noexcept
{
    return getFullBits(_DX);
}
uint16_t Registers::DH() const noexcept
{
    return getHighBits(_DX);
}
uint16_t Registers::DL() const noexcept
{
    return getLowBits(_DX);
}
void Registers::DX(uint16_t value) noexcept
{
    setFullBits(value, _DX);
}
void Registers::DH(uint16_t value) noexcept
{
    setHighBits(value, _DX);
}
void Registers::DL(uint16_t value) noexcept
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
