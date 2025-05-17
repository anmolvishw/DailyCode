#include<stdio.h>

int linearSearch(int arr[],int size,int key){
    for(int i =0; i<size; i++)
        if(key == arr[i]) return i;
    
        return -1;
}

int main(){
    int arr[] ={17,15,10,7,0,1,-5,11,2,16};
    int key = 0;
    int size = sizeof(arr) / sizeof(arr[0]);


    int res = linearSearch(arr,size,key);

    if(res == -1){
        printf("Key not present in array");
    }else{
        printf("Key present at %d pos ( value is %d)",res+1,key);
    }
    return 0;
}