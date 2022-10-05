
struct node{
    char d;
    unordered_map<char,node*> m;
    bool isterminal;
    int cnt;

    node(char _d){
        d = _d;
        isterminal = false;
        cnt = 0;
    }
};

struct trie{
    node * root;

    trie(){
        root = new node('\0');
    }

    void add_word(string s){
        node * temp = root;
        for(auto ch : s){
            if(temp->m.count(ch) == 0){
                node * n = new node(ch);
                temp->m[ch] = n;
            }

            temp = temp->m[ch];
            temp->cnt++;
        }
        temp->isterminal = true;
    }

    int search(string s){
        node * temp = root;
        for(auto ch : s){
            if(temp->m.count(ch) == 0){
                return 0;
            }
            temp = temp->m[ch];
        }
        return temp->cnt;
    }
};


class Solution{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        vector<int> ans;
        trie t;
        for(int i = 0 ; i < N ; i++) t.add_word(li[i]);
        for(int i = 0 ; i < Q ; i++){
            ans.push_back(t.search(query[i]));
        }
        return ans;
        // code here
    }
};
