#ifndef TEST5_H_
#define TEST5_H_

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <gtest.h>

namespace test5
{
struct TreeNode
{
	struct TreeNode *left_child;
	struct TreeNode *right_child;
	int id;

	TreeNode(int id, TreeNode *left, TreeNode *right) : id(id), left_child(left), right_child(right)
	{
	}
	explicit TreeNode(int id) : TreeNode(id, nullptr, nullptr)
	{
	}
};

using acc_vv_t = std::vector<std::vector<const TreeNode *>>;
using acc_v_t = std::vector<const TreeNode *>;

bool hasOneChield(const TreeNode *t);
bool hasTwoChildren(const TreeNode *t);
bool hasNoChildren(const TreeNode *t);
void foldToVector(const TreeNode *t, acc_vv_t &acc0,
				  void f(acc_vv_t &acc, const TreeNode *t));
void allPathesFinder(acc_vv_t &acc, const TreeNode *t);
void printPathesLen(acc_vv_t &vv);
std::string getPath(acc_v_t &v);
void printPathes(acc_vv_t &vv);
void dropLessPathes(acc_vv_t &vv);
} // namespace test5

#endif /* TEST5_H_ */
