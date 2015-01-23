#include <stdio.h>
#include <stdbool.h>

// name_char(c) determines if c is valid in a C identifier (name)
//    PRE: true
//    POST: returns true or false, Boolean 
//name_char(c) returns true in the input char is valid to put into a name
// else returns false 

bool name_char(char c) {
   return ((c >= 48) && (c <=57)) || ((c >= 65) && (c <=90)) ||
            ((c >= 97) && (c <=122)) || c == 95 ? true:
            false; 
            }
      
      
      /*
 int main (void) { 
   printf("%d\n", name_char('^'));
   printf("%d\n", name_char('d'));
   printf("%d\n", name_char('V'));
   printf("%d\n", name_char('_'));
   printf("%d\n", name_char('/'));
   printf("%d\n", name_char(']'));
   }

*/
