//#include "Head.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <map>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(typeof(x.begin()) e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define MAXN (1e6)
typedef long long LL;
const int INF = ~0U>>1, MOD = ~0U>>1;

typedef enum { ROUTE, WALL, START, END, AVAILABLE } Status;
typedef enum { UNKNOW, EAST, SOUTH, WEST, NORTH, ABOVE, BELOW, NO_WAY } DIRECTION;
inline DIRECTION nextDir ( DIRECTION dir ) { return DIRECTION ( dir + 1 ); }

struct Cell {
    int x, y, z, steps;
    Status status;
    DIRECTION outgoing;
};

#define LABY_MAX 30
Cell laby[LABY_MAX][LABY_MAX][LABY_MAX];
int x, y, z; int ans; Cell* start; char c;

inline bool isValidNeighbor ( Cell* cell ) {
    switch ( cell->outgoing ) {
        case ABOVE: return cell->z < z - 1;
        case SOUTH: return cell->x < x - 1;
        case EAST : return cell->y < y - 1;
        case BELOW: return cell->z > 0;
        case NORTH: return cell->x > 0;
        case WEST : return cell->y > 0;
        default   : exit(-1);
    }
}

inline Cell* neighbor ( Cell* cell ) {
    switch ( cell->outgoing ) {
        case ABOVE: return cell + LABY_MAX * LABY_MAX;
        case SOUTH: return cell + LABY_MAX;
        case EAST : return cell + 1;
        case BELOW: return cell - LABY_MAX * LABY_MAX;
        case NORTH: return cell - LABY_MAX;
        case WEST : return cell - 1;
        default   : exit(-1);
    }
}

int labyrinth ( Cell* start )
{
    queue<Cell*> path; start->status = ROUTE; path.push ( start );
    do {
        Cell* c = path.front(); path.pop();
        while ( ( c->outgoing = nextDir ( c->outgoing ) ) < NO_WAY )
            if ( isValidNeighbor(c) && END <= neighbor(c)->status ){
                neighbor(c)->steps = c->steps + 1;
                if ( neighbor(c)->status == END ) return neighbor(c)->steps;
                neighbor(c)->status = ROUTE;
                path.push( neighbor(c) );
            }
    } while ( !path.empty() );
    return false;
}

int main()
{
    while ( cin >> z >> x >> y, z ) {
        for ( int i = 0; i < z; i++ ) {
            for ( int j = 0; j < x; j++ ) {
                for ( int k = 0; k < y; k++ ) {
                    cin >> c;
                    if ( c == 'S' ) { start = &laby[i][j][k]; laby[i][j][k].status = START; }
                    else if ( c == 'E' ) laby[i][j][k].status = END;
                    else if ( c == '.' ) laby[i][j][k].status = AVAILABLE;
                    else                 laby[i][j][k].status = WALL;
                    laby[i][j][k].z = i; laby[i][j][k].x = j; laby[i][j][k].y = k;
                    laby[i][j][k].steps = 0; laby[i][j][k].outgoing = UNKNOW;
                }
                cin.get();
            }
            cin.get();
        }
        if ( !(ans = labyrinth ( start ) ) ) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", ans);
    }
}
