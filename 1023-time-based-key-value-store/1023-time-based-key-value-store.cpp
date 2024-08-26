class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>myMap;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamyMap) {
     myMap[key].push_back({timestamyMap, value});
    }
    
    string get(string key, int timestamyMap) {
    if(myMap.find(key) == myMap.end())
      {
          return "";
      }
    int l = 0;
    int r = myMap[key].size()-1;
    if(myMap[key][0].first > timestamyMap)
    {
        return "";
    }
    string ans;
    while(l<=r)
    {
      int mid = l + (r-l)/2;
      if(myMap[key][mid].first == timestamyMap)
      {
          return myMap[key][mid].second;
      }
      else if(myMap[key][mid].first < timestamyMap)
      {
          ans = myMap[key][mid].second;
          l = mid+1;
      }
      else
      {
          r = mid-1;
      }
    }
    return ans;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */