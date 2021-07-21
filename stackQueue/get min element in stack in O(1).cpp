/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/
int _stack :: getMin()
{
    if(s.empty()) return -1;
    return minEle;
   //Your code here
}

/*returns poped element from stack*/
int _stack ::pop()
{
    int x;
    if(s.empty()) return -1;
    if(s.top() < minEle){
        x = minEle;
        minEle = 2*x - s.top();
    }
    else x = s.top();
    s.pop();
    return x;
   //Your code here
}

/*push element x into the stack*/
void _stack::push(int x)
{
    if(s.empty()){
        s.push(x);
        minEle = x;
    }else if(x>=minEle){
        s.push(x);
    }
    else{
        s.push(2*x - minEle);
        minEle = x;
    }
   //Your code here
}
