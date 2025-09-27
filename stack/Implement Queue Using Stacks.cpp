class MyQueue {
public:
    stack<int>input;
    stack<int>output;

    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        int front = output.top();
        output.pop();

        return front;
    }
    
    int peek() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};