#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index){ //returns the index of the minimum value
 
    unsigned smallesti = index;
    for (unsigned i = index; i < vals.size(); i++){
        if (vals[i] < vals[smallesti]){
            smallesti = i;
        }
    }
    return smallesti;
}
   
vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}
 
template<typename T> 
void selection_sort(vector<T> &vals)  
{
  for (unsigned i = 0; i < vals.size(); i++)
  {
    unsigned currMin = min_index(vals, i);
    T currTemp = vals[currMin];
    vals[currMin] = vals[i];
    vals[i] = currTemp;
  
  } 
}
// b > a    c b a d e f   temp = a; a = b; b = temp;   

template<typename T>
T getElement(vector<T> vals, int index)
{
  //1. Check if the index is valid
  //2. find the element on that index 
  int size = vals.size();
  if (index < 0 || index >= size )  
  {
    throw out_of_range("out of range exception occured");  
  }
  
  return vals[index];
}


//helper functions


int main(){
  try
  { 
    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    while(--numOfRuns >= 0){
      cout << "Enter a number: " << endl;
      cin >> index;
      curChar = getElement(vals,index);
      cout << "Element located at " << index << ": is " << curChar << endl;
    }
  }
  catch (const out_of_range& excpt) 
  {
    cout << excpt.what() << endl;
  }
    return 0;
}

