#include <iostream>
using namespace std;

void QuickSort(int arr[],int left,int right){
    int l = left;
    int r = right;
    int pivot = arr[ (l + r)  / 2];//选用中间值作为基准
    //while循环使当前选定中值（基准）的左边都比它小，右边都比它大
    while (l < r){
        //在pivot的左边找一个比它大的
        //如果没有找到，说明此时pivot的左边都比它小
        //而且此时l == pivot对应的数组下标，后面要处理一下，避免死循环
        while( arr[l] < pivot ){
            l++;
        }
        //在pivot的右边找一个比它小的，同上
        while( arr[r] > pivot ){
            r--;
        }
        //这里就是前面说的处理，满足条件说明pivot左边都比它小，右边都比它大
        //那就不用进行下面的操作了呗，直接跳出循环
        //判读条件写==也行，你开心就好
        if(l >= r){
            break;
        }
        //如果上面没有退出循环，这里接着就要交换一大一小的两个值
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        //如果交换完发现arr[l] == pivot，就将 r-- ,相当于前移
        //因为这里有种情况要考虑，比如数组中有三个这样的数字： 0 0 0
        //运行到 l 是左边的 0 ，r 是右边的0，pivot是中间的
        //下一次循环时 l r pivot都不会改变，l == pivot == r
        //又开始交换，又进入下一次循环，又开始交换。。。死循环
        if(arr[l] == pivot){
            r--;
        }
        //同上
        if(arr[r] == pivot){
            l++;
        }
    }
    //上面的循环保证了此时的pivot的左边都是比它小的，右边都是比它大的
    //接下来可以开始准备递归，但是递归前还要加个判断
    //看到break的条件，发现此时有可能 l == r
    //，如果相等就必须将l和r错开，否则，会报栈溢出的错误
    //因为最后的最后，全部排好序了
    // l = r 其实最后就是left = right
    //没有这个判读，直接不停地递归
    //一下子就StackOverflowError
    if(l == r){
        l++;
        r--;
    }
    //向左递归
    //就是递归的意思。。。都不用想，边界肯定是这样的
    //要想弄懂递归，首先要弄懂递归
    //先向左向右都行，你开心就好
    //如果注释掉向左递归，那么中值右边的就都是有序的，左边的就不一定了
    if( left < r){
        QuickSort(arr,left,r);
    }
    //向右递归，同上
    if ( right > l){
        QuickSort(arr,l,right);
    }
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    QuickSort(arr,0,n-1);
    for (int j = 0; j < n; ++j) {
        cout << arr[j] << " ";
    }
    cout << endl;
    return 0;
}
