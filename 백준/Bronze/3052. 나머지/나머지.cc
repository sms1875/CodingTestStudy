#include<iostream>
using namespace std;


int main (){
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


    int tmp,res=0; 
    int list[10]={};
    for(int i=0;i<10;i++){
        cin>>tmp;
        list[i]=tmp%42;
    }
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if(list[i]==list[j]){
                res++;
                list[j]=-j;
            }
        }
    }
    
    cout<<10-res;
    return 0;
}
