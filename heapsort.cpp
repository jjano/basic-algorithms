#include <iostream>
#include <algorithm>


using namespace std;

int parent(int i){
    return (i-1)/2;
}

int left(int i){
    return 2*(i+1)-1;
}

int right(int i){
    return 2*(i+1);
}

int heapheight(int length){
    int s=0;
    while(length){
            length/=2;
            s++;
    }
    return s;
}

void heapify (int t[], int i,int length){
    int l=left(i);
    int r=right(i);
    int largest;
    if (l<=length && t[l]>t[i])largest=l;
    else largest=i;
    if (r<=length && t[r]>t[largest])largest=r;
    if (largest!=i){
        swap (t[i],t[largest]);
        heapify(t, largest, length);
    }

}





void printheap(int t[], int length){
    int jump=2;
    cout<<t[0]<<endl;
    for(int i=1;i<length;i++){
        if(i+1>jump){
                cout<<t[i]<<endl;
                jump=jump*2+2;
        }
        else cout<<t[i]<<" ";

    }

}

void maxheap(int t[], int length){
    for(int i=(length-1)/2;i>=0;i--){
        heapify(t,i,length);
    }
}

void heapsort(int t[],int length){
    maxheap(t,length);
    for(int i=length-1;i>=1;i--){
        swap(t[0],t[i]);
        heapify(t,0,i-1);
    }


}



int main()
{
    int t[10]= {1 , 7, 8, 9, 6, 2, 4, 5, 3, 10};
    int length=10;
    heapsort(t,length);
    printheap(t,length);
}
