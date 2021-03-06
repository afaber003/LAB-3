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
    unsigned vectorindex = 0;
    while(--numOfRuns >= 0){
      cout << "Enter a number: " << endl;
      cin >> index;
      curChar = getElement(vals,index);
      cout << "Element located at " << index << ": is " << curChar << endl;
    }
    vector<char> charTestV;
    cout << "Selection Sort testing: " << endl;
    cout << endl;

    charTestV.push_back('v');
    charTestV.push_back('i');
    charTestV.push_back('c');
    charTestV.push_back('e');
    charTestV.push_back('a');
    cout << "charTestV before selection sort: " << endl;

    while (vectorindex < charTestV.size())
    {
      cout << charTestV.at(vectorindex) << ' ';
      ++vectorindex;
    }
    cout << endl;
    cout << endl;

    vectorindex = 0;
    cout << "charTestV after selection sort: " << endl;
    selection_sort(charTestV);
    while (vectorindex < charTestV.size())
    {
      cout << charTestV.at(vectorindex) << ' ';
      ++vectorindex;
    }
    vectorindex = 0;
    cout << endl;
    cout << endl;

    vector<int> intTestV;
    cout << "Selection Sort testing (for ints): " << endl;
    cout << endl;
    intTestV.push_back(11);
    intTestV.push_back(100);
    intTestV.push_back(3);
    intTestV.push_back(86);
    intTestV.push_back(27);
    intTestV.push_back(16);
    intTestV.push_back(31);
    intTestV.push_back(10781);

    cout << "intTestV before selection sort: " << endl;
    while (vectorindex < intTestV.size())
    {
      cout << intTestV.at(vectorindex) << ' ';
      ++vectorindex;
    }
    cout << endl;
    cout << endl;
    vectorindex = 0;

    selection_sort(intTestV);

    cout << "intTestV after selection sort: " << endl;
    while (vectorindex < intTestV.size())
    {
      cout << intTestV.at(vectorindex) << ' ';
      ++vectorindex;
    }
    cout << endl;
    cout << endl;
    vectorindex = 0;

    vector<string> stringTestV;
    cout << "Selection Sort testing (for strings): " << endl;
    cout << endl;

    stringTestV.push_back("car");
    stringTestV.push_back("apple");
    stringTestV.push_back("bar");
    stringTestV.push_back("house");
    stringTestV.push_back("movie");
    stringTestV.push_back("telescope");
    stringTestV.push_back("zoo");
    stringTestV.push_back("door");
    stringTestV.push_back("mouse");
    stringTestV.push_back("ancient");
    stringTestV.push_back("computer science");
    stringTestV.push_back("character");
    
    cout << "stringTestV before selection sort: " << endl;
    while (vectorindex < stringTestV.size())
    {
      cout << stringTestV.at(vectorindex) << ' ';
      ++vectorindex;
    }
    cout << endl;
    cout << endl;
    vectorindex = 0;

    selection_sort(stringTestV);
    cout << "stringTestV after selection sort: " << endl;
    while (vectorindex < stringTestV.size())
    {
      cout << stringTestV.at(vectorindex) << ' ';
      ++vectorindex;
    }
    cout << endl;
    cout << endl;
    vectorindex = 0;
    
  }
  catch (const out_of_range& excpt) 
  {
    cout << excpt.what() << endl;
  }


    return 0;
}

