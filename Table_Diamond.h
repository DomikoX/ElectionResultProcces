#pragma once

#include "Table_List.h"

namespace DS
{
	template <typename K, typename T>
	class Table_Diamond :
		public Table_List<K, T>
	{
	public:
		Table_Diamond(const CompareFunction<K> compare);
		Table_Diamond(const Table_Diamond<K, T>& other);

		Structure* clone() const override;
		virtual Table_Diamond<K, T>& operator=(const Table_Diamond<K, T>& other);

		T& operator[](const K& key) override;

		void insert(const K& key, const T& value) override;
		T remove(const K& key) override;
	protected:
		int indexOfKey(const K& key) const override;

	private:
		void restoreDiamond(int index);

		int getGreatestLeftIndex(int index) const;
		int getLeastRightIndex(int index) const;

		int getUpperLeft(int index) const;
		int getLowerLeft(int index) const;
		int getUpperRight(int index) const;
		int getLowerRight(int index) const;
		
		int getLevel(int index) const;
		bool isIndexInRange(int index, int level) const;
	};

	template<typename K, typename T>
	Table_Diamond<K, T>::Table_Diamond(const CompareFunction<K> compare)
	{
		throw -1;
	}

	template<typename K, typename T>
	Table_Diamond<K, T>::Table_Diamond(const Table_Diamond<K, T>& other)
	{
		throw -1;
	}

	template<typename K, typename T>
	Structure * Table_Diamond<K, T>::clone() const
	{
		throw -1;
	}

	template<typename K, typename T>
	Table_Diamond<K, T>& Table_Diamond<K, T>::operator=(const Table_Diamond<K, T>& other)
	{
		throw -1;
	}

	template<typename K, typename T>
	T & Table_Diamond<K, T>::operator[](const K & key)
	{
		throw -1;
	}

	template<typename K, typename T>
	void Table_Diamond<K, T>::insert(const K & key, const T & value)
	{
		throw -1;
	}

	template<typename K, typename T>
	T Table_Diamond<K, T>::remove(const K & key)
	{
		throw -1;
	}

	template<typename K, typename T>
	int Table_Diamond<K, T>::indexOfKey(const K & key) const
	{
		throw -1;
	}

	template<typename K, typename T>
	void Table_Diamond<K, T>::restoreDiamond(int index)
	{
		throw -1;
	}

	template<typename K, typename T>
	int Table_Diamond<K, T>::getGreatestLeftIndex(int index) const
	{
		throw -1;
	}

	template<typename K, typename T>
	int Table_Diamond<K, T>::getLeastRightIndex(int index) const
	{
		throw -1;
	}

	template<typename K, typename T>
	int Table_Diamond<K, T>::getUpperLeft(int index) const
	{
		throw -1;
	}

	template<typename K, typename T>
	int Table_Diamond<K, T>::getLowerLeft(int index) const
	{
		throw -1;
	}

	template<typename K, typename T>
	int Table_Diamond<K, T>::getUpperRight(int index) const
	{
		throw -1;
	}

	template<typename K, typename T>
	int Table_Diamond<K, T>::getLowerRight(int index) const
	{
		throw -1;
	}

	template<typename K, typename T>
	int Table_Diamond<K, T>::getLevel(int index) const
	{
		throw -1;
	}

	template<typename K, typename T>
	bool Table_Diamond<K, T>::isIndexInRange(int index, int level) const
	{
		throw -1;
	}
}