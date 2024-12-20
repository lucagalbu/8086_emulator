#ifndef __REGISTERS
#define __REGISTERS

class Registers
{
private:
    // Registers
    int _AX = 0, _BX = 0, _CX = 0, _DX = 0;
    int _SP = 0, _SI = 0, _DI = 0, _BP = 0;
    int _CS = 0, _SS = 0, _DS = 0, _ES = 0;
    int _IP = 0;

    // Utilities
    int getFullBits(int reg16) const noexcept;
    int getLowBits(int reg16) const noexcept;
    int getHighBits(int reg16) const noexcept;
    void setFullBits(int value, int &reg16) noexcept;
    void setLowBits(int value, int &reg16) noexcept;
    void setHighBits(int value, int &reg16) noexcept;

public:
    // Getters
    int AX() const noexcept;
    int AH() const noexcept;
    int AL() const noexcept;

    int BX() const noexcept;
    int BH() const noexcept;
    int BL() const noexcept;

    int CX() const noexcept;
    int CH() const noexcept;
    int CL() const noexcept;

    int DX() const noexcept;
    int DH() const noexcept;
    int DL() const noexcept;

    int SP() const noexcept;
    int SI() const noexcept;
    int DI() const noexcept;
    int BP() const noexcept;

    int CS() const noexcept;
    int SS() const noexcept;
    int DS() const noexcept;
    int ES() const noexcept;

    int IP() const noexcept;

    // Setters
    void AX(int value) noexcept;
    void AH(int value) noexcept;
    void AL(int value) noexcept;

    void BX(int value) noexcept;
    void BH(int value) noexcept;
    void BL(int value) noexcept;

    void CX(int value) noexcept;
    void CH(int value) noexcept;
    void CL(int value) noexcept;

    void DX(int value) noexcept;
    void DH(int value) noexcept;
    void DL(int value) noexcept;

    void SP(int value) noexcept;
    void SI(int value) noexcept;
    void DI(int value) noexcept;
    void BP(int value) noexcept;

    void CS(int value) noexcept;
    void SS(int value) noexcept;
    void DS(int value) noexcept;
    void ES(int value) noexcept;

    void IP(int value) noexcept;
};

#endif
