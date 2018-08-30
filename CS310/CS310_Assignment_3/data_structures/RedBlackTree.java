package data_structures;

import java.util.Iterator;
import java.util.NoSuchElementException;

import data_structures.Hash.HashElement;

/*
 * @author Andrew De Leon
 * @authorid 819470542
 * 
 * Six rules for a red-black tree:
 * 
 * 1. Every node is either red or black.
 * 2. Root is always black.
 * 3. New insertions are colored red (except the root)
 * 4. Every path from root to leaf has the same number of black nodes
 * 5. No path can have two consecutive red nodes (a red node can not have a red parent or a red child)
 * 6. Null nodes are black
 * 
 * Correct violation:
 * 1. If the node that causes the violation has a black aunt, then you rotate that node
 * 2. If the node that causes the violation has a red aunt, then you color flip that node
 * 
 * Change parent.parent to grandparent for Redgy when debugging to reduce confusion
*/

@SuppressWarnings("unused")
public class RedBlackTree<K, V> implements RedBlackI<K, V> {

	Node<K,V> root;
	int size;
	
	/**
	 * Node class and constructor
	 *
	 * @param <K> key
	 * @param <V> value
	 */
	@SuppressWarnings("hiding")
	class Node<K,V> {
		K key;
		V value;
		Node<K,V> left, right, parent;
		boolean isLeftChild, black;
		public Node (K key, V value) {
			this.key = key;
			this.value = value;
			left = right = parent = null;
			black = false;
			isLeftChild = false;
		}
	}
	
	/**
	 * Checks color of the tree to see if correct coloring is in place.
	 * Root must me black.
	 * 
	 * @param node
	 */
	public void checkColor(Node<K,V> node) {
		if (node == root)
			return;
		
		if (!node.black && !node.parent.black)
			correctTree(node);
		
		if (node.parent != null)
			checkColor(node.parent);
	}
	
	/**
	 * Checks if the tree is in the correct position.
	 * 
	 * @param node
	 */
	public void correctTree(Node<K,V> node) {
		if (node.parent.isLeftChild) {
			if (node.parent.parent.right == null || node.parent.parent.right.black) {
				rotate(node);
			} else {
				if (node.parent.parent.right != null)
					node.parent.parent.right.black = true;
				node.parent.parent.black = false;
				node.parent.black =  true;		
			}
		} else {
			if (node.parent.parent.left == null || node.parent.parent.left.black) {
				rotate(node);
			} else {
				if (node.parent.parent.left != null)
					node.parent.parent.left.black = true;
				node.parent.parent.black = false;
				node.parent.black =  true;		
			}
		}
	}
	
	/**
	 * Rotation.
	 * 
	 * After rotate, children are red (node.parent.direction), parent is black.
	 * 
	 * @param node
	 */
	public void rotate(Node<K,V> node) {
		if (node.isLeftChild) {
			if (node.parent.isLeftChild) {
				rightRotate(node.parent.parent);
				node.black = false;
				node.parent.black = true;
				if (node.parent.right != null)
					node.parent.right.black = false;
			} 
			else {
				rightLeftRotate(node.parent.parent);
				node.black = true;
				node.right.black = false;
				node.left.black = false;
			}
		} 
		else {
			if (node.parent.isLeftChild) {
				leftRightRotate(node.parent.parent);
				node.black = true;
				node.right.black = false;
				node.left.black = false;
			} 
			else {
				leftRotate(node.parent.parent);
				node.black = false;
				node.parent.black = true;
				if (node.parent.left != null)
					node.parent.left.black = false;
			}
		}
	}
	
	/**
	 * Rotates left. Code given in class.
	 * 
	 * @param node
	 */
	public void leftRotate(Node<K,V> node) {
		Node<K,V> temp = node.right;
		
		node.right = temp.left;

		if (node.right != null) {
			node.right.parent = node;
			node.right.isLeftChild = false;
		}
		
		if (node.parent == null) {
			root = temp;
			temp.parent = null;
		} else {
			temp.parent = node.parent;
			if (node.isLeftChild) {
				temp.isLeftChild = true;
				temp.parent.left = temp;
			} else {
				temp.isLeftChild = false;
				temp.parent.right = temp;
			}
		}
		temp.left = node;
		node.isLeftChild = true;
		node.parent = temp;
	}
	
	/**
	 * Rotates right. Code made from revising the left rotate.
	 * 
	 * @param node
	 */
	public void rightRotate(Node<K,V> node) {
		Node<K,V> temp = node.left;
		node.left = temp.right;

		if (node.left != null) {
			node.left.parent = node;
			node.left.isLeftChild = true;
		}

		if (node.parent == null) {
			root = temp;
			temp.parent = null;
		} else {
			temp.parent = node.parent;
			if (node.isLeftChild) {
				temp.isLeftChild = true;
				temp.parent.left = temp;
			} else {
				temp.isLeftChild = false;
				temp.parent.right = temp;
			}
		}

		temp.right = node;
		node.isLeftChild = false;
		node.parent = temp;
	}
	
	/**
	 * Left right rotate.
	 * 
	 * @param node
	 */
	public void leftRightRotate(Node<K,V> node) {
		leftRotate(node.left);
		rightRotate(node);
	}
	
	/**
	 * Right left rotate.
	 * 
	 * @param node
	 */
	public void rightLeftRotate(Node<K,V> node) {
		rightRotate(node.right);
		leftRotate(node);
	}
	
	/**
	 * Checks number of black nodes on both ends.
	 * 
	 * @param node
	 * @return
	 * @throws Exception
	 */
	public int blackNodes(Node<K,V> node) {
		if (node == null)
			return 1;
		int rightBlackNodes = blackNodes(node.right);
		int leftBlackNodes = blackNodes(node.left);
		if (rightBlackNodes != leftBlackNodes)
			throw new IllegalArgumentException("rightBlackNodes != leftBlackNodes");
		if (node.black)
			leftBlackNodes++;
		return leftBlackNodes;
	}
	
	/**
	 * Adds node, starting with the root.
	 * 
	 * @param key	key of node
	 * @param value value of node
	 */
	public void add(K key, V value) {
		Node <K,V> node  = new Node<K,V>(key, value);
		
		if (root == null) {
			root = node;
			node.black = true;
			size++;
			return;
		}	
		add(root, node);
		root.black = true;
		size++;
	}

	/**
	 * Adds node to the next available correct location.
	 * 
	 * @param parent  location of the existing node's parent
	 * @param newNode location of an existing node's new child
	 * @return		  none
	 */
	@SuppressWarnings("unchecked")
	private void add(Node<K,V> parent, Node<K,V> newNode) {
		if (((Comparable<K>)newNode.key).compareTo(parent.key) > 0) {
			if (parent.right == null) {
				parent.right = newNode;
				newNode.parent = parent;
				newNode.isLeftChild = false;
				return;
			}
			else {
				add(parent.right, newNode);	
			}
		}
		else {
			if (parent.left == null) {
			parent.left = newNode;
			newNode.parent = parent;
			newNode.isLeftChild = true;
			return;
			}
			else { 
				add(parent.left, newNode);
			}
		}
		checkColor(newNode);
	}

	/**
	 * Sees if the node is within the tree.
	 * 
	 * containshelper named contains for consistency. Goes to check if equal, left, or right.
	 * Goes down the tree till the node is found. Start at root.
	 */
	@Override
	public boolean contains(K key) {
		return contains(root, key);
	}
	
	@SuppressWarnings("unchecked")
	private boolean contains(Node<K,V> node, K key) {
		if (node == null)
			return false;
		if(((Comparable<K>)key).compareTo(node.key) == 0)
			return true;
		if(((Comparable<K>)key).compareTo(node.key) < 0)
			return contains(node.left, key);
		return contains(node.right, key);
	}

	/**
	 * Get the value.
	 * 
	 * Same as contains, but get value instead of the node itself.
	 */
	@Override
	public V getValue(K key) {
		return getValue(root, key);
	}
	
	@SuppressWarnings("unchecked")
	private V getValue(Node<K,V> node, K key) {
		if (node == null)
			return null;
		if(((Comparable<K>)key).compareTo(node.key) == 0)
			return (node.value);
		if(((Comparable<K>)key).compareTo(node.key) < 0)
			return getValue(node.left, key);
		return getValue(node.right, key);
	}

	/**
	 * Return size.
	 */
	@Override
	public int size() {
		return size;
	}

	/**
	 * Check if empty.
	 */
	@Override
	public boolean isEmpty() {
		return size == 0;
	}

	/**
	 * Return height.
	 */
	@Override
	public int height() {
		if (root == null)
			return 0;
		return height(root) - 1;
	}
	
	/**
	 * Return height. Code given in class.
	 * 
	 * @param node
	 * @return height
	 */
	public int height(Node<K,V> node) {
		if (node == null)
			return 0;
		int leftheight = height(node.left) + 1;
		int rightheight = height (node.right) + 1;
		if (leftheight > rightheight)
			return leftheight;
		return rightheight;
	}

	/**
	 * Iterator.
	 */
	@Override
	public Iterator<K> iterator() {
		return new IteratorHelper();
	}
	
	/**
	 * Iterator helper.
	 * 
	 * traverse:
	 * if node is null, return
	 * traverse left
	 * add position
	 * traverse right
	 */
	class IteratorHelper implements Iterator<K> {
		private K[] RBT;
		private int position;
		
		@SuppressWarnings("unchecked")
		public IteratorHelper() {
			RBT = (K[]) new Object[size];
			position = 0;
			traverse(root);
			position = 0;
		}

		public void traverse(Node<K,V> node) {
			if (node == null)
				return;
			traverse(node.left);
			RBT[position++] = node.key;
			traverse(node.right);
		}
		
		@Override
		public boolean hasNext() {
			return position <= RBT.length;
		}

		@Override
		public K next() {
			if (!hasNext())
				throw new NoSuchElementException();
			return RBT[position++];
		}
	}

	/**
	 * Print in inorder traversal.
	 */
	@Override
	public void print() {
		print(root);
	}
	
	public void print(Node<K,V> node) {
		if (node == null)
			return;
		print(node.left);
		System.out.println(node.value);
		print(node.right);
	}

	/**
	 * Tester for RBT if it works.
	 * 
	 * public static void main(String[] a) {
		RedBlackTree<String,Integer> tree = new RedBlackTree<>();
		
		tree.add("",  1);
		tree.add("w",  10);
		
		for (int i = 0; i < 99999; i++)
			tree.add("", i);
		
		System.out.println("Finished. RBT works.");
	}
	 * @param a
	 */
}