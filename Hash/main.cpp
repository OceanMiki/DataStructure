#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef struct ElemType{
    int key;
    bool flag;//当前位置是否被占用
    int cnt = 1;//比较次数
}DATA,*PDATA;

int main() {
    int n,m;
    cin >> n >>m;
    map<int,int> map;
    set<int> set;
    auto keys = new DATA[n];

    while (m--){
        int key,index;
        cin >> key;
        if (set.count(key)){
            cout << keys[map[key]].cnt << endl;
        } else{
            set.insert(key);
            int mod = key % 11;
            int cnt = 1;
            while (keys[mod].flag){
                mod++;
                cnt++;
            }
            keys[mod].flag = true;
            keys[mod].key = key;
            keys[mod].cnt = cnt;
            index = mod;
            map[key] = index;
            cout << "NO" << endl;
        }
    }

    return 0;
}
