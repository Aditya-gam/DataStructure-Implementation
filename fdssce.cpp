#include<iostream>
#include<vector>

using namespace std;

int maxJars(vector<int> j,int k){
    int max = 0, smax = 0,count = 0, maxJar = 0;

    for(int i = 0; i < j.size(); i++){
        if(j[i]<max&&j[i]<smax){
            count++;
        }
        else{
            if(j[i]>smax){
                if(j[i]<=max){
                    smax = j[i];
                }
                else if(j[i]>max){
                    smax = max;
                    max = j[i];
                }
            }

            // if(j[i]<=max&&j[i]>=smax){
            //     smax = j[i];
            // }
            if(i>=1){
                if((max+smax)<=k){
                    count++;
                }
                else{
                    if(maxJar<count){
                        maxJar = count;
                    }
                    count = 0;
                    max = 0;
                    smax = 0;
                    i--;
                    // continue;                    
                }
            }
            else{
                count++;
                continue;
            }
        }
    }
    if(maxJar<count){
        maxJar = count;
    }
    return maxJar;
}

int main(){
    int t, n, k;
    cin >> t;
    while(t-->0){
        cin >> n >> k;
    }
    vector<int> jars(n);
    for(int i = 0; i < n; i++){
        cin >> jars[i];
    }
    cout << maxJars(jars, k);
}