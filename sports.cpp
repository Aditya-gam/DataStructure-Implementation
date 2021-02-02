#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<string> sports;
    vector<string> name;
    vector<int> count;

    bool sameNameFound = false;
    int n, i;
    cin >> n;
    string nameString, sportString;

    while(n-->0){
        bool sameNameFound = false, sportNotFound = true;

        cin >> nameString >> sportString;
        for(i = 0; i < name.size(); i++){
            if(nameString == name[i]){
                sameNameFound = true;
                break;
            }
        }

        if(!sameNameFound){
            for(i = 0; i < sports.size(); i++){
                if(sportString == sports[i]){
                    count[i]++;
                    break;
                }
            }
            if(i == sports.size()){
                name.push_back(nameString);
                sports.push_back(sportString);
                count.push_back(1);
            }
        }
    }
    int maxCount = count[0], footballCount, maxCountIndex = 0; 

    if("football" == sports[0]){
        footballCount = count[0];
    }

    for(i=1; i<sports.size(); i++){
        if("football" == sports[i]){
            footballCount = count[i];
        }

        if(count[i] > maxCount){
            maxCount = count[i];
            maxCountIndex = i;
        }
    }

    cout << sports[maxCountIndex] << endl << footballCount ;
}