#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include "register_vals.h"

// Prints the String buffer into the binary representation
void print_bin(uint64_t* bin){
  int8_t j = 0;
  int8_t count = 0;
  for(j = 63; j >= 0; j--){
    printf("%ld",bin[j]);
    count++;
     if(count == 4){
      printf(" | ");
      count = 0;
    }
  }
}

// Converts the decimal value into a binary string
void dec2bin(int64_t dec, uint64_t* bin_vals){
    uint64_t i = 0; 
    while (dec > 0) { 
        // storing remainder in binary array 
        bin_vals[i] = dec % 2; 
        dec = dec / 2; 
        i++; 
    }
    print_bin(bin_vals);

}

// Collects data from registers
void dump_registers(int64_t* value) {
    asm inline("mrs %0, ID_AA64PFR0_EL1" : "=r" (value[0]));
    asm inline("mrs %0, ID_AA64PFR1_EL1" : "=r" (value[1]));
    asm inline("mrs %0, ID_AA64AFR0_EL1" : "=r" (value[2]));
    asm inline("mrs %0, ID_AA64DFR0_EL1" : "=r" (value[3]));
    asm inline("mrs %0, ID_AA64MMFR0_EL1" : "=r" (value[4]));
    asm inline("mrs %0, ID_AA64MMFR1_EL1" : "=r" (value[5]));
    asm inline("mrs %0, ID_AA64MMFR2_EL1" : "=r" (value[6]));
    asm inline("mrs %0, ID_AA64ISAR0_EL1" : "=r" (value[7]));
    asm inline("mrs %0, ID_AA64ISAR1_EL1" : "=r" (value[8]));
    asm inline("mrs %0, ID_AA64ISAR2_EL1" : "=r" (value[9]));
}

int main() {
    int64_t register_info[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    //int64_t* reg_dumps[10] = &register_info;
    reg_vals binary_register_vals;
    reg_vals* regs = &binary_register_vals;
    dump_registers(register_info);
    printf("## ID_PFR0 register value ##\n");
    dec2bin(register_info[0], regs->pfr0);
    printf("\n");
    printf("## ID_PFR1 register value ##\n");
    dec2bin(register_info[1], regs->pfr1);
    printf("\n");
    printf("## ID_AFR0 register value ##\n");
    dec2bin(register_info[2], regs->afr0);
    printf("\n");
    printf("## ID_DFR0 register value ##\n");
    dec2bin(register_info[3], regs->dfr0);
    printf("\n");
    printf("## ID_MMFR0 register value ##\n");
    dec2bin(register_info[4], regs->mmfr0);
    printf("\n");
    printf("## ID_MMFR1 register value ##\n");
    dec2bin(register_info[5], regs->mmfr1);
    printf("\n");
    printf("## ID_MMFR2 register value ##\n");
    dec2bin(register_info[6], regs->mmfr2);
    printf("\n");
    printf("## ID_ISAR0 register value ##\n");
    dec2bin(register_info[7], regs->isar0);
    printf("\n");
    printf("## ID_ISAR1 register value ##\n");
    dec2bin(register_info[8], regs->isar1);
    printf("\n");
    printf("## ID_ISAR2 register value ##\n");
    dec2bin(register_info[9], regs->isar2);
    printf("\n");
    return 0;
}
