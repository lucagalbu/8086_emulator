#include <gtest/gtest.h>
#include "../include/registers.hpp"

TEST(ClassRegisters, ModifyFull)
{
    Registers registers;
    registers.AX(0x1110);
    registers.BX(0x2112);
    registers.CX(0x3113);
    registers.DX(0x4114);
    registers.SP(0x5115);
    registers.SI(0x6116);
    registers.DI(0x7117);
    registers.BP(0x8118);
    registers.CS(0x9119);
    registers.DS(0xA11A);
    registers.SS(0xB11B);
    registers.ES(0xC11C);
    registers.IP(0xD11D);

    EXPECT_EQ(registers.AX(), 0x1110);
    EXPECT_EQ(registers.AH(), 0x11);
    EXPECT_EQ(registers.AL(), 0x10);
    EXPECT_EQ(registers.BX(), 0x2112);
    EXPECT_EQ(registers.BH(), 0x21);
    EXPECT_EQ(registers.BL(), 0x12);
    EXPECT_EQ(registers.CX(), 0x3113);
    EXPECT_EQ(registers.CH(), 0x31);
    EXPECT_EQ(registers.CL(), 0x13);
    EXPECT_EQ(registers.DX(), 0x4114);
    EXPECT_EQ(registers.DH(), 0x41);
    EXPECT_EQ(registers.DL(), 0x14);
    EXPECT_EQ(registers.SP(), 0x5115);
    EXPECT_EQ(registers.SI(), 0x6116);
    EXPECT_EQ(registers.DI(), 0x7117);
    EXPECT_EQ(registers.BP(), 0x8118);
    EXPECT_EQ(registers.CS(), 0x9119);
    EXPECT_EQ(registers.DS(), 0xA11A);
    EXPECT_EQ(registers.SS(), 0xB11B);
    EXPECT_EQ(registers.ES(), 0xC11C);
    EXPECT_EQ(registers.IP(), 0xD11D);
}

TEST(ClassRegisters, ModificationLow)
{
    Registers registers;

    // Set an intial value
    registers.AX(0x1110);
    registers.BX(0x2112);
    registers.CX(0x3113);
    registers.DX(0x4114);

    // Change the value of the low bit
    registers.AL(0xAB);
    registers.BL(0xCD);
    registers.CL(0xEF);
    registers.DL(0x00);

    // Check that content has the updated low bit
    EXPECT_EQ(registers.AX(), 0x11AB);
    EXPECT_EQ(registers.BX(), 0x21CD);
    EXPECT_EQ(registers.CX(), 0x31EF);
    EXPECT_EQ(registers.DX(), 0x4100);
}

TEST(ClassRegisters, ModificationHigh)
{
    Registers registers;

    // Set an intial value
    registers.AX(0x1110);
    registers.BX(0x2112);
    registers.CX(0x3113);
    registers.DX(0x4114);

    // Change the value of the high bit
    registers.AH(0xAB);
    registers.BH(0xCD);
    registers.CH(0xEF);
    registers.DH(0x00);

    // Check that content has the updated high bit
    EXPECT_EQ(registers.AX(), 0xAB10);
    EXPECT_EQ(registers.BX(), 0xCD12);
    EXPECT_EQ(registers.CX(), 0xEF13);
    EXPECT_EQ(registers.DX(), 0x0014);
}
