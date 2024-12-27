#include <gtest/gtest.h>
#include "../include/registers.hpp"
#include "../include/memory.hpp"
#include "../include/interrupts.hpp"
#include "../include/flags.hpp"
#include "../include/op_codes.hpp"

class OpCodesTest : public testing::Test
{
protected:
    Memory memory;
    Registers registers;
    Interrupts interrupts;
    Flags flags;
    OpCodes op_codes;

    OpCodesTest() : memory(), registers(), interrupts(registers, memory), flags(), op_codes(registers, memory, flags, interrupts)
    {
        flags.AF(0);
        flags.CF(0);
        flags.DF(0);
        flags.IF(0);
        flags.OF(0);
        flags.PF(0);
        flags.SF(0);
        flags.TF(0);
        flags.ZF(0);

        registers.AX(0);
        registers.BX(0);
        registers.CX(0);
        registers.DX(0);
        registers.DI(0);
        registers.DS(0);
        registers.BP(0);
        registers.CS(0);
        registers.ES(0);
        registers.IP(0);
    }
};

TEST_F(OpCodesTest, cmpImmediateAcc_1)
{
    registers.AX(0x1234);
    memory.setByte(registers.CS(), registers.IP(), uint8_t(0x3D));
    memory.setWord(registers.CS(), registers.IP() + 1, uint16_t(0x1234));

    op_codes.exec(1);
    EXPECT_TRUE(flags.ZF());
    EXPECT_TRUE(flags.PF());
    EXPECT_FALSE(flags.AF());
    EXPECT_FALSE(flags.CF());
    EXPECT_FALSE(flags.DF());
    EXPECT_FALSE(flags.IF());
    EXPECT_FALSE(flags.OF());
    EXPECT_FALSE(flags.SF());
    EXPECT_FALSE(flags.TF());
}

TEST_F(OpCodesTest, cmpImmediateAcc_2)
{
    registers.AX(0x8);
    memory.setByte(registers.CS(), registers.IP(), uint8_t(0x3D));
    memory.setWord(registers.CS(), registers.IP() + 1, uint16_t(0x5));

    op_codes.exec(1);
    EXPECT_FALSE(flags.ZF());
    EXPECT_TRUE(flags.PF());
    EXPECT_FALSE(flags.AF());
    EXPECT_FALSE(flags.CF());
    EXPECT_FALSE(flags.DF());
    EXPECT_FALSE(flags.IF());
    EXPECT_FALSE(flags.OF());
    EXPECT_FALSE(flags.SF());
    EXPECT_FALSE(flags.TF());
}

TEST_F(OpCodesTest, cmpImmediateAcc_3)
{
    registers.AX(0x5);
    memory.setByte(registers.CS(), registers.IP(), uint8_t(0x3D));
    memory.setWord(registers.CS(), registers.IP() + 1, uint16_t(0x8));

    op_codes.exec(1);
    EXPECT_FALSE(flags.ZF());
    EXPECT_FALSE(flags.PF());
    EXPECT_TRUE(flags.AF());
    EXPECT_TRUE(flags.CF());
    EXPECT_FALSE(flags.DF());
    EXPECT_FALSE(flags.IF());
    EXPECT_FALSE(flags.OF());
    EXPECT_TRUE(flags.SF());
    EXPECT_FALSE(flags.TF());
}