#include <iostream>
#include <vector>
#include <algorithm>
#include "debug_set.h"

using namespace std;

int main() {
    set s;
    vector<int> a;
    srand(NULL);
    for (int i = 0; i < 2000; i++) {
        //if (i!=7) {
        a.push_back(i);
        // }
    }
    random_shuffle(a.begin(), a.end());
    for (int i = 0; i < 2000; i++) {
        //if (i!=7) {
        s.insert(a[i]);
        // }
    }
    set b = s;
   /// s.erase(s.find(19));
    //cout<<s.size()<<" ";
    for (int i = 0; i < 1990; i++) {
        //if (i!=7) {
        //cout<<*s.find(a[i])<<" ";

         s.erase(s.find(a[i]));
        //printf("\n");
        /*for (set::iterator it = s.begin(); it != s.end(); it++) {
            cout << *it << " ";
            // cout.flush();
        }*/
        //cout<<s.size();
        //s.print();
      //  printf("\n");
        // }
    }
    printf("\n");
   // s.print();
   // printf("\n");
    //s.erase(s.find(a[17]));
    for (set::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
       // cout.flush();
    }
    printf("\n");
    for (set::iterator it = b.begin(); it != b.end(); it++) {
        cout << *it << " ";
        // cout.flush();
    }
    //s.print();set s;
    //s.print();
    return 0;
}