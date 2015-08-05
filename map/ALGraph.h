#pragma once
#include <iostream>
#include "VertexNode.h"
#include "Graph.h"
using namespace std;
#define MaxVeryexNum 100
typedef int WeightType;
typedef int VertexType;
//边节点
class arcNode {
public:
	void setWeight(WeightType weight) {
		this->weight = weight;
	}
	void setNext(arcNode* p) {
		next = p;
	}
	void setEnd(VertexType end) {
		adjvex = end;
	}
	VertexType getEnd() {
		return adjvex;
	}
	WeightType getWeight() {
		return weight;
	}
	arcNode* getNext() {
		return next;
	}
private:
	VertexType adjvex;//终点
	WeightType weight;//权重
	arcNode* next;//下一条边
};

class VertexNode_AL : public VertexNode {
public:
	arcNode* getFirst() {
		return first;
	}
	void setFirst(arcNode* p) {
		first = p;
	}
private:
	arcNode* first;
};


class ALGraph : public Graph{
public:
	ALGraph(bool isDirection) : Graph(isDirection) { initMemory(); };
	//内存初始化
	void initMemory() {
		memset(vex, 0, sizeof(VertexNode_AL)*MaxVeryexNum);
	}
	//确认相连
	bool isConnect(int x, int y);
	//查找相邻节点
	int* getNeighbors(int x);
	//插入节点
	void addVertex(int x, VertexType data);
	//删除节点
	bool removeVertex(int x);
	//添加边
	void addEdge(int x, int y, WeightType weight);
	//删除边
	bool removeEdge(int x, int y);
	//设置边权值
	bool setEdgeValue(int x, int y, WeightType v);
	//得到边权值
	WeightType getEdgeValue(int x, int y);
	//显示
	void show();
private:
	//邻接表
	VertexNode_AL vex[MaxVeryexNum];
	int MaxNum = MaxVeryexNum;
};
#undef MaxVeryexNum