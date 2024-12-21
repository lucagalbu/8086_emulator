#ifndef __REGISTERS
#define __REGISTERS

#include <cstdint>

class Registers
{
private:
    // Registers
    uint16_t _AX = 0, _BX = 0, _CX = 0, _DX = 0;
    uint16_t _SP = 0, _SI = 0, _DI = 0, _BP = 0;
    uint16_t _CS = 0, _SS = 0, _DS = 0, _ES = 0;
    uint16_t _IP = 0;

    // Utilities
    uint16_t getFullBits(uint16_t reg16) const noexcept;
    uint16_t getLowBits(uint16_t reg16) const noexcept;
    uint16_t getHighBits(uint16_t reg16) const noexcept;
    void setFullBits(uint16_t value, uint16_t &reg16) noexcept;
    void setLowBits(uint16_t value, uint16_t &reg16) noexcept;
    void setHighBits(uint16_t value, uint16_t &reg16) noexcept;

public:
    // Getters
    uint16_t AX() const noexcept;
    uint16_t AH() const noexcept;
    uint16_t AL() const noexcept;

    uint16_t BX() const noexcept;
    uint16_t BH() const noexcept;
    uint16_t BL() const noexcept;

    uint16_t CX() const noexcept;
    uint16_t CH() const noexcept;
    uint16_t CL() const noexcept;

    uint16_t DX() const noexcept;
    uint16_t DH() const noexcept;
    uint16_t DL() const noexcept;

    uint16_t SP() const noexcept;
    uint16_t SI() const noexcept;
    uint16_t DI() const noexcept;
    uint16_t BP() const noexcept;

    uint16_t CS() const noexcept;
    uint16_t SS() const noexcept;
    uint16_t DS() const noexcept;
    uint16_t ES() const noexcept;

    uint16_t IP() const noexcept;

    // Setters
    void AX(uint16_t value) noexcept;
    void AH(uint16_t value) noexcept;
    void AL(uint16_t value) noexcept;

    void BX(uint16_t value) noexcept;
    void BH(uint16_t value) noexcept;
    void BL(uint16_t value) noexcept;

    void CX(uint16_t value) noexcept;
    void CH(uint16_t value) noexcept;
    void CL(uint16_t value) noexcept;

    void DX(uint16_t value) noexcept;
    void DH(uint16_t value) noexcept;
    void DL(uint16_t value) noexcept;

    void SP(uint16_t value) noexcept;
    void SI(uint16_t value) noexcept;
    void DI(uint16_t value) noexcept;
    void BP(uint16_t value) noexcept;

    void CS(uint16_t value) noexcept;
    void SS(uint16_t value) noexcept;
    void DS(uint16_t value) noexcept;
    void ES(uint16_t value) noexcept;

    void IP(uint16_t value) noexcept;
};

#endif
