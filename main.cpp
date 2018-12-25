// RadixSort time complexity O(n)

#include <iostream>
#include <list>

using namespace std;
void radixsort(list<unsigned int>& s);
void display(list<unsigned int> s);
int findmax(list<unsigned int> s);

int main() {

    list<unsigned int> original;

    original.push_front(6);
    original.push_front(5);
    original.push_front(23);
    original.push_front(9);
    original.push_front(10);
    original.push_front(8);
    original.push_front(12);
    original.push_front(7);
    original.push_front(11);
    original.push_back(21);

    cout << "Original : ";
    display(original);
    
    radixsort(original);

    cout << "After RadixSort: ";
    display(original);

}

void radixsort(list<unsigned int>& s) {
    list<unsigned int> list0; 
    list<unsigned int> list1; 
	
	// Find maximum number to know number of digits
    int max = findmax(s);     
    int const fixedSize = s.size()-1;

    const int MAX_ITERATIONS = sizeof(s)*8;  
	
	// We use the divisor to sort by ten's digit, hundred's digit, etc
    int divisor = 1;

    for(int i = 0; i < MAX_ITERATIONS; ++i) { 
        for (int i = 0; i <= fixedSize; ++i) { 
            if ((s.front() / divisor) % 2 == 0) { //
                list0.push_back(s.front()); 
            } else {
                list1.push_back(s.front()); 
            }
            s.pop_front(); 
        }

        s.splice(s.begin(), list1); 
        s.splice(s.begin(), list0); 
        divisor = 2 * divisor;      
        if(divisor >= max){          
            return;
        }

    }
}


void display(list <unsigned int> s) {
    if(s.size() == 0){
        cout << "List empty";
    }
    else {
        for (list<unsigned int>::iterator it = s.begin(); it != s.end(); ++it) {
            cout << ' ' << *it;
        }
    }
    cout << endl;
}


int findmax(list<unsigned int> t){
    int max = 0;
    list<unsigned int>::const_iterator current = t.begin();
    int high = *current++;

    while(current != t.end()){
        if (*current > high){
            high = *current;
        }
        ++current;
    }
    return high;
}

