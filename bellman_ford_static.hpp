#include <queue>
#include <vector>

using namespace std;

template <class T>
class BellmanFord
{
public:
	static const int maxn = 100000;

	class Edge
	{
	public:
		int u, v;
		T w;

		Edge(void) : u(0), v(0), w(0)
		{

		}

		Edge(const int & u, const int & v, const T & w) : u(u), v(v), w(w)
		{

		}
	};

	int n;
	vector<Edge> e[maxn];
	T d[maxn];
	bool inq[maxn];
	int cnt[maxn];

	BellmanFord(void) : n(0)
	{

	}

	void resize(const int & n)
	{
		for (int i = 0; i < this->n; i++)
			e[i].clear();
		this->n = n;
	}

	void add_edge(const int & u, const int & v, const T & w)
	{
		e[u].emplace_back(u, v, w);
	}

	bool bellman_ford(void)
	{
		queue<int> que;
		memset(d, 0, sizeof d[0] * n);
		memset(inq, true, sizeof inq[0] * n);
		memset(cnt, 0, sizeof cnt[0] * n);
		for (int i = 0; i < n; i++)
			que.push(i);
		for (; !que.empty(); que.pop())
		{
			int u = que.front();
			inq[u] = false;
			for (const auto & edge : e[u])
			{
				int v = edge.v;
				T w = edge.w;
				if(d[v] > d[u] + w)
				{
					d[v] = d[u] + w;
					if(!inq[v])
					{
						cnt[v]++;
						if (cnt[v] >= n)
							return true;
						que.push(v);
						inq[v] = true;
					}
				}
			}
		}
		return false;
	}
};
