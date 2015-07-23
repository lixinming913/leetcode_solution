/*  Implement Stack using Queues
 *  Implement the following operations of a stack using queues.
 *  push(x) -- Push element x onto stack.
 *  pop() -- Removes the element on top of the stack.
 *  top() -- Get the top element.
 *  empty() -- Return whether the stack is empty.
 */


class Stack {
public:
    deque<int> Q;
    // Push element x onto stack.
    void push(int x) {
        Q.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        Q.pop_back();
    }

    // Get the top element.
    int top() {
        if(!Q.empty())
            return Q.back();
        return -1;
    }

    // Return whether the stack is empty.
    bool empty() {
        return Q.empty();
            
    }
};