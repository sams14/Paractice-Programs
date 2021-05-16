// Given an abstract base class Cache with member variables and functions:
// mp - Map the key to the node in the linked list
// cp - Capacity
// tail - Double linked list tail pointer
// head - Double linked list head pointer
// set() - Set/insert the value of the key, if present, otherwise add the key as the most recently used key. If the cache has reached its capacity, it should replace the least recently used key with a new key.
// get() - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// You have to write a class LRUCache which extends the class Cache and uses the member functions and variables to implement an LRU cache.

// Input Format:
// First line of input will contain the  number of lines containing  or  commands followed by the capacity  of the cache.
// The following  lines can either contain  or  commands.
// An input line starting with  will be followed by a  to be found in the cache. An input line starting with  will be followed by the  and  respectively to be inserted/replaced in the cache.

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache: public Cache
{
    public:
    LRUCache(int c) { cp = c; }
    void set(int k,int v)
    {
        if(mp.empty()) //if no node then create one and back to main() 
        {
            tail = head = new Node(k,v);
            mp[k] = head;
            return;
        }   
        if(mp.find(k) != mp.end()) //if node in the map already then 
        {
            if(head == mp[k]) //if node is already head then return to main()
                return;

            // below lines to handle node removal from its place
            mp[k]->prev->next = mp[k]->next;
            if(tail == mp[k]) 
                tail = tail->prev;
            else                   
                mp[k]->next->prev = mp[k]->prev;
            
            // after node is removed from its place and rest list is adjusted then node is made the head
            mp[k]->next = head;     mp[k]->prev = NULL;
            head->prev = mp[k];     head = mp[k];
        }
        else               // No in hash table
        {
            head->prev = new Node(head->prev,head,k,v); 
            head = head->prev;
            mp[k] = head;            
            if(mp.size() > cp) // if capacity is overpassed then
            {
                tail = tail->prev;
                mp.erase(tail->next->key);
                delete tail->next; 
                tail->next = NULL;
            }   
        }
    }
    int get(int k)
    {
        if(mp.find(k) != mp.end())
            return mp[k]->value;
        return -1;
    }
};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
