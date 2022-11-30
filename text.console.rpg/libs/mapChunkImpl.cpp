#include "stdafx.h"
#include "mapChunk.h"

template <class T>
class MapChunk<T>::Impl { };

template <class T>
MapChunk<T>::MapChunk(const T& ptrObj) : d_(std::make_unique<Impl>()), m_obj{ ptrObj } { };
template <class T>
MapChunk<T>::~MapChunk() { };

template <class T>
T &MapChunk<T>::getObj() const { return m_obj; };

template <class T>
void MapChunk<T>::setObj(const T &obj) { m_obj = obj; };