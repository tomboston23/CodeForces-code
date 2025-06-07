#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

struct pt {
    int x;
    int y;
};

int gcd(int a,int b){
    if (b==0) return a;
    return gcd(b, a%b);
}

vector<int> std_form(pt first, pt second){
    int x1 = first.x;
    int y1 = first.y;
    int x2 = second.x;
    int y2 = second.y;
    vector<int> v(3);
    if (x1 == x2) {
        v[0] = 1;
        v[1] = 0;
        v[2] = x1;
    } else if (y1 == y2){
        v[0] = 0;
        v[1] = 1;
        v[2] = y1;
    } else {
        v[0] = y2-y1;
        v[1] = x1-x2;
        v[2] = v[0]*x1+v[1]*y1;
        int g = gcd(v[0], gcd(v[1], v[2]));
        v[0]/=g;
        v[1]/=g;
        v[2]/=g;
    }
    return v;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, A, B;
    cin >> n >> A >> B;
    vector<pt> problems;
    set<ii> used;
    for (int i = 0; i < n; i++){
        pt p;
        cin >> p.x >> p.y;
        if (used.find(make_pair(p.x,p.y)) != used.end()){
            continue;
        } else{
            used.insert(make_pair(p.x,p.y));
            problems.push_back(p);
        }
    }

    pt start;
    pt end;
    start.x = 0; start.y = 0;
    end.x = A; end.y = B;

    vector<int> sol_line = std_form(start, end);
    cout << sol_line[0] <<"x + " << sol_line[1] << "y = " << sol_line[2] << endl;

    if (problems.size() == 2){
        vector<int> std = std_form(problems[0], problems[1]);
        cout << std[0] <<"x + " << std[1] << "y = " << std[2] << endl;

        double det = sol_line[0]*std[1] - sol_line[1]*std[0];
        double x = (double)(sol_line[2] * std[1] - std[2] * sol_line[1]) / det;
        double y = (double)(sol_line[0] * std[2] - std[0] * sol_line[2]) / det;
        cout << "intersection: (" << x << ", " << y << ")" << endl;
        pair<double, double> choice;
        if (x > problems[0].x && x > problems[1].x){
            pt c = problems[0].x > problems[1].x ? problems[0] : problems[1];
            choice.first = c.x;
            choice.second = c.y;
        } else if (x < problems[0].x && x < problems[1].x){
            pt c = problems[0].x < problems[1].x ? problems[0] : problems[1];
            choice.first = c.x;
            choice.second = c.y;
        } else {
            choice.first = x;
            choice.second = y;
        }

        double len = max((double)(A / choice.first), (double)(B / choice.second));
        cout << "len: " << len << endl;
    }

    return 0;
}


/*
Each point within the convex hull is a linear combination of other points
 - sum of coefficients is equal to 1
 - all coefficients are non-negative




*/