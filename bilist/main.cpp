#include <iostream>
#include "bilist.h"
#include <vector>
#include <ctime>

using namespace std;

int main() {
    bilist a;
    for (int y = 0; y < 1; y++) {

        for (int i = 0; i < 100; i++) {
            a.push_back(i);
        }
        //cout<<(NULL == 0);
        for (bilist::iterator it = a.begin(); it != a.end(); it++) {
            if (*it == 5) {
                a.insert(it, 99);
            }
        }
         /*for (bilist::iterator it = a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }*/
        //*a.end();
        //cout << "\n";
        srand((long long) time(NULL));
        vector<bilist::iterator> d;
        for (bilist::iterator it = a.begin(); it != a.end(); it++) {
            if (rand() % 2 == 0) {
                d.push_back(it);
            }
        }
        //printf("%d\n",d.size());
        for (int i = 0; i < d.size(); i++) {
            // cout<<*d[i]<<" ";
           // a.erase(d[i]);
        }
        // printf("\n");
        //a.erase(d[3]);
        /* for (int i = 0;i<10;i++){
        a.pop_front();
    }*/
        /* for (bilist::iterator it = a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }*/
        d.clear();
        a.clear();
    }
    return 0;
}