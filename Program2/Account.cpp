#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/* This is a class for accounts. Each object has associated attributes that are the values from CSV.
   ID is what will be used to identify the person and is stored into a class vector called accounts. */
class Account {
      
   public:
      // Setters
      void SetID (int acctid);
      void SetFirstName(string acctfName);
      void SetLastName(string acctlName);
      void SetSavings(double acctSavings);
      void SetChecking(double acctChecking);
      void SetAllAttributes(int acctid, string acctfName, string acctlName, double acctSavings, double acctChecking);

      // Getters
      int GetID();
      string GetFirstName();
      string GetLastName();
      double GetSavings();
      double GetChecking();
      double GetTotal(double acctSavings, double acctChecking);
   
   private:
      int id;
      string firstName, lastName;
      double savings, checking, totalbal;
};

// Setter Functions
void Account::SetID(int acctid) {
   id = acctid;
}
void Account::SetFirstName(string acctfName) {
   firstName = acctfName;
}
void Account::SetLastName(string acctlName) {
   lastName = acctlName;
}
void Account::SetSavings(double acctSavings) {
   savings = acctSavings;
}
void Account::SetChecking(double acctChecking) {
   checking = acctChecking;
}
void Account::SetAllAttributes(int acctid, string acctfName, string acctlName, double acctSavings, double acctChecking) {
   id = acctid;
   firstName = acctfName;
   lastName = acctlName;
   savings = acctSavings;
   checking = acctChecking;
}


// Getter Functions
int Account::GetID() {
   return id;
}
string Account::GetFirstName() {
   return firstName;
}
string Account::GetLastName() {
   return lastName;
}
double Account::GetSavings() {
   return savings;
}
double Account::GetChecking() {
   return checking;
}

double Account::GetTotal(double acctSavings, double acctChecking) {
   totalbal = acctSavings + acctChecking;
   return totalbal;
}