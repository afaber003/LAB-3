#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// I HAVE NO IDEA IF THIS IS RIGHT AT ALL
template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index){ //returns the index of the minimum value
    
    try {
        //exceptions
        if (index > vals.size() - 1){throw runtime_error("Too Big");}
        if (index < 1){throw runtime_error("Too Small");}

        // actual search
        unsigned smallesti = index;
        int smallest = vals[index];
        for (int i = index; i < vals.size(); i++){
            if (vals[i] < smallesti){
                smallest = i;
            }
        }
    }

    catch(runtime_error& error){
        cout << error.what() << endl;
    }

    return smallest;
}

template <typename T>
void selection_sort(vector<T> &vals){

}


int main() {



    



    return 0;
}