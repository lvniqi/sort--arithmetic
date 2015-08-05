#pragma once
#include "VertexNode.h"
#include "Graph.h"
#include <iostream>
using namespace std;
#define MaxVeryexNum 100
typedef int VertexType;
typedef int WeightType;
typedef WeightType EdgeType;
class MGragh: public Graph {
public:
	MGragh(bool isDirection) :Graph(isDirection) { initMemory(); };
	//内存初始化
	void initMemory() {
		memset(edge, -1, sizeof(EdgeType)*MaxVeryexNum*MaxVeryexNum);
		memset(vex, 0, sizeof(VertexNode)*MaxVeryexNum);
	}
	//确认相连
	bool isConnect(int x, int y);
	//得到相连的节点
	int* getConnects(int x);
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
	int MaxNum = MaxVeryexNum;
	VertexNode vex[MaxVeryexNum];
	EdgeType edge[MaxVeryexNum][MaxVeryexNum];
};
#undef MaxVeryexNum