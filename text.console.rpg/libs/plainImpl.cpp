#include "stdafx.h"

#include "plain.h"

class Plain::Impl { };

Plain::Plain(int posX, int posY): d_(std::make_unique<Impl>()), 
	MapObj(posX, posY, m_id) { }
Plain::~Plain() { }

char Plain::getId() const { return m_id; }
const char* Plain::getClass() const { return typeid(Plain).name(); }

void Plain::setId(char id) { m_id = id; }