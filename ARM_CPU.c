#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

void dec2bin(uint64_t c){
   int i = 0;
   for(i = 63; i >= 0; i--){
     if((c & (1 << i)) != 0){
       printf("1");
     }else{
       printf("0");
     } 
   }
}

void dump_registers(uint64_t* value) {
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
    uint64_t register_info[10];
    dump_registers(register_info);
    printf("ID_PFR0 register value: ");
    dec2bin(register_info[0]);
    printf("\n");
    printf("ID_PFR1 register value: ");
    dec2bin(register_info[1]);
    printf("\n");
    printf("ID_AFR0 register value: ");
    dec2bin(register_info[2]);
    printf("\n");
    printf("ID_DFR0 register value: ");
    dec2bin(register_info[3]);
    printf("\n");
    printf("ID_MMFR0 register value: ");
    dec2bin(register_info[4]);
    printf("\n");
    printf("ID_MMFR1 register value: ");
    dec2bin(register_info[5]);
    printf("\n");
    printf("ID_MMFR2 register value: ");
    dec2bin(register_info[6]);
    printf("\n");
    printf("ID_ISAR0 register value: ");
    dec2bin(register_info[7]);
    printf("\n");
    printf("ID_ISAR1 register value: ");
    dec2bin(register_info[8]);
    printf("\n");
    printf("ID_ISAR2 register value: ");
    dec2bin(register_info[9]);
    printf("\n");
    return 0;
}
