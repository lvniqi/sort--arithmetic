#pragma once
typedef int VertexType;
class VertexNode{
public:
	bool isUsed() {
		return  isuse;
	}
	VertexType getData() {
		return data;
	}
	void setUsed(bool f) {
		this->isuse = f;
	}
	void setData(VertexType d) {
		data = d;
	}
private:
	VertexType data;
	bool isuse;
};