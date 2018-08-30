/**
 * 
 */
package data_structures;

import java.util.Iterator;
import java.util.NoSuchElementException;

import data_structures.LinkedList.IteratorHelper;
import data_structures.LinkedList.Node;

/*
 * The linked list for our hash will only implement the
 * methods in the HashListI interface, a reduced set of
 * methods compared to the linked list from Assignment 1.
 * 
 * @author Andrew De Leon
 * @authorid 819470542
 * 
 * Reuse methods from Assignment 1 and modified them.
 *
 */

@SuppressWarnings("unused")
public class LinkedList<E> implements HashListI<E> {

	// Initiates Nodes.
	@SuppressWarnings("hiding")
	class Node<E> {
		public E data;
		public Node<E> next;

		public Node(E obj) {
			data = obj;
			next = null;
		}
	}

	// Create a new linked list.
	private Node<E> head, tail;
	private int size;

	public LinkedList() {
		head = null;
		tail = null;
		size = 0;
	}

	/* 
	 * Originally addFirst method.
	 * Add the first object in the Linked List.
	 * Increase size each time the method is used.
	 * 
	 * @param obj	provide an object to add on the data structure.
	 * @return		none.
	 * @see 		data_structures.ListI#addFirst(java.lang.Object)
	 */
	@Override
	public void add(E obj) {
		Node<E> node = new Node<E>(obj);
		if (isEmpty()) {
			head = tail = node;
			size++;
			return;
		}
		node.next = head;
		if (head == null)
			tail = node;
		head = node;
		size++;
	}

	/*
	 * Originally removeFirst method.
	 * Remove the first object in the Linked List.
	 * Decrease size each time the method is used.
	 * 
	 * @param obj	provide an object to remove on the data structure.
	 * @return tmp	return temporary object.
	 * @see			data_structures.ListI#removeFirst()
	 */
	@Override
	public E remove(E obj) {
		if (head == null)
			return null;
		if (obj == head.data) 
			return removeFirst();
		if (obj == tail.data)
			return removeLast();
		Node<E> current = head;
		Node<E> previous = null;
		while (current != null) {
			if (((Comparable<E>)current.data).compareTo(obj) == 0) {
				previous.next = current.next;
				size--;
				return current.data;
			}
			previous = current;
			current = current.next;
		}
		return null;
	}
	
	/**
	 * Removes the first Object in the list and returns it.
	 * Returns null if the list is empty.
	 * 
	 * @return the object removed.
	 */
	public E removeFirst() {
		if (isEmpty())
			return null;
		E temp = head.data;
		if(head == tail) {
			head = tail = null;
		}
		else {
			head = head.next;
		}
		size--;
		return temp;
	}
	
	/**
	 * Removes the last Object in the list and returns it.
	 * Returns null if the list is empty.
	 * 
	 * @return the object removed.
	 */
	public E removeLast() {
		if (isEmpty())
			return null;
		if (head == tail)
			return removeFirst();
		Node <E> current = head;
		Node <E> previous = null;
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
	 * Make Linked List empty.
	 * Make head null to garbage collect all other disconnected nodes.
	 * Create size to zero.
	 * 
	 * @param		none.
	 * @return		none.
	 * @see 		data_structures.ListI#makeEmpty()
	 */
	@Override
	public void makeEmpty() {
		head = null;
		tail = null;
		size = 0;
	}

	/*
	 * Linked List is empty.
	 * 
	 * @param					none.
	 * @return true, false		return true if size is 0, false if != 0.
	 * @see 					data_structures.ListI#isEmpty()
	 */
	@Override
	public boolean isEmpty() {
		if (size == 0)
			return true;
		else
			return false;
	}

	/*
	 * Return size.
	 * 
	 * @param			none.
	 * @return size		return immediate size of the data structure.
	 * @see 			data_structures.ListI#size()
	 */
	@Override
	public int size() {
		return size;
	}

	/*
	 * Check the Linked List if it contains a specific object.
	 * 
	 * @param obj			provide an object to remove on the data structure.
	 * @return true,false	return true if data structure contains said object, false if not.
	 * @see 				data_structures.ListI#contains(java.lang.Object)
	 */

	@Override
	public boolean contains(E obj) {
		Node<E> current = head;
		while (current != null) {
			if (((Comparable<E>)obj).compareTo(current.data) == 0) {
				return true;
			}
		current = current.next;
		}
		return false;
	}

	/*
	 * Linked List Iterator to check each object.
	 * 
	 * @see data_structures.ListI#iterator()
	 */
	@Override
	public Iterator<E> iterator() {
		return new IteratorHelper();
	}

	class IteratorHelper implements Iterator<E> {
		Node<E> newNode;

		public IteratorHelper() {
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
