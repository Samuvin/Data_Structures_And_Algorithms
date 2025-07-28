/**
You and some monsters are in a labyrinth. When taking a step to some direction in the labyrinth, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.
Your task is to find out if your goal is possible, and if it is, print a path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.

Input
The first input line has two integers n and m: the height and width of the map.
After this there are n lines of m characters describing the map. Each character is . (floor), # (wall), A (start), or M (monster). There is exactly one A in the input.
Output
First print "YES" if your goal is possible, and "NO" otherwise.
If your goal is possible, also print an example of a valid path (the length of the path and its description using characters D, U, L, and R). You can print any path, as long as its length is at most n \cdot m steps.

Example
Input:
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

Output:
YES
5
RRDDR
**/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int n, m;
vector<string> maze;
vector<vector<int>> distMonster, distPlayer;
vector<int> dirR = {1, 0, -1, 0}, dirC = {0, 1, 0, -1};
string directions = "DRUL";    // Down, Right, Up, Left
vector<vector<int>> direction; // for path reconstruction
int closestDist = INT_MAX, closestRow = -1, closestCol = -1;

bool isPathValid(int nextR, int nextC, int r, int c, vector<vector<int>> &dist)
{
    return nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && maze[nextR][nextC] != '#' && dist[r][c] + 1 < dist[nextR][nextC];
}

void multiSourceBfs(queue<pair<int, int>> &q, vector<vector<int>> &dist)
{
    int dirSize = dirR.size();
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < dirSize; i++)
        {
            int nextR = r + dirR[i];
            int nextC = c + dirC[i];
            if (isPathValid(nextR, nextC, r, c, dist))
            {
                dist[nextR][nextC] = dist[r][c] + 1;
                direction[nextR][nextC] = i; // store direction for path reconstruction
                q.push({nextR, nextC});
            }
        }
    }
}

void retracePath(int r, int c, int personR, int personC, vector<vector<int>> &dist, string &path)
{
    while (r != personR || c != personC)
    {
        int dir = direction[r][c];
        path += directions[dir];
        r -= dirR[dir];
        c -= dirC[dir];
    }
    reverse(path.begin(), path.end());
}

void checkBoundary(int r, int c)
{
    if (maze[r][c] != '#' && distPlayer[r][c] < distMonster[r][c] && distPlayer[r][c] < closestDist)
    {
        closestDist = distPlayer[r][c];
        closestRow = r;
        closestCol = c;
    }
}

int main()
{
    cin >> n >> m;

    maze.resize(n);
    distMonster.resize(n, vector<int>(m, INT_MAX));
    distPlayer.resize(n, vector<int>(m, INT_MAX));
    direction.resize(n, vector<int>(m, -1));

    queue<pair<int, int>> q;
    int personR, personC;
    for (int i = 0; i < n; i++)
    {
        cin >> maze[i];
        for (int j = 0; j < maze[i].length(); j++)
        {
            if (maze[i][j] == 'M')
            {
                q.push({i, j});
                distMonster[i][j] = 0;
            }
            else if (maze[i][j] == 'A')
            {
                distPlayer[i][j] = 0;
                personR = i;
                personC = j;
            }
        }
    }

    // BFS for monsters
    multiSourceBfs(q, distMonster);

    // BFS for player
    q.push({personR, personC});
    multiSourceBfs(q, distPlayer);

    // check border cells
    for (int i = 0; i < n; i++)
    {
        checkBoundary(i, 0);
        checkBoundary(i, m - 1);
    }

    for (int j = 0; j < m; j++)
    {
        checkBoundary(0, j);
        checkBoundary(n - 1, j);
    }

    if (closestDist == INT_MAX)
    {
        cout << "NO" << "\n";
    }
    else
    {
        cout << "YES" << "\n";
        cout << closestDist << "\n";

        // Reconstruct path
        string path = "";
        retracePath(closestRow, closestCol, personR, personC, distPlayer, path);
        cout << path << "\n";
    }

    return 0;
}

// ------------------------------------------------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int n, m;
vector<string> maze;
vector<vector<int>> distMonster, distPlayer;
vector<int> dirR = {1, 0, -1, 0}, dirC = {0, 1, 0, -1};
string directions = "DRUL";    // Down, Right, Up, Left
vector<vector<int>> direction; // for path reconstruction
int closestDist = INT_MAX, closestRow = -1, closestCol = -1;
bool isPersonBfs = false;
bool isPathFound = false;
string validPath = "";
int personR, personC;

bool isPathValid(int nextR, int nextC, int r, int c, vector<vector<int>> &dist)
{
    return nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && maze[nextR][nextC] != '#' && dist[r][c] + 1 < dist[nextR][nextC];
}

bool checkIsPersonBfs(int r, int c)
{
    if (!isPersonBfs)
        return false;

    // Only accept if it's on the boundary AND monster can't reach before or at the same time
    return (r == 0 || c == 0 || r == n - 1 || c == m - 1) && distPlayer[r][c] < distMonster[r][c];
}

void retracePath(int r, int c, int personR, int personC, vector<vector<int>> &dist, string &path)
{
    while (r != personR || c != personC)
    {
        int dir = direction[r][c];
        path += directions[dir];
        r -= dirR[dir];
        c -= dirC[dir];
    }
    reverse(path.begin(), path.end());
}

void multiSourceBfs(queue<pair<int, int>> &q, vector<vector<int>> &dist)
{
    int dirSize = dirR.size();
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (checkIsPersonBfs(r, c))
        {
            isPathFound = true;
            validPath = "";
            retracePath(r, c, personR, personC, distPlayer, validPath);
            return;
        }

        for (int i = 0; i < dirSize; i++)
        {
            int nextR = r + dirR[i];
            int nextC = c + dirC[i];
            if (isPathValid(nextR, nextC, r, c, dist))
            {
                dist[nextR][nextC] = dist[r][c] + 1;
                if (isPersonBfs)
                    direction[nextR][nextC] = i; // store direction for path reconstruction
                q.push({nextR, nextC});
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    maze.resize(n);
    distMonster.resize(n, vector<int>(m, INT_MAX));
    distPlayer.resize(n, vector<int>(m, INT_MAX));
    direction.resize(n, vector<int>(m, -1));
    validPath = "";
    isPathFound = false;
    isPersonBfs = false;
    personR = -1;
    personC = -1;
    closestDist = INT_MAX;

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        cin >> maze[i];
        for (int j = 0; j < maze[i].length(); j++)
        {
            if (maze[i][j] == 'M')
            {
                q.push({i, j});
                distMonster[i][j] = 0;
            }
            else if (maze[i][j] == 'A')
            {
                distPlayer[i][j] = 0;
                personR = i;
                personC = j;
            }
        }
    }

    // BFS for monsters
    multiSourceBfs(q, distMonster);

    // BFS for player
    isPersonBfs = true;
    q.push({personR, personC});
    multiSourceBfs(q, distPlayer);
    if (!isPathFound)
    {
        cout << "NO" << "\n";
    }
    else
    {
        cout << "YES" << "\n";
        cout << validPath.length() << "\n";
        cout << validPath << "\n";
    }

    return 0;
}