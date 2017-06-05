#pragma once

#include <iostream>
#include <vector>

template<class Container>
class Action
{
public:
	// Define function pointer with 0 parameters and void return type.
	typedef void(Container::*void_delegate)();

	Action();
	virtual ~Action();

	void AddAction(void_delegate&& action);
	void Invoke();

	Action<Container> operator+=(void_delegate* action);
	Action<Container> operator()();

protected:
	std::vector<void_delegate> invokables_;
};

template<class Container>
inline Action<Container>::Action()
{
}

template<class Container>
inline Action<Container>::~Action()
{
}

template<class Container>
inline void Action<Container>::AddAction(void_delegate&& action)
{
	this->invokables_.push_back(action);
}

template<class Container>
inline void Action<Container>::Invoke()
{
	for (void_delegate& invokable : this->invokables_)
	{
		invokable;
	}
}

template<class Container>
inline Action<Container> Action<Container>::operator+=(void_delegate* action)
{
	this->invokables_.push_back(action);
}

template<class Container>
inline Action<Container> Action<Container>::operator()()
{
	for (auto* invokable : this->invokables_)
	{
		(*this).*invokable();
	}
}
