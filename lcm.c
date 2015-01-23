#include <stdio.h>
#include <assert.h>

// lcm_withacc(int a, int b) computes the least common multiple of a and b
//PRE: a > 0, b > 0, least common multiple of a and b is less than 2,147,483,648 (2^31).
//POST: returns an integer > 0
static int lcm_withacc (int a, int b, int acc) {
   return (a * acc) % b == 0 ? (a * acc): 
         lcm_withacc( a, b, acc + 1); 
     } 


// lcm(int a, int b) computes the least common multiple of a and b
//     PRE: a > 0, b > 0, least common multiple of a and b is less than 2,147,483,648 (2^31).
//     POST: returns an integer > 0

int lcm (int a, int b){ 
   assert(a > 0);
   assert(b > 0);
   return lcm_withacc (a , b, 1);
   }
   
/*
int main(void) { 
      printf("%d\n", lcm (30,45)) ;
       printf("%d\n", lcm (16,20)) ;
       printf("%d\n", lcm (5,8)) ;
      }
      */
