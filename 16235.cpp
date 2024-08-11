#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring> 

#define ll long long
#define MAX 987654321
#define MIN -987654321 

#define FOR(n) for(int i = 1; i <= n; i++)
#define FOR2(n) for(int j = 1; j <= n; j ++)
#define FOR3(n) for(int k = 1; k <= n; k++)

using namespace std; 


typedef struct Tree{
    int age=1; 
    bool bornThisYear = true; 
}Tree;
typedef struct Node{
    int nutrnt=5;
    // vector <Tree*> trees; 
    Tree ** trees; 
    int treeCnt = 0; 
}Node; 

bool compare(Tree *a, Tree *b)
{
    return a->age > b->age; 
}

void solve()
{
    int N, M, K; 
    int A[11][11]; 
    Node nodes[11][11]; 

    cin >> N >> M >> K;
    FOR(N)
    {
        FOR2(N)
        {
            cin >> A[i][j]; 
            nodes[i][j].trees = new Tree* [1000];
        }
    }

    int x, y, age; 
    FOR(M)
    {
        cin >> x >> y >> age;
        Tree *tree = new Tree; 
        tree->age = age; 
        tree->bornThisYear = false; 
        nodes[x][y].trees[nodes[x][y].treeCnt++] = tree; 
    }
    for (int k = 0; k < K; k++)
    // while(K--)
    {
        // 봄, 여름 
        FOR(N)
        {
            FOR2(N)
            {
                // 봄
                Node * node = &nodes[i][j];
                if (k == 0) // 0년차에만 정렬을 한다.
                    sort(node->trees, node->trees + node->treeCnt, compare) ;

                
                int dead_tree_nutrnt = 0; 
                int idx = 0; 
                vector <int> dead_trees; 
                int l; 
                bool deadTreeFlag = false; 
                int lastLivingTreeIdx=0;  
                int livingTreeCnt = 0; 
                for (l = node->treeCnt-1; l >= 0; l -=1)
                {
                    if(node->trees[l]->bornThisYear == true)
                    {
                        node->trees[l]->bornThisYear = false; 
                        livingTreeCnt += 1; 
                        continue; 
                    } 
                    if (node->nutrnt >= node->trees[l]->age)
                    {
                        node->nutrnt -= node->trees[l]->age;
                        node->trees[l]->age += 1; 
                        livingTreeCnt += 1; 
                    } 
                    else 
                    {
                        if (!deadTreeFlag)
                        {
                            lastLivingTreeIdx = l+1; 
                            deadTreeFlag = true;
                        }
                        dead_tree_nutrnt += node->trees[l]->age / 2; 
                    }
                }    
                if (!deadTreeFlag)
                    lastLivingTreeIdx = 0;

                
                Tree ** new_trees = new Tree*[1000];
                if (livingTreeCnt != 0)
                    memcpy(new_trees, &node->trees[lastLivingTreeIdx], sizeof(Tree*)* livingTreeCnt); 
                delete[] node->trees; 
                node->trees = new_trees; 
                node->treeCnt = livingTreeCnt; 
                node->nutrnt += dead_tree_nutrnt; 
 
        
                // Fall&Winter Integrated version.  
                int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; 
                int dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};     
                for (int v = 0; v < node->treeCnt; v++)
                // for (Tree * tree: node->trees)
                {
                    Tree * tree = node->trees[v]; 
                    if (tree->age % 5 == 0)
                    {
                        for(int c = 0; c < 8; c++)
                        {
                            int ni = i + di[c]; 
                            int nj = j + dj[c]; 
                            if (ni >= 1 && ni <= N && nj >= 1 && nj <= N)
                            {
                                Tree *new_tree = new Tree; 
                                // nodes[ni][nj].trees.push_back(new_tree);        
                                nodes[ni][nj].trees[nodes[ni][nj].treeCnt] = new_tree; 
                                nodes[ni][nj].treeCnt += 1; 
                                // printf("%d %d | %d %d %d\n", i, j, ni, nj, nodes[ni][nj].treeCnt);
                            }
                        }        
                    }
                }
                //겨울 
                nodes[i][j].nutrnt += A[i][j]; 
            

                // Following codes should be comment out. 
                /*
                for(Tree* tree: nodes[i][j].trees)
                {
                    if (node->nutrnt >= tree->age)
                    {
                        node->nutrnt -= tree->age; 
                        tree->age += 1;          
                    } 
                    else{
                        dead_trees.push_back(idx); 
                        dead_tree_nutrnt += tree->age/2; 
                    }
                    idx += 1; 
                }
                // 여름
                for (int k = 0; k < dead_trees.size(); k++)
                // for(int k = dead_trees.size()-1; k >=0; k-=1)
                {
                    node->trees.pop_back(); 
                    // node->trees.erase(node->trees.begin() + dead_trees[k]); 
                }
                node->nutrnt += dead_tree_nutrnt; 
                */
                // Above code should be comment out. 
            }
        }
    }

    int ans = 0; 
    FOR(N)
    {
        FOR2(N)
        {
            // ans += nodes[i][j].trees.size(); 
            ans += nodes[i][j].treeCnt; 
        }
    }
    cout << ans; 

    return; 
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false); 
    solve(); 
    return 0; 
}