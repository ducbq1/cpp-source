#include <stdio.h>

#define OPE_MASK_ADD (1 << 0) // 1 = 0x01 = 00000001
#define OPE_MASK_SUB (1 << 1) // 2 = 0x02 = 00000010
#define OPE_MASK_MUL (1 << 2) // 4 = 0x04 = 00000100
#define OPE_MASK_DIV (1 << 3) // 8 = 0x08 = 00001000

void math_operator(int a, int b, unsigned char ope)  
 {  
   if(ope & OPE_MASK_ADD){  
     printf("sum: a+b= %d \n", (a+b));  
   }  
   
   if(ope & OPE_MASK_SUB){  
     printf("sub: a-b= %d \n", (a-b));  
   }  
   
   if(ope & OPE_MASK_MUL){  
     printf("multi: a*b= %d \n", (a*b));  
   }  
   
   if(ope & OPE_MASK_DIV){  
     if(b!=0)  
       printf("devi: a/b= %f \n", ((float)a/b));  
     else  
       printf("fail ! \n");  
   }  
   printf("\n");  
 }  
   
 int main()  
 {  
   
   math_operator(4,2, (OPE_MASK_ADD));  
   math_operator(4,2, (OPE_MASK_ADD | OPE_MASK_SUB));  
   math_operator(4,2, (OPE_MASK_ADD | OPE_MASK_SUB | OPE_MASK_MUL));  
   math_operator(4,2, (OPE_MASK_ADD | OPE_MASK_SUB) | OPE_MASK_MUL | OPE_MASK_DIV);  
   
   return 0;  
 }  
