#include "../include/registers.hpp"

// Private
int Registers::getFullBits(int reg16) const noexcept
{
    return reg16 & 0xFFFF;
}
int Registers::getLowBits(int reg16) const noexcept
{
    return reg16 & 0x00FF;
}
int Registers::getHighBits(int reg16) const noexcept
{
    return (reg16 & 0xFF00) >> 8;
}
void Registers::setFullBits(int value, int &reg16) noexcept
{
    reg16 = value & 0xFFFF;
}
void Registers::setLowBits(int value, int &reg16) noexcept
{
    reg16 = (value & 0xFF) | (getHighBits(reg16) << 8);
}
void Registers::setHighBits(int value, int &reg16) noexcept
{
    reg16 = ((value & 0xFF) << 8) | getLowBits(reg16);
}

// Public
int Registers::AX() const noexcept
{
    return getFullBits(_AX);
}
int Registers::AH() const noexcept
{
    return getHighBits(_AX);
}
int Registers::AL() const noexcept
{
    return getLowBits(_AX);
}
void Registers::AX(int value) noexcept
{
    setFullBits(value, _AX);
}
void Registers::AH(int value) noexcept
{
    setHighBits(value, _AX);
}
void Registers::AL(int value) noexcept
{
    setLowBits(value, _AX);
}

int Registers::BX() const noexcept
{
    return getFullBits(_BX);
}
int Registers::BH() const noexcept
{
    return getHighBits(_BX);
}
int Registers::BL() const noexcept
{
    return getLowBits(_BX);
}
void Registers::BX(int value) noexcept
{
    setFullBits(value, _BX);
}
void Registers::BH(int value) noexcept
{
    setHighBits(value, _BX);
}
void Registers::BL(int value) noexcept
{
    setLowBits(value, _BX);
}

int Registers::CX() const noexcept
{
    return getFullBits(_CX);
}
int Registers::CH() const noexcept
{
    return getHighBits(_CX);
}
int Registers::CL() const noexcept
{
    return getLowBits(_CX);
}
void Registers::CX(int value) noexcept
{
    setFullBits(value, _CX);
}
void Registers::CH(int value) noexcept
{
    setHighBits(value, _CX);
}
void Registers::CL(int value) noexcept
{
    setLowBits(value, _CX);
}

int Registers::DX() const noexcept
{
    return getFullBits(_DX);
}
int Registers::DH() const noexcept
{
    return getHighBits(_DX);
}
int Registers::DL() const noexcept
{
    return getLowBits(_DX);
}
void Registers::DX(int value) noexcept
{
    setFullBits(value, _DX);
}
void Registers::DH(int value) noexcept
{
    setHighBits(value, _DX);
}
void Registers::DL(int value) noexcept
{
    setLowBits(value, _DX);
}

int Registers::SP() const noexcept
{
    return getFullBits(_SP);
}

void Registers::SP(int value) noexcept
{
    setFullBits(value, _SP);
}

int Registers::SI() const noexcept
{
    return getFullBits(_SI);
}

void Registers::SI(int value) noexcept
{
    setFullBits(value, _SI);
}

int Registers::DI() const noexcept
{
    return getFullBits(_DI);
}

void Registers::DI(int value) noexcept
{
    setFullBits(value, _DI);
}

int Registers::BP() const noexcept
{
    return getFullBits(_BP);
}

void Registers::BP(int value) noexcept
{
    setFullBits(value, _BP);
}

int Registers::CS() const noexcept
{
    return getFullBits(_CS);
}

void Registers::CS(int value) noexcept
{
    setFullBits(value, _CS);
}

int Registers::SS() const noexcept
{
    return getFullBits(_SS);
}

void Registers::SS(int value) noexcept
{
    setFullBits(value, _SS);
}

int Registers::DS() const noexcept
{
    return getFullBits(_DS);
}

void Registers::DS(int value) noexcept
{
    setFullBits(value, _DS);
}

int Registers::ES() const noexcept
{
    return getFullBits(_ES);
}

void Registers::ES(int value) noexcept
{
    setFullBits(value, _ES);
}

int Registers::IP() const noexcept
{
    return getFullBits(_IP);
}

void Registers::IP(int value) noexcept
{
    setFullBits(value, _IP);
}
