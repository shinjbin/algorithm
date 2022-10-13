#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minCostPath' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. WEIGHTED_INTEGER_GRAPH g
 *  2. INTEGER x
 *  3. INTEGER y
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

int dijkstra(int start, int end, vector<vector<pair<int, int>>> AL)
{
    vector<int> distance(AL.size(), INT32_MAX);
    distance[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        int weight = pq.top().first;
        int from = pq.top().second;
        if (from == end)
            break;
        pq.pop();

        for (auto i : AL[from])
        {
            int next = i.second;
            int next_w = weight + i.first;

            if (distance[next] > next_w)
            {
                distance[next] = next_w;
                pq.push({next_w, next});
            }
        }
    }
    return distance[end];
}

int minCostPath(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight, int x, int y)
{
    vector<vector<pair<int, int>>> AL(g_nodes + 1);
    for (int i = 0; i < g_from.size(); i++)
    {
        AL[g_from[i]].push_back({g_weight[i], g_to[i]});
        AL[g_to[i]].push_back({g_weight[i], g_from[i]});
    }

    int first = dijkstra(1, x, AL);
    int second = dijkstra(x, y, AL);
    int third = dijkstra(y, g_nodes, AL);

    return first + second + third;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++)
    {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    string x_temp;
    getline(cin, x_temp);

    int x = stoi(ltrim(rtrim(x_temp)));

    string y_temp;
    getline(cin, y_temp);

    int y = stoi(ltrim(rtrim(y_temp)));

    int result = minCostPath(g_nodes, g_from, g_to, g_weight, x, y);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
