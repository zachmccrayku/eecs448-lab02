/**
*	@author: Zachary McCray
*	@date: 9/8/2021
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	int count; //creates a counter
	Node<T>* temp = m_front; //sets a temporary node to the front of the list
	while(temp != nullptr){ //checks to see if the node is empty
		count++; //counts every node
		temp = temp->getNext(); //traverses to the next node
		}
	return(count); //returns the size of the list
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
        Node<T>* temp = m_front; //sets the front
        bool isFound = false; //initializes boolean
        while(temp != nullptr) //checks to see if temp is empty
	{
                if(temp->getValue() == value) //checks the current value
                {
                        isFound == true;
                        return(isFound); //returns the value if it's true
                }
                else
                {
                temp = temp->getNext(); //continues to navigate the list
                }
	}
        return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;
	if(!isEmpty()) //checks to see if the list empty
{
	secondintoLast = m_front; //sets the second to last node
	lastNode = m_front; //sets the last node
	for(int i = 0; i < m_size-2; i++) //size doesn't include the final node
	{
	secondintoLast = secondintoLast->getNext(); //gets the value
	}
	lastNode = secondintoLast->getNext();
	delete lastNode; //deletes the node
	m_size--; //adjusts the size
	secondintoLast->setNext(nullptr); //reconfigures the new last node
	isRemoved = true;
}
	return(isRemoved);
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
