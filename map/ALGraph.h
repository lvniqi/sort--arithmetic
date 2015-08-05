#pragma once
#include <iostream>
#include "VertexNode.h"
#include "Graph.h"
using namespace std;
#define MaxVeryexNum 100
typedef int WeightType;
typedef int VertexType;
//�߽ڵ�
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
	VertexType adjvex;//�յ�
	WeightType weight;//Ȩ��
	arcNode* next;//��һ����
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
	//�ڴ��ʼ��
	void initMemory() {
		memset(vex, 0, sizeof(VertexNode_AL)*MaxVeryexNum);
	}
	//ȷ������
	bool isConnect(int x, int y);
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
	//�ڽӱ�
	VertexNode_AL vex[MaxVeryexNum];
	int MaxNum = MaxVeryexNum;
};
#undef MaxVeryexNum