#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int pirates;
    int totalBucc;
    int flag;

    Node(int pirates){
      this->pirates = pirates;
      this->totalBucc = pirates;
      this->flag = 0;
    }
};


vector<Node> nodes;

int left(int p){ return p << 1;}
int right(int p){ return (p << 1) | 1;}

void propagate(int p){
  if(nodes[p].flag)
  {
    nodes[p].pirates = 1;
    nodes[p].totalBucc += nodes[p].flag;
  }
}

int main()
{
    int n;
    scanf("%d", &n);

    while(n--){
        int m;
        scanf("%d", &m);
        string pirates, inputString;
       
        while(m--){
            int t;
            scanf("%d", &t);
            cin>>inputString;
            while(t--){
              pirates += inputString;
            }
        }

        int lenPirates = pirates.length();

        for(int i = 0 ;i < lenPirates; i++){
          if(pirates[i] == '1')
            nodes.push_back(Node(1));
          else
            nodes.push_back(Node(0));
        }
        
        int q;
        scanf("%d", &q);

        while(q--)
        {
               
        }
    }
}
