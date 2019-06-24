#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class stack{
int i,ele,top,len,m[400000],maxele;
//vector<int> s(400000);
public:
stack(){top=-1;maxele=-99999;}

bool isempty()
{
    if(top==-1)
    {
        return true;
    }
    return false;
}

void push(int x){
    top++;
    if(isempty())
    {
        m[top] = x;
        maxele = x;
    }
    else
    {
        if(x<=maxele)
        {
            m[top] = x;
        }
        else
        {
            m[top] = 2*x - maxele;
            maxele = x;
        }
    }
    
}
void pop(){
    int y = m[top--];
    if(y>maxele)
    {
        maxele = 2*maxele - y;
    }
}
int max()
{
    return maxele;
}

};
int main(){
    stack s;

    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            s.push(stoi(value));
        }
        else if (query == "pop") {
            s.pop();
        }
        else if (query == "max") {
            cout << s.max() << "\n";
        }
        else {
            return 0;
        }
    }

    return 0;
}