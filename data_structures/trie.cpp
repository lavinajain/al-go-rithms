//IMPLEMENTATION IN CPP
#include<iostream>
#define ll long long int
using namespace std;

struct Node{
    int data;
    struct Node* next;

};

const int ALPHABET_SIZE=26;
struct TrieNode{
  struct TrieNode *child[ALPHABET_SIZE];
  bool isend;
};

struct TrieNode *getNode(void){
    
    struct TrieNode *pNode=new TrieNode();
    pNode->isend=false;
    for(int i=0;i<ALPHABET_SIZE;i++){
        pNode->child[i]=NULL;
    }

  return pNode;  
}

void insert(struct TrieNode *root,string key){
 struct TrieNode *pCrawl=root;
 
 for(int i=0;i<key.length();i++){
     int index=key[i]-'a';
     if(!pCrawl->child[index]){
         pCrawl->child[index]= getNode();
     }
     pCrawl=pCrawl->child[index];
 }
  pCrawl->isend=true;  
}

bool search(struct TrieNode *root,string key){
    struct TrieNode *pCrawl=root;
    
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(!pCrawl->child[index]){
            return false;
        }
        pCrawl=pCrawl->child[index];
    }
    
    return (pCrawl!=NULL && pCrawl->isend!=false);
}






int main()
 { 
   int t;
   cin>>t;
  while(t--){
  int n;
  cin>>n;


struct TrieNode *root= getNode();

for(int i=0;i<n;i++){
    string key;
    cin>>key;
    insert(root,key);
}


  string a;
  cin>>a;
  if(search(root,a)==true){
      cout<<1<<endl;
  }else{
      cout<<0<<endl;
  }
  
  }
	return 0;
}
