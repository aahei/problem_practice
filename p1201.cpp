#include <iostream>
#include <map>
#include <vector>

using namespace std;

int np;

void addMoney(string name, int money, vector<pair<string,int> > & people){
    for(int j = 0; j < np; j++){
        if(people[j].first == name){
            people[j].second += money; //can't % by 0
            // cout << people[j].second << " ";
            break;
        }
    }
}

int main(){
    cin >> np;
    vector<pair<string,int> > people(np);
    for(int i = 0; i < np; i++){
        cin >> people[i].first;
    }
    for(int i = 0; i < np; i++){
        string name; //for initialization define more than one variable
        int money;
        int ngi;
        cin >> name;
        cin >> money;
        cin >> ngi;
        if(ngi){
            int avg = money / ngi;
            addMoney(name, (-avg) * ngi, people);
            for(int j = 0; j < ngi; j++){
                string giveTo;
                cin >> giveTo;
                addMoney(giveTo, avg, people);
            }
        }
        else //when give to nobody
            addMoney(name, -money, people);
    }

    for(int i = 0; i < np; i++){
        cout << people[i].first << " " << people[i].second << endl;
    }
    return 0;
}
