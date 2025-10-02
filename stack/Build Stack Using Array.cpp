class myStack {
  public:
    vector<int>stack;
    int N;
  
    myStack(int n) : N(n){
        // Define Data Structures
    }

    bool isEmpty() {
        return stack.size() == 0;
    }

    bool isFull() {
        return stack.size() == N;
    }

    void push(int x) {
        if(stack.size() == N) {
            return;
        }
        
        stack.push_back(x);
    }

    void pop() {
        if(stack.size() == 0){
            return;
        }
        
        stack.pop_back();
    }

    int peek() {
        if(stack.size() == 0) {
            return -1;
        }
        
        return stack.back();
    }
};