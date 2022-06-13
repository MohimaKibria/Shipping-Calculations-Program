#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

char x , z = '*', v = '.', w = '-';//stores the single characters in the code wHere user is asked if the item is fragile and stores characters like the dash in order to avoid hard coding.
string IT, DES;
double TP, TC, SP;
double SH;
const double LU = 6.00, LC = 8.00, LA = 10.00, LT = 12.00;
const double FU = 9.00, FC = 12.00, FA = 14.00, FT = 16.00;
const double OU = 12.00, OC = 15.00, OA = 17.00, OT = 19.00;
const double FFF = 0.00, FRAG = 2.00;
const double SOT = 50.00, MOT = 50.01, NOT = 100.00, LOT = 100.01, POT = 150.00, XOT = 150.01;//const numbers above the main function because they will not change

int main() 
{
  cout << setw(49) << setfill('*') << z << endl;
  cout << "ITCS 2530 - Programming Assignment for week #3 " << endl;
  cout << setw(49) << setfill(z) << z << endl; //intro to program
  cout << "Please enter the item name (no spaces)" << setw(10) << setfill('.') << v << ":"; 
  cin >> IT;//asking for item name
  cout << "Is the item fragile? (y=yes/n=no)" << setw(15) << setfill('.') << v << ":";
  cin >> x;//asking the user to enter the characters y or n to answer if the item is fragile.
        switch (x)
				{
					case 'y':
					SP = SP + FRAG;
					break;
					case 'Y':
					SP = SP + FRAG;//adds $2.00 to shipping because item is fragile
					break;
					case 'n':
          SP = SP + FFF;
					break;
					case 'N':
          SP = SP + FFF;//adds $0.00 to shipping because item is not fragile.
					break;
					default:
						cout << "Invalid entry, exiting";
						return 0;
				}//switch structure used as an alternative to if-else in order to stop the code if user doesnt enter one of the case values the program is stopped. If the user enters the given case values then the shipping cost will change accordingly.
  cout << "Please enter your order total" << setw(19) << setfill('.') << v << ":";
  cin >> TP;//Asking user to input order total
    cout << "Please enter destination. (usa/can/aus/turkey)" << setw(9) << setfill('.') << v << ":";
  cin >> DES;//asking user to input destination to where the package will ship.
      if (DES == "usa"|| DES == "USA"|| DES == "can"|| DES == "CAN"||DES == "aus"||DES =="AUS"||DES == "turkey"||DES == "TURKEY"){
        cout << endl;}
      else 
      {
        cout << endl;
			  cout << "Invalid entry, exiting";
        return 0;
      }//if the user does NOT enter the right destination the program will exit
  
    if (DES == "usa" && TP <=  SOT||DES =="USA" && TP <=  SOT)
      SP = SP + LU;
    else if (DES == "usa" && TP <= NOT && TP >= MOT|| DES == "USA" && TP <= NOT && TP >= MOT)
      SP = SP + FU;
    else if (DES == "usa" && TP <= POT && TP >= LOT||DES == "USA" && TP <= POT && TP >= LOT)
      SP = SP + OU;
    else if (DES == "can" && TP <= SOT||DES == "CAN" && TP <= SOT)
      SP = SP + LC;
    else if (DES == "can" && TP <= NOT && TP >= MOT||DES == "CAN" && TP <= NOT && TP >= MOT)
      SP = SP + FC;
    else if (DES == "can" && TP <= POT && TP >= LOT||DES == "CAN" && TP <= POT && TP >= LOT)
      SP = SP + OC;
    if (DES == "aus" && TP <= SOT||DES == "AUS" && TP <= SOT)
      SP = SP + LA;
    else if (DES == "aus" && TP <= NOT && TP >= MOT||DES == "AUS" && TP <= NOT && TP >= MOT)
      SP = SP + FA;
    else if (DES == "aus" && TP <= POT && TP >= LOT||DES == "AUS" && TP <= POT && TP >= LOT)
      SP = SP + OA;
    if (DES == "turkey" && TP <=  SOT||DES =="TURKEY" && TP <=  SOT)
      SP = SP + LT;
    else if (DES == "turkey" && TP <= NOT && TP >= MOT|| DES == "TURKEY" && TP <= NOT && TP >= MOT)
      SP = SP + FT;
    else if (DES == "turkey" && TP <= POT && TP >= LOT||DES == "TURKEY" && TP <= POT && TP >= LOT)
      SP = SP + OT;
    else 
      SP = SP + FFF;//this statement is for orders above 150
  //based on the users input when asked about the order total, destination, and how fragile the item is, the correct statement will be executed in order to determine the shipping cost.
 
  TC = TP + SP;//calculates total cost by adding item cost and shipping cost
  
  transform(IT.begin(), IT.end(), IT.begin(), ::toupper);//this function is used to convert the variable to Upper case. 
  cout << "Your item is" << setw(36) << setfill(v) << IT << endl; 
  cout << "Your shipping cost is" << setw(19) << setfill(v) << fixed << setprecision(2) << "$" << SP << endl;//fixed and setprecision manipulator in order to output 2 decimal places instead of one. 
  transform(DES.begin(), DES.end(), DES.begin(), ::toupper);//the toupper function is used again inorder to convert the destination to uppercase.
  cout << "You are shipping to" << setw(23) << setfill(v) << DES << endl;//returns yor shipping location in uppercase
  cout << "Your total shipping costs are" << setw(11) << setfill(v) << fixed << setprecision(2)<< "$" << TC << endl;//gives user the total payment after adding shipping and item price with two decimal places
  cout << endl;
  cout << setw(49) << setfill(w) << "Thank you!" << endl;
}
	