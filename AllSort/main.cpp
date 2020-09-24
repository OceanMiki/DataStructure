#include <iostream>

using namespace std;

//直接插入：左边有序，右边无序，从右边取数依次插入有序中
void InsertSort(int List[], int len) {
    for (int i = 1; i < len; ++i) {
        if (List[i - 1] > List[i]) {
            int temp = List[i];//此temp可在数组中留出List[0]作为哨兵
            //有序数组后移
            int j = i;
            for (; j > 0 && List[j - 1] > temp; --j) { List[j] = List[j - 1]; }
            List[j] = temp;
        }
        cout << i << " : " << endl;
        for (int k = 0; k < len; ++k) {
            cout << List[k] << " ";
        }
        cout << endl;
    }
}

//希尔排序，定步长距离d，List[i]和List[i+d]进行大小交换
//步长选择都是从n/2开始，每次再减半，直到最后为1。其实也可以有另外的更高效的步长选择
void shellsort1(int a[], int n)
{
    int i, j, gap;

    for (gap = n / 2; gap > 0; gap /= 2) { //步长
        for (i = 0; i < gap; i++) {       //直接插入排序
            for (j = i + gap; j < n; j += gap)
                if (a[j] < a[j - gap]) {
                    int temp = a[j];
                    int k = j - gap;
                    while (k >= 0 && a[k] > temp) {
                        a[k + gap] = a[k];
                        k -= gap;
                    }
                    a[k + gap] = temp;
                }
        }
        cout << gap << " : " << endl;
        for (int l = 0; l < n; ++l) {
            cout << a[l] << " ";
        }
        cout << endl;
    }
}

//快速排序(递归)：选取第一个数为轴心点
int Partition(int List[],int low,int high){
    int pivotkey=List[low];
    while(low!=high){
        //先从右边开始找
        while(low<high&&List[high]>=pivotkey) --high;
        List[low]=List[high];
        while(low<high&&List[low]<=pivotkey)  ++low;
        List[high]=List[low];
    }
    List[low]=pivotkey;
    return low;
}
//low为0，high为len-1
void QuickSort(int List[],int low,int high){
    if(low<high){
        int pivot=Partition(List,low,high);
        QuickSort(List,low,pivot-1);
        QuickSort(List,pivot+1,high);
        for (int k = 0; k < 10; ++k) {
            cout << List[k] << " ";
        }
        cout << endl;
    }
}

//堆排序：将欲排数组构建成完全二叉树，从n/2开始调整堆(逻辑存储是二叉树，物理存储是顺序表)
void AdjustHeap(int List[],int i,int len){
    //i节点的左右孩子是2*i+1，2*i+2
    int temp=List[i];
    int j=2*i+1;
    while(j<len){
        //j为左右子节点中最大的位置
        if(j+1<len&&List[j+1]>List[j])  j++;
        if(List[j]<=temp) break;
        List[i]=List[j];
        //下一层要检查比较
        i=j;
        j=2*i+1;
    }
    List[i]=temp;
}

//一次调整，能得到最大的
void MakeMaxHeap(int List[],int len){
    for(int i=len/2-1;i>=0;i--){
        AdjustHeap(List,i,len);
    }
}

//建大顶堆的话，每一次建堆，会选出最大的，和最后面的对换，再只要调整头，则能得到第二大的，再和倒数的对换，能得到一个递增的数组
void HeapSort(int List[],int len){
    for(int i=len/2-1;i>=0;i--){
        AdjustHeap(List,i,len);
    }
    for(int j=len-1;j>0;j--){
        swap(List[0],List[j]);
        AdjustHeap(List,0,j);
        for (int i = 0; i < 10; ++i) {
            cout << List[i] << " ";
        }
        cout << endl;
    }
}

//归并算法
//将有二个有序数列a[first...mid]和a[mid...last]合并。
void mergearray(int a[], int first, int mid, int last, int temp[]){
    int i = first, j = mid + 1;
    int m = mid,   n = last;
    int k = 0;

    while (i <= m && j <= n){
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)   temp[k++] = a[i++];
    while (j <= n)   temp[k++] = a[j++];
    for (i = 0; i < k; i++)  a[first + i] = temp[i];
}

void mergesort(int a[], int first, int last, int temp[]){
    if (first < last){
        int mid = (first + last) / 2;
        mergesort(a, first, mid, temp);    //左边有序
        mergesort(a, mid + 1, last, temp); //右边有序
        mergearray(a, first, mid, last, temp); //再将二个有序数列合并
        for (int i = 0; i < 10; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

bool MergeSort(int a[], int n){
    int *p = new int[n];
    mergesort(a, 0, n - 1, p);
    delete[] p;
    return true;

}

int i,j,k;

void Select_Sort(int a[],int n)
{   //对排序表R[1].....R[n]进行冒泡排法，n是记录个数
    for(i=1; i<n; i++)  /*做n-1趟选取*/
    {
        k=i;    /*在i开始的n-i+1个记录中选关键码最小的记录*/
        for(j=i+1;j<=n;j++)
            if(a[j]<a[k])
                k=j;    /*k中存放关键码最小记录的下标*/
        if(i!=k)    /*关键码最小的记录与第i个记录交换*/
        {
            int temp;
            temp=a[k];
            a[k]=a[i];
            a[i]=temp;
        }
        for (int l = 0; l < 10; ++l) {
            cout << a[l] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {503, 87, 512, 61, 908, 170, 897, 275, 653, 426};
//    InsertSort(arr, 10);
//    shellsort1(arr,10);
//    QuickSort(arr,0,9);
//    HeapSort(arr,10);
//    mergesort(arr,0,9,new int[10]);
    Select_Sort(arr,10);
    return 0;
}
