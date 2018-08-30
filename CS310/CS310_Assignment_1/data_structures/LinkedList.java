/* @author Andrew De Leon
 * @description Assignment1
 * @class CS 310
 * @instructor Edwards
 * 
 * LinkedList.java
*/

package data_structures;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class LinkedList<E> implements ListI<E> {

	// Initiates Nodes.
	class Node<E> {
		E data;
		Node<E> next;
		Node<E> previous;

		public Node(E obj) {
			data = obj;
			next = null;
			previous = null;
		}
	}

	// Create a new linked list.
	private Node<E> head, tail, current;
	private int size;

	public LinkedList() {
		head = null;
		tail = null;
		size = 0;
	}

	/*
	 * Add the first object in the Linked List.
	 * 
	 * @see data_structures.ListI#addFirst(java.lang.Object)
	 */
	@Override
	public void addFirst(E obj) {
		Node<E> node = new Node<E>(obj);
		node.next = head;
		if (head == null)
			tail = node;
		head = node;
		size++;
	}

	/*
	 * Add the last object in the Linked List.
	 * 
	 * @see data_structures.ListI#addLast(java.lang.Object)
	 */
	@Override
	public void addLast(E obj) {
		Node<E> node = new Node<E>(obj);
		if (head == null) {
			head = tail = node;
			size++;
			return;
		}
		tail.next = node;
		tail = node;
		size++;
		return;
	}

	/*
	 * Remove the first object in the Linked List.
	 * 
	 * @see data_structures.ListI#removeFirst()
	 */
	@Override
	public E removeFirst() {
		if (head == null)
			return null;
		E tmp = head.data;
		if (head == tail)
			head = tail = null;
		else
			head = head.next;
		size--;
		return tmp;
	}

	/*
	 * Remove the last object in the Linked List.
	 * 
	 * @see data_structures.ListI#removeLast()
	 */
	@Override
	public E removeLast() {
		if (current == tail)
			return null;
		if (head == tail)
			return removeFirst();
		Node<E> current = head, previous = null;
		while (current != tail) {
			previous = current;
			current = current.next;
		}
		previous.next = null;
		tail = previous;
		size--;
		return current.data;
	}

	/*
	 * Peek the first object in the Linked List.
	 * 
	 * @see data_structures.ListI#peekFirst()
	 */
	@Override
	public E peekFirst() {
		if (head == null)
			return null;
		return head.data;
	}

	/*
	 * Peek the first object in the Linked List.
	 * 
	 * @see data_structures.ListI#peekLast()
	 */
	@Override
	public E peekLast() {
		if (tail == null)
			return null;
		return tail.data;
	}

	/*
	 * Make Linked List empty.
	 * 
	 * @see data_structures.ListI#makeEmpty()
	 */
	@Override
	public void makeEmpty() {
		head = null;
		size = 0;
	}

	/*
	 * Linked List is empty.
	 * 
	 * @see data_structures.ListI#isEmpty()
	 */
	@Override
	public boolean isEmpty() {
		if (size == 0)
			return true;
		else
			return false;
	}

	/*
	 * Indicate if the Linked List if full. (Keep false.)
	 * 
	 * @see data_structures.ListI#isFull()
	 */
	@Override
	public boolean isFull() {
		return false;
	}

	/*
	 * Return size.
	 * 
	 * @see data_structures.ListI#size()
	 */
	@Override
	public int size() {
		return size;
	}

	/*
	 * Check the Linked List if it contains a specific object.
	 * 
	 * @see data_structures.ListI#contains(java.lang.Object)
	 */
	@SuppressWarnings({ "unchecked", "null" })
	@Override
	public boolean contains(E obj) {
		Node<E> current = head;
		while (current != null) {
			if (((Comparable<E>)obj).compareTo(current.data) == 0)
				return true;
		}
		current = current.next;
		return false;
	}

	/*
	 * Linked List Iterator to check each object.
	 * 
	 * @see data_structures.ListI#iterator()
	 */
	@Override
	public Iterator<E> iterator() {
		return new LinkedListIterator();
	}

	class LinkedListIterator implements Iterator<E> {
		Node<E> newNode;

		public LinkedListIterator() {
			newNode = head;
		}

		@Override
		public boolean hasNext() {
			return (newNode != null);
		}

		@Override
		public E next() {
			if (!hasNext())
				throw new NoSuchElementException();
			E val = newNode.data;
			newNode = newNode.next;
			return val;
		}

	}
}
