#pragma once

#include "stdafx.h"

template <class T>
class MapChunk
{
private:
	T &m_obj;

	class Impl;
	std::unique_ptr<Impl> d_;
public:
	MapChunk(const T& ptrObj);
	~MapChunk();

	T &getObj() const;

	void setObj(const T &obj);
};