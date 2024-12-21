#include <gtest/gtest.h>
#include "../include/memory.hpp"

TEST(ClassMemory, setByte)
{
    Memory memory;
    memory.set(0x1234, 0x0022, std::uint8_t(0x16));

    EXPECT_EQ(memory.get(0x12362), 0x16);
}

TEST(ClassMemory, setWord)
{
    Memory memory;
    memory.set(0x1234, 0x0022, std::uint16_t(0x1617));

    EXPECT_EQ(memory.get(0x12362), 0x17);
    EXPECT_EQ(memory.get(0x12363), 0x16);
}

TEST(ClassMemory, load)
{
    Memory memory;
    std::vector<uint8_t> data = {0x12, 0x76, 0x34, 0xBD};

    memory.load(0x1234, 0x0022, data);

    EXPECT_EQ(memory.get(0x12362), 0x12);
    EXPECT_EQ(memory.get(0x12363), 0x76);
    EXPECT_EQ(memory.get(0x12364), 0x34);
    EXPECT_EQ(memory.get(0x12365), 0xBD);
}
