#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class myHeap{
    public:
        myHeap() {
            hp.push_back(0); // number of elements in the heap
        }
    
        void sink(int idx) {
            while (2*idx <= hp[0]) {
                int j = 2*idx; // left child
                // exchange with its smaller child 
                if (j < hp[0] && hp[j+1] < hp[j]) ++j;
                // if current node lesser than its smaller child, no need to sink
                if (hp[idx] < hp[j]) break;
                swap(hp[j],hp[idx]);
                idx = j;
            }
        }
        
        void swim(int idx) {
            // root is at idx 1
            while (idx > 1 &&  hp[idx] < hp[idx/2]) {
                swap(hp[idx/2],hp[idx]);
                idx /= 2;
            }
        }
            
        void push(int val) {
            hp.push_back(val);
            ++hp[0];
            int idx = hp[0];
            swim(idx);
           // cout << hp[1] << endl;
           // cout << "Pushing: "<<val << endl;
        }
        
        void remove(int val) {
            int idx = 1;
            for (; idx <= hp[0]; ++idx) {
                if (hp[idx] == val) break;
            }
            if (idx > hp[0]) return;
            swap(hp[idx], hp[hp[0]]);
            hp.resize(--hp[0]);
            sink(idx);
            
           // cout << "HP size: "<< hp.size() << ", HP[1]" << hp[1] << endl;
        }
    
        int getTop() {
            if (hp[0]) return hp[1];
            else return -1;
        }
    
    private:
        vector<int> hp;
};


int main() {
    int n;
    cin >> n;
    myHeap h;
    while (n--) {
        int cmd, val;
        cin >> cmd;
        if (cmd == 3) 
            cout << h.getTop() << endl;
        else if (cmd == 1) {
            cin >> val;
            h.push(val);
        }
        else if (cmd == 2) {
            cin >> val;
            h.remove(val);
        }
        
    }
    return 0;
}
