#include<algorithm>

void Init(int **&p,int n){//初始化，n为vector的个数,传入的p指向nullptr
	p = new int*[n];
	for(int i = 0; i < n; i++){
		p[i] = new int[2];
		p[i][0] = 0;
		p[i][1] = 0;
	}
}

void Add_element(int **&p,int x,int y){//在第x(1base)个vector后面添加一个元素y
	x--;
	if(p[x][0] >= p[x][1]){
		int *tmp = new int[(p[x][1] == 0 ? 1 : p[x][1] * 2) + 2];
		tmp[0] = p[x][0];
		tmp[1] = (p[x][1] == 0 ? 1 : p[x][1] * 2);
		for(int i = 0; i < p[x][0]; i++){
			tmp[i + 2] = p[x][i + 2];
		}
		delete[] p[x];
		p[x] = tmp;
	}
	p[x][p[x][0] + 2] = y;
	p[x][0]++;
}

int Get_element(int **&p,int x,int k){//获取第x(1base)个vector中第k个(1-base)元素的值
	return p[x - 1][k + 1];
}

void Clear(int **&p,int n){//回收空间
	for(int i = 0; i < n; i++){
		delete[] p[i];
	}
	delete[] p;
}
