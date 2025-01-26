#ifndef __UTILITIES
#define __UTILITIES

#include <cstdlib>
#include "../include/memory.hpp"
#include "../include/registers.hpp"

void printMemory(const Memory &memory, uint32_t start, uint32_t end);
void printRegisters(const Registers &registers);

#endif
