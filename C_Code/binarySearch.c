#include<stdio.h>

 void sortarr(int arr[],int size){
        for(int i =0; i<size; i++){
            for(int j = i+1; j<size; j++){
                if(arr[i] > arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
        }
    }

        printf("\n Print array \n");
        for(int i =0; i<size; i++){
            printf("%d, ",arr[i]);
        }
        printf("\n");
}

int binarSearch(int arr[],int size, int key){
    sortarr(arr,size);
    int start = 0;
    int end = size-1;
   
    while (start<=end)
    {
        int mid = start + (end -start)/2;

        if(arr[mid] == key) return mid;
        else if(arr[mid] > key){
            end = mid -1;
        }else{
            start = mid + 1;
        }
    }
    
    return -1;
    
}

   
int main(){
    int arr[] ={17,15,10,7,0,1,-5,11,2,16};
    int key = 10;
    int size = sizeof(arr) / sizeof(arr[0]);


    int res = binarSearch(arr,size,key);

    if(res == -1){
        printf("Key not present in array");
    }else{
        printf("Key present at %d pos ( value is %d)",res+1,key);
    }
    
    return 0;
}