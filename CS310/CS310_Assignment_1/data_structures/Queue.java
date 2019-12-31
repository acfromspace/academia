
/* @author kingofthenorth
 * @description Assignment1
 * @class CS 310
 * @instructor Edwards
 * 
 * Queue.java
*/

package data_structures;

import java.util.Iterator;

public class Queue<E> implements Iterable<E> {
	private ListI<E> list;

	// Initializes a new queue.
	public Queue() {
		list = new LinkedList<>();
	}

	// Add object to the line.
	public void enqueue(E obj) {
		list.addLast(obj);
	}

	// Remove object from the line.
	public E dequeue() {
		return list.removeFirst();
	}

	// Returns size.
	public int size() {
		return list.size();
	}

	// True if queue is empty, false if not.
	public boolean isEmpty() {
		return list.isEmpty();
	}

	// Returns next one in line.
	public E peek() {
		return list.peekFirst();
	}

	// Look for a specific object and return true if object exists.
	public boolean contains(E obj) {
		return list.contains(obj);
	}

	// Make queue empty.
	public void makeEmpty() {
		list.isEmpty();
	}

	// Iterator through the Linked List.
	public Iterator<E> iterator() {
		return list.iterator();
	}
}