#ifndef __MEMORY
#define __MEMORY

constexpr size_t MEM_SIZE_BYTE = 131072;

class Memory
{
private:
    std::unique_ptr<uint8_t[]> _memory;
    uint32_t computeAddress(uint16_t segment, uint16_t offset) const noexcept;

public:
    explicit Memory();
    void load(uint16_t segment, uint16_t offset, std::vector<uint8_t> data);

    // Setters
    void setByte(uint16_t segment, uint16_t offset, uint8_t value);
    void setWord(uint16_t segment, uint16_t offset, uint16_t value);

    // Getters
    uint8_t get(uint32_t address) const;
    uint8_t getByte(uint16_t segment, uint16_t offset) const;
    uint16_t getWord(uint16_t segment, uint16_t offset) const;
};

#endif