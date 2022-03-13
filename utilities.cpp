#include "utilities.h"

using namespace std;
/*
int binarySearch(const vector<int>& node, int left, int right, int v) {
    if (left <= right) {
        int mid = (left+right)/2;
        if (node[mid] == v) return mid;
        else if (v < node[mid]) return binarySearch(node,left,mid - 1,v);
        else return binarySearch(node,mid + 1,right,v);
    }
    return -1;
}
*/
int binarySearch(const vector<int>& node, int left, int right, int v) {
    bool trobat = false;
    int i = 0, size = node.size();
    while (!trobat && i < size) {
        trobat = node[i] == v;
        ++i;
    }

    if (trobat) return i - 1;
    else return -1;
}