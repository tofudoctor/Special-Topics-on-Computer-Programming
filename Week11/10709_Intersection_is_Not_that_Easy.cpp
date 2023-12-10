#include<bits/stdc++.h>

using namespace std;

typedef struct vec{
    double x, y;
}vec;

typedef struct point{
    double x, y;
    vec operator-(const point &a){
        vec res;
        res.x = x - a.x;
        res.y = y - a.y;
        return res;
    }
}point;

typedef struct line{
    point p1, p2;
    vec v;
}line;

typedef struct segment{
    point p1, p2;
    vec v;
}seg;

double eps = 2e5;
double a, b, c, d, e, f, g, h;
string s_1, s_2;

int sign(double x){
    if(abs(x) < eps) return 0;
    if(x < 0) return -1;
    return 1;
}

double dot(vec a, vec b){
    return a.x * b.x + a.y * b.y;
}

double cross(vec a, vec b){
    return a.x * b.x + a.y * b.y;
}

double get_length(vec v){
    return sqrt(dot(v, v));
}

double point_dis_line(point p, line l){
    vec v = p - l.p1;
    return abs(cross(l.v, v) / get_length(l.v));
}

double point_dis_segment(point p, seg s){
    vec v1 = p - s.p1, v2 = p - s.p2;
    if (sign(dot(s.v, v1)) < 0) return get_length(v1);
    if (sign(dot(s.v, v2)) > 0) return get_length(v2);
    return abs(cross(s.v, v1) / get_length(s.v));
}

bool segment_intersection(seg a, seg b){
    if(sign(cross(a.v, b.v)) == 0){
        if(sign(point_dis_segment(a.p1, b)) == 0 || sign(point_dis_segment(a.p2, b)) == 0 || sign(point_dis_segment(b.p1, a)) == 0 || sign(point_dis_segment(b.p2, a)) == 0) return true;
        return false;
    }
    return true;
}

bool line_intersection(line a, line b){
    if(sign(cross(a.v, b.v)) == 0){
        if(sign(point_dis_line(a.p1, b)) == 0) return true;
        return false;
    }
    return true;
}

bool line_segment_intersection(seg a, line b){
    if(sign(cross(a.v, b.v)) == 0){
        if(sign(point_dis_line(a.p1, b) == 0)) return true;
        return false;
    }
    else{
        vec u = a.p1 - b.p1;
        double t = cross(b.v, u) / cross(a.v, b.v);
        double len = get_length(a.v);
        point interpoint = {a.p1.x + len * t, a.p1.y + len * t};

        if(sign(point_dis_segment(interpoint, a)) == 0) return 0;
        return min({point_dis_line(a.p1, b), point_dis_line(a.p2, b)});
    }
}

double line_dis_line(line a, line b){
    if(!line_intersection(a, b)) return 0;
    return point_dis_line(a.p1, b);
}

double segment_dis_segment(seg a, seg b){
    if(!segment_intersection(a, b)) return 0;
    return min({point_dis_segment(a.p1, b), point_dis_segment(a.p2, b), point_dis_segment(b.p1, a), point_dis_segment(b.p2, a)});
}

double segment_dis_line(seg a, line b){
    if(!line_segment_intersection(a, b)) return 0;
    return min({point_dis_line(a.p1, b), point_dis_line(a.p2, b)});
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> a >> b >> c >> d >> s_1){
        cin >> e >> f >> g >> h >> s_2;
        if(s_1 == "END" && s_2 == "END") break;

        line l1, l2;
        seg s1, s2;
        if(s_1 == "L") l1 = {{a, b}, {c, d}, {c - a, d - b}};
        else s1 = {{a, b}, {c, d}, {c - a, d - b}};
        if(s_2 == "L") l2 = {{e, f}, {g, h}, {g - e, h - f}};
        else s2 = {{e, f}, {g, h}, {g - e, h - f}};

        // cout << line_dis_line(l1, l2) << "\n";

        if(s_1 == "L" && s_2 == "L") cout << fixed << setprecision(5) << line_dis_line(l1, l2) << "\n";
        else if(s_1 == "LS" && s_2 == "LS") cout << fixed << setprecision(5) << segment_dis_segment(s1, s2) << "\n";
        else if(s_1 == "LS" && s_2 == "L") cout << fixed << setprecision(5) << segment_dis_line(s1, l2) << "\n";
        else cout << fixed << setprecision(5) << segment_dis_line(s2, l1) << "\n";
    }

    return 0;
}