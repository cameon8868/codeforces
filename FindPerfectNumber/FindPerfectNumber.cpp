#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
 
using namespace std;
 
int findPerfectNumLeftDelete(vector<int>* v){
    int count = 0;
 
    while(true){
 
        if(v->size() <= 1){
            return count;
        }
        int s_sum = accumulate(v->begin(), v->end(), 0);
        if(find(v->begin(), v->end(), s_sum) != v->end()){
            return count;
        } else {
            v->erase(v->begin());
            count++;
        }
    }
}
 
int findPerfectNumRightDelete(vector<int>* v){
    int count = 0;
 
    while(true){
 
        if(v->size() <= 1){
            return count;
        }
        int s_sum = accumulate(v->begin(), v->end(), 0);
        if(find(v->begin(), v->end(), s_sum) != v->end()){
            return count;
        } else {
            v->erase(v->end()-1);
            count++;
        }
    }
}
 
 
int main() {
    int n;
    cin >> n;
 
    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        vector<int> v;
 
        if(-100<=l && l<=100 && -100<=r && r<=100){
            for(int j=l;j<=r;j++){
                v.push_back(j);
            }
        }
 
        vector<int> v_copy = v;
 
        int s = accumulate(v.begin(), v.end(), 0);
 
        if(find(v.begin(), v.end(), s) != v.end()){
            cout << 0 << endl;
        } else {
            v_copy = v;
            cout << min(findPerfectNumLeftDelete(&v), findPerfectNumRightDelete(&v_copy)) << endl;
        }
    }
    return 0;
}