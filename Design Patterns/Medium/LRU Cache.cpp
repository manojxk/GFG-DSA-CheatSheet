#include <bits/stdc++.h>
using namespace std;
list<pair<int, int>> cache;
unordered_map<int, list<pair<int, int>>::iterator> mp; // store key and their address in the queue
int capacity;
void refreshPosition(int key, int value)
{
    cache.erase(mp[key]);
    cache.push_front({key, value});
    mp[key] = cache.begin();
}
LRUCache(int capacity)
{
    this->capacity = capacity;
}

int get(int key)
{
    if (mp.find(key) != mp.end())
    {
        refreshPosition(key, (*mp[key]).second);
        return (*mp[key]).second;
    }
    else
        return -1;
}

void put(int key, int value)
{
    if (mp.find(key) != mp.end())
    {
        refreshPosition(key, value);
    }
    else
    {
        cache.push_front({key, value});
        mp[key] = cache.begin();
        if (cache.size() > capacity)
        {
            mp.erase(cache.back().first);
            cache.pop_back();
        }
    }
}
