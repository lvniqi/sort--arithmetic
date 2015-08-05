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
	//�ڴ��ʼ��
	virtual void initMemory() = 0;
	//ȷ������
	virtual bool isConnect(int x, int y) = 0;
	//�������ڽڵ�
	virtual int* getNeighbors(int x) = 0;
	//����ڵ�
	virtual void addVertex(int x, VertexType data) = 0;
	//ɾ���ڵ�
	virtual bool removeVertex(int x) = 0;
	//��ӱ�
	virtual void addEdge(int x, int y, WeightType weight) = 0;
	//ɾ����
	virtual bool removeEdge(int x, int y) = 0;
	//���ñ�Ȩֵ
	virtual bool setEdgeValue(int x, int y, WeightType v) = 0;
	//�õ���Ȩֵ
	virtual WeightType getEdgeValue(int x, int y) = 0;
	//��ʾ
	virtual void show() = 0;
protected:
	//�Ƿ�Ϊ����ͼ
	bool isDirection;
	//�������
	int vex_len;
	//�߸���
	int edge_len;
};