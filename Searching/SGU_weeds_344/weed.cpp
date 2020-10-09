//344. Weed
//http://acm.sgu.ru/problem.php?contest=0&problem=344

#include<bits/stdc++.h>

using namespace std;

int grid[1000][1000];
queue< pair<int, int> > weeds;
int cntr = 0, m, n;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};


void push(int i, int j){
	weeds.push(make_pair(i, j));
	cntr ++;
}

bool isValid(int i, int j)
{
	if ( i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 2)
		return false;
	return true;
}


void bfs(){
	while(weeds.size() != 0)
	{
		pair<int, int> poped = weeds.front();
		weeds.pop();
		for (int i = 0; i < 4; i++)
		{
			if (isValid(poped.first + dx[i] , poped.second + dy[i]))
			{
				grid[poped.first + dx[i]][poped.second + dy[i]] ++;
				if (grid[poped.first + dx[i]][poped.second + dy[i]] == 2)
					push(poped.first + dx[i], poped.second + dy[i]);
			}
		}
	}
}

int main()
{
	memset(grid, 0, sizeof grid);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == 'X'){
				grid[i][j] = 2;
				push(i,j);	
			}
		}
	}
	bfs();
	cout << cntr << endl;	
}
