#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// *You* are not allowed to use global variables
//  but for just the output portion *we* will. ;>
int combo = 1;

// @brief Prints a single combination of teams
//
// @param[in] team1 Array containing the names of team 1
// @param[in] team2 Array containing the names of team 2
// @param[in] len Size of each array
void printSolution(const string* team1, 
		   const string* team2,
		   int len)
{
  cout << "\nCombination " << combo++ << endl;
  cout << "T1: ";
  for(int i=0; i < len; i++){
    cout << team1[i] << " ";
  }
  cout << endl;
  cout << "T2: ";
  for(int i=0; i < len; i++){
    cout << team2[i] << " ";
  }
  cout << endl;
}

// You may add additional functions here

bool loadPlayers(istream& ifile, string *&arr, int &size){

  string tempString;
  getline(ifile, tempString, '\n');

  if(tempString[0] < '0' || tempString[0] > '9'){
    cout << "Error";
    return false;
  }

  int statedNumPlayers = atoi(tempString.c_str());
  int countedNumPlayers = 0;

  arr = new string[statedNumPlayers];
  size = statedNumPlayers;

  while(ifile >> tempString){
    arr[countedNumPlayers] = tempString;
    countedNumPlayers++;
  }

  if(countedNumPlayers != statedNumPlayers){
    cout << "Error";
    return false;
  }

  return true;
};

void permutate(string *players, string *team1, string *team2, int t1i, int t2i, int pi, int size){
  if(pi == size){
    printSolution(team1, team2, size/2);
  } else {
    if (t1i < size/2) {
      team1[t1i] = players[pi];
      permutate(players, team1, team2, t1i+1, t2i, pi+1, size);
    } 
    if (t2i < size/2) {
      team2[t2i] = players[pi];
      permutate(players, team1, team2, t1i, t2i+1, pi+1, size);
    }      
  }
}

void findTeams(string* players, int size){
  string *team1 = NULL;
  string *team2 = NULL;
  team1 = new string[size/2];
  team2 = new string[size/2];
  permutate(players, team1, team2, 0, 0, 0, size);
  delete [] team1;
  delete [] team2;
  team1 = NULL;
  team2 = NULL; 
}

int main(int argc, char* argv[])
{
  if(argc < 2){
    cerr << "Please provide a file of names" << endl;
    return 1;
  }
  // Complete the rest of main
  ifstream ifile(argv[1]);
  if(ifile.fail()){
    cerr << "Error" << endl;
    ifile.close();
    return 1;
  }

  string* arr = NULL;
  int size = 0;

  if ( ! loadPlayers(ifile, arr, size) ){
    cerr << "Error" << endl;
    ifile.close();
    return 1;
  }

  findTeams(arr, size);

  delete [] arr;
  arr = NULL;

  return 0;
}
