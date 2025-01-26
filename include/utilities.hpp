#ifndef __UTILITIES
#define __UTILITIES

#include <cstdlib>
#include "../include/memory.hpp"
#include "../include/registers.hpp"
#include "../include/flags.hpp"

void printMemory(const Memory &memory, uint32_t start, uint32_t end);
void printRegisters(const Registers &registers);
void printFlags(const Flags &flags);

#endif
