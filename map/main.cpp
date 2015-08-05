#include"MGragh.h"
#include"ALGraph.h"
int main(void) {
	//MGragh t(false);
	ALGraph t(false);
	t.addVertex(1,12);
	t.addVertex(2,32);
	t.addVertex(3,45);
	t.addVertex(4,34);
	t.addVertex(5,21);
	for (int i = 0; i < 5; i++) {
		for (int j = i; j < 5; j++) {
			t.addEdge(i, j, i);
		}
	}
	t.show();
	t.removeEdge(1, 4);
	t.show();
	t.removeVertex(3);
	t.show();
	getchar();
}