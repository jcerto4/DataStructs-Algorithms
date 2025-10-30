//Joe Certo
//10/21/2025
//str_tbl.h
//The purpose of this lab is to construct a hash table template class that uses string keys,
//hashes the key, and determines what bucket in the hash table to add it too. The hash table
//utilizes chaining to resolve collisions of hashes

#ifndef STR_TBL_H
#define STR_TBL_H

#include <list>
#include <utility>
#include <iostream> 
#include <string>

using namespace std;

template <typename V>
class str_tbl{
private:
    unsigned int _nbuckets;
    unsigned int _size = 0;
    list<pair<string, V>>** bucket;
    unsigned int hashCode(const string& key){
        unsigned int hash = 0;
        for(int i = 0; i < key.length(); i++){
            hash = 31 * hash + key[i];
        }

        return hash % _nbuckets;
    }
public:
    str_tbl() : str_tbl(10) { }
    str_tbl(const unsigned int nbuckets){
        _nbuckets = nbuckets;
        bucket = new list<pair<string, V>>*[_nbuckets];
        for(int i = 0; i < _nbuckets; i++){
            bucket[i] = new list<pair<string, V>>();
        }
    }
    ~str_tbl(){
        for(int i = 0; i < _nbuckets; i++){
            delete bucket[i];
        }
        delete[] bucket;
    }
    void insert(const string& key, const V& value){
        int index = hashCode(key);
        auto& temp = *bucket[index];
        V* found = search(key);
        if(found){
            *found = value;
            return;
        }
        temp.push_front(make_pair(key, value));
        ++_size;
    }
    V* search(const string& key){
        int index = hashCode(key);
        auto& temp = *bucket[index];
        for(auto it = temp.begin(); it != temp.end(); it++){
            if(it->first == key){
                return &(it->second);
            }
        }
        return nullptr;
        
    }
    void remove(const string& key){
        int index = hashCode(key);
        auto& temp = *bucket[index];
        for(auto it = temp.begin(); it != temp.end(); it++){
            if(it->first == key){
                temp.erase(it);
                --_size;
                return;
            }
        } 
    }
    double load_factor(){
        return static_cast<double>(_size) / _nbuckets;
    }
    unsigned int size(){
        return _size;
    }
    void display(ostream& os) const {
        for(int i = 0; i < _nbuckets; i++){
            os << "bucket[" << i << "]: ";
            const auto& temp = *bucket[i];
            bool front = true;
            for(auto it = temp.begin(); it != temp.end(); it++){
                if(!front) os << " -> ";
                os << "(" << it->first << ":" << it->second << ")";
                front = false;
            }
            temp.empty() ? os << "null" : os << " -> null";
            os << endl;
        }
    }

};


#endif