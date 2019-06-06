// Project 4: Solve Knapsack using bound and branch and bound
//

#include <iostream>
#include <limits.h>
#include <list>
#include <fstream>
#include <queue>
#include <vector>
#include <time.h>
#include <stack>

using namespace std;

#include "d_except.h"
#include "d_matrix.h"
#include "knapsack.h"

int main()
{
   char x;
   ifstream fin;
   stack <int> moves;
   string fileName;
   
   // Read the name of the file from the keyboard or
   // hard code it here for testing.
   
    fileName = "knapsack8.input";

   //cout << "Enter filename" << endl;
   //cin >> fileName;
   
   fin.open(fileName.c_str());
   if (!fin)
   {
      cerr << "Cannot open " << fileName << endl;
      exit(1);
   }

   try
   {
      cout << "Reading knapsack instance" << endl;
      knapsack k(fin);

	  k.bubbleSort(k.getNumObjects());
      int bound = k.bound();

	  cout << "Bound: " << bound << endl;

      cout << endl << "Best solution" << endl;
      k.printSolution();
      
   }    

   catch (indexRangeError &ex) 
   { 
      cout << ex.what() << endl; exit(1);
   }
   catch (rangeError &ex)
   {
      cout << ex.what() << endl; exit(1);
   }
}

