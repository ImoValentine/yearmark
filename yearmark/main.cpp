#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {
   string subjectCode; //variable declaration for subject code
   float percentAssignment1Contri = 0; //variable for percentage of assignment 1 contribution
   float studentpercentAssignment1 = 0; //variable for student percent in assignment 1
   float percentAssignment2Contri = 0;//variable for percentage of assignment 2 contribution
   float studentpercentAssignment2 = 0;//variable for student percent in assignment 1
   float totalPercentForCourse; //variable for year percentage of course

   ifstream in; //declaring ifstream variable to read a file
   ofstream myfile; //declaring ofstream variable to write a file
in.open("assignments.dat"); //open the input dat file
   myfile.open("yearmark.dat"); //open the output dat file
   string str; //variable for reading
   while ( getline(in,str)) { // Continue if the line was sucessfully read.

totalPercentForCourse = 0;
        std::istringstream iss(str); //string stream to read the line by line string

        if (!(iss >> subjectCode >> percentAssignment1Contri >> studentpercentAssignment1 >> percentAssignment2Contri>>studentpercentAssignment2)) { break; } //error when the text file is not in the right format

totalPercentForCourse = (studentpercentAssignment1/100*percentAssignment1Contri )+(studentpercentAssignment2/100*percentAssignment2Contri ); //calculate the year percent for that course
myfile<< subjectCode <<" "<< fixed << setprecision(2)<< totalPercentForCourse<<"%" <<endl; //store in output file

   }
   myfile.close(); //close the output file
   in.close(); //close the input file
   cout<<"Created file yearmark.dat with overall percentage";
   } //prompt after file output
