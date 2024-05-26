#include <queue>
#include <vector>

using namespace std;

template <class T>
class BellmanFord
{
public:
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
	vector<vector<Edge> > e;
	vector<T> d;
	vector<bool> inq;
	vector<int> cnt;

	BellmanFord(void) : n(0)
	{

	}

	void resize(const int & n)
	{
		this->n = n;
		e.clear();
		e.resize(n);
		d.resize(n);
		inq.resize(n);
		cnt.resize(n);
	}

	void add_edge(const int & u, const int & v, const T & w)
	{
		e[u].emplace_back(u, v, w);
	}

	bool bellman_ford(void)
	{
		queue<int> que;
		fill(d.begin(), d.end(), 0);
		fill(inq.begin(), inq.end(), true);
		fill(cnt.begin(), cnt.end(), 0);
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
