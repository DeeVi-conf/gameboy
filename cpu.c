#include <stdint.h>

// redfining reg names to be more intutive
#define A AF.byte.high
#define F AF.byte.low
#define B BC.byte.high
#define C BC.byte.low
#define D DE.byte.high
#define E DE.byte.low
#define H HL.byte.high
#define L HL.byte.low


// Layed out in little endian nortation, with the first byte high, second byte low
struct reg_pair {
    
    uint16_t value;
    
    struct {
        uint8_t high;
        uint8_t low;
    } byte;

};

struct registers {

    struct reg_pair AF;
    struct reg_pair BC;
    struct reg_pair DE;
    struct reg_pair HL;

    uint16_t SP;
    uint16_t PC;

};

struct registers reg;