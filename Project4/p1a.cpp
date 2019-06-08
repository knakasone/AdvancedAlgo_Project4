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
#include <deque>

using namespace std;

#include "d_except.h"
#include "d_matrix.h"
#include "knapsack.h"

void branchAndBound(knapsack& k, int t) {
	deque <knapsack> knapsackDeque;
	int numObjects = k.getNumObjects();
	int costLimit = k.getCostLimit();
	int level = 1;

	//sort the objects from largest to smallest value-cost ratio
	k.bubbleSort(numObjects);
	int zStar = k.initialSol();
	int championIndex = -1;

	while (level < numObjects + 1) {
		for (int i = 0; i < pow(2, level); i++) {
			knapsack newKnapsack = knapsack(k);
			knapsackDeque.push_front(newKnapsack);
			for (int j = 1; j < level; j++) {
				if (i % 2 == 1) {
					newKnapsack.select(j);
				}
				int currBound = newKnapsack.bound();
				if (newKnapsack.isFeasible(costLimit) && newKnapsack.isIntegral() && currBound < zStar) {
					zStar = currBound;
					championIndex = i;
				}
				if (!newKnapsack.isFeasible(costLimit) || newKnapsack.isIntegral() || currBound > zStar) {

				}
			}

			level++;
		}
		
	}
}

int main()
{
   char x;
   ifstream fin;
   stack <int> moves;
   string fileName, outFile;
   
   // Read the name of the file from the keyboard or
   // hard code it here for testing.
   
    fileName = "knapsack8.input";
	outFile = "test.txt";

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

	  //k.bubbleSort(k.getNumObjects());
      //int bound = k.bound();
	  //cout << "Bound: " << bound << endl;

      cout << endl << "Best solution" << endl;
      //k.printSolution(outFile);
	  cout << k;
      
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

