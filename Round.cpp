#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int quan(vector< vector<char> > v, char c) {
//	int outsize = (int)v.size(), insize = v[0].size();
//	int count{};
//	for (int j = insize - 1; j > -1; --j)
//		for (int i = 0; i < outsize; ++i)
//			if (v[i][j] == c)
//				++count;
//	return count;
//}

void show_place(vector< vector<char> > v) {
	int outsize = (int)v.size(), insize = v[0].size();
	string s{};
	for (int j = insize - 1; j > -1; --j) {
		for (int i = 0; i < outsize; ++i)
			s += v[i][j];
		s += "||\n";
	}
	for (int i = 0; i < outsize + 2; ++i)
		s += '=';
	cout << s << endl;
}

double length(int x1, int y1, int x2, int y2) {
	return abs(sqrt(pow(double(x1) - x2, 2) + pow(double(y1) - y2, 2)));
}

vector< vector<char> > make_round(vector< vector<char> > v, char center, int radius, int x, int y, int orad) {
	int outsize = (int)v.size(), insize = v[0].size();
	for (int j = insize - 1; j > -1; --j)
		for (int i = 0; i < outsize; ++i) {
			int dist = int(length(x, y, i, j));
			if ((dist <= radius) && (dist > orad))
				v[i][j] = center;
		}
	return v;
}

int main() {
	vector< vector<char> > v(50, vector<char>(50, ' '));
	string command{};
	while (true) {
		show_place(v);
		cout << "> ";
		cin >> command;
		if (command == "draw") {
			int outsize = (int)v.size(), insize = v[0].size();
			if ((outsize > 0) && (insize > 0)) {
				int radius{}, x{}, y{}, orad{};
				char fone{};
				cin >> radius >> orad >> x >> y >> fone;
				v = make_round(v, fone, radius, x, y, orad);
				cout << "Round was made)\n";
			}
			else
				cout << "Size of matrix too small to make a round!!";
		}
		else if (command == "clear_matrix") {
			for (int i = 0; i < (int)v.size(); ++i)
				for (int j = 0; j < v[0].size(); ++j)
					v[i][j] = ' ';
		}
		else if (command == "resize") {
			int x, y;
			cin >> x >> y;
			v.resize(x, vector<char>(y));
			for (int i = 0; i < (int)v.size(); ++i)
				v[i].resize(y);
		}
		system("cls");
	}
	/*vector< vector<char> > v(50, vector<char>(50, ' '));
	show_place(v);
	v = make_round(v, '#', 10, 24, 24);
	show_place(v);*/
}