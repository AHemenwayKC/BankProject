#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "Account.cpp"
using namespace std;

// FIXME: Function will read in CSV file.

vector<Account> accounts;

void readFile() {
   ifstream fin;
   Account TempAcct;
   fin.open("CS201PGM2.csv");
   vector<string> row; // vector used to temporarily store each part of the row in csv file.
   string line, letter, info, custID, fname, lname, sbal, cbal;
   string acctChoice, transChoice, transAmt;
   double tempVal;

   getline(fin, line);
   while (fin.good()) {
      letter = line.substr(0,1);
      
      // If first column contains letter A, program adds new customer to accounts vector.
      if (letter == "A") {
         row.clear();
         stringstream inSS(line);
         while (getline(inSS, info, ',')) {
            row.push_back(info);
         }
         custID = stoi(row[1]); // FIXME: add a try catch here.
         fname = row[2];
         lname = row[3];
         sbal = stod(row[4]); // FIXME: add a try catch here.
         cbal = stod(row[5]);
         TempAcct.SetAllAttributes(custID, fname, lname, sbal, cbal);
         accounts.push_back(TempAcct);
      }
      // If first column contains letter U, program updates existing customer in accounts vector.
      else if (letter == "U") {
         row.clear();
         stringstream inSS(line);
         while (getline(inSS, info, ',')) {
            row.push_back(info);
         }
         custID = stoi(row[1]); // FIXME: add a try catch here.
         acctChoice = row[2];
         transChoice = row[3];
         transAmt = stod(row[4]);
         /* WHAT NEEDS TO HAPPEN HERE:
            - Once I extract the customer ID, then I need to check row[3] for either dep or withdraw.
            - If it's deposit, then get value at row[4] and +/- to that acct value attribute.
         */
         for (int i = 0; i < accounts.size(); i++) { // Checks vector for matching custID attribute.
            /* If statements starting from outer loop: If custID matches attribute within vector.
               2nd layer if statement checks for either D or W.
               3rd layer if statements determines checking or savings.
            */
            if (accounts.at(i).GetID() == custID) { // FIXME: Need to add try catch if custID not found.      
               if (transChoice == "D") {
                  if (acctChoice == "C") {
                     tempVal = accounts.at(i).GetChecking();
                     tempVal = tempVal + transAmt;
                     accounts.at(i).SetChecking(tempVal);
                  }
                  else if (acctChoice == "S") {
                     tempVal = accounts.at(i).GetSavings();
                     tempVal = tempVal + transAmt;
                     accounts.at(i).SetSavings(tempVal);
                  }
               }
               else if (transChoice == "W") {
                  if (acctChoice == "C") {
                     tempVal = accounts.at(i).GetChecking();
                     tempVal = tempVal - transAmt;
                     accounts.at(i).SetChecking(tempVal);
                  }
                  else if (acctChoice == "S") {
                     tempVal = accounts.at(i).GetSavings();
                     tempVal = tempVal - transAmt;
                     accounts.at(i).SetSavings(tempVal);
                  }
               }
            }

         }
      }
   }

}

// FIXME: Prints out bank records. NEED TO OUTPUT TO bankInfo.txt FILE.
void printBankInfo() {
   ofstream fout;
   fout.open("BankSummaryReport.txt");
   // FIXME: Need to add a try/catch here to catch any errors and output to error file.
   fout << endl;
   fout << setfill(' ');
   fout << "                                      Welcome to Bank of Kansas City" << endl;
   fout << "                                         Customer Summary Report" << endl;
   fout << endl;
   fout << setw(15) << left << " Bank ID" << setw(15) << left << "First Name" << setw(17) << left << "Last Name" << setw(17) << right << "Savings" << setw(15) << right << "Checking" << setw(15) << right << "Total" << endl;
   fout.close();
}

// FIXME: Prints errors that occur while running code. NEED TO OUTPUT TO errorLog.txt FILE.
/*void printError() {


}*/
