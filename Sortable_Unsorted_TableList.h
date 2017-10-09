#pragma once
#include "Table_ArrayList_Unsorted.h"
#include <math.h>
namespace DS {

	template <typename K, typename T>
class Sortable_Unsorted_TableList :
	public Table_ArrayList_Unsorted<K,T> 
{
public:
	Sortable_Unsorted_TableList(const CompareFunction<K> compare);
	Sortable_Unsorted_TableList(const Table_ArrayList_Unsorted<K, T>& other);
	Sortable_Unsorted_TableList(const Sortable_Unsorted_TableList<K, T>& other);

	Structure* clone() const override;
	Sortable_Unsorted_TableList<K, T>& operator=(const Sortable_Unsorted_TableList<K, T>& other);

	void sortBy(int(*cFcion)(const T &a,const  T &b));
private:
	void quick(int min, int max, int(*cFcion)(const T &a, const T &b));
	void bubbleSort(int(*cFcion)(const T &a, const T &b));
	void shellSort(int step, int(*cFcion)(const T &a, const T &b));
	
};
template<typename K, typename T>
Sortable_Unsorted_TableList<K, T>::Sortable_Unsorted_TableList(const CompareFunction<K> compare):
	Table_ArrayList_Unsorted(compare)
{
}

template<typename K, typename T>
 Sortable_Unsorted_TableList<K, T>::Sortable_Unsorted_TableList(const Table_ArrayList_Unsorted<K, T>& other):
	 Table_ArrayList_Unsorted(other)
{
}
template<typename K, typename T>
 Sortable_Unsorted_TableList<K, T>::Sortable_Unsorted_TableList(const Sortable_Unsorted_TableList<K, T>& other) :
	 Table_ArrayList_Unsorted(other)
{
}
template<typename K, typename T>
 Structure * Sortable_Unsorted_TableList<K, T>::clone() const
{
	return new Sortable_Unsorted_TableList<K,T>(*this);
}


template<typename K, typename T>
 Sortable_Unsorted_TableList<K, T>& Sortable_Unsorted_TableList<K, T>::operator=(const Sortable_Unsorted_TableList<K, T>& other)
{
	*this = other;
	//*this = Table_List<K, T>::operator=(other);
	return *this;
	
}

 template<typename K, typename T>
  void Sortable_Unsorted_TableList<K, T>::sortBy(int(*cFcion)(const T &a, const T &b))
 {
	
	//bubbleSort(cFcion);
	//quick(0,size() -1 , cFcion);
	int step = static_cast<int>(log10(size())+1);
	 shellSort(step,cFcion);
	 
 }

 template<typename K, typename T>
 void Sortable_Unsorted_TableList<K, T>::quick(int min, int max, int(*cFcion)(const T &a, const T &b))
 {
	 int pivotIndex = (min + max) / 2;
 	 T pivot = (*list_)[pivotIndex]->getData();
	 int left = min;
	 int right = max;
	 do{
		 while (cFcion((*list_)[left]->getData(), pivot )< 0) {
			 left++;
		 }
		 while (cFcion((*list_)[right]->getData(), pivot )> 0) {
			 right--;
		 }
		
		 if (left <= right) {
			 DSRoutines::swap((*list_)[left], (*list_)[right]);
			 left++;
			 right--;
		 }
		 
	 
	 } while (left <= right);

		 if (min < right) {
			 quick(min, right, cFcion);
		 }
	 if (left < max) {
		 quick(left, max, cFcion);
	 }

 }

 template<typename K, typename T>
  void Sortable_Unsorted_TableList<K, T>::bubbleSort(int(*cFcion)(const T &a, const T &b))
 {
	 bool exchange = false;
	 do {

		 exchange = false;
		 for (int i = 0; i <= size() - 2; i++) {
			if  (cFcion((*list_)[i]->getData(), (*list_)[i+1]->getData()) > 0) {
				DSRoutines::swap((*list_)[i], (*list_)[i+1]);
				exchange = true;
		 }
		 }
	 } while (exchange);

	

 }

  template<typename K, typename T>
  void Sortable_Unsorted_TableList<K, T>::shellSort(int step, int(*cFcion)(const T &a, const T &b))
  {


	  for (int delta = 0; delta <= step - 1; delta++) {
		  for (int i = delta; i <= size() - 1; i += step) {
			  int j = i;
			  while ((j - step >= delta) && (cFcion((*list_)[j]->getData(), (*list_)[j - step]->getData()) < 0)) {
				  DSRoutines::swap((*list_)[j], (*list_)[j - step]);
				  j -= step;
			  }

			 
		  }

	  }
	  if (step > 1) {
		  shellSort(step - 1, cFcion);
	  }
	 
  }

}
