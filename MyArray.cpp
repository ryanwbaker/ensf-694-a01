/*
 *  MyArray.cpp
 *  ENSF 694 Lab 1 Exercise F
 *  Completed by: Ryan Baker
 *  Development Date: July 2, 2024
 */

#include "MyArray.h"

int search(const MyArray* myArray, int obj){
// Students are supposed to complete the implementation of the this function
    for(int i = 0; i < myArray->list_size; i++){
        if(myArray->array[i] == obj){
            return i;
        }
    }
    return -1;
}

void initialize(MyArray* myArray) {
    // Students are supposed to complete the implementation of the this function
    myArray->list_size = 0;
}

int retrieve_at(MyArray* myArray, int pos){
    // Students are supposed to complete the implementation of the this function
    return myArray->array[pos];
}

int count(MyArray* myArray, int obj ){
    // Students are supposed to complete the implementation of the this function
    int count = 0; 
    for(int i = 0; i < myArray->list_size; i++){
        if(myArray->array[i] == obj) count++;
    }
    return count;
}

void append( MyArray* myArray, int array[], int n ) {
    // Students are supposed to complete the implementation of the this function
    if((myArray->list_size + n) <= (int)(sizeof(myArray->array)/sizeof(int))){
        for(int i = 0; i < n; i++){
            myArray->array[myArray->list_size] = array[i];
            myArray->list_size++;
        }
    }
}

void insert_at(MyArray* myArray, int pos, int val) {
    // Students are supposed to complete the implementation of the this function
    myArray->list_size++;
    for(int i = myArray->list_size - 1; i > pos; i--){
        myArray->array[i] = myArray->array[i-1];
    }
    myArray->array[pos] = val;
}

int remove_at(MyArray* myArray, int pos ) {
    // Students are supposed to complete the implementation of the this function
    int val = myArray->array[pos];
    for(int i = pos; i < myArray->list_size; i++){
        myArray->array[i] = myArray->array[i+1];
    }
    myArray->list_size--;
    return val;
}

int remove_all(MyArray* myArray, int value ) {
    // Students are supposed to complete the implementation of the this function
    int count = 0;
    for(int i = 0; i < myArray->list_size; i++){
        if(myArray->array[i] == value){
            remove_at(myArray, i);
            count++;
        }
    }
    return count;
}

// You can modify this function however you want:  it will not be tested
void display_all(MyArray* myArray) {
    // Students are supposed to complete the implementation of the this function
    for(int i = 0; i < myArray->list_size; i++){
        cout << myArray->array[i] << " ";
    }
    cout << endl;
}

bool is_full(MyArray* myArray){
    // Students are supposed to complete the implementation of the this function
    return ((sizeof(myArray->array) / sizeof(int)) == myArray->list_size);
}

bool isEmpty(MyArray* myArray){
    // Students are supposed to complete the implementation of the this function
    return myArray->list_size == 0;
}

int size(MyArray* myArray){
    // Students are supposed to complete the implementation of the this function
    return myArray->list_size;
}
