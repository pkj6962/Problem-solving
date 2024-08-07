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
}Tree;

struct compare{
    bool operator()(Tree * a, Tree * b)
    {
        return a->age > b->age; 
    }
};


typedef struct Node{
    int nutrnt=5;
    // vector <Tree*> trees; 
    priority_queue<Tree*, vector<Tree*>, compare> trees; 
}Node; 


/*
bool compare(Tree *a, Tree *b)
{
    return a->age < b->age; 
}
*/


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
        }
    }

    int x, y, age; 
    FOR(M)
    {
        cin >> x >> y >> age;
        Tree *tree = new Tree; 
        tree->age = age; 
        // nodes[x][y].trees.push_back(tree); 
        nodes[x][y].trees.push(tree); 
    }

    while(K--)
    {
        // 봄, 여름 
        FOR(N)
        {
            FOR2(N)
            {
                // 봄
                Node * node = &nodes[i][j];
                // sort(node->trees.begin(), node->trees.end(), compare) ;
                int dead_tree_nutrnt = 0, dead_tree_cnt = 0; 
                vector <Tree*> tempTrees; 
                while (!node->trees.empty() && node->nutrnt >= node->trees.top()->age)
                {
                    Tree * tree = node->trees.top(); 
                    node->trees.pop(); 
                    node->nutrnt -= tree->age; 
                    tree->age += 1; 
                    tempTrees.push_back(tree); 
                }
                while(!node->trees.empty())
                {
                    dead_tree_cnt += 1; 
                    dead_tree_nutrnt += node->trees.top()->age / 2; 
                    node->trees.pop(); 
                }
                // cout << "A"; 
                for(Tree* tree:tempTrees)
                {
                    node->trees.push(tree); 
                }
                // cout << "B"; 
                // tempTrees.erase(); 
                node->nutrnt += dead_tree_nutrnt; 
            

                /*
                for(Tree* tree: nodes[i][j].trees)
                {
                    // cout << tree->age << '\n'; 
                    if (node->nutrnt >= tree->age)
                    {
                        node->nutrnt -= tree->age; 
                        tree->age += 1;          
                    } 
                    else{
                        dead_tree_cnt += 1; 
                        // dead_trees.push_back(idx); 
                        dead_tree_nutrnt += tree->age/2; 
                    }
                    idx += 1; 
                }
                // 여름
                // 시간초과 의심 지점
                for(int k = 0; k < dead_tree_cnt; k++)
                // for(int k = dead_trees.size()-1; k >=0; k-=1)
                {
                    node->trees.pop_back(); 
                    // node->trees.erase(node->trees.begin() + dead_trees[k]); 
                }
                node->nutrnt += dead_tree_nutrnt; 
                */
            }
        }
        // 가을
        int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; 
        int dj[8] = {0, 1, 1, 1, 0, -1, -1, -1}; 
        FOR(N)
        {
            FOR2(N)
            {
                Node * node = &nodes[i][j]; 
                // for (Tree * tree: node->trees)
                vector <Tree *> tempTrees; 
                while(!node->trees.empty())
                {
                    Tree * tree = node->trees.top();
                    tempTrees.push_back(tree);
                    node->trees.pop();
                    if (tree->age % 5 == 0)
                    {
                        for(int k = 0; k < 8; k++)
                        {
                            int ni = i + di[k]; 
                            int nj = j + dj[k]; 
                            if (ni >= 1 && ni <= N && nj >= 1 && nj <= N)
                            {
                                Tree *new_tree = new Tree; 
                                nodes[ni][nj].trees.push(new_tree);        
                            }
                        }                    
                    }
                    // cout << "asdf"; 
                }
                static int idx = 0; 
                // cout << "hehllo " << idx << '\n'; 
                idx ++ ;

                for (Tree * tree: tempTrees)
                {
                    node->trees.push(tree); 
                }
            }
        }
        // cout << "hehllo"; 
        //겨울 
        FOR(N)
        {
            FOR2(N)
            {
                nodes[i][j].nutrnt += A[i][j]; 
            }
        }                
    }

    int ans = 0; 
    FOR(N)
    {
        FOR2(N)
        {
            ans += nodes[i][j].trees.size(); 
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