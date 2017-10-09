#pragma once

#include "BST.h"
#include "StructureItem.h"
#include "DSRoutines.h"
#include <stdexcept>
#include <random>

namespace DS
{
	template <typename K, typename T>
	class Treap :
		public BST<K, T>
	{
	public:
		Treap(const CompareFunction<K> compare);
		Treap(const Treap<K, T>& other);
		//terba konstruktor

		Structure* clone() const override;
		virtual Treap<K, T>& operator=(const Treap<K, T>& other);

		T& operator[](const K& key) override;

		void insert(const K& key, const T& value) override;
		T remove(const K& key) override;

	private:
		std::minstd_rand0 rnd_;
		// atributy

		void restoreHeapAfterInsertion(TreapNode<K, T>* node);
		void moveNodeToLeaf(TreapNode<K, T>* node);
		void rotateLeft(TreapNode<K, T>* node);
		void rotateRight(TreapNode<K, T>* node);
		TreapNode<K, T>* getGreaterSonNode(TreapNode<K, T>* node);
	};


	template<typename K, typename T>
	Treap<K, T>::Treap(const CompareFunction<K> compare) :
		BST<K,T>(compare),
		rnd_(new std::minstd_rand0(0))
	{
	}

	template<typename K, typename T>
	Treap<K, T>::Treap(const Treap<K, T>& other) :
		BST<K,T>(other),
		rnd_(new std::minstd_rand0(*other.rnd_))
	{
	}

	template<typename K, typename T>
	Structure * Treap<K, T>::clone() const
	{
		return nre Treap<K,T>(*this);
	}

	template<typename K, typename T>
	Treap<K, T>& Treap<K, T>::operator=(const Treap<K, T>& other)
	{
		BST<K, T>::operator=(other);
		*rnd_ = *other.rnd_;
		return *this;
	}

	template<typename K, typename T>
	T & Treap<K, T>::operator[](const K & key)
	{
		BSTNode<K, T>* node = nullptr;
		if (!tryFindNode(key, node)) {

		}
	}

	template<typename K, typename T>
	void Treap<K, T>::insert(const K & key, const T & value)
	{
		// throw -1
	}

	template<typename K, typename T>
	T Treap<K, T>::remove(const K & key)
	{
		// throw -1
	}

	template<typename K, typename T>
	void Treap<K, T>::restoreHeapAfterInsertion(TreapNode<K, T>* node)
	{
		// throw -1
	}

	template<typename K, typename T>
	void Treap<K, T>::moveNodeToLeaf(TreapNode<K, T>* node)
	{
		// throw -1
	}

	template<typename K, typename T>
	void Treap<K, T>::rotateLeft(TreapNode<K, T>* node)
	{
		// throw -1
	}

	template<typename K, typename T>
	void Treap<K, T>::rotateRight(TreapNode<K, T>* node)
	{
		// throw -1
	}   

	template<typename K, typename T>
	TreapNode<K, T>* Treap<K, T>::getGreaterSonNode(TreapNode<K, T>* node)
	{
		// throw -1
	}
}