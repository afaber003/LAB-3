#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <string>

using namespace std;

// I HAVE NO IDEA IF THIS IS RIGHT AT ALL
template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index){ //returns the index of the minimum value
 
    
  
       //exceptions
       // if (index > vals.size() - 1){throw runtime_error("Too Big");}
       // if (index < 1){throw runtime_error("Too Small");}
        unsigned smallesti = index;

        // actual search
        //unsigned smallesti = index;
        // T smallest = vals[index];  // not needed
        for (unsigned i = index; i < vals.size(); i++){
            if (vals[i] < vals[smallesti])
            {
                smallesti = i;
                // smallest = vals[i];
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

