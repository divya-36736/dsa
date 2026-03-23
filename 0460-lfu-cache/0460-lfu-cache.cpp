#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, value, freq;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        freq = 1;
        prev = next = NULL;
    }
};

class DLL {
public:
    Node* head;
    Node* tail;

    DLL() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // insert at front
    void addFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // remove any node
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // remove least recently used (tail->prev)
    Node* removeLast() {
        if (head->next == tail) return NULL;
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

    bool isEmpty() {
        return head->next == tail;
    }
};

class LFUCache {
public:
    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyNode;   // key → node
    unordered_map<int, DLL*> freqNode;   // freq → list

    LFUCache(int cap) {
        capacity = cap;
        minFreq = 0;
    }

    void updateFreq(Node* node) {
        int freq = node->freq;
        freqNode[freq]->removeNode(node);

        // if this was the only node in minFreq list
        if (freq == minFreq && freqNode[freq]->isEmpty()) {
            minFreq++;
        }

        node->freq++;

        if (freqNode.find(node->freq) == freqNode.end()) {
            freqNode[node->freq] = new DLL();
        }

        freqNode[node->freq]->addFront(node);
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }

        Node* node = keyNode[key];
        updateFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        // if key already exists
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        // if cache is full
        if (keyNode.size() == capacity) {
            DLL* list = freqNode[minFreq];
            Node* nodeToRemove = list->removeLast();
            keyNode.erase(nodeToRemove->key);
            delete nodeToRemove;
        }

        // insert new node
        Node* newNode = new Node(key, value);
        minFreq = 1;

        if (freqNode.find(1) == freqNode.end()) {
            freqNode[1] = new DLL();
        }

        freqNode[1]->addFront(newNode);
        keyNode[key] = newNode;
    }
};