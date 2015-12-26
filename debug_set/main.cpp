#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include "set.h"
using namespace std;

int main() {
    set s;
    vector<int> a;
    srand(NULL);
    for (int i=0;i<2000;i++){
        //if (i!=7) {
            a.push_back(i);
       // }
    }
  // random_shuffle(a.begin(), a.end());
    for (int i=0;i<2000;i++){
        //if (i!=7) {
        s.insert(a[i]);
        // }
    }
    for (int i=0;i<1900;i++){
        //if (i!=7) {
      // cout<< a[i]<<" ";
        s.erase(s.find(a[i]));
        // }
    }

    //s.insert(7);s
    //cout<<a[51]<<"\n";
    //set::iterator it1 = s.find(a[51]);
    //cout<<(it1.it->l== nullptr)<<(it1.it->r== nullptr)<<(it1.it->p== nullptr);
    //it1++;
    //cout<<*it1;
    //it1++;
    /*for (int i=0;i<1;i++){
        s.erase(s.find(i));
    }*/
    //s.erase(it1);
   // s.clear();
    //cout<<"\n"<<s.find(580)<<"\n";
   for (set::iterator it = s.begin();it!=s.end();it++){
        printf("%d ", *it);
    }
   //s.print();
    return 0;
}