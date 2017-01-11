/* a simple register VM emulation*/
#include "stdio.h"

#define NUM_REGS 4
#define TRUE 1
#define FALSE 0
#define INVALID -1

/*structure of the instruction*/
struct VMData_ {
    int reg0;
    int reg1;
    int reg2;
    int reg3;
    int op;
    int scal;
};
typedef struct VMData_ VMData;
/* register set*/
int regs[NUM_REGS];
/*
   * Addressing Modes:
   * - Register used as r0, r1, ... rn;
   * - Scalar/ Constant (immediate) values represented as #XXXX
   * - Memory addresses begin with @XXXX
*/
/*
   * Instruction Set:
   * - Load an immediate number(constant) into a register;
   * - Perform an arithmetic sum of two register;
   * - Halt the machine
   * LOAD reg0 #100
   * LOAD reg1 $200
   * ADD reg2 reg1 reg0 //reg2 is the result register
   * HALT
*/
enum opCodes {
    HALT = 0x0;
    LOAD = 0x1;
    ADD = 0x2;
};
/*
   * Instruction Codecs:
   * Since here only have a few number of istructions,so:
   * - 16bits instructions
   *
   * Operands get 8bits, so number range will be [0-255]
   * The Operands Gets place from LSB bit
   * |7|6|5|4|3|2|1|0|
   * The 8bits alse can be use represent 2 register
   * Low 4-bits and high 4-bits
   *
   * Register number can be encoded in 4-bits
   * |11|10|9|8|
   *
   * opcode using the remained bits.
   * |15|14|13|12|
*/



/*fetch the next instruction*/
int fetch();
/*decode the instruction*/
void decode(int instruction, VMData *data);
/*execute the instruction*/
void execute(VMData *data);
/*the instructions dispatcher*/
void run();
