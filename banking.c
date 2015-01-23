
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "banking.h"

//Global variables
//struct bank_acct ba = {1, 1};
struct bank_acct *p = NULL; 
 
//A pointer var to keep track of the total number of deposits 
int num_trans = 0;  
int *nt = &num_trans; 

//A pointer var to keep track of the  largest deposit so far in the active account 
int largest_deposit = 0; 
int *ld = &largest_deposit;

//A pointer var to keep track of the largest withdrawal so far in the active account 
int largest_withdrawal = 0; 
int *lw = &largest_withdrawal; 

//NOTE: All 
//4a
struct bank_acct create_acct(int new_id, int new_bal){
   struct bank_acct bankaccount = {new_id, new_bal};
   return bankaccount; 
   }

//4b
void set_active_acct(struct bank_acct *acct) { 
    assert (acct != NULL); 
    *nt = 0; 
    *ld = 0; 
    *lw = 0; 
     p = acct;  
   }
   
//4c
void deposit(int amt) {
   //Manage the Account 
   int new_balance = (*p).balance + amt;
   struct bank_acct money_deposited = {(*p).id, new_balance};
   *p = money_deposited;
   //printf("Stats are as follows after deposit: %d, %d\n", (*p).id, (*p).balance);
   //Align the Internal Statistics 
   *nt = num_trans + 1; 
   if (amt > largest_deposit) 
    {
      *ld = amt; 
      //printf("Largest deposit so far:%d\n", largest_deposit); 
      //printf("Total Positive Transactions:%d\n", num_trans); 
    }
    else 
      { 
        *ld = largest_deposit; 
       //printf("Largest deposit so far:%d\n", largest_deposit); 
      }   
   }
   
//4d
bool withdraw(int amt){
   if (amt < (*p).balance)
   { 
      //Change the Account Info
      int new_balance_w = (*p).balance - amt;
      struct bank_acct money_withdraw = {(*p).id, new_balance_w};
      *p = money_withdraw;
      //printf("Stats are as follows after withdrawal: %d, %d\n", (*p).id, (*p).balance);
     
      //Align the Internal Stats 
      *nt = num_trans + 1; 
      if (amt > largest_withdrawal)
       {
         *lw = amt; 
         //printf("Largest withdrawal so far:%d\n", largest_withdrawal); 
       }
       else 
       {
         *lw = largest_withdrawal; 
         //printf("Largest withdrawal so far:%d\n", largest_withdrawal); 
       }
        return true; 
      
   }
   else 
   { //Money Requested more than avaliable in account == Unsucessful Transaction '
      *lw = largest_withdrawal;
      //printf("Error with Tranaction"); 
      return false; 
      
   }
}

//4d
int max_withdrawal(void){
   return largest_withdrawal; 
 }

//4e 
int max_deposit(void) {
   return largest_deposit; 
  }
  
//4f 
int transaction_count(void){
   return num_trans; 
}

/*
struct bank_acct account1 = {123456789, 0};
struct bank_acct account2 = {987654321, 100};

int main (void) { 
   
   set_active_acct(&account1);
   deposit(30);
   withdraw(20);
   printf ("Balance is: %d \n", account1.balance);
   printf ("max withdrawal: %d \n", max_withdrawal());
   printf ("max deposit: %d \n", max_deposit());
   printf ("transaction_count %d \n", transaction_count());
   
   set_active_acct(&account2);
   printf ("The local stats are: %d, %d, %d \n", num_trans, largest_deposit, largest_withdrawal); 
    deposit(100); 
   printf ("Balance is: %d \n", (*p).balance);
   printf ("max withdrawal: %d \n", max_withdrawal());
   printf ("max deposit: %d \n", max_deposit());
   printf ("transaction_count %d \n", transaction_count());
   }


*/

