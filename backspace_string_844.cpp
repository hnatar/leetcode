class Solution {
public:
    void insert_into_stack(string str, stack<char> &Stack) {
        // builds a version of the string without 
        // backspace ('#') using a stack S
        for(auto &c: str) {
            if( c=='#' ) {
                if( !Stack.empty() )
                    Stack.pop();
            }
            else Stack.push(c);
        }
    }

    void rebuild_string(stack<char> Stack, string &str) {
        while( !Stack.empty() ) {
            str += Stack.top();
            Stack.pop();
        }
    }

    bool backspaceCompare(string S, string T) {
        // convert the strings into no-backspace form
        // should be O( len(S) + len(T) )
        stack<char> stack_s, stack_t;
        insert_into_stack(S, stack_s);
        insert_into_stack(T, stack_t);

        // the stacks hold the strings in reverse order
        // and cannot be iterated over, so build new strings.
        // should be O( len(S) + len(T) ). Can just use the
        // stacks but this seems easier mentally.

        string mod_s, mod_t; // modified
        rebuild_string(stack_s, mod_s);
        rebuild_string(stack_t, mod_t);

        return mod_s == mod_t;
    }
};