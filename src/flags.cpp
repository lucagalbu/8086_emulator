#include "../include/flags.hpp"

// Getters
void Flags::AF(bool set) noexcept { _AF = set ? 1 : 0; }
void Flags::CF(bool set) noexcept { _CF = set ? 1 : 0; }
void Flags::OF(bool set) noexcept { _OF = set ? 1 : 0; }
void Flags::SF(bool set) noexcept { _SF = set ? 1 : 0; }
void Flags::PF(bool set) noexcept { _PF = set ? 1 : 0; }
void Flags::ZF(bool set) noexcept { _ZF = set ? 1 : 0; }
void Flags::DF(bool set) noexcept { _DF = set ? 1 : 0; }
void Flags::IF(bool set) noexcept { _IF = set ? 1 : 0; }
void Flags::TF(bool set) noexcept { _TF = set ? 1 : 0; }

// Setters
bool Flags::AF() const noexcept { return _AF ? true : false; }
bool Flags::CF() const noexcept { return _CF ? true : false; }
bool Flags::OF() const noexcept { return _OF ? true : false; }
bool Flags::SF() const noexcept { return _SF ? true : false; }
bool Flags::PF() const noexcept { return _PF ? true : false; }
bool Flags::ZF() const noexcept { return _ZF ? true : false; }
bool Flags::DF() const noexcept { return _DF ? true : false; }
bool Flags::IF() const noexcept { return _IF ? true : false; }
bool Flags::TF() const noexcept { return _TF ? true : false; }
