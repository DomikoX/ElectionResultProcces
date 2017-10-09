#pragma once

#include "Table_List.h"
#include "ArrayList.h"
namespace DS
{
	template <typename K, typename T>
	class Table_ArrayList_Sorted :
		public Table_List<K, T>
	{
	public:
		Table_ArrayList_Sorted(const CompareFunction<K> compare);
		Table_ArrayList_Sorted(const Table_ArrayList_Sorted<K, T>& other);

		Structure* clone() const override;
		virtual Table_ArrayList_Sorted<K, T>& operator=(const Table_ArrayList_Sorted<K, T>& other);
	protected:
		int indexOfKey(const K& key) const override;
	};


	template<typename K, typename T>
	Table_ArrayList_Sorted<K, T>::Table_ArrayList_Sorted(const CompareFunction<K> compare) : Table_List<K,T>( new ArrayList<TableItem<K, T>*>, compare)
	{

	}

	template<typename K, typename T>
	Table_ArrayList_Sorted<K, T>::Table_ArrayList_Sorted(const Table_ArrayList_Sorted<K, T>& other) : Table_List<K, T>(other)
	{
		
	}

	template<typename K, typename T>
	Structure * Table_ArrayList_Sorted<K, T>::clone() const
	{
		return new Table_ArrayList_Sorted <K, T>(*this);
	}

	template<typename K, typename T>
	Table_ArrayList_Sorted<K, T>& Table_ArrayList_Sorted<K, T>::operator=(const Table_ArrayList_Sorted<K, T>& other)
	{
		*this = other;
		//*this = Table_List<K, T>::operator=(other);
		return *this;
	}

	template<typename K, typename T>
	int Table_ArrayList_Sorted<K, T>::indexOfKey(const K & key) const
	{
		int startIndex = 0;
		int stopIndex = static_cast<int>(list_->size());
		
		while (startIndex < stopIndex) {
		
			int index = startIndex + (stopIndex - startIndex) / 2;


			if (functionCompare(key, (*list_)[index]->getKey()) < 0) {
				startIndex = index + 1;
			}
			else {
				stopIndex = index;
			}
		}
		//if (otockaVcykle == 0)
		//return -1;
		//if (stopIndex < list_->size()) {
		//	if ((*list_)[stopIndex]->getKey() == key && (*list_)[stopIndex] != nullptr)
		//		return stopIndex;
		//	else
		//		return -1;
		//}
			
	//	else
			return stopIndex;
	}
}