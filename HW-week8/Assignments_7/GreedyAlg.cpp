#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct artifact{
    int weight;
    int value;
    float realValue;

    artifact(int w, int v, float rV) {
        weight = w;
        value = v;
        realValue = rV;
    }
};

vector<artifact> stolen;
vector<artifact> arti_stolen;
ifstream input;
int maxWeight;
int totalVal = 0;
int n;

void inputVal() {
    input.open("input.txt");
    if(input.is_open())
    {
        input >> maxWeight >> n;
        for(int i = 0; i < n; i++) {
            int w, v;
            input >> w >> v;
            float rV = ((float)v)/w;
            artifact s(w, v, rV);
            stolen.push_back(s);
        }
    }
}

bool cmp(artifact a, artifact b) {
    return a.realValue > b.realValue;
}

void greedy() {
    sort(stolen.begin(), stolen.end(), cmp);
    for(artifact s : stolen) {
        int tmp = maxWeight;
        tmp -= s.weight;
        if(tmp >= 0) {
            totalVal += s.value;
            maxWeight = tmp;
            arti_stolen.push_back(s);
        }
    }
    for(artifact s : arti_stolen) {
        cout << s.weight << " " << s.value << endl;
    }
    cout << totalVal;
}

int main() {
    inputVal();
    greedy();
}
