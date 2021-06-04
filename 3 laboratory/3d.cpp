#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PriorityQueue{
private:

    vector<int> array;
    int size = 0;

    void siftUp(int i){
        if ((i > 0) && (array[i] < array[(i - 1) / 2])) {
            swap(array[i], array[(i - 1) / 2]);
            siftUp((i - 1) / 2);
        }
    }

    void siftDown(int i){
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;
        if ((l < size) && (array[i] > array[l]))
            largest = l;
        if ((r < size) && (array[largest] > array[r]))
            largest = r;
        if (largest != i){
            swap(array[i], array[largest]);
            siftDown(largest);
        }
    }

    int findKey(int key) {
        for (int i = 0; i < size; i++) {
            if (array[i] == key)
                return i;
        }
        return -1;
    }

public:
    PriorityQueue(){
        array.resize(1000000);
    }

    void push(int key) {
        array[size] = key;
        siftUp(size++);
    }

    int extractMin(){
        if (size > 0) {
            int value = array[0];
            array[0] = array[--size];
            siftDown(0);
            return value;
        }
        else
            return -1000000001;
    }

    void decreaseKey(int key, int newNumber){
        int index = findKey(key);
        array[index] = newNumber;
        siftUp(index);
    }

};

int main() {
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);

    PriorityQueue priorit;

    vector<int> key(1000000);

    string cmd;
    int x, y;
    int count = 0;
    while (!cin.eof()) {
        cmd = "";
        cin >> cmd;
        if (cmd == "push") {
            cin >> x;
            priorit.push(x);
            key[count] = x;
        }
        else if (cmd == "extract-min") {
            int min = priorit.extractMin();
            if (min > -1000000001)
                cout << min << endl;
            else
                cout << '*' << endl;
        }
        else if (cmd == "decrease-key") {
            cin >> x >> y;
            priorit.decreaseKey(key[x - 1], y);
            key[x - 1] = y;
        }
        count++;
    }
    return 0;
}