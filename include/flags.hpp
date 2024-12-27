#ifndef __FLAGS
#define __FLAGS

#include <cstdint>

class Flags
{
private:
    uint8_t _AF, _CF, _OF, _SF, _PF, _ZF, _DF, _IF, _TF;

public:
    // Setters
    void AF(bool set) noexcept;
    void CF(bool set) noexcept;
    void OF(bool set) noexcept;
    void SF(bool set) noexcept;
    void PF(bool set) noexcept;
    void ZF(bool set) noexcept;
    void DF(bool set) noexcept;
    void IF(bool set) noexcept;
    void TF(bool set) noexcept;

    // Getters
    bool AF() const noexcept;
    bool CF() const noexcept;
    bool OF() const noexcept;
    bool SF() const noexcept;
    bool PF() const noexcept;
    bool ZF() const noexcept;
    bool DF() const noexcept;
    bool IF() const noexcept;
    bool TF() const noexcept;
};

#endif