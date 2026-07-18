class BrowserHistory {
    class Node {
    public:
        string data;
        Node* next;
        Node* back;

        Node(string x) {
            data = x;
            next = nullptr;
            back = nullptr;
        }
    };

    Node* curr;

public:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    void visit(string url) {
        Node* node = new Node(url);
        curr->next = node;
        node->back = curr;
        curr = node;
    }

    string back(int steps) {
        while (steps && curr->back) {
            curr = curr->back;
            steps--;
        }
        return curr->data;
    }

    string forward(int steps) {
        while (steps && curr->next) {
            curr = curr->next;
            steps--;
        }
        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
