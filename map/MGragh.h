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
	//�ڴ��ʼ��
	void initMemory() {
		memset(edge, -1, sizeof(EdgeType)*MaxVeryexNum*MaxVeryexNum);
		memset(vex, 0, sizeof(VertexNode)*MaxVeryexNum);
	}
	//ȷ������
	bool isConnect(int x, int y);
	//�õ������Ľڵ�
	int* getConnects(int x);
	//�������ڽڵ�
	int* getNeighbors(int x);
	//����ڵ�
	void addVertex(int x, VertexType data);
	//ɾ���ڵ�
	bool removeVertex(int x);
	//��ӱ�
	void addEdge(int x, int y, WeightType weight);
	//ɾ����
	bool removeEdge(int x, int y);
	//���ñ�Ȩֵ
	bool setEdgeValue(int x, int y, WeightType v);
	//�õ���Ȩֵ
	WeightType getEdgeValue(int x, int y);
	//��ʾ
	void show();
private:
	int MaxNum = MaxVeryexNum;
	VertexNode vex[MaxVeryexNum];
	EdgeType edge[MaxVeryexNum][MaxVeryexNum];
};
#undef MaxVeryexNum