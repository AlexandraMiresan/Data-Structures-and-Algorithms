#include "Matrix.h"
#include <exception>
#include <queue>
#include <utility>
using namespace std;

// Time complexity: Θ(1)
Matrix::Matrix(int nrLines, int nrCols) {
	this->nrOfLines = nrLines;
	this->nrOfCols = nrCols;
	root = nullptr;
}

// Time complexity: Θ(1)
int Matrix::nrLines() const {
	return this->nrOfLines;
}

// Time complexity: Θ(1)
int Matrix::nrColumns() const {
	return this->nrOfCols;
}

// Best case: Θ(1)
// Worst case: Θ(n)
// Total case: O(n)
TElem Matrix::element(int i, int j) const {
	if(i >= this->nrOfLines || j >= this->nrOfCols || i < 0 || j < 0) {
		throw exception();
	}

	Node* current = root;

	while(current!=nullptr) {
		if(i == current->line && j == current->col) {
			return current->elem;
		}
		else if(i >current->line || (i == current->line && j > current->col)) {
			current = current->right;
		}else {
			current = current->left;
		}
	}
	return NULL_TELEM;
}


// Best case: Θ(1)
// Worst case: Θ(n)
// Total case: O(n)
TElem Matrix::modify(int i, int j, TElem e) {
	if(i >= this->nrOfLines || j >= this->nrOfCols || i < 0 || j < 0) {
		throw exception();
	}

	Node* parent = nullptr;
	Node* current = root;

	while(current!=nullptr) {
		if(i == current->line && j == current->col) {
			TElem old =  current->elem;
			current->elem = e;
			return old;
		}
		parent = current;
		if(i > current->line || (i == current->line && j > current->col)) {
			current = current->right;
		}else {
			current = current->left;
		}
	}

	if(e != NULL_TELEM) {
		Node* newNode = new Node{i, j, e, nullptr,nullptr};
		if(root == nullptr) {
			root = newNode;
		}
		else {
			if(i > parent->line || (i == parent->line && j > parent->col)) {
				parent->right = newNode;
			}
			else {
				parent->left = newNode;
			}
		}

	}
	return NULL_TELEM;
}

// Best case: Θ(1)
// Worst case: Θ(n)
// Total case: O(n)
pair<int, int> Matrix::positionOf(TElem elem) const {
	if (root == nullptr)
		return {-1, -1};

	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* current = q.front();
		q.pop();

		if (current->elem == elem)
			return {current->line, current->col};

		if (current->left != nullptr)
			q.push(current->left);
		if (current->right != nullptr)
			q.push(current->right);
	}

	return {-1, -1};
}