/* @author kingofthenorth
 * @description Assignment1
 * @class CS 310
 * @instructor Edwards
 * 
 * Stack.java
*/

package data_structures;

import java.util.Iterator;

public class Stack<E> {
	private ListI<E> list;

	// Initializes the new stack.
	public Stack() {
		list = new LinkedList<>();
	}

	// Adds the object to the stack.
	public void push(E obj) {
		list.addFirst(obj);
	}

	// Removes and returns the last object added.
	public E pop() {
		return list.removeFirst();
	}

	// Return number of items in the stack.
	public int size() {
		return list.size();
	}

	// True if the stack is empty.
	public boolean isEmpty() {
		return list.isEmpty();
	}

	// Hardcoded to return false.
	public boolean isFull() {
		return list.isFull();
	}

	// Returns the most recent object.
	public E peek() {
		return list.peekFirst();
	}

	// Look for a specific object and return true if object exists.
	public boolean contains(E obj) {
		return list.contains(obj);
	}

	// Make topPlate null thus whole stack is gone.
	public void makeEmpty() {
		list.makeEmpty();
	}
	
	// Iterator through the Linked List.
	public Iterator<E> iterator() {
		return list.iterator();
	}
}