#pragma once
#define MaxVeryexNum 100
typedef int VertexType;
typedef int WeightType;
typedef WeightType EdgeType;
class Graph {
public:
	Graph(bool isDirection) {
		this->isDirection = isDirection;
		vex_len = 0;
		edge_len = 0;
	}
	//内存初始化
	virtual void initMemory() = 0;
	//确认相连
	virtual bool isConnect(int x, int y) = 0;
	//查找相邻节点
	virtual int* getNeighbors(int x) = 0;
	//插入节点
	virtual void addVertex(int x, VertexType data) = 0;
	//删除节点
	virtual bool removeVertex(int x) = 0;
	//添加边
	virtual void addEdge(int x, int y, WeightType weight) = 0;
	//删除边
	virtual bool removeEdge(int x, int y) = 0;
	//设置边权值
	virtual bool setEdgeValue(int x, int y, WeightType v) = 0;
	//得到边权值
	virtual WeightType getEdgeValue(int x, int y) = 0;
	//显示
	virtual void show() = 0;
protected:
	//是否为有向图
	bool isDirection;
	//定点个数
	int vex_len;
	//边个数
	int edge_len;
};