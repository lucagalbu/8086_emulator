#include <memory>
#include <vector>

#include "../include/memory.hpp"

// Constructor
Memory::Memory()
{
    _memory = std::make_unique<uint8_t[]>(MEM_SIZE_BYTE);
}

uint32_t Memory::computeAddress(uint16_t segment, uint16_t offset) const noexcept
{
    uint32_t address = (segment << 4) + offset;
    return address;
}

void Memory::load(uint16_t segment, uint16_t offset, std::vector<uint8_t> data)
{
    uint32_t address = computeAddress(segment, offset);
    std::memcpy(&_memory[address], data.data(), data.size());
}

// Setters
void Memory::set(uint16_t segment, uint16_t offset, uint8_t value)
{
    uint32_t address = computeAddress(segment, offset);
    _memory[address] = value;
}

void Memory::set(uint16_t segment, uint16_t offset, uint16_t value)
{
    uint32_t address = computeAddress(segment, offset);
    uint8_t value_low = value & 0x00FF;
    uint8_t value_high = (value & 0xFF00) >> 8;

    // Store in reverse order, according to Intel standard
    _memory[address] = value_low;
    _memory[++address] = value_high;
}

// Getters
uint8_t Memory::get(uint16_t segment, uint16_t offset) const
{
    uint32_t address = computeAddress(segment, offset);
    return _memory[address];
}

uint8_t Memory::get(uint32_t address) const
{
    address = address & 0xFFFFF; // Ensure the address is 20bit
    return _memory[address];
}
