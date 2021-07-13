#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Point
{
	int x, y;
public:
	Point(){}
	Point(int _x, int _y) : x(_x), y(_y) {}
	int get_x() { return x; }
	int get_y() { return y; }
};

// 1. 对p、q中顶点"(x, y)" 升序排序并输出(要求按照x大小，若x相等则按y的大小)
void Fun1(vector<Point>& points1, vector<Point>& points2)
{
	sort(points1.begin(), points1.end(), [](Point& point1, Point& point2) {return point1.get_x() < point2.get_x() || (point1.get_x() == point2.get_x() && point1.get_y() < point2.get_y()); });
	for_each(points1.begin(), points1.end(), [](Point& point) {cout << "(" << point.get_x() << ", " << point.get_y() << ")" << endl; });
	sort(points2.begin(), points2.end(), [](Point& point1, Point& point2) {return point1.get_x() < point2.get_x() || (point1.get_x() == point2.get_x() && point1.get_y() < point2.get_y()); });
	for_each(points2.begin(), points2.end(), [](Point& point) {cout << "(" << point.get_x() << ", " << point.get_y() << ")" << endl; });
}

// 2. 升序输出p中满足x > 0, y > 0的所有顶点与(0, 0)的距离的平方
void Fun2(vector<Point>points)
{
	vector<Point>now_points(points.size());
	auto it1 = copy_if(points.begin(), points.end(), now_points.begin(), [](Point& point) {return point.get_x() > 0 && point.get_y() > 0; });
	now_points.resize(distance(now_points.begin(), it1));
	vector<int>dist_points(now_points.size());
	auto it2 = transform(now_points.begin(), now_points.end(), dist_points.begin(), [](Point& point) {return point.get_x() * point.get_x() + point.get_y() * point.get_y(); });
	dist_points.resize(distance(dist_points.begin(), it2));
	sort(dist_points.begin(), dist_points.end());
	for_each(dist_points.begin(), dist_points.end(), [](int x) {cout << x << endl; });
}

// 3. 根据1排序后p中顶点的顺序计算满足x > 0, y > 0相邻两个顶点的距离的平方和
int Fun3(vector<Point>points)
{
	vector<Point>now_points(points.size());
	auto it1 = copy_if(points.begin(), points.end(), now_points.begin(), [](Point& point) {return point.get_x() > 0 && point.get_y() > 0; });
	now_points.resize(distance(now_points.begin(), it1));
	vector<int>dist_points(points.size() - 1);
	auto it2 = transform(now_points.begin(), now_points.end() - 1, now_points.begin() + 1, dist_points.begin(), [](Point& point1, Point& point2) {return (point1.get_x() - point2.get_x()) * (point1.get_x() - point2.get_x()) + (point1.get_y() - point2.get_y()) * (point1.get_y() - point2.get_y()); });
	dist_points.resize(distance(dist_points.begin(), it2));
	return accumulate(dist_points.begin(), dist_points.end(), 0);
}

// 4. 计算p中x > 0, y > 0的顶点与(0, 0)的距离的平方和
int Fun4(vector<Point>points)
{
	vector<Point>now_points(points.size());
	auto it = copy_if(points.begin(), points.end(), now_points.begin(), [](Point& point) {return point.get_x() > 0 && point.get_y() > 0; });
	now_points.resize(distance(now_points.begin(), it));
	return accumulate(now_points.begin(), now_points.end(), 0, [](int partial, Point& point) {return partial + point.get_x() * point.get_x() + point.get_y() * point.get_y(); });
}

// 5. p、q在每个象限顶点数目相同，统计在1排序后p、q中满足x < 0, y < 0的顶点中按顺序所对应顶点距离的平方为2的数目
int Fun5(vector<Point>points1, vector<Point>points2)
{
	vector<Point>now_points1(points1.size());
	auto it1 = copy_if(points1.begin(), points1.end(), now_points1.begin(), [](Point& point) {return point.get_x() > 0 && point.get_y() > 0; });
	now_points1.resize(distance(now_points1.begin(), it1));
	vector<Point>now_points2(points2.size());
	auto it2 = copy_if(points2.begin(), points2.end(), now_points2.begin(), [](Point& point) {return point.get_x() > 0 && point.get_y() > 0; });
	now_points2.resize(distance(now_points2.begin(), it2));
	vector<int>now_points(points1.size());
	auto it = transform(points1.begin(), points1.end(), points2.begin(), now_points.begin(), [](Point& point1, Point& point2) {return (point1.get_x() - point2.get_x()) * (point1.get_x() - point2.get_x()) + (point1.get_y() - point2.get_y()) * (point1.get_y() - point2.get_y()); });
	now_points.resize(distance(now_points.begin(), it));
	return accumulate(now_points.begin(), now_points.end(), 0, [](int partial, int point) {return partial + point == 2; });
}

int main()
{
	vector<Point> p, q;
	p.push_back(Point(-1, -1));
	p.push_back(Point(2, 2));
	q.push_back(Point(1, 1));
	q.push_back(Point(-2, -2));

	vector<Point>p_copy, q_copy;
	p_copy = p, q_copy = q;

	Fun1(p_copy, q_copy);
	Fun2(p);
	cout << Fun3(p_copy) << endl;
	cout << Fun4(p) << endl;
	cout << Fun5(p_copy, q_copy) << endl;

	return 0;
}
