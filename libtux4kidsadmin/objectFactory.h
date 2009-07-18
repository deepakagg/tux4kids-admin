///////////////////////////////////////////////////////////////////////////////
//
// The folowing implementation is based on Robert Geiman's ideas published on:
// http://www.gamedev.net/reference/articles/article841.asp
//
///////////////////////////////////////////////////////////////////////////////
//
// ObjectFactory
//
// The ObjectFactory class is a object factory implementation.  It allows users
// to register and unregister classes during run-time by specifying a
// user-defined unique identifier per class.  Instances of any registered class
// can then be instantiated simply by calling the create method and passing the
// proper unique identifier.
//
///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2004 Robert Geiman.
//
// Permission to copy, modify, and use this code for personal and commercial
// software is granted provided this copyright notice appears in all copies.
// This software is provided "as is" without any expressed or implied warranty.
//
// Any comments or questions can be sent to: rgeiman@buckeye-express.com
//
///////////////////////////////////////////////////////////////////////////////

#ifndef OBJECT_FACTORY_H
#define OBJECT_FACTORY_H

#include <QMap>
#include <QDebug>

/****************************** 0 parameters *************************/

template <typename CtorSignature, typename UniqueIdType> class ObjectFactory;

template<typename BaseClassType, typename ClassType>
BaseClassType *CreateObject()
{
	return new ClassType();
}

template<typename BaseClassType, typename UniqueIdType>
class ObjectFactory<BaseClassType (), UniqueIdType>
{
protected:
	typedef BaseClassType *(*CreateObjectFunc)();

public:
	template<typename ClassType>
	bool registerType(UniqueIdType uniqueId)
	{
		if (m_objectCreator.contains(uniqueId))
			return false;
		m_objectCreator[uniqueId] = &CreateObject<BaseClassType, ClassType>;
			return true;
	}

	bool unregisterType(UniqueIdType uniqueId)
	{
		return (m_objectCreator.remove(uniqueId) >= 1);
	}

	BaseClassType *create(UniqueIdType uniqueId)
	{
		if (!m_objectCreator.contains(uniqueId))
			return 0;
		else
			return m_objectCreator[uniqueId]();
	}

protected:
	QMap <UniqueIdType, CreateObjectFunc> m_objectCreator;
};

/****************************** 1 parameter *************************/

template<typename BaseClassType, typename Param1Type, typename ClassType>
BaseClassType *CreateObject(Param1Type param1)
{
	return new ClassType(param1);
}

template<typename BaseClassType, typename Param1Type, typename UniqueIdType>
class ObjectFactory<BaseClassType (Param1Type), UniqueIdType>
{
protected:
	typedef BaseClassType *(*CreateObjectFunc)(Param1Type);

public:

	template<typename ClassType>
	bool registerType(UniqueIdType uniqueId)
	{
		if (m_objectCreator.contains(uniqueId))
			return false;
		m_objectCreator[uniqueId] = &CreateObject<BaseClassType, Param1Type, ClassType>;
			return true;
	}

	bool unregisterType(UniqueIdType uniqueId)
	{
		return (m_objectCreator.remove(uniqueId) >= 1);
	}

	BaseClassType *create(UniqueIdType uniqueId, Param1Type param1)
	{
		if (!m_objectCreator.contains(uniqueId))
			return 0;
		else
			return m_objectCreator[uniqueId](param1);
	}

protected:
	QMap <UniqueIdType, CreateObjectFunc> m_objectCreator;

};

/****************************** 2 parameters *************************/

template<typename BaseClassType, typename Param1Type, typename Param2Type, typename ClassType>
BaseClassType *CreateObject(Param1Type param1, Param2Type param2)
{
	return new ClassType(param1, param2);
}

template<typename BaseClassType, typename Param1Type, typename Param2Type, typename UniqueIdType>
class ObjectFactory<BaseClassType (Param1Type, Param2Type), UniqueIdType>
{
protected:
	typedef BaseClassType *(*CreateObjectFunc)(Param1Type, Param2Type);

public:

	template<typename ClassType>
	bool registerType(UniqueIdType uniqueId)
	{
		if (m_objectCreator.contains(uniqueId))
			return false;
		m_objectCreator[uniqueId] = &CreateObject<BaseClassType, Param1Type, Param2Type, ClassType>;
			return true;
	}

	bool unregisterType(UniqueIdType uniqueId)
	{
		return (m_objectCreator.remove(uniqueId) >= 1);
	}

	BaseClassType *create(UniqueIdType uniqueId, Param1Type param1, Param2Type param2)
	{
		if (!m_objectCreator.contains(uniqueId)) {
			return 0;
		} else {
			BaseClassType *tmp = (m_objectCreator[uniqueId])(param1, param2);
			return tmp;
		}
	}

protected:
	QMap <UniqueIdType, CreateObjectFunc> m_objectCreator;
};

#endif

