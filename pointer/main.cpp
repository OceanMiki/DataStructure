#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef struct ElemType{
    int key = -999;
    bool flag = false;//当前位置是否被占用
    int cnt = 1;//比较次数
}DATA,*PDATA;

int hashSet(PDATA d,int key){
    int mod = key % 11;
    int cnt = 1;
    while (d[mod].flag){
        mod++;
        cnt++;
    }
    d[mod].key = key;
    d[mod].flag = true;
    d[mod].cnt = cnt;
    return mod;
}

int main() {
    int n,m;
    cin >> n >>m;
    map<int,int> map;
    set<int> set;
    auto keys = new DATA[n];

    while (m--){
        int key;
        cin >> key;
        if (set.count(key)){
            cout << keys[map[key]].cnt << endl;
        } else{
            set.insert(key);
            map[key] = hashSet(keys,key);
            cout << "NO" << endl;
        }
    }

    return 0;
}