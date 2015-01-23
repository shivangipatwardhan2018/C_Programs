#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

//change_tobin: Int --> Int 
//


//diff_ham: Int Int Int --> Int 
// PRE: a >=0, a >=0, acc = 0 
//POST: Nat >= 0 
//diff_ham(a, b, acc) return how many digits differe between a and b
static int diff_ham (int a, int b, int acc) { 
   return //((a == 1) && (b == 0)) || ((a == 0) && (b == 1)) ? (acc + 1) : 
       (a == 0) && ( b == 0) ? acc: 
      (a % 2) == (b % 2) ? diff_ham(a/2, b/2, acc):
      diff_ham (a/2, b/2, acc + 1);
     } 
      
//hamming: Int Int --> Int 
// PRE: a >=0, a >=0sdw
//POST: Nat >= 0 
//hamming(a,b) returns the hamming difference between the two input numbers 
int hamming (int a, int b) { 
   assert (a>=0);
   assert (b>=0);
   return diff_ham (a, b, 0 );
   }
  /*
int main(void){
   printf("%d\n", hamming (3, 13)); 
  // printf("%d\n", hamming (1001001, 1011101)); 
   // printf("%d\n", hamming (-10, 1011101)); 
  // printf("%d\n%d\n", 100100101101%10, 101000100010%10); 
   }*/

   
