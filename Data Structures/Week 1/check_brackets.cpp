#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket()
    {

    }

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> st;
    Bracket br;
    for (int i = 0; i < text.length(); ++i) {
        char next = text[i];

        if (next == '(' || next == '[' || next == '{') {
            br.position = i;
            br.type = next;
            st.push(br);
        }

        
        if (next == ')' || next == ']' || next == '}') {
            if(!st.empty()){
            if(next == ')')
            {
                if(st.top().type == '(')
                {
                    st.pop();
                }
                else
                {
                std::cout<<i+1;
                return 0;
                }
            }
            else if(next == ']')
            {
                if(st.top().type == '[')
                {
                    st.pop();
                }
                else
                {
                std::cout<<i+1;
                return 0;
                }
            }
            if(next == '}')
            {
                if(st.top().type == '{')
                {
                    st.pop();
                }
                else
                {
                std::cout<<i+1;
                return 0;
                }
            }
            }
            else
            {
            std::cout<<i+1;
            return 0;
            }
        }
        
    }

    if(st.empty())
    {
        std::cout<<"Success";
    }
    else
    {
        std::cout<<st.top().position+1;
    }
    

    return 0;
}
