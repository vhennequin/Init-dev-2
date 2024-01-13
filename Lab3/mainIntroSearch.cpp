#include <iostream>
#include <iostream>
#include <vector>

using namespace std;

/// ============== Prototypes and constants
const int STOP = 999;

/// display: displays vector content followed by indices
void display(const vector<int> & v);

/// binarySearch: returns an index at which val is stored in vector v, or -1 if val is not in v
int binarySearch(const vector<int> & v, int val);

/// binarySearchMin: returns the smallest index at which val is in vector v, or -1 if val is not in v
int binarySearchMin (const vector<int> & v, int val);

/// ============== Main program

int main()
{
    vector<int> v1 = {0,1,2,2,2,5,7,7,7,9};
    int val; /// the value that the user wants to search for
    int ind; /// the index returned by the search function

    cout << "Content of the vector : " << endl;
    display(v1);

    cout << "\nWhat value are you looking for? (" << STOP << " to finish)" << endl;
    cin >> val;

    while (val!=STOP)
    {
        cout << "Result of binary search: " << endl;
        ind = binarySearch(v1, val);
        if (ind != -1)
            cout << val << " is in the vector at index " << ind << endl;
        else
            cout << val << " is not in the vector." << endl;

        cout << "Result of binary search min : " << endl;
        ind = binarySearchMin(v1, val);
        if (ind != -1)
            cout << "The first occurrence of " << val << " is at index "<< ind << endl;
        else
            cout << val << " is not in the vector." << endl;

        cout << "\nWhat value are you looking for?" << endl;
        cin >> val;
    }

    return 0;
}

/// ============== Subprogram definitions

/// display: displays vector content followed by indices
void display(const vector<int> & v)
{
    cout << "values : ";
    for (int i=0 ; i<v.size() ; i++)
        cout << v[i] << " " ;
    cout << endl;
    cout << "indices: ";
    for (int i=0 ; i<v.size() ; i++)
        cout << i << " " ;
    cout << endl;
}

/// binarySearch: returns an index at which val is stored in vector v, or -1 if val is not in v
int binarySearch(const vector<int> & v, int val)
{
    int start, finish, middle;
    start = 0;
    finish = v.size()-1;
    int ind = -1;
    while (ind == -1 && start <= finish){
        middle = (start + finish)/2;
        if (v[middle] == val) ind = middle;
        else{
            if (v[middle] > val) finish = middle-1;
            else start = middle+1;
        }
    }
    return (ind);
}

/// binarySearchMin: returns the smallest index at which val is in vector v, or -1 if val is not in v
int binarySearchMin (const vector<int> & v, int val)
{
    int start, finish, middle;
    start = 0;
    finish = v.size()-1;
    int ind = -1;
    while (ind == -1 && start <= finish){
        middle = (start + finish)/2;
        if (v[middle] == val){
            if (v[middle-1] == val){
                finish = middle-1;
            }
            else ind = middle;
        }
        else{
            if (v[middle] > val) finish = middle-1;
            else start = middle+1;
        }
    }
    return (ind);
}
