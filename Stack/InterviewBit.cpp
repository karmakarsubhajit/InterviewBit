// https://www.interviewbit.com/problems/min-stack/
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor.
*/
// Time complexity::- O(n)

vector<pair<int,int>> v;
MinStack::MinStack() 
{
     while(!v.empty()){
        v.pop_back();
    }
}

void MinStack::push(int x) {
    if(v.empty())
    {
        v.push_back(make_pair(x,x));
    }
    else
    {
        int mnEle = v[v.size()-1].second;
        if(x<mnEle)
            mnEle = x;
        v.push_back(make_pair(x,mnEle));
    }
}

void MinStack::pop() 
{
    if(!v.empty())
        v.pop_back();
}

int MinStack::top() 
{
    if(!v.empty())
    {
        pair<int,int> tmp = v[v.size()-1];
        
        return tmp.first;
    }
    else
    {
        return -1;
    }
}

int MinStack::getMin() 
{
    if(!v.empty())
    {
        pair<int,int> tmp = v[v.size()-1];
        
        return tmp.second;
    }
    else
    {
        return -1;
    }
}

