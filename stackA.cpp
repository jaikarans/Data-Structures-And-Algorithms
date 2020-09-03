#include <iostream>
/**
 * This is program to make a Stack
 * Using Array data strecture.
 */

/** User will enter the function name in input to interect
 * with program.
 *  Like pop(), push(134), printStack() and exit for exiting loop.
 * */

using namespace std;

class Stack{
    public :
    int static const size=10;
    int stac[size]={0};
    int pop();
    int top();
    void push(int);
    void printStack();

};

//Top element of stack that is empty
int Stack::top(){
    for(int i=0; i<size; i++){
        if(stac[i]==0){
            return i;
        }
    }
    return size-1;
}

// For pushing value of function
void Stack::push(int a){
    if(top()>size-1)
        cout << "Stack overflow";
    else{
        stac[top()]=a;
        cout << "\n" << a << " appended in Stack \n\n";
    }
}

// For poping outer most element of stack
int Stack::pop(){
    if(top()>0 && top()<=size-1){
        int temp = stac[top()-1];
        stac[top()-1]=0;            // after pop making index 0
        cout << "\n" << temp << "\n\n";
        return temp;
    }
    else{
        cout << "StackUnderFlow\n\n";
        return 0;
    }     
}

// Printing the whole stack
void Stack::printStack(){
    if(top()>0){
        for(int i=0; i<top(); i++){
            cout << stac[i] << "\t";
        }
        cout << endl;
    }
    else 
        cout << "\nStack is empty\n\n";
}

/** 
 * making function for exterecting number from string push(number);
 * user input string.
 * from 5th charcter to string.length()-2
 * 
 * 
*/
int baseTen(int a){
    int base=1;
    int i=1;
    while(a>1 && i<a){
        base*=10;
        i++;
    }
    return base;
}
int extrectNum(string s){
    int num=0;
    for(int i=5; i<s.length()-1; i++){
        num+=((s[i]-48)*baseTen(s.length()-1-i)); //stringDigit*10BaseOfNum-48 because ancii code of 0 is 48
    }
    return num;
}


int main(void){
    printf("\n********************************************************************\n");
    printf("input function for stack such as pop(),push(anyNumber),printStack()");
    printf("\nAnd for exit program Enter exit");
    printf("anything other than these inputs will cause wrong output.");
    printf("\n********************************************************************\n");
    Stack stack;
    string choice="top()";
    while(choice!="exit"){
        if(choice=="pop()")
            stack.pop();
        else if(choice=="top()")
            stack.top();
        else if(choice=="printStack()")
            stack.printStack();
        else 
            stack.push(extrectNum(choice)); //exterecting number from choice string
            
        cin >> choice;
    }
    
}
