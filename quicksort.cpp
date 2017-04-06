
#include <iostream>
#include <algorithm>
using namespace std;


void quicksort(int t[],int l,int r){
    int middle=(l+r)/2;
    int i=l;
    int j=r;
    while(i<=j){
        while(t[i]<t[middle])i++;
        while(t[j]>t[middle])j--;
        if(i<=j){
            swap(t[i],t[j]);
            i++;
            j--;
        }
    }
    if(l<j)quicksort(t,l,j);
    if(i<r)quicksort(t,i,r);
}

void printtab(int t[],int length){
    for (int i=0;i<length;i++)cout<<t[i]<<",";
}

int main()
{
    int length=10;
    int tab[10]={3,10,1,2,9,8,4,6,7,5};
    printtab(tab,length);
    cout<<endl;
    quicksort(tab,0,9);
    printtab(tab,length);

}
