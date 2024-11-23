#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int c;
    cin >> c;
    set<int> stickers;
    for(int i = 0; i < c; i++){
        int sticker;
        cin >> sticker;
        stickers.insert(sticker);
    }
    int b;
    cin >> b;
    set<int> boughtBag;
    for(int i = 0; i < b; i++){
        int sticker;
        cin >> sticker;
        boughtBag.insert(sticker);
    }


    for(int sticker : stickers){
        boughtBag.erase(sticker);
    }

    cout << boughtBag.size() << endl;
    auto it = boughtBag.begin();
    for(int i = 0; i < boughtBag.size(); i++){
        cout << *it++;
        if(i != boughtBag.size() - 1) {
            cout << ' '; continue;
        } else
            cout << endl; break;
    }

}