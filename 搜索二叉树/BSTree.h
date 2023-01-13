#pragma once
#include<assert.h>
#include<queue>

namespace sht
{

	template<class T>
	struct BSTreeNode
	{
		BSTreeNode(const T& x)
			:val(x)
			,left(nullptr)
			,right(nullptr)
		{

		}

		

		T val;
		BSTreeNode* left;
		BSTreeNode* right;
	};



	template<class T>
	class BSTree
	{
		
		typedef BSTreeNode<T> Node;
		
	public:
		BSTree()
			:root(nullptr)
		{
			
		}

		bool insert(const T& x)
		{
			if (root == nullptr)
			{
				root = new Node(x);
				return true;
			}

			Node* cur = root;
			Node* prev = nullptr;

			while (cur)
			{
				if (x > cur->val)
				{
					prev = cur;
					cur = cur->right;
				}
				else if (x < cur->val)
				{
					prev = cur;
					cur = cur->left;
				}
				else
					return false;

			}

			Node* p = new Node(x);

			if (x > prev->val)
				prev->right = p;
			else
				prev->left = p;

		}

		Node* find(const T& x)
		{
			Node* cur = root;
			while (cur)
			{
				if (x > cur->val)
					cur = cur->right;
				else if (x < cur->val)
					cur = cur->left;
				else
					return cur;
			}
			return nullptr;
			
		}


		Node* getroot()
		{
			return root;
		}

		void erase(const T& x)
		{
			
			Node* cur = root;
			Node* prev = nullptr;
			

			while (cur)
			{
				if (x > cur->val)
				{
					prev = cur;
					cur = cur->right;
				}
				else if (x < cur->val)
				{
					prev = cur;
					cur = cur->left;
				}
				else
					break;
			}
			assert(cur != nullptr);
			if (cur->left == nullptr && cur->right == nullptr)
				prev = nullptr;
			else if (cur->left == nullptr || cur->right == nullptr)
			{
				if (cur->left == nullptr)
				{
					if (prev->left == cur)
						prev->left = cur->right;
					else
						prev->right = cur->right;
				}
				else
				{
					if (prev->left == cur)
						prev->left = cur->left;
					else
						prev->right = cur->left;
				}
			}
			else  //找左子树的最大节点 或 找右子树的最小节点
			{
				Node* son = cur->right;
				Node* father = nullptr;

				while (son->left)
				{
					father = son;
					son = son->left;
				}

				cur->val = son->val;

				if (father == nullptr)
					cur->right = son->right;
				else if (father->left == cur)
					father->left = cur->right;
				else 
					father->right = cur->right;
				son->~BSTreeNode();
			}



		}


		



	private:
		BSTreeNode<T>* root;
	};

	template<class T>
	void levelorder(BSTreeNode<T>* root)
	{
		std::queue<BSTreeNode<T>*> a;
		a.push(root);

		while (!a.empty())
		{
			BSTreeNode<T>* p = a.front();
			if (p->left != nullptr)
				a.push(p->left);
			if (p->right != nullptr)
				a.push(p->right);
			a.pop();
			std::cout << p->val << " ";
		}
	}


	
}