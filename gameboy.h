#ifndef GAMEBOY_H_
#define GAMEBOY_H_


// TODO:
// Audio file and macro definitions
// Confirm if byte data type should be unsigned or not (for negative offset operations)
// Decide if it's better to have an array holding the cycles count for each opcode
// Decide if it's better to increment the PC during the instruction
// Create a macro that reads and writes from/to memory to avoid opcode-specific bugs
// Add headers to each file with descriptions of code
// CPU Start up procedure
// Research interrupt flag bits

// Datatype Definitions
typedef unsigned char byte;
typedef unsigned short word;

/*
	CPU Definitions and Macros
*/
#define MAX_GB_MEMORY        0x10000 // 64k of byte-addresable memory
#define MAX_GB_MAIN_RAM      0x2000  // 8k Main Working RAM
#define MAX_GB_VID_RAM       0x2000  // 8k Video RAM

// Cast LSB and MSB as a WORD (16 bits)
#define CASTWD(x, y) (((((word)x) << 8) & 0xFF00) | ((word)y) & 0x00FF)

// PUSH/POP to/from stack
#define PUSH(x, y)   MEM[SP] = y; --SP; MEM[SP] = x; --SP;         // PUSH stores LSB first, then MSB
#define POP(x, y)    ++SP; x = MEM[SP]; ++SP; y = MEM[SP];         // POP loads MSB first, then LSB

// Set and clear bits (used mainly for setting status register)
#define SETBIT(val, bit) val |= (0x01 << bit)
#define CLRBIT(val, bit) val &= ~(0x01 << bit)

/*
	Picture Processing Unit Definitions
*/
#define MAX_SPRITES          40
#define MAX_SPRITES_PER_LINE 10

#define MAX_SPRITES_ROW      8
#define MAX_SPRITES_COL      16
#define MIN_SPRITES_ROW      8
#define MIN_SPRITES_COL      8

/*
	Interrupt Flag Definitions - Highest Priority = Lowest Bit (0)
	FFFF - IE - Interrupt Enable (1 = Enabled)
	FF0F - IF - Interrupt Flag	 (1 = Request)

 b8|0		0		0		0		0		0		0		0|b0
	-		-		-		Joypad	Serial	Timer	LCD St	V-Blank	
*/
#define INTERRUPT_ENABLE	0xFFFF
#define INTERRUPT_FLAG		0xFF0F

#endif /* GAMEBOY_H_ */
