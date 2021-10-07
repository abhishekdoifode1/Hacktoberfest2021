#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
vector<int> mergedArray;
priority_queue<int, vector<int>, greater<int>> minHeap;
for (int i = 0; i < input.size(); i++) {
for (int j = 0; j < input[i]->size(); j++) {
minHeap.push(input[i]->at(j));
}
}
while (!minHeap.empty()) {
mergedArray.push_back(minHeap.top());
minHeap.pop();
}
return mergedArray;
}

int main() {
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}
