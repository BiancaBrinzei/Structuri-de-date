#include <vector>
#include <iostream>
using namespace std;

struct Edge {
    int x, y;
    Edge(int x, int y) {
        this->x = x;
        this->y = y;
    }
};
vector<int> ad[618]; // lista de adiacență

int find(Edge edge) {
    for (int j = 0; j < int(ad[edge.x].size()); j++)
        if (ad[edge.x][j] == edge.y)
            return j;
    return -1;
}

void remove(Edge edge) {
    for (int j = 0; j < int(ad[edge.x].size()); j++)
        if (ad[edge.x][j] == edge.y) {
            swap(ad[edge.x][j], ad[edge.x].back());
            ad[edge.x].pop_back();
            return;
        }
}

void insert(Edge edge) {
    ad[edge.x].push_back(edge.y);
}

void neighbors(int node) {
    for (int j = 0; j < int(ad[node].size()); j++)
        cout << ad[node][j] << ' ';
    cout << '\n';
}

int main() {
    insert(Edge(5, 1));
    insert(Edge(5, 2));
    insert(Edge(5, 4));

    insert(Edge(5, 3));
    remove(Edge(5, 3));

    cout << find(Edge(5, 2)) << '\n';
    cout << find(Edge(2, 5)) << '\n';

    neighbors(5);
    return 0;
}
