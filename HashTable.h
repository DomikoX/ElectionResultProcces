#pragma once

#include "Table.h"
#include "Array.h"

namespace DS
{
	template <typename K, typename T>
	class HashTable :
		public Table<K, T>
	{
	public:
		HashTable(size_t size, HashFunction<K> hashFunction, CompareFunction<K> compareFunction);
		HashTable(const HashTable<K, T>& other);
		~HashTable() override;

		Structure* clone() const override;
		virtual HashTable<K, T>& operator=(const HashTable<K, T>& other);

		size_t size() const override;
		T& operator[](const K& key) override;
		const T& operator[](const K& key) const override;

		void insert(const K& key, const T& value) override;
		T remove(const K& key) override;
		bool tryFind(const K& key, T& value) const override;
		void clear() override;

		Iterator<TableItem<K, T>*> begin() const override;
		Iterator<TableItem<K, T>*> end() const override;

	private:
		//atributy

	protected:
		void resolveCollision(TableItem<K, T>* data, int index);

	};

	template<typename K, typename T>
	HashTable<K, T>::HashTable(size_t szie, HashFunction<K> hashFunction, CompareFunction<K> compareFunction)
	{
		throw - 1;
	}

	template<typename K, typename T>
	HashTable<K, T>::HashTable(const HashTable<K, T>& other)
	{
		throw - 1;
	}

	template<typename K, typename T>
	HashTable<K, T>::~HashTable()
	{
	}

	template<typename K, typename T>
	Structure * HashTable<K, T>::clone() const
	{
		throw - 1;
	}

	template<typename K, typename T>
	HashTable<K, T>& HashTable<K, T>::operator=(const HashTable<K, T>& other)
	{
		throw - 1;
	}

	template<typename K, typename T>
	size_t HashTable<K, T>::size() const
	{
		throw - 1;
	}

	template<typename K, typename T>
	T & HashTable<K, T>::operator[](const K & key)
	{
		throw - 1;
	}

	template<typename K, typename T>
	const T & HashTable<K, T>::operator[](const K & key) const
	{
		throw - 1;
	}

	template<typename K, typename T>
	void HashTable<K, T>::insert(const K & key, const T & value)
	{
		throw - 1;
	}

	template<typename K, typename T>
	T HashTable<K, T>::remove(const K & key)
	{
		throw - 1;
	}

	template<typename K, typename T>
	bool HashTable<K, T>::tryFind(const K & key, T & value) const
	{
		throw - 1;
	}

	template<typename K, typename T>
	void HashTable<K, T>::clear()
	{
		throw - 1;
	}

	template<typename K, typename T>
	Iterator<TableItem<K, T>*> HashTable<K, T>::begin() const
	{
		throw - 1;
	}

	template<typename K, typename T>
	Iterator<TableItem<K, T>*> HashTable<K, T>::end() const
	{
		throw - 1;
	}

	template<typename K, typename T>
	void HashTable<K, T>::resolveCollision(TableItem<K, T>* data, int index)
	{
		throw - 1;
	}
}