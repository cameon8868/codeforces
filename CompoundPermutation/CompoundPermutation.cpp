#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    if(!(1 <= t && t<= 100)){
        return 0;
    }

    for(int tc=0;tc<t;tc++){
        int n;
        vector<int> p;

        cin >> n;

        if(!(1 <= n && n <= 100)){
            return 0;
        }
                
        if(n<4){
            cout << -1 << endl;
        }
        else{
            p.push_back(4);

            for(int i = 2; i<=n;i++){
                if(i == 4){
                    p.push_back(1);
                }
                else{
                    p.push_back(i);
                }
            }
            
            for(int num : p){
                cout << num << " ";
            }
            cout << endl;
        }

        
    }
    return 0;
}