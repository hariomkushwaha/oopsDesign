#include <bits/stdc++.h>

using namespace std;

 class Node
 {
 public:
 	int key;
 	int val;
 	Node* next;
 	Node* pre;
 	Node(int key,int val){
 		this->key=key;
 		this->val=val;
 	}
 };

 class LRUCache
 {
 private: 
 
 	unordered_map<int,Node*>ump;
 
 	int cap;
 	Node *head=new Node(-1,-1);
 	Node *tail=new Node(-1,-1);

 public:
 	LRUCache(int cap){
 		this->cap=cap;
 		head->next=tail;
 		tail->pre =head;
 	}

 	
 	 	void addNode(Node* delnod){
 		Node * temp=head->next;
 		delnod->next=temp;
 		delnod->pre=head;
 		head->next=delnod;
 		temp->pre=delnod;
 	}


 	void deleteNode(Node* delnod){
 		Node *delnext=delnod->next;
 		Node *delpre=delnod->pre;

 		delnext->pre=delpre;
 		delpre->next=delnext;
 	}

 	void put(int key,int val){
 		if(ump.find(key)!=ump.end()){
 			Node *delnod=ump[key];
 			ump.erase(key);
 			deleteNode(delnod);
 		}

 		if(cap==mp.size()){
 			ump.erase(tail->pre->val);
 			deleteNode(tail->pre);
 		}

 		addNode(new Node(key,val));
 		ump[key]=head->next;
 	}

 	int get(int key){
 		if(ump.find(key)!=ump.end()){
 			Node *delnod=ump[key];
 			int ans= delnod->val;
 			ump.erase(key);
 			deleteNode(delnod);
 			addNode(delnod);
 			ump[key]=head->next;
 			return ans;	
 		}
 		return -1;
 	}
 	
 	
 };



int main(){

	LRUCache * obj= new LRUCache(3);

	obj->put(3,34);
	obj->put(2,35);
	obj->put(4,1);
	cout<<obj->get(3)<<endl;
	cout<<obj->get(2)<<endl;
	cout<<obj->get(4)<<endl;
	
	obj->put(3,4);
	obj->put(2,5);
	obj->put(4,10);
	cout<<obj->get(4)<<endl;
	cout<<obj->get(3)<<endl;
	cout<<obj->get(2)<<endl;



	return 0;
}
