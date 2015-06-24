int *a = nullptr;
int volatile *b = nullptr;
int *volatile c = nullptr;
int volatile *volatile d = nullptr;
int main() {
    a = a;
   // a = b;
    a = c;
    //a = d;
    b = a;
    b = b;
    b = c;
    b = d;
    c = a;
   // c = b;
    c = c;
   // c = d;
    d = a;
    d = b;
    d = c;
    d = d;
    return 0;
}
