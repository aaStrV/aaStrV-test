#include "test5.h"
using namespace std;

namespace test5
{
/**
 * Свертка дерева TreeNode при обходе слева
 */
void foldToVector(const TreeNode *t, acc_vv_t &acc0,
				  void f(acc_vv_t &acc, const TreeNode *t))
{
	stack<const TreeNode *> pathStack;

	if (t == nullptr)
	{
		return;
	}
	pathStack.push(t);
	int current_level = 1;
	int current_level_down = 0;
	while (true)
	{
		if (pathStack.size() == 0)
		{
			break;
		}
		const TreeNode *node = pathStack.top();
		f(acc0, node);
		pathStack.pop();
		if (node->right_child != nullptr)
		{
			pathStack.push(node->right_child);
		}
		if (node->left_child != nullptr)
		{
			pathStack.push(node->left_child);
		}
	}
}

bool hasOneChield(const TreeNode *t)
{
	bool left_null = ((t->left_child) == nullptr);
	bool right_null = ((t->right_child) == nullptr);

	if ((left_null && !right_null) | (!left_null && right_null))
	{
		return true;
	}
	return false;
}

bool hasTwoChildren(const TreeNode *t)
{
	bool left_null = ((t->left_child) == nullptr);
	bool right_null = ((t->right_child) == nullptr);

	if (!left_null && !right_null)
	{
		return true;
	}
	return false;
}

bool hasNoChildren(const TreeNode *t)
{
	bool left_null = ((t->left_child) == nullptr);
	bool right_null = ((t->right_child) == nullptr);

	if (left_null && right_null)
	{
		return true;
	}
	return false;
}

/**
 * Строит все пути
 */
void allPathesFinder(acc_vv_t &acc, const TreeNode *t)
{
	// init accumulator
	if (acc.empty())
	{
		acc.push_back(acc_v_t());
	}

	// get current path from accumulator
	acc_v_t cur_path;
	cur_path = acc[acc.size() - 1];

	// append this node to path
	cur_path.push_back(t);

	// current node is last in path? Save current
	// path, return to last fork
	if (hasNoChildren(t))
	{
		acc[acc.size() - 1] = (cur_path); // save this path
		while (true)
		{
			const TreeNode *save_back = cur_path[cur_path.size() - 1];
			cur_path.pop_back();
			if (cur_path.empty())
			{
				return;
			}
			if (hasTwoChildren(cur_path[cur_path.size() - 1]))
			{
				if ((cur_path[cur_path.size() - 1]->right_child) == save_back)
				{
					// this is last call of allPathFinder, all done
					return;
				}
				else
				{
					acc.push_back(cur_path); // now searching new path
				}
				break;
			}
		}
	}
	// save current path to acc and return
	acc[acc.size() - 1] = cur_path;
}

void printPathesLen(acc_vv_t &vv)
{
	cout << vv.size() << " pathes detected" << endl;
	for (int i = 0, len = vv.size(); i < len; ++i)
	{
		cout << "Path " << i << ", length: " << vv[i].size() << " nodes"
			 << endl;
	}
}

string getPath(acc_v_t &v)
{
	string path = "/";
	auto last = v.end() - 1;
	for (auto i = v.begin(); i < last; ++i)
	{
		if ((*i)->left_child == *(i + 1))
		{
			path += "left/";
		}
		else
		{
			path += "right/";
		}
	}
	return path;
}

void printPathes(acc_vv_t &vv)
{
	for (auto v : vv)
	{
		cout << getPath(v) << endl;
	}
}

void dropLessPathes(acc_vv_t &vv)
{
	// Get max len
	int max = 0;
	for (auto v : vv)
	{
		max = v.size() > max ? v.size() : max;
	}

	// Drop less elements
	auto pred = [&max](const acc_v_t &elem) -> bool {
		return (elem.size() < max) ? true : false;
	};
	acc_vv_t::iterator it = remove_if(vv.begin(), vv.end(), pred);
	vv.erase(it, vv.end());
}

TEST(allPathesFinderTest, zero)
{
	TreeNode n0(0);
	acc_vv_t vv;
	foldToVector(&n0, vv, allPathesFinder);
	ASSERT_TRUE(vv.size() == 1);
	ASSERT_TRUE(getPath(vv[0]) == "/");
}

TEST(allPathesFinder, onlyRoot)
{
	acc_vv_t vv;
	foldToVector(nullptr, vv, allPathesFinder);
	ASSERT_TRUE(vv.size() == 0);
}
} // namespace test5
