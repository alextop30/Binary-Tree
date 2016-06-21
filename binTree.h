#include "Node.h"

typedef enum { left_side, right_side } SIDE;

template < class T > class binTree
{
public:
	binTree();								// default constructor
	unsigned height() const;						// returns height of tree
	virtual void insert(const T&);						// inserts a node in tree
	void inorder(void(*) (const T&));					// inorder traversal of tree  -- pointer to the print function implemented by user
protected:
	Node < T >* root;							// root of tree
private:
	unsigned height(Node < T >*) const;					// private version of height ( )
	void insert(Node < T >*&, const T&);					// private version of insert ( )
	void inorder(Node < T >*, void(*) (const T&));				// private version of inorder ( )

};

//PRIVATE FUNCTION IMPLEMENTATION

template < class T >
unsigned binTree<T>::height(Node <T> *ptr) const
{
	if (ptr == NULL)							//if root is nulll --- break out 
	{
		return 1;
	}

	int left = height(ptr->left);						//take the left path recursivelly
	int right = height(ptr->right);						//take the left path recursivelly

	if (left >= right)							//if left is bigger than right
	{
		return (1 + left);						//return 1+ number of left - account for root

	}
	else
	{
		return (1 + right);						//if right is bigger the left do the same
	}

}

SIDE rnd() { return rand() % 2 ? right_side : left_side; };

template < class T >
void binTree<T>::insert(Node <T> *&ptr, const T& x)
{
	if (ptr == NULL)
	{
		ptr = new Node <T>(x, NULL, NULL);

	}
	else
	{

		if (rnd()%2 ==0)						//if random is one right side is taken
		{
			insert(ptr ->left, x);
		}
		else								//if random is zero left side is taken
		{
			insert(ptr->right, x);

		}
	}

}


template < class T >
void binTree<T>::inorder(Node < T >*ptr, void(*Print) (const T& ))
{
	if (ptr != NULL)
	{
		inorder(ptr->left, Print);
		Print(ptr->data);
		inorder(ptr->right, Print);

	}


}

//PUBLIC FUNCTIONN IMPLEMENTATION

template < class T >
binTree<T>::binTree()								//default constructor 
{
	root = NULL;								//set root to NULL
}

template < class T > 
unsigned binTree<T>::height() const						//Public Height
{
	
	return height(root);							//call private height with root ptr
}



template < class T >
void binTree<T>::inorder(void (*Print) (const T& x))
{

	inorder(root, Print);
}


template < class T >
void binTree<T>::insert(const T& x)						//Public Insert
{
		insert(root, x);

}
