#include"ALGraph.h"
bool ALGraph::isConnect(int x, int y) {
	arcNode* p = vex[x].getFirst();
	while (p) {
		if (p->getEnd() == y) {
			return true;
		}
		p = p->getNext();
	}
	p = vex[y].getFirst();
	while (p) {
		if (p->getEnd() == x) {
			return true;
		}
		p = p->getNext();
	}
	return false;
}
//输出格式：长度，各个相连的节点
int* ALGraph::getNeighbors(int x) {
	int* result = (int*)malloc(sizeof(int)*(vex_len + 1));
	memset(result, 0, sizeof(int)*(vex_len + 1));
	int* data_start = result + 1;
	arcNode* p = vex[x].getFirst();
	while (p) {
		*(result++) = p->getEnd();
		p = p->getNext();
	}
	*result = (data_start - result - 1);
	return result;
}
void ALGraph::addVertex(int x, VertexType data) {
	if (!(vex[x].isUsed())) {
		vex_len++;
		vex[x].setData(data);
		vex[x].setUsed(true);
	}
}
bool ALGraph::removeVertex(int x) {
	if (vex[x].isUsed()) {
		int pop_len = 0;
		//移除当前顶点的边
		arcNode* p = vex[x].getFirst();
		while (p) {
			arcNode* t = p;
			p = p->getNext();
			if (t->getEnd() == x) {
				pop_len += 2;
			}
			else {
				pop_len++;
			}
			free(t);
		}
		vex[x].setFirst(NULL);
		//移除所有边
		for (int i = 0; i < MaxNum;i++){
			p = vex[i].getFirst();
			arcNode* last = NULL;
			while (p) {
				if (p->getEnd() == x) {
					if (last) {
						last->setNext(p->getNext());
					}
					else {
						vex[i].setFirst(p->getNext());
					}
					free(p);
					pop_len++;
					break;
				}
				last = p;
				p = p->getNext();
			}
		}
		if(!isDirection){
			edge_len -= pop_len / 2;
		}
		else {
			edge_len -= pop_len;
		}
		vex_len--;
		vex[x].setUsed(false);
		return true;
	}
	else {
		return false;
	}
}

void ALGraph::addEdge(int x, int y, WeightType weight) {
	if (vex[x].isUsed() && vex[y].isUsed()) {
		//如果已存在 直接弹出
		arcNode* p = vex[x].getFirst();
		while (p) {
			if (p->getEnd() == y) {
				return;
			}
			p = p->getNext();
		}
		edge_len++;
		arcNode* now = (arcNode*)malloc(sizeof(arcNode));
		now->setEnd(y);
		now->setNext(vex[x].getFirst());
		now->setWeight(weight);
		vex[x].setFirst(now);
		if (!isDirection&&x!=y) {
			arcNode* now = (arcNode*)malloc(sizeof(arcNode));
			now->setEnd(x);
			now->setNext(vex[y].getFirst());
			now->setWeight(weight);
			vex[y].setFirst(now);
		}
	}
}
bool ALGraph::setEdgeValue(int x, int y, WeightType v) {
	arcNode* p = vex[x].getFirst();
	while (p) {
		if (p->getEnd() == y) {
			p->setWeight(v);
			if (!isDirection) {
				p = vex[y].getFirst();
				while (p) {
					if (p->getEnd() == x) {
						p->setWeight(v);
						return true;
					}
					p = p->getNext();
				}
			}
			return true;
		}
		p = p->getNext();
	}
	return false;
}
WeightType ALGraph::getEdgeValue(int x, int y) {
	arcNode* p = vex[x].getFirst();
	while (p) {
		if (p->getEnd() == y) {
			return p->getWeight();
		}
		p = p->getNext();
	}
	return -1;
}
bool ALGraph::removeEdge(int x, int y) {
	arcNode* p = vex[x].getFirst();
	arcNode* last = NULL;
	while (p) {
		//找到y
		if (p->getEnd() == y) {
			if (last) {
				last->setNext(p->getNext());
				free(p);
			}
			else {
				vex[x].setFirst(p->getNext());
				free(p);
			}
			//无向图
			if (!isDirection) {
				p = vex[y].getFirst();
				last = NULL;
				while (p) {
					//找到x
					if (p->getEnd() == x) {
						if (last) {
							last->setNext(p->getNext());
							free(p);
						}
						else {
							vex[y].setFirst(p->getNext());
							free(p);
						}
						edge_len--;
						return true;
					}
					last = p;
					p = p->getNext();
				}
			}
			edge_len--;
			return true;
		}
		p = p->getNext();
	}
	return false;
}
void ALGraph::show() {
	cout << "-----vex:" << vex_len << "------" << endl;
	for (int i = 0; i < MaxNum; i++) {
		if (vex[i].isUsed()) {
			cout << i << ": " << vex[i].getData() << "  ";
		}
	}
	cout << endl << "-----edge:" << edge_len << "-----" << endl;
	for (int i = 0; i < MaxNum; i++) {
		arcNode* p = vex[i].getFirst();
		while (p) {
			cout << '<' << i << ',' << p->getEnd() << '>' << ": " << p->getWeight() << endl;
			p = p->getNext();
		}
	}
}