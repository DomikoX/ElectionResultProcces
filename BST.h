#pragma once

#include <stdexcept>
#include "Table.h"
#include "StructureItem.h"
#include "DSRoutines.h"
#include "ExplicitQueue.h"

namespace DS
{
	template <typename K, typename T>
	class BST :
		public Table<K, T>
	{
	protected:
		class BSTIterator :
			public StructureIterator<TableItem<K, T>*>
		{
		public:
			BSTIterator(const BST<K, T>* bst, BSTNode<K, T>* startNode);
			BSTIterator(const BSTIterator& other);
			~BSTIterator() override;

			bool operator!=(const StructureIterator<TableItem<K, T>*>& other) const override;
			TableItem<K, T>* const & operator*() const override;
			const StructureIterator<TableItem<K, T>*>& operator++() override;

			StructureIterator<TableItem<K, T>*>* clone() const override;
		private:
			ExplicitQueue<TableItem<K, T>*> queue_;
			// atributy
      
      void fillQueue(BSTNode<K, T>* node, const K startKey, const CompareFunction<K> compare);
		};

	public:
		BST(const CompareFunction<K> compare);
		BST(const BST<K, T>& other);
		~BST() override;

		Structure* clone() const override;
		Structure& operator=(const Structure& other) override;
		Table<K, T>& operator=(const Table<K, T>& other) override;
		virtual BST<K, T>& operator=(const BST<K, T>& other);

		size_t size() const override;
		T& operator[](const K& key) override;
		const T& operator[](const K& key) const override;

		void insert(const K& key, const T& value) override;
		T remove(const K& key) override;
		bool tryFind(const K& key, T& value) const override;
		void clear() override;

		Iterator<TableItem<K, T>*> begin() const override;
		Iterator<TableItem<K, T>*> end() const override;

	protected:
		// atributy
		BSTNode<K,T> *root_;
		size_t size_;

		bool tryFindNode(const K& key, BSTNode<K, T>*& node) const;
		bool tryInsertNode(BSTNode<K, T>* node);
		bool tryExtractNode(const K& key, BSTNode<K, T>*& node);
		BSTNode<K, T>* inorderSuccessor(BSTNode<K, T>* node);
	};

	template<typename K, typename T>
	BST<K, T>::BST(const CompareFunction<K> compare) :
		Table(compare),
		root_(nullptr),
		size_(0)
	{
	}

	template<typename K, typename T>
	BST<K, T>::BST(const BST<K, T>& other) 
	{
    throw -1;
	}

	template<typename K, typename T>
	BST<K, T>::~BST()
	{
		if (root_ == nullptr) {
			return;
		}
		root_->clear(true);
		size_ = 0;
		delete root_;
		root_ = nullptr;
	}

	template<typename K, typename T>
	Structure * BST<K, T>::clone() const
	{
		throw -1;
	}

	template<typename K, typename T>
	Structure & BST<K, T>::operator=(const Structure & other)
	{
		throw -1;
	}

	template<typename K, typename T>
	Table<K, T>& BST<K, T>::operator=(const Table<K, T>& other)
	{
		throw -1;
	}

	template<typename K, typename T>
	BST<K, T>& BST<K, T>::operator=(const BST<K, T>& other)
	{
		Table::operator=(other);
		if (*this != &other) {
			clear();
			root_ = other.root_->cloneDeep();
		}

		return *this;
		
	}

	template<typename K, typename T>
	size_t BST<K, T>::size() const
	{
		return size_;
	}

	template<typename K, typename T>
	T& BST<K, T>::operator[](const K & key)
	{
		throw -1;
	}

	template<typename K, typename T>
	const T & BST<K, T>::operator[](const K & key) const
	{
		throw -1;
	}

	template<typename K, typename T>
	void BST<K, T>::insert(const K & key, const T & value)
	{
		BSTNode<K, T> *pom = new BSTNode<K, T>(key, value);

		if (!tryInsertNode(pom)) {
			delete pom;
			throw std::invalid_argument;
		}
	}

	template<typename K, typename T>
	T BST<K, T>::remove(const K & key)
	{
		throw -1;
	}

	template<typename K, typename T>
	bool BST<K, T>::tryFind(const K & key, T & value) const
	{
		BSTNode<K, T> *pom;
		if (tryFindNode(key, pom)) {
			value = pom->getData();
			return true;
		}
		return false;
	}

	template<typename K, typename T>
	void BST<K, T>::clear()
	{
		if (root_ != nullptr) {
			root_->clear(true);
			delete root_;
			root_ = nullptr;
			size_ = 0;
		}
	}

	template<typename K, typename T>
	Iterator<TableItem<K, T>*> BST<K, T>::begin() const
	{
		throw -1;
	}

	template<typename K, typename T>
	Iterator<TableItem<K, T>*> BST<K, T>::end() const
	{
		throw -1;
	}

	template<typename K, typename T>
	bool BST<K, T>::tryFindNode(const K & key, BSTNode<K, T>*& node) const
	{
		

		BSTNode<K, T> *pom = root_;
		

		while (pom != nullptr) {
			node = pom;
		switch (compare_(pom->getKey(),key)) {
		case 0: 
			return true;
		case 1:
			pom = pom->getRSon();
			break;
		case -1:
			pom = pom->getLSon();
			break;
		}

		}
		return false;

	}

	template<typename K, typename T>
	bool BST<K, T>::tryInsertNode(BSTNode<K, T>* node)
	{
		if (root_ == nullptr) {
			root_ = node;
			size_++;
			return true;
		}
		BSTNode<K, T> *pom;
		if (!tryFindNode(node->getKey(), pom)) {

			if (compare_(node->getKey(), pom->getKey) < 0) {
				pom->setLSon(node);
			}
			else {
				pom->setRSon(node);
			}
			size_++;
			return true;
		}
			
		return false;
	}

	template<typename K, typename T>
	bool BST<K, T>::tryExtractNode(const K & key, BSTNode<K, T>*& node)
	{
		throw -1;
	}

	template<typename K, typename T>
	BSTNode<K, T>* BST<K, T>::inorderSuccessor(BSTNode<K, T>* node)
	{
		throw -1;
	}

	template<typename K, typename T>
	BST<K, T>::BSTIterator::BSTIterator(const BST<K, T>* bst, BSTNode<K, T>* startNode):
		queue_(new ExplicitQueue<TableItem<K,T>*>)
	{
		if (startNode != nullptr) {
			fillQueue(bst->root_, startNode->getKey(), bst->compare_);
		}
		
	}

	template<typename K, typename T>
	BST<K, T>::BSTIterator::BSTIterator(const BSTIterator & other) :
		queue_(new ExplicitQueue<TableItem<K,T>*>(other))
	{
		
	}

	template<typename K, typename T>
	BST<K, T>::BSTIterator::~BSTIterator()
	{

		delete	queue_;
		queue_ = nullptr;
	}

	template<typename K, typename T>
	bool BST<K, T>::BSTIterator::operator!=(const StructureIterator<TableItem<K, T>*>& other) const
	{
		const BSTIterator& otherIterator = dynamic_cast<BSTIterator>(other);
		if (queue_->size() != otherIterator.queue_->size()) {
			return true;
		}
		else if (queue_->size() > 0 && (queue_->peek() != otherIterator.queue_->peek()) {
			return true;
		}
		else {
			return false;
		}
	}

	template<typename K, typename T>
	TableItem<K, T>* const & BST<K, T>::BSTIterator::operator*() const
	{
		return queue_->peek();
	}

	template<typename K, typename T>
	const StructureIterator<TableItem<K, T>*>& BST<K, T>::BSTIterator::operator++()
	{		
		queue_->pop();
		return *this;
	}

	template<typename K, typename T>
	StructureIterator<TableItem<K, T>*>* BST<K, T>::BSTIterator::clone() const
	{
		throw -1;
	}

	template<typename K, typename T>
	void BST<K, T>::BSTIterator::fillQueue(BSTNode<K, T>* node, const K startKey, const CompareFunction<K> compare)
	{
		if (node->getLSon() != nullptr && compare(startKey, node->getKey()) <= 0) {
			fillQueue(node->getLSon(), startKey, compare);
		}

		if (compare(startKey,node->getKey()) <= 0) {
			queue_->push(node);
		}
		

		if (node->getRSon() != nullptr) {
			fillQueue(node->getRSon(), startKey, compare);
		}
	}

}
