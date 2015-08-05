#include "MGragh.h"
bool MGragh::isConnect(int x, int y) {
	if (edge[x][y] != -1) {
		return true;
	}
	else {
		return false;
	}
}
//�����ʽ�����ȣ����������Ľڵ�
int* MGragh::getConnects(int x) {
	int* result = (int*)malloc(sizeof(int)*(vex_len + 1));
	memset(result, 0, sizeof(int)*(vex_len + 1));
	int* data_start = result + 1;
	for (int i = 0; i < MaxNum; i++) {
		if ((edge[x][i] != -1 || edge[i][x] != -1) && vex[i].isUsed()) {
			*(data_start++) = i;
		}
	}
	*result = (data_start - result - 1);
	return result;
}
//�����ʽ�����ȣ����������Ľڵ�
int* MGragh::getNeighbors(int x) {
	int* result = (int*)malloc(sizeof(int)*(vex_len+1));
	memset(result, 0, sizeof(int)*(vex_len + 1));
	int* data_start = result + 1;
	for (int i = 0; i < MaxNum; i++) {
		if ((edge[x][i] != -1 )&& vex[i].isUsed()){
			*(data_start++) = i;
		}
	}
	*result = (data_start - result - 1);
	return result;
}
void MGragh::addVertex(int x, VertexType data) {
	if (!(vex[x].isUsed())) {
		vex_len++;
		vex[x].setUsed(true);
		vex[x].setData(data);
	}
}
bool MGragh::removeVertex(int x) {
	if (vex[x].isUsed()) {
		//�Ƴ����б�
		int*neighbors = getConnects(x);
		for (int i = 1; i <= neighbors[0]; i++) {
			removeEdge(x, neighbors[i]);
			removeEdge(neighbors[i],x);
		}
		free(neighbors);
		vex[x].setUsed(false);
		vex_len--;
		return true;
	}
	else {
		return false;
	}
}
void MGragh::addEdge(int x, int y, WeightType weight) {
	if (edge[x][y] == -1 && vex[x].isUsed()&& vex[y].isUsed()) {
		edge_len++;
		edge[x][y] = weight;
		if (!isDirection) {
			edge[y][x] = weight;
		}
	}
}
bool MGragh::setEdgeValue(int x, int y, WeightType v) {
	if (edge[x][y] != -1) {
		edge[x][y] = v;
		if (!isDirection) {
			edge[y][x] = v;
		}
		return true;
	}
	return false;
}
WeightType MGragh::getEdgeValue(int x, int y) {
	return edge[x][y];
}
bool MGragh::removeEdge(int x, int y) {
	if (edge[x][y] != -1) {
		edge_len--;
		edge[x][y] = -1;
		if (!isDirection) {
			edge[y][x] = -1;
		}
		return true;
	}
	return false;
}
void MGragh::show() {
	cout << "-----vex:"<<vex_len<<"------" << endl;
	for (int i = 0; i < MaxNum; i++) {
		if (vex[i].isUsed()) {
			cout << i << ": "<<vex[i].getData()<<"  ";
		}
	}
	cout << endl<<"-----edge:" << edge_len << "-----" <<endl;
	for (int i = 0; i < MaxNum; i++) {
		for (int j = 0; j < MaxNum; j++) {
			if (edge[i][j] != -1) {
				cout<<'<' << i << ','<<j<<'>'<<": "<<edge[i][j]<<endl;
			}
		}
	}
}