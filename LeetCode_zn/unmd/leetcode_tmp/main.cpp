//#include "GlobalHead.h"

#include <iostream>
#include <vector>
using namespace std;

struct  TreeNode{
    int val;
    int time;
    vector<TreeNode *> next;
    TreeNode(int val, int time ): val(val), time(time){}
};


void traverse(TreeNode *root, int& res, int& curLen, int& paths ){
    if(root -> next.size() == 0){
        paths++;
        res  = (res < curLen) ? curLen:res;
        return;
    }

    for(int i=0; i < root -> next.size(); i++){
        curLen += root->next[i] -> time;
        traverse(root->next[i],  res, curLen, paths );
        curLen -= root->next[i] -> time;
    }
}

int main() {
    int systems, yilai;
    cin >> systems;
    cin >> yilai;

    vector<TreeNode> time;
    for(int i = 0; i< systems; i ++){
        int ti;
        cin >> ti;
        TreeNode nn(i, ti);
        time.push_back(nn);
    }

    vector<bool> vec(systems, false);
    for(int i=0; i< yilai; i++){
        int one, two;
        cin >> one;
        cin >> two;
        time[one-1].next.push_back(&time[two-1]);
        vec[two-1] = true;
    }

//    vector<bool> vec(systems, false);
//    for(int i=0; i < systems; i++){
//        for(int j=0; j < time[i].next.size(); j++){
//            vec[time[i].next[j]->val] = true;
//        }
//    }

    vector<int> only;
    for( int i=0; i< vec.size(); i++ ){
        if (vec[i] == false)
            only.push_back(i);
    }

    int res = 0;
    int paths = 0;
    for (int i = 0; i < only.size(); i++){
        TreeNode& head = time[only[i]];
        int curLen = head.time;
        traverse(&head, res, curLen, paths );
    }

    cout << paths << "\t" << res << endl;

    return 0;
}



/* input
5 4
2
5
4
6
6
1 2
1 3
2 5
4 5
 */

/* output
5 4
2
5
4
6
6
1 2
1 3
2 5
4 5
13	3

*/