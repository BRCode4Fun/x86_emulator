#include <iostream>
#include <string>
#include "include/emulator.h"

const size_t MEMORY_SPACE_SIZE = 4096;

int main(int argc, char *argv[]){

  FILE *bin;
  bin = fopen(argv[1], "rb");

  Emulator emulator;
  emulator.init(MEMORY_SPACE_SIZE, bin);
  fclose(bin);

  while(emulator.get_eip() < MEMORY_SPACE_SIZE) {
    uint8_t opcode = emulator.read_next_opcode();
    emulator.exec(opcode);

    if (emulator.get_eip() == 0x00) break;
  }

  emulator.free();

  return 0;
}
