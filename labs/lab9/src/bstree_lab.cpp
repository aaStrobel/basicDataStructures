/*Lab 9: Binary search trees
 *Description: this lab utilizes various functions to find the height, depth, balance, etc. of  binary search trees
 *Coded by Austin Strobel
 *Last edited on 11/9/2022
 */

/*Spoke with Blake (and Anika) during office hours about the recursive height function
 *Briefly spoke with Robert from Pellissippi
 */

#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include "bstree.hpp"
using namespace std;
using CS140::BSTree;
using CS140::BSTNode;

/* Node
   class BSTNode {
   public:
   BSTNode *left;
   BSTNode *right;
   BSTNode *parent;
   std::string key;
   void *val;
   };
   */

/* BSTree class
   class BSTree {
   public:

   BSTree();
   BSTree(const BSTree &t);
   BSTree& operator= (const BSTree &t);
   ~BSTree();

   void Clear();                                      // Turns the tree into an empty tree.

   bool Insert(const std::string &key, void *val);    // Insert the key and val.  Returns success (duplicates are not allowed.
   void *Find(const std::string &key) const;          // Return the val associated with the key.  Returns NULL if key not found.
   bool Delete(const std::string &key);               // Delete the node with the key.  Returns whether there was such a node.

   void Print() const;                                // These are obvious.
   size_t Size() const;
   bool Empty() const;

   std::vector <std::string> Ordered_Keys() const;    // Return a vector of sorted keys
   std::vector <void *> Ordered_Vals() const;         // Return a vector of the vals, sorted by the keys.

   int Depth(const std::string &key) const;		   // Distance from a node to the root.  Returns -1 if the key is not in the tree.
   int Height() const;                                // Returns the depth of the node with maximum depth, plus one.

   protected:
   BSTNode *sentinel;                                 // Like the dlists, there is a sentinel.  Its right points to the root.
   size_t size;                                       // Size of the tree

   void recursive_inorder_print(int level, const BSTNode *n) const;          // A helper for Print()
   void recursive_destroy(BSTNode *n);                                       // A helper for Clear()
   void make_val_vector(const BSTNode *n, std::vector<void *> &v) const;     // A helper for Ordered_Vals()

   int recursive_find_height(const BSTNode *n) const;                        // A helper for Height()
   void make_key_vector(const BSTNode *n, std::vector<std::string> &v) const; // A helper for Ordered_Keys()
   BSTNode *make_balanced_tree(const std::vector<std::string> &sorted_keys,   // A helper for the copy constructor and assignment overload.
   const std::vector<void *> &vals,
   size_t first_index,
   size_t num_indices) const;
   };
   */

/* ---------------------------------------------- */
/* You'll write all of these as part of your lab. */

// Distance from a node to the root.  Returns -1 if the key is not in the tree.
int BSTree::Depth(const string &key) const
{
	//	(void) key;
	BSTNode *n;
	int count = 0;

	n = sentinel->right;
	//the root node is the right child of the sentinel node
	while (1){
		if (n == sentinel) return -1;
		if (key == n->key) return count;
		//n = (key < n->key) ? n->left : n->right;
		if (key < n->key){
			n = n->left;
			count++;
		} else { //if the left doesn't work, go to the right
			n = n-> right;
			count++;
		}
	}

	return count;
}

// Returns the depth of the node with maximum depth, plus one       
int BSTree::Height() const
{
	//use recursive helper function
	return recursive_find_height(sentinel->right);
}

// Return a vector of sorted keys
vector <string> BSTree::Ordered_Keys() const
{
	vector <string> rv;
	make_key_vector(sentinel->right, rv); //call helper function
	return rv;
}

//copy constructor
BSTree::BSTree(const BSTree &t)        
{
	//allocate new sentinel
	sentinel = new BSTNode;
	sentinel->left = NULL;
	sentinel->right = sentinel;
	sentinel->parent = NULL;
	sentinel->key = "---SENTINEL---";
	sentinel->val = NULL;

	size = 0; //reset size

	*this = t; //set object (uses assignment overload)
}

//assignment overload
BSTree& BSTree::operator= (const BSTree &t) 
{
	Clear(); //clear tree

	//create new balanced tree
	make_balanced_tree(t.Ordered_Keys(), t.Ordered_Vals(), 0, t.size);

	size = t.size; //set size

	return *this;
}

//recursive helper function to find greatest depth
int BSTree::recursive_find_height(const BSTNode *n) const
{
	//	(void) n;
	int leftHeight, rightHeight, maxHeight;
//	n = sentinel->right;
	if (n == sentinel) return 0;
	
	rightHeight = (recursive_find_height(n->right) + 1);
	//if you can't recursively go to the right in one recursion call, the function will try to go left instead in the next recursive call
	leftHeight = (recursive_find_height(n->left) + 1);

	if (leftHeight > rightHeight) maxHeight = leftHeight;
	//comparing heights to find the larger one
	else maxHeight = rightHeight;

	return maxHeight;
}

//recursive helper function to create ordered key vector
void BSTree::make_key_vector(const BSTNode *n, vector<string> &v) const
{
	if (n == sentinel){
		return;
	} else {
		make_key_vector(n->left, v);
		v.push_back(n->key);
		make_key_vector(n->right, v);
	}
	
	//base case: if n is sentinel

	//else, recursively call make_key_vector for left and right nodes.
	//	also, add smallest node before right side recursive call
}

//recursive helper function to create balanced tree in assignment overload.
//	post-order traversal (children traversed before parents)
BSTNode *BSTree::make_balanced_tree(const vector<string> &sorted_keys, 
		const vector<void *> &vals,
		size_t first_index,
		size_t num_indices) const
{
	//new node for left and right child
	BSTNode *node, *leftNode, *rightNode;

	node = new BSTNode;
	
	leftNode = sentinel;
	rightNode = sentinel;

	size_t middleNode = first_index + (num_indices/2);
	int flexMid = (num_indices/2) - !(num_indices % 2); //!(num_indices % 2) could be 1 or 0 depending on if the number of indices is even or odd
	//got some of this syntax from the TAs

	if (num_indices > 1){
		leftNode = make_balanced_tree(sorted_keys, vals, first_index, num_indices/2);
		//recursively go left 
		if (flexMid > 0){
			rightNode = make_balanced_tree(sorted_keys, vals, middleNode + 1, flexMid);
		}
	}
	//got some help from the TAs on the logic of these lines

	node->left = leftNode;
	node->right = rightNode;
	node->parent = sentinel;
	node->key = sorted_keys[middleNode];
	node->val = vals[middleNode];
	//setting left, right, parent, key, and val to the node's left, node's right, node's parent, sorted_keys vector at the middle node, and the vals vector at the middle node

	if (leftNode != sentinel){
		leftNode->parent = node;
	}
	if (rightNode != sentinel){
		rightNode->parent = node;
	}

	if (num_indices == sorted_keys.size()){
		sentinel->right = node;
	}
	//"if we are in the first call" from Clara's notes

	return node;

}
