/*
Simplify Path
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

"/home/foo/../bar"	"/bar"	"/home/bar"
"/home/foo/./.././bar"	"/home/foo/bar"	"/home/bar"

*/


#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
		string p;

		//remove duplicate slash
		int slash = 0;
		for (int i = 0; i < path.size(); i++) {
			if (!slash || path[i] != '/')
				p += path[i];

			slash = (path[i] == '/');
		}

		//remove '/.'

		if (p[p.size()-1] != '/')
			p += '/';

		while (1) {
			int dot = p.find("/./");
			if (dot == -1) {
				break;
			}

			if (dot + 2 < p.size()) {
				p = p.substr(0, dot) + p.substr(dot + 2);
			} else {
				p = p.substr(0, dot);
			}
		}

		// resolve "/.."
		while (1) {
			int dotdot = p.find("/..");
			if (dotdot == -1) {
				break;
			}

			int end = dotdot - 1;
			end = max(0, end);
			while (end > 0) {
				if (p[end] == '/') {
					break;
				}
				end--;
			}

			if (dotdot + 3 < p.size())
				p = p.substr(0, end) + p.substr(dotdot + 3);
			else
				p = p.substr(0, end);
		}

		if (p.size() == 0)
			return "/";

		if (p.size() > 1 && p[p.size()-1] == '/')
			return p.substr(0, p.size() - 1);

		return p;
    }
};

int main(int argc, char *argv[])
{
	Solution c;
	cout << c.simplifyPath("/home/foo/../bar") << endl;
	return 0;
}
