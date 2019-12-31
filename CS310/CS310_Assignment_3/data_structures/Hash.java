package data_structures;

import java.util.Iterator;

/**
 * The Hash data structure has O(1) time complexity (best case) for add, remove, and find
 * for an object in the data structure. The methods in the Hash data structure are defined
 * by the HashI interface. The Hash consists of an array of Linked Lists,
 * the Linked Lists are defined by the HashListI interface.
 * 
 * @author kingofthenorth
 * @authorid 123456789
 *
 * @param <K> The key for entries in the hash
 * @param <V> The value for entries in the hash
 */

public class Hash<K, V> implements HashI<K, V> {
	// 1025201656
	// LinkedList
	HashListI<HashElement<K,V>> [] hash_array;
	int tableSize, numElements;
	double maxLoadFactor;
	
	// Constructor that accepts tableSize.
	@SuppressWarnings("unchecked")
	public Hash(int tableSize) {
		this.tableSize = tableSize;
		maxLoadFactor = 0.75;
		numElements = 0;
		hash_array = (LinkedList<HashElement<K,V>>[]) new LinkedList[tableSize];
			for (int i = 0; i < tableSize; i++)
				hash_array[i] = new LinkedList<HashElement<K,V>>();
	}
	
	// 1025201649
	// @param <K>
	// @param <V>
	@SuppressWarnings("hiding")
	class HashElement<K,V> implements Comparable<HashElement<K,V>> {
		K key;
		V value;
		
		public HashElement(K key, V value) {
			this.key = key;
			this.value = value;
		}
		@SuppressWarnings("unchecked")
		public int compareTo(HashElement<K, V> o) {
			return (((Comparable<K>) this.key).compareTo((K) o.key));
		}
	}
	
	// Add an element to the hash.
	//
	// Check size if need to resize.
	// Create new V value.
	// Find the correct key.
	// Add value to the key.
	// Increment numElements.
	@Override
	public boolean add(K key, V value) {
		if (loadFactor() > maxLoadFactor)
			resize(tableSize * 2);
		HashElement<K, V> hashElement = new HashElement<K, V>(key, value);
		int hashVal = (key.hashCode() & 0x7FFFFFFF) % tableSize;
		if (contains(key))
			return false;
		hash_array[hashVal].add(hashElement);
		numElements++;
		return true;
	}

	// Remove an element from the hash.
	//
	// Cannot remove if there are no elements in the data structure.
	// Find the correct key.
	// Remove value to the key.
	// Decrement numElements.
	@SuppressWarnings("unchecked")
	@Override
	public boolean remove(K key) {
		if (isEmpty())
			return false;
		int hashVal = (key.hashCode() & 0x7FFFFFFF) % tableSize;
		for (HashElement<K, V> currentElement: hash_array[hashVal])
			if (((Comparable<K>)key).compareTo(currentElement.key) == 0) {
				if(hash_array[hashVal].remove(currentElement) != null){
					numElements--;
					return true;
				}
			}
		return false;
	}

	// Change the certain value sought for.
	@SuppressWarnings("unchecked")
	@Override
	public boolean changeValue(K key, V value) {
		if (isEmpty())
			return false;
		int hashVal = (key.hashCode() & 0x7FFFFFFF) % tableSize;
		for (HashElement<K, V> currentElement: hash_array[hashVal])
			if (((Comparable<K>)key).compareTo(currentElement.key) == 0) {
				currentElement.value = value;
				return true;
			}
		return false;
	}

	// If the hash contains the said value, return true.
	@SuppressWarnings("unchecked")
	@Override
	public boolean contains(K key) {
		int hashVal = (key.hashCode() & 0x7FFFFFFF) % tableSize;
		for (HashElement<K, V> hashElement: hash_array[hashVal])
			if (((Comparable<K>)key).compareTo(hashElement.key) == 0) {
				if (hash_array[hashVal].contains(hashElement))
					return true;
			}
		return false;
	}
	
	// Get the said value.
	@SuppressWarnings("unchecked")
	@Override
	public V getValue(K key) {
		int hashVal = (key.hashCode() & 0x7FFFFFFF) % tableSize;
		for (HashElement<K, V> hashElement: hash_array[hashVal])
			if (((Comparable<K>)key).compareTo(hashElement.key) == 0)
				return hashElement.value;
		return null;
	}

	// Gives current size of numElements.
	@Override
	public int size() {
		return numElements;
	}

	// If hash has 0 amount of numElements, return true, else, return false.
	@Override
	public boolean isEmpty() {
		return numElements == 0;
	}

	// Make hash empty.
	@Override
	public void makeEmpty() {
		for (int i = 0; i < hash_array.length; i++)
			hash_array[i].makeEmpty();
		numElements = 0;
	}

	@Override
	public double loadFactor() {
		return numElements/tableSize;
	}

	@Override
	public double getMaxLoadFactor() {
		return maxLoadFactor;
	}

	@Override
	public void setMaxLoadFactor(double loadFactor) {
		maxLoadFactor = loadFactor;
	}
	
	// Creates a resized hash array to provide for more data.
	@Override
	public void resize(int newSize) {
		@SuppressWarnings("unchecked")
		LinkedList<HashElement<K, V>>[] new_array = (LinkedList<HashElement<K, V>>[]) new LinkedList[newSize];
		for (int i = 0; i < newSize; i++)
			new_array[i] = new LinkedList<HashElement<K, V>>();
		for (K key: this) {
			V val = getValue(key);
			HashElement<K, V> hashElement = new HashElement<K, V>(key, val);
			int hashVal = (key.hashCode() & 0x7FFFFFFF) % newSize;
			new_array[hashVal].add(hashElement);
		}
		hash_array = new_array;
		tableSize = newSize;
	}

	@Override
	public Iterator<K> iterator() {
		return new IteratorHelper<K>();
	}
	
	class IteratorHelper<T> implements Iterator<T> {
		private T[] keys;
		private int position;

		@SuppressWarnings("unchecked")
		public IteratorHelper() {
			keys = (T[]) new Object[numElements];
			position = 0;
			int p = 0;
			for (int i = 0; i < tableSize; i++) {
				LinkedList<HashElement<K, V>> list = (LinkedList<HashElement<K, V>>) hash_array[i];
				for (HashElement<K,V> h: list)
					keys[p++] = (T) h.key;
			}
		}
		public boolean hasNext() {
			return position < keys.length;
		}
		public T next() {
			if (!hasNext())
				return null;
			return keys[position++];
		}  
	}
}
